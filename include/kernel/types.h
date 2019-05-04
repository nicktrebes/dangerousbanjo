#ifndef __KERNEL_TYPES_H__
#define __KERNEL_TYPES_H__

/*
 * MIT License
 *
 * include/kernel/types.h
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

#ifndef __GNUC__
#error GNU Compiler Collection required at this time.
#endif /* ! __GNUC__ */

#include <asm/bits.h>

#ifdef __KERNEL_X86__
#define __cdecl   __attribute__((cdecl))
#define __stdcall __attribute__((stdcall))
#else /* __KERNEL_X86__ */
#define __cdecl
#define __stdcall
#endif /* __KERNEL_X86__ */

#define __aligned(n)    __attribute__((aligned(n)))
#define __format(t,s,f) __attribute__((format(t,s,f)))
#define __noreturn      __attribute__((noreturn))
#define __packed        __attribute__((packed))
#define __pure          __attribute__((pure))
#define __unused        __attribute__((unused))

typedef __INT8_TYPE__  s8;
typedef __INT16_TYPE__ s16;
typedef __INT32_TYPE__ s32;
typedef __INT64_TYPE__ s64;

typedef __UINT8_TYPE__  u8;
typedef __UINT16_TYPE__ u16;
typedef __UINT32_TYPE__ u32;
typedef __UINT64_TYPE__ u64;

#endif /* ! __KERNEL_TYPES_H__ */
