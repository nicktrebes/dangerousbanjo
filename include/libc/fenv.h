#ifndef __FENV_H__
#define __FENV_H__

/*
 * MIT License
 *
 * include/libc/fenv.h
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

#include <asm/fenv.h>
#include <sys/types.h>

int feclearexcept(int flags);
int fegetenv(fenv_t* fenv);
int fegetexceptflag(fexcept_t* fexcept, int flag);
int fegetround(void);
int feholdexcept(fenv_t* fenv);
int feraiseexcept(int except);
int fesetenv(const fenv_t* fenv);
int fesetexceptflag(const fexcept_t* fexcept, int flag);
int fesetround(int round);
int fetestexcept(int except);
int feupdateenv(const fenv_t* fenv);

#endif /* ! __FENV_H__ */
