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

int accept(int fd, struct sockaddr* restrict addr, socklen_t* restrict len);
int bind(int fd, const struct sockaddr* addr, socklen_t len);
int connect(int fd, const struct sockaddr* addr, socklen_t len);
int getpeername(int fd, struct sockaddr* restrict addr, socklen_t* restrict len);
int getsockname(int fd, struct sockaddr* restrict addr, socklen_t* restrict len);
int getsockopt(int fd, int level, int opt, void* restrict val, socklen_t* restrict len);
int listen(int fd, int backlog);
ssize_t recv(int fd, void* buf, size_t len, int flags);
ssize_t recvfrom(int fd, void* restrict buf, size_t blen, int flags,
	struct sockaddr* restrict addr, socklen_t* restrict alen);
ssize_t recvmsg(int fd, struct msghdr* msg, int flags);
ssize_t send(int fd, const void* buf, size_t len, int flags);
ssize_t sendmsg(int fd, const struct msghdr* msg, int flags);
ssize_t sendto(int fd, const void* buf, size_t blen, int flags,
	const struct sockaddr* addr, socklen_t alen);
int setsockopt(int fd, int level, int opt, const void* val, socklen_t len);
int shutdown(int fd, int how);
int sockatmark(int fd);
int socket(int domain, int type, int protocol);
int socketpair(int domain, int type, int protocol, int sv[2]);

#endif /* ! __SYS_SOCKET_H__ */
