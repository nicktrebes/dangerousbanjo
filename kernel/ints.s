/*
 * MIT License
 *
 * kernel/ints.s
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

.section .data
idtr:
.word
.long

.section .text

.extern int14_handler
.extern irq0_handler
.extern irq1_handler
.extern irq2_handler
.extern irq3_handler
.extern irq4_handler
.extern irq5_handler
.extern irq6_handler
.extern irq7_handler
.extern irq8_handler
.extern irq9_handler
.extern irq10_handler
.extern irq11_handler
.extern irq12_handler
.extern irq13_handler
.extern irq14_handler
.extern irq15_handler

.global int14
.type int14, @function
int14:
	call int14_handler
	addl $4, %esp
	iret

.global irq0
.type irq0, @function
irq0:
	pusha
	call irq0_handler
	popa
	iret

.global irq1
.type irq1, @function
irq1:
	pusha
	call irq1_handler
	popa
	iret

.global irq2
.type irq2, @function
irq2:
	pusha
	call irq2_handler
	popa
	iret

.global irq3
.type irq3, @function
irq3:
	pusha
	call irq3_handler
	popa
	iret

.global irq4
.type irq4, @function
irq4:
	pusha
	call irq4_handler
	popa
	iret

.global irq5
.type irq5, @function
irq5:
	pusha
	call irq5_handler
	popa
	iret

.global irq6
.type irq6, @function
irq6:
	pusha
	call irq6_handler
	popa
	iret

.global irq7
.type irq7, @function
irq7:
	pusha
	call irq7_handler
	popa
	iret

.global irq8
.type irq8, @function
irq8:
	pusha
	call irq8_handler
	popa
	iret

.global irq9
.type irq9, @function
irq9:
	pusha
	call irq9_handler
	popa
	iret

.global irq10
.type irq10, @function
irq10:
	pusha
	call irq10_handler
	popa
	iret

.global irq11
.type irq11, @function
irq11:
	pusha
	call irq11_handler
	popa
	iret

.global irq12
.type irq12, @function
irq12:
	pusha
	call irq12_handler
	popa
	iret

.global irq13
.type irq13, @function
irq13:
	pusha
	call irq13_handler
	popa
	iret

.global irq14
.type irq14, @function
irq14:
	pusha
	call irq14_handler
	popa
	iret

.global irq15
.type irq15, @function
irq15:
	pusha
	call irq15_handler
	popa
	iret

.global load_idt
.type load_idt, @function
load_idt:
	movl 4(%esp), %eax
	movl %eax, idtr + 2
	movw 8(%esp), %ax
	movw %ax, idtr
	lidt idtr
	sti
	ret
