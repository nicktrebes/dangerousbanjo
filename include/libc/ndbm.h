#ifndef __NDBM_H__
#define __NDBM_H__

/*
 * MIT License
 *
 * include/libc/ndbm.h
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
#include <sys/types.h>

enum {
	DBM_INSERT,
	DBM_REPLACE
};

int dbm_clearerr(DBM*);
void dbm_close(DBM*);
int dbm_delete(DBM*, datum);
int dbm_error(DBM*);
datum dbm_fetch(DBM*, datum);
datum dbm_firstkey(DBM*);
datum dbm_nextkey(DBM*);
DBM* dbm_open(const char*, int, mode_t);
int dbm_store(DBM*, datum, datum, int);

#endif /* ! __NDBM_H__ */
