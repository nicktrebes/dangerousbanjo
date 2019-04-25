/*
 * MIT License
 *
 * kernel/vga.c
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

#include "kutil.h"
#include "kvaddr.h"
#include "vga.h"

static const uint8_t VGA_HEIGHT = 25;
static const uint8_t VGA_TAB = 4;
static const uint8_t VGA_WIDTH = 80;

#define VGA_ENTRY(r,c) ((r * VGA_WIDTH) + c)

static uint16_t* _vga_buf;
static uint16_t _vga_color;
static uint8_t _vga_col, _vga_row;

static void _putc(char c);

void vga_clear(void) {
	uint16_t entry;
	uint8_t col, row;
	entry = (_vga_color | ' ');
	for (row = 0; row < VGA_HEIGHT; ++row) {
		for (col = 0; col < VGA_WIDTH; ++col)
			_vga_buf[(row * VGA_WIDTH) + col] = entry;
	}
	_vga_col = 0;
	_vga_row = 0;
}

void vga_color(vga_color_t fg, vga_color_t bg) {
	_vga_color = ((((uint16_t)bg) << 12) | (((uint16_t)fg) << 8));
}

void vga_cursor(uint8_t row, uint8_t col) {
	_vga_col = (col % VGA_WIDTH);
	_vga_row = (row % VGA_HEIGHT);
}

void vga_init(void) {
	_vga_buf = (uint16_t*)KVADDR_VGA_BUF;
	vga_color(VGA_COLOR_LIGHT_GREY,VGA_COLOR_BLACK);
	vga_clear();
}

void vga_putc(char c) {
	switch (c) {
	case '\n':
		do { _putc(' '); } while (_vga_col);
		break;
	case '\r':
		_vga_col = 0;
		vga_putc('\n');
		--_vga_row;
		break;
	case '\t':
		do { _putc(' '); } while (_vga_col % VGA_TAB);
		break;
	default:
		_putc(c);
	}
}

void vga_scroll(uint8_t lines) {
	uint16_t entry = (_vga_color | ((uint16_t)' '));
	uint8_t col, row;

	if (lines >= VGA_HEIGHT) {
		vga_clear();
		return;
	}

	for (row = 0; row < (VGA_HEIGHT - lines); ++row) {
		for (col = 0; col < VGA_WIDTH; ++col)
			_vga_buf[VGA_ENTRY(row,col)] = _vga_buf[VGA_ENTRY((row + lines),col)];
	}

	for (; row < VGA_HEIGHT; ++row) {
		for (col = 0; col < VGA_WIDTH; ++col)
			_vga_buf[VGA_ENTRY(row,col)] = entry;
	}
}

void vga_write(const char* str) {
	char c;
	for (; (c = *str); ++str) vga_putc(c);
}

static void _putc(char c) {
	_vga_buf[VGA_ENTRY(_vga_row,_vga_col)] = (_vga_color | ((uint16_t)c));
	if ((++_vga_col) >= VGA_WIDTH) {
		_vga_col = 0;
		if ((++_vga_row) >= VGA_HEIGHT) {
			vga_scroll(1);
			_vga_row = (VGA_HEIGHT - 1);
		}
	}
}
