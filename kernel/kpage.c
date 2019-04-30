/*
 * MIT License
 *
 * kernel/kpage.c
 * Copyright (C) 2019 Nick Trebes
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "kpage.h"
#include "kutil.h"
#include "kvaddr.h"

static uint32_t _kpage_map[KPAGE_MAPSIZE];
static uint32_t _kpage_pre[KPAGE_PREALLOC];
static uint32_t _kpage_pcount, _kpage_ptr;

static uint32_t _alloc_page();
static inline void _flush_tlb(void);
static void _free_page(uint32_t page);

void kinit_page() {
	uint32_t n;

	_kpage_pcount = 0;
	_kpage_ptr = 0;

	for (n = 0; n < KPAGE_MAPSIZE; ++n)
		_kpage_map[n] = 0;
	for (n = 0; n < KPAGE_PREALLOC; ++n)
		_kpage_pre[n] = 0;
}

uint32_t kpage_alloc() {
	if (_kpage_pcount == 0) {
		uint32_t n;
		for (n = 0; n < KPAGE_PREALLOC; ++n)
			_kpage_pre[n] = _alloc_page();
		_kpage_pcount = KPAGE_PREALLOC;
	}
	return _kpage_pre[--_kpage_pcount];
}

void kpage_free(uint32_t page) {
	if (_kpage_pcount < KPAGE_PREALLOC)
		_kpage_pre[_kpage_pcount++] = page;
	else _free_page(page);
}

void kpage_map(uint32_t vaddr, uint32_t paddr, uint16_t flags) {
	uint32_t *pd, *pt;
	uint32_t pde, pdi, pti;

	pd = (uint32_t*)KVADDR_PAGE_DIR;
	pdi = ((vaddr >> 22) & 0x000003FF);
	pde = pd[pdi];
	pt = (uint32_t*)(KVADDR_PAGE_TAB | (pdi << 12));

	if ((pde & 1) == 0) {
		uint32_t n;
		pd[pdi] = (kpage_alloc() | 0x003);
		for (n = 0; n < 1024; ++n) pt[n] = 0;
	}

	pti = ((vaddr >> 12) & 0x000003FF);
	pt[pti] = (paddr | (flags & 0x03FF));

	_flush_tlb();
}

uint32_t kpage_resolve(uint32_t vaddr) {
	uint32_t *pd, *pt;
	uint32_t pde, pdi, pti;

	pd = (uint32_t*)KVADDR_PAGE_DIR;
	pdi = ((vaddr >> 22) & 0x000003FF);
	pde = pd[pdi];
	if ((pde & 1) == 0) return 0;

	pt = (uint32_t*)(KVADDR_PAGE_TAB | (pdi << 12));
	pti = ((vaddr >> 12) & 0x000003FF);
	return (pt[pti] & 0xFFFFFC00);
}

static uint32_t _alloc_page() {
	uint32_t n = _kpage_ptr;
	do {
		uint32_t entry = _kpage_map[n];
		if (entry ^ 0xFFFFFFFF) {
			uint32_t page, taken = 0x80000000;
			for (page = 0; page < 32; ++page) {
				if ((entry & taken) == 0) {
					_kpage_map[n] = (entry | taken);
					_kpage_ptr = n;
					return (KPAGE_START + (KPAGE_SIZE * ((n * 32) + page)));
				}
				taken >>= 1;
			}
		}
		n = ((n + 1) % KPAGE_MAPSIZE);
	} while (n != _kpage_ptr);

	kpanic("OUT OF PAGES");
	return 0;
}

static inline void _flush_tlb(void) {
	asm volatile ( "movl %%cr3, %%eax" : : );
	asm volatile ( "movl %%eax, %%cr3" : : );
}

static void _free_page(uint32_t page) {
	uint32_t rel = ((page - KPAGE_START) / KPAGE_SIZE);
	uint32_t idx = (rel / 32);
	uint32_t bit = (0x80000000 >> (rel % 32));
	if (idx >= KPAGE_MAPSIZE)
		kpanic("ATTEMPT TO FREE INVALID PAGE");
	_kpage_map[idx] &= (~bit);
}
