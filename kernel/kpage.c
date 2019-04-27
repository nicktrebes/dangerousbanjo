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

#define KPAGE_MAPSIZE  (131040)
#define KPAGE_PREALLOC (16)

extern uint32_t _kernel_end;

static uint8_t _kpage_map[KPAGE_MAPSIZE];
static kpage_t _kpage_pre[KPAGE_PREALLOC];
static uint32_t _kpage_pcount, _kpage_ptr, _kpage_start;

static kpage_t _alloc_page();
static void _free_page(kpage_t page);

void kinit_page() {
	uint32_t end = (_kernel_end - 0xC0000000);
	uint32_t n;

	_kpage_pcount = 0;
	_kpage_ptr = 0;
	_kpage_start = ((end % KPAGE_SIZE) ?
		((end - (end % KPAGE_SIZE)) + KPAGE_SIZE) : end);

	for (n = 0; n < KPAGE_MAPSIZE; ++n)
		_kpage_map[n] = 0;
	for (n = 0; n < KPAGE_PREALLOC; ++n)
		_kpage_pre[n] = 0;
}

kpage_t kpage_alloc() {
	if (_kpage_pcount == 0) {
		uint32_t n;
		for (n = 0; n < KPAGE_PREALLOC; ++n)
			_kpage_pre[n] = _alloc_page();
		_kpage_pcount = KPAGE_PREALLOC;
	}
	return _kpage_pre[--_kpage_pcount];
}

void kpage_free(kpage_t page) {
	if (_kpage_pcount < KPAGE_PREALLOC)
		_kpage_pre[_kpage_pcount++] = page;
	else _free_page(page);
}

static kpage_t _alloc_page() {
	uint32_t n = _kpage_ptr;
	do {
		uint8_t entry = _kpage_map[n];
		if ((entry & 0x0FF) == 0) {
			uint8_t frame, taken = 0x80;
			for (frame = 0; frame < 8; ++frame) {
				if ((entry & taken) == 0) {
					_kpage_map[n] = (entry | taken);
					_kpage_ptr = n;
					return (kpage_t)(_kpage_start + (KPAGE_SIZE * ((n * 8) + frame)));
				}
				taken >>= 1;
			}
		}
		n = ((n + 1) % KPAGE_MAPSIZE);
	} while (n != _kpage_ptr);

	kpanic("OUT OF MEMORY");
	return 0;
}

static void _free_page(kpage_t page) {
	uint32_t rel = (((uint32_t)page) - _kpage_start);
	uint32_t idx = (rel / KPAGE_SIZE);
	uint8_t bit = (0x80 >> (rel % 8));
	if (idx >= KPAGE_MAPSIZE)
		kpanic("ATTEMPT TO FREE INVALID PAGE");
	_kpage_map[idx] &= (~bit);
}
