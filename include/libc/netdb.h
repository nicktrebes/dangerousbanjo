#ifndef __NETDB_H__
#define __NETDB_H__

/*
 * MIT License
 *
 * include/libc/netdb.h
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

#include <inttypes.h>
#include <sys/socket.h>

#define AI_PASSIVE     (1<<0)
#define AI_CANONNAME   (1<<1)
#define AI_NUMERICHOST (1<<2)
#define AI_NUMERICSERV (1<<3)
#define AI_V4MAPPED    (1<<4)
#define AI_ALL         (1<<5)
#define AI_ADDRCONFIG  (1<<6)

#define NI_NOFQDN       (1<<0)
#define NI_NUMERICHOST  (1<<1)
#define NI_NAMEREQD     (1<<2)
#define NI_NUMERICSERV  (1<<3)
#define NI_NUMERICSCOPE (1<<4)
#define NI_DGRAM        (1<<5)

enum {
	EAI_AGAIN = 1,
	EAI_BADFLAGS,
	EAI_FAIL,
	EAI_FAMILY,
	EAI_MEMORY,
	EAI_NONAME,
	EAI_SERVICE,
	EAI_SOCKTYPE,
	EAI_SYSTEM,
	EAI_OVERFLOW
};

void endhostent(void);
void endnetent(void);
void endprotoent(void);
void endservent(void);
void freeaddrinfo(struct addrinfo*);
const char* gai_strerror(int);
int getaddrinfo(const char* restrict, const char* restrict,
	const struct addrinfo* restrict, struct addrinfo** restrict);
struct hostent* gethostent(void);
int getnameinfo(const struct sockaddr* restrict, socklen_t,
	char* restrict, socklen_t, char* restrict, socklen_t, int);
struct netent* getnetbyaddr(uint32_t, int);
struct netent* getnetbyname(const char*);
struct netent* getnetent(void);
struct protoent* getprotobyname(const char*);
struct protoent* getprotobynumber(int);
struct protoent* getprotoent(void);
struct servent* getservbyname(const char*, const char*);
struct servent* getservbyport(int, const char*);
struct servent* getservent(void);
void sethostent(int);
void setnetent(int);
void setprotoent(int);
void setservent(int);

#endif /* ! __NETDB_H__ */
