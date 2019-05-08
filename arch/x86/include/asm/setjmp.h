#ifndef __X86_ASM_SETJMP_H__
#define __X86_ASM_SETJMP_H__

/*
 * MIT License
 *
 * arch/x86/include/asm/setjmp.h
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

#include <asm/bits.h>
#ifdef __KERNEL_X86__

#define _JBLEN (0 /* TODO */)

typedef int jmp_buf[_JBLEN];
typedef int sigjmp_buf[_JBLEN + 1];

#define longjmp _longjmp
#define setjmp  _setjmp

void   _longjmp(jmp_buf, int);
int    _setjmp(jmp_buf);
void   siglongjmp(sigjmp_buf, int);
int    sigsetjmp(sigjmp_buf, int);

#endif /* __KERNEL_X86__ */
#endif /* ! __X86_ASM_SETJMP_H__ */
