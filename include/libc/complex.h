#ifndef __COMPLEX_H__
#define __COMPLEX_H__

/*
 * MIT License
 *
 * include/libc/complex.h
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

#define complex      _Complex
#define _Complex_I   (const float complex)
#define imaginary    _Imaginary
#define _Imaginary_I (const float imaginary)
#define I            (_Imaginary_I)

double cabs(double complex);
float cabsf(float complex);
long double cabsl(long double complex);
double complex cacos(double complex);
float complex cacosf(float complex);
double complex cacosh(double complex);
float complex cacoshf(float complex);
long double complex cacoshl(long double complex);
long double complex cacosl(long double complex);
double carg(double complex);
float cargf(float complex);
long double cargl(long double complex);
double complex casin(double complex);
float complex casinf(float complex);
double complex casinh(double complex);
float complex casinhf(float complex);
long double complex casinhl(long double complex);
long double complex casinl(long double complex);
double complex catan(double complex);
float complex catanf(float complex);
double complex catanh(double complex);
float complex catanhf(float complex);
long double complex catanhl(long double complex);
long double complex catanl(long double complex);
double complex ccos(double complex);
float complex ccosf(float complex);
double complex ccosh(double complex);
float complex ccoshf(float complex);
long double complex ccoshl(long double complex);
long double complex ccosl(long double complex);
double complex cexp(double complex);
float complex cexpf(float complex);
long double complex cexpl(long double complex);
double cimag(double complex);
float cimagf(float complex);
long double cimagl(long double complex);
double complex clog(double complex);
float complex clogf(float complex);
long double complex clogl(long double complex);
double complex conj(double complex);
float complex conjf(float complex);
long double complex conjl(long double complex);
double complex cpow(double complex, double complex);
float complex cpowf(float complex, float complex);
long double complex cpowl(long double complex, long double complex);
double complex cproj(double complex);
float complex cprojf(float complex);
long double complex cprojl(long double complex);
double creal(double complex);
float crealf(float complex);
long double creall(long double complex);
double complex csin(double complex);
float complex csinf(float complex);
double complex csinh(double complex);
float complex csinhf(float complex);
long double complex csinhl(long double complex);
long double complex csinl(long double complex);
double complex csqrt(double complex);
float complex csqrtf(float complex);
long double complex csqrtl(long double complex);
double complex ctan(double complex);
float complex ctanf(float complex);
double complex ctanh(double complex);
float complex ctanhf(float complex);
long double complex ctanhl(long double complex);
long double complex ctanl(long double complex);

#endif /* ! __COMPLEX_H__ */
