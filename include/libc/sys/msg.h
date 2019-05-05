#ifndef __SYS_MSG_H__
#define __SYS_MSG_H__

/*
 * MIT License
 *
 * include/libc/sys/msg.h
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


#include <sys/ipc.h>

#define MSG_NOERROR (1<<0)

typedef u16 msglen_t;
typedef u16 msgqnum_t;

struct msqid_ds {
	struct ipc_perm msg_perm;
	msgqnum_t       msg_qnum;
	msglen_t        msg_qbytes;
	pid_t           msg_lspid;
	pid_t           msg_lrpid;
	time_t          msg_stime;
	time_t          msg_rtime;
	time_t          msg_ctime;
};

int msgctl(int msqid, int cmd, struct msqid_ds* buf);
int msgget(key_t key, int msgflg);
ssize_t msgrcv(int msqid, void* msgp, size_t msgsz, long msgtyp, int msgflg);
int msgsnd(int msqid, const void* msgp, size_t msgsz, int msgflg);

#endif /* ! __SYS_MSG_H__ */
