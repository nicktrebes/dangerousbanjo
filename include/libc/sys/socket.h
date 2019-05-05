#ifndef __SYS_SOCKET_H__
#define __SYS_SOCKET_H__

/*
 * MIT License
 *
 * include/libc/sys/socket.h
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

#define AF_INET   (4)
#define AF_INET6  (6)
#define AF_UNIX   (1)
#define AF_UNSPEC (0)

#define MSG_CTRUNC    (1<<0)
#define MSG_DONTROUTE (1<<1)
#define MSG_EOR       (1<<2)
#define MSG_OOB       (1<<3)
#define MSG_NOSIGNAL  (1<<4)
#define MSG_PEEK      (1<<5)
#define MSG_TRUNC     (1<<6)
#define MSG_WAITALL   (1<<7)

// TODO: define constants

enum {
	SHUT_RD,
	SHUT_RDWR,
	SHUT_WR
};

enum {
	SO_ACCEPTCONN,
	SO_BROADCAST,
	SO_DEBUG,
	SO_DONTROUTE,
	SO_ERROR,
	SO_KEEPALIVE,
	SO_LINGER,
	SO_OOBINLINE,
	SO_RCVBUF,
	SO_RCVLOWAT,
	SO_RCVTIMEO,
	SO_REUSEADDR,
	SO_SNDBUF,
	SO_SNDLOWAT,
	SO_SNDTIMEO,
	SO_TYPE
};

enum {
	SOCK_STREAM,
	SOCK_SEQPACKET,
	SOCK_RAW,
	SOCK_DGRAM
};

int accept(int, struct sockaddr* restrict, socklen_t* restrict);
int bind(int, const struct sockaddr*, socklen_t);
int connect(int, const struct sockaddr*, socklen_t);
int getpeername(int, struct sockaddr* restrict, socklen_t* restrict);
int getsockname(int, struct sockaddr* restrict, socklen_t* restrict);
int getsockopt(int, int, int, void* restrict, socklen_t* restrict);
int listen(int, int);
ssize_t recv(int, void*, size_t, int);
ssize_t recvfrom(int, void* restrict, size_t, int,
	struct sockaddr* restrict, socklen_t* restrict);
ssize_t recvmsg(int, struct msghdr*, int);
ssize_t send(int, const void*, size_t, int);
ssize_t sendmsg(int, const struct msghdr*, int);
ssize_t sendto(int, const void*, size_t, int, const struct sockaddr*, socklen_t);
int setsockopt(int, int, int, const void*, socklen_t);
int shutdown(int, int);
int sockatmark(int);
int socket(int, int, int);
int socketpair(int, int, int, int, int[2]);

#endif /* ! __SYS_SOCKET_H__ */
