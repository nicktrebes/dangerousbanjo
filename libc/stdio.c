/*
 * MIT License
 *
 * libc/stdio.c
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

#include <stdio.h>

char* ctermid(char* buf) {
	// TODO
	return NULL;
}

int remove(const char* path) {
	// TODO
	return 0;
}

int rename(const char* path0, const char* path1) {
	// TODO
	return 0;
}

int renameat(int fd0, const char* path0, int fd1, const char* path1) {
	// TODO
	return 0;
}

char* tempnam(const char* dir, const char* pfx) {
	// TODO
	return NULL;
}

FILE* tmpfile(void) {
	return fopen(tempnam(NULL,NULL),"w");
}

char* tmpnam(char* buf) {
	// TODO
	return NULL;
}
