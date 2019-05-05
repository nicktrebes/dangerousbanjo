#ifndef __STDARG_H__
#define __STDARG_H__

/*
 * MIT License
 *
 * include/libc/stdarg.h
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

#include <sys/types.h>

#ifdef __KERNEL32__
#define _STACK_ELEM (4)
#else /* __KERNEL32__ */
#define _STACK_ELEM (8)
#endif /* __KERNEL32__ */

#define _STACK_OFFSET(type) ((sizeof(type) % _STACK_ELEM) ? \
	(((sizeof(type) / _STACK_ELEM) + 1) * _STACK_ELEM) : sizeof(type))

#define va_arg(list,type) (*(type*)(((size_t)(list = (va_list)(((size_t)list) \
	+ _STACK_OFFSET(type)))) \
	- _STACK_OFFSET(type)))
#define va_copy(dst,src) (((va_list)dst) = ((va_list)src))
#define va_end(list) ((void)(list = ((va_list)NULL)))
#define va_start(list,param) (list = (va_list)(((size_t)(&param)) \
	+ _STACK_OFFSET(param)))

typedef void* va_list;

#endif /* ! __STDARG_H__ */
