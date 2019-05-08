#ifndef __FMTMSG_H__
#define __FMTMSG_H__

/*
 * MIT License
 *
 * include/libc/fmtmsg.h
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

#define MM_HARD    (1<<0)
#define MM_SOFT    (1<<1)
#define MM_FIRM    (1<<2)
#define MM_APPL    (1<<3)
#define MM_UTIL    (1<<4)
#define MM_OPSYS   (1<<5)
#define MM_RECOVER (1<<6)
#define MM_NRECOV  (1<<7)
#define MM_HALT    (1<<8)
#define MM_ERROR   (1<<9)
#define MM_WARNING (1<<10)
#define MM_INFO    (1<<11)
#define MM_NOSEV   (1<<12)
#define MM_PRINT   (1<<13)
#define MM_CONSOLE (1<<14)

enum {
	MM_OK,
	MM_NOTOK,
	MM_NOMSG,
	MM_NOCON
};

int fmtmsg(long, const char*, int,
	const char*, const char*, const char*);

#endif /* ! __FMTMSG_H__ */
