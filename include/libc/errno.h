#ifndef __ERRNO_H__
#define __ERRNO_H__

/*
 * MIT License
 *
 * include/libc/errno.h
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

enum {
	E2BIG,
	EACCES,
	EADDRINUSE,
	EADDRNOTAVAIL,
	EAFNOSUPPORT,
	EAGAIN,
	EALREADY,
	EBADF,
	EBADMSG,
	EBUSY,
	ECANCELED,
	ECHILD,
	ECONNABORTED,
	ECONNREFUSED,
	ECONNRESET,
	EDEADLK,
	EDESTADDRREQ,
	EDOM,
	EDQUOT,
	EEXIST,
	EFAULT,
	EFBIG,
	EHOSTUNREACH,
	EIDRM,
	EILSEQ,
	EINPROGRESS,
	EINTR,
	EINVAL,
	EIO,
	EISCONN,
	EISDIR,
	ELOOP,
	EMFILE,
	EMLINK,
	EMSGSIZE,
	EMULTIHOP,
	ENAMETOOLONG,
	ENETDOWN,
	ENETRESET,
	ENETUNREACH,
	ENFILE,
	ENOBUFS,
	ENODATA,
	ENODEV,
	ENOENT,
	ENOEXEC,
	ENOLCK,
	ENOLINK,
	ENOMEM,
	ENOMSG,
	ENOPROTOOPT,
	ENOSPC,
	ENOSR,
	ENOSTR,
	ENOSYS,
	ENOTCONN,
	ENOTDIR,
	ENOTEMPTY,
	ENOTRECOVERABLE,
	ENOTSOCK,
	ENOTSUP,
	ENOTTY,
	ENXIO,
	EOPNOTSUPP,
	EOVERFLOW,
	EOWNERDEAD,
	EPERM,
	EPIPE,
	EPROTO,
	EPROTONOSUPPORT,
	EPROTOTYPE,
	ERANGE,
	EROFS,
	ESPIPE,
	ESRCH,
	ESTALE,
	ETIME,
	ETIMEDOUT,
	ETXTBSY,
	EWOULDBLOCK,
	EXDEV
};

extern int errno;

#endif /* ! __ERRNO_H__ */
