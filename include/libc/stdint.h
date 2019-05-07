#ifndef __STDINT_H__
#define __STDINT_H__

/*
 * MIT License
 *
 * include/libc/stdint.h
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

#include <kernel/types.h>

/* Exact-width integer limits */

#define INT8_MIN   (-0x7F - 1)
#define INT16_MIN  (-0x7FFF - 1)
#define INT32_MIN  (-0x7FFFFFFF - 1)
#define INT64_MIN  (-0x7FFFFFFFFFFFFFFFL - 1)
#define INTMAX_MIN (INT64_MIN)

#define INT8_MAX   (0x7F)
#define INT16_MAX  (0x7FFF)
#define INT32_MAX  (0x7FFFFFFF)
#define INT64_MAX  (0x7FFFFFFFFFFFFFFFL)
#define INTMAX_MAX (INT64_MAX)

#define UINT8_MAX   (0xFF)
#define UINT16_MAX  (0xFFFF)
#define UINT32_MAX  (0xFFFFFFFF)
#define UINT64_MAX  (0xFFFFFFFFFFFFFFFFL)
#define UINTMAX_MAX (UINT64_MAX)

/* Minimum-width integer limits */

#define INT_LEAST8_MIN  (INT8_MIN)
#define INT_LEAST16_MIN (INT16_MIN)
#define INT_LEAST32_MIN (INT32_MIN)
#define INT_LEAST64_MIN (INT64_MIN)

#define INT_LEAST8_MAX  (INT8_MAX)
#define INT_LEAST16_MAX (INT16_MAX)
#define INT_LEAST32_MAX (INT32_MAX)
#define INT_LEAST64_MAX (INT64_MAX)

#define UINT_LEAST8_MAX  (UINT8_MAX)
#define UINT_LEAST16_MAX (UINT16_MAX)
#define UINT_LEAST32_MAX (UINT32_MAX)
#define UINT_LEAST64_MAX (UINT64_MAX)

/* Casting */

#define INT8_C(n)   ((int_least8_t)n)
#define INT16_C(n)  ((int_least16_t)n)
#define INT32_C(n)  ((int_least32_t)n)
#define INT64_C(n)  ((int_least64_t)n)
#define INTMAX_C(n) ((intmax_t)n)

#define UINT8_C(n)   ((uint_least8_t)n)
#define UINT16_C(n)  ((uint_least16_t)n)
#define UINT32_C(n)  ((uint_least32_t)n)
#define UINT64_C(n)  ((uint_least64_t)n)
#define UINTMAX_C(n) ((uintmax_t)n)

/* Signed typedefs */

typedef s8  int8_t;
typedef s16 int16_t;
typedef s32 int32_t;
typedef s64 int64_t;

typedef s8  int_least8_t;
typedef s16 int_least16_t;
typedef s32 int_least32_t;
typedef s64 int_least64_t;

typedef s64    intmax_t;
typedef sptr_t intptr_t;

/* Unsigned typedefs */

typedef u8  uint8_t;
typedef u16 uint16_t;
typedef u32 uint32_t;
typedef u64 uint64_t;

typedef u8  uint_least8_t;
typedef u16 uint_least16_t;
typedef u32 uint_least32_t;
typedef u64 uint_least64_t;

typedef u64    uintmax_t;
typedef uptr_t uintptr_t;

#ifdef __KERNEL32__

/* Signed address-width limits */

#define INTPTR_MIN (INT32_MIN)
#define INTPTR_MAX (INT32_MAX)

/* Signed fast integer limits */

#define INT_FAST8_MIN  (INT32_MIN)
#define INT_FAST16_MIN (INT32_MIN)
#define INT_FAST32_MIN (INT32_MIN)
#define INT_FAST64_MIN (INT64_MIN)

#define INT_FAST8_MAX  (INT32_MAX)
#define INT_FAST16_MAX (INT32_MAX)
#define INT_FAST32_MAX (INT32_MAX)
#define INT_FAST64_MAX (INT64_MAX)

/* Unsigned address-width limit */

#define UINTPTR_MAX (UINT32_MAX)

/* Unsigned fast integer limits */

#define UINT_FAST8_MAX  (UINT32_MAX)
#define UINT_FAST16_MAX (UINT32_MAX)
#define UINT_FAST32_MAX (UINT32_MAX)
#define UINT_FAST64_MAX (UINT64_MAX)

/* Fast integer typedefs */

typedef s32 int_fast8_t;
typedef s32 int_fast16_t;
typedef s32 int_fast32_t;
typedef s64 int_fast64_t;

typedef u32 uint_fast8_t;
typedef u32 uint_fast16_t;
typedef u32 uint_fast32_t;
typedef u64 uint_fast64_t;

#else /* __KERNEL32__ */

/* Signed address-width limits */

#define INTPTR_MIN (INT64_MIN)
#define INTPTR_MAX (INT64_MAX)

/* Signed fast integer limits */

#define INT_FAST8_MIN  (INT64_MIN)
#define INT_FAST16_MIN (INT64_MIN)
#define INT_FAST32_MIN (INT64_MIN)
#define INT_FAST64_MIN (INT64_MIN)

#define INT_FAST8_MAX  (INT64_MAX)
#define INT_FAST16_MAX (INT64_MAX)
#define INT_FAST32_MAX (INT64_MAX)
#define INT_FAST64_MAX (INT64_MAX)

/* Unsigned address-width limit */

#define UINTPTR_MAX (UINT64_MAX)

/* Unsigned fast integer limits */

#define UINT_FAST8_MAX  (UINT64_MAX)
#define UINT_FAST16_MAX (UINT64_MAX)
#define UINT_FAST32_MAX (UINT64_MAX)
#define UINT_FAST64_MAX (UINT64_MAX)

/* Fast integer typedefs */

typedef s64 int_fast8_t;
typedef s64 int_fast16_t;
typedef s64 int_fast32_t;
typedef s64 int_fast64_t;

typedef u64 uint_fast8_t;
typedef u64 uint_fast16_t;
typedef u64 uint_fast32_t;
typedef u64 uint_fast64_t;

#endif /* __KERNEL32__ */
#endif /* ! __STDINT_H__ */
