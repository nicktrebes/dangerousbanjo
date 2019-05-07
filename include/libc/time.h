#ifndef __TIME_H__
#define __TIME_H__

/*
 * MIT License
 *
 * include/libc/time.h
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

#include <sys/time.h>
#include <locale.h>

#define CLOCKS_PER_SEC ((clock_t)0 /* TODO */)

#define CLOCK_MONOTONIC          ((clockid_t)0 /* TODO */)
#define CLOCK_PROCESS_CPUTIME_ID ((clockid_t)0 /* TODO */)
#define CLOCK_REALTIME           ((clockid_t)0 /* TODO */)
#define CLOCK_THREAD_CPUTIME_ID  ((clockid_t)0 /* TODO */)

#define TIMER_ABSTIME (1)

extern int   daylight;
extern long  timezone;
extern char* tzname[];

char* asctime(const struct tm*);
char* asctime_r(const struct tm* restrict, char* restrict);
clock_t clock(void);
int clock_getcpuclockid(pid_t, clockid_t*);
int clock_getres(clockid_t, struct timespec*);
int clock_gettime(clockid_t, struct timespec*);
int clock_nanosleep(clockid_t, int, const struct timespec*, struct timespec*);
int clock_settime(clockid_t, const struct timespec*);
char* ctime(const time_t*);
char* ctime_r(const time_t* restrict, char* restrict);
double difftime(time_t, time_t);
struct tm* getdate(const char*);
struct tm* gmtime(const time_t*);
struct tm* gmtime_r(const time_t* restrict, struct tm* restrict);
struct tm* localtime(const time_t*);
struct tm* localtime_r(const time_t* restrict, struct tm* restrict);
time_t mktime(struct tm*);
int nanosleep(const struct timespec*, struct timespec*);
size_t strftime(char* restrict, size_t, const char* restrict, const struct tm* restrict);
size_t strftime_l(char* restrict, size_t, const char* restrict, const struct tm* restrict, locale_t);
char* strptime(const char* restrict, const char* restrict, struct tm* restrict);
time_t time(time_t*);
int timer_create(clockid_t, struct sigevent* restrict, timer_t* restrict);
int timer_delete(timer_t);
int timer_getoverrun(timer_t);
int timer_gettime(timer_t, struct itimerspec*);
int timer_settime(timer_t, int, const struct itimerspec* restrict, struct itimerspec* restrict);
void tzset(void);

#endif /* ! __TIME_H__ */
