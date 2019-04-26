/*
 * MIT License
 *
 * kernel/gdtc.c
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

#include "gdt.h"
#include "kutil.h"

extern void load_gdt();

static uint8_t _gdt_buf[32];

static void _gdt_entry(uint8_t* entry, uint32_t base, uint32_t limit, uint8_t type);

void kinit_gdt() {
	_gdt_entry((&_gdt_buf[0]),0,0,0);
	_gdt_entry((&_gdt_buf[8]),0,0xFFFFFFFF,0x9A);
	_gdt_entry((&_gdt_buf[16]),0,0xFFFFFFFF,0x92);
	_gdt_entry((&_gdt_buf[24]),(uint32_t)ktss,(uint32_t)sizeof(ktss),0x89);
	load_gdt(_gdt_buf,sizeof(_gdt_buf));
}

static void _gdt_entry(uint8_t* entry, uint32_t base, uint32_t limit, uint8_t type) {
	// Check limit and adjust granularity if necessary
	if (limit > 65536) {
		if ((limit & 0x0FFF) != 0x0FFF)
			kpanic("INVALID GDT ENTRY");
		limit >>= 12;
		entry[6] = 0xC0;
	} else entry[6] = 0x40;

	// Encode limit
	entry[0] = (uint8_t)(limit & 0x0FF);
	entry[1] = (uint8_t)((limit >> 8) & 0x0FF);
	entry[6] |= (uint8_t)((limit >> 16) & 0x0F);

	// Encode base
	entry[2] = (uint8_t)(base & 0x0FF);
	entry[3] = (uint8_t)((base >> 8) & 0x0FF);
	entry[4] = (uint8_t)((base >> 16) & 0x0FF);
	entry[7] = (uint8_t)((base >> 24) & 0x0FF);

	// Encode type
	entry[5] = type;
}
