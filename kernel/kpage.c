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

#define KPAGE_MAPSIZE  (0xB0000000 / (KPAGE_SIZE * 32))
#define KPAGE_PREALLOC (16)
#define KPAGE_START    (0x10000000)

static uint32_t _kpage_map[KPAGE_MAPSIZE];
static uint32_t _kpage_pre[KPAGE_PREALLOC];
static uint32_t _kpage_pcount, _kpage_ptr;

static uint32_t _alloc_page();
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
	uint32_t page;
	if (_kpage_pcount == 0) {
		uint32_t n;
		for (n = 0; n < KPAGE_PREALLOC; ++n)
			_kpage_pre[n] = _alloc_page();
		_kpage_pcount = KPAGE_PREALLOC;
	}
	page = _kpage_pre[--_kpage_pcount];
	klogf("Allocated page at 0x%x\n",(uint32_t)page);
	return page;
}

void kpage_free(uint32_t page) {
	if (_kpage_pcount < KPAGE_PREALLOC)
		_kpage_pre[_kpage_pcount++] = page;
	else _free_page(page);
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

	kpanic("OUT OF MEMORY");
	return 0;
}

static void _free_page(uint32_t page) {
	uint32_t rel = ((page - KPAGE_START) / KPAGE_SIZE);
	uint32_t idx = (rel / 32);
	uint32_t bit = (0x80000000 >> (rel % 32));
	if (idx >= KPAGE_MAPSIZE)
		kpanic("ATTEMPT TO FREE INVALID PAGE");
	_kpage_map[idx] &= (~bit);
}
