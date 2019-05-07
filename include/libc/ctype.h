#ifndef __CTYPE_H__
#define __CTYPE_H__

/*
 * MIT License
 *
 * include/libc/ctype.h
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

#include <locale.h>

#define _tolower(c) (((c >= 'A') & (c <= 'Z')) ? ((c - 'A') + 'a') : c)
#define _toupper(c) (((c >= 'a') & (c <= 'z')) ? ((c - 'a') + 'A') : c)

int isalnum(int c);
int isalnum_l(int c, locale_t locale);
int isalpha(int c);
int isalpha_l(int c, locale_t locale);
int isascii(int c);
int isblank(int c);
int isblank_l(int c, locale_t locale);
int iscntrl(int c);
int iscntrl_l(int c, locale_t locale);
int isdigit(int c);
int isdigit_l(int c, locale_t locale);
int isgraph(int c);
int isgraph_l(int c, locale_t locale);
int islower(int c);
int islower_l(int c, locale_t locale);
int isprint(int c);
int isprint_l(int c, locale_t locale);
int ispunct(int c);
int ispunct_l(int c, locale_t locale);
int isspace(int c);
int isspace_l(int c, locale_t locale);
int isupper(int c);
int isupper_l(int c, locale_t locale);
int isxdigit(int c);
int isxdigit_l(int c, locale_t locale);
int toascii(int c);
int tolower(int c);
int tolower_l(int c, locale_t locale);
int toupper(int c);
int toupper_l(int c, locale_t locale);

#endif /* ! __CTYPE_H__ */
