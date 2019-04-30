#ifndef __KPAGE_H__
#define __KPAGE_H__

/*
 * MIT License
 *
 * kernel/kpage.h
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

#include <stdint.h>

#define KPAGE_SIZE     (4096)
#define KPAGE_START    (0x10000000 /* & 0xF0000000 */)
#define KPAGE_MAPSIZE  ((0xFFFE0000 - KPAGE_START) / (KPAGE_SIZE * 32))
#define KPAGE_PREALLOC (16)

void kinit_page();
uint32_t kpage_alloc();
void kpage_free(uint32_t page);
void kpage_map(uint32_t vaddr, uint32_t paddr, uint16_t flags);
uint32_t kpage_resolve(uint32_t vaddr);
void kpage_umap(uint32_t vaddr, int free);

#endif
