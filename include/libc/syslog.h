#ifndef __SYSLOG_H__
#define __SYSLOG_H__

/*
 * MIT License
 *
 * include/libc/syslog.h
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

#define LOG_PID    (1<<0)
#define LOG_CONS   (1<<1)
#define LOG_NDELAY (1<<2)
#define LOG_ODELAY (1<<3)
#define LOG_NOWAIT (1<<4)

#define LOG_MASK(pri) (0 /* TODO */)

enum {
	LOG_KERN,
	LOG_USER,
	LOG_MAIL,
	LOG_NEWS,
	LOG_UUCP,
	LOG_DAEMON,
	LOG_AUTH,
	LOG_CRON,
	LOG_LPR,
	LOG_LOCAL0,
	LOG_LOCAL1,
	LOG_LOCAL2,
	LOG_LOCAL3,
	LOG_LOCAL4,
	LOG_LOCAL5,
	LOG_LOCAL6,
	LOG_LOCAL7
};

enum {
	LOG_EMERG,
	LOG_ALERT,
	LOG_CRIT,
	LOG_ERR,
	LOG_WARNING,
	LOG_NOTICE,
	LOG_INFO,
	LOG_DEBUG
};

void closelog(void);
void openlog(const char* indent, int options, int facility);
int setlogmask(int mask);
void syslog(int priority, const char* fmt, ...);

#endif /* ! __SYSLOG_H__ */
