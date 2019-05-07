#ifndef __LOCALE_H__
#define __LOCALE_H__

/*
 * MIT License
 *
 * include/libc/locale.h
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

#include <stddef.h>

// TODO
#define LC_ALL      (0)
#define LC_COLLATE  (0)
#define LC_CTYPE    (0)
#define LC_MESSAGES (0)
#define LC_MONETARY (0)
#define LC_NUMERIC  (0)
#define LC_TIME     (0)

#define LC_COLLATE_MASK  (1<<0)
#define LC_CTYPE_MASK    (1<<1)
#define LC_MESSAGES_MASK (1<<2)
#define LC_MONETARY_MASK (1<<3)
#define LC_NUMERIC_MASK  (1<<4)
#define LC_TIME_MASK     (1<<5)
#define LC_ALL_MASK      (0x3F)

#define LC_GLOBAL_LOCALE _lc_global_locale()

typedef char* locale_t;

struct lconv {
	char* currency_symbol;
	char* decimal_point;
	char  frac_digits;
	char* grouping;
	char* int_curr_symbol;
	char  int_frac_digits;
	char  int_n_cs_precedes;
	char  int_n_sep_by_space;
	char  int_n_sign_posn;
	char  int_p_cs_precedes;
	char  int_p_sep_by_space;
	char  int_p_sign_posn;
	char* mon_decimal_point;
	char* mon_grouping;
	char* mon_thousands_sep;
	char* negative_sign;
	char  n_cs_precedes;
	char  n_sep_by_space;
	char  n_sign_posn;
	char* positive_sign;
	char  p_cs_precedes;
	char  p_sep_by_space;
	char  p_sign_posn;
	char* thousands_sep;
};

locale_t LC_GLOBAL_LOCALE;

locale_t duplocate(locale_t locale); // Why is this misspelled in the POSIX standard?
void freelocale(locale_t locale);
struct lconv* localeconv(void);
locale_t newlocale(int mask, const char* locale, locale_t base);
char* setlocale(int mask, const char* locale);
locale_t uselocale(locale_t locale);

#endif /* ! __LOCALE_H__ */
