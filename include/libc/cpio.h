#ifndef __CPIO_H__
#define __CPIO_H__

/*
 * MIT License
 *
 * include/libc/cpio.h
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

#define C_IRUSR  (0000400)
#define C_IWUSR  (0000200)
#define C_IXUSR  (0000100)
#define C_IRGRP  (0000040)
#define C_IWGRP  (0000020)
#define C_IXGRP  (0000010)
#define C_IROTH  (0000004)
#define C_IWOTH  (0000002)
#define C_IXOTH  (0000001)
#define C_ISUID  (0004000)
#define C_ISGID  (0002000)
#define C_ISVTX  (0001000)
#define C_ISDIR  (0040000)
#define C_ISFIFO (0010000)
#define C_ISREG  (0100000)
#define C_ISBLK  (0060000)
#define C_ISCHR  (0020000)
#define C_ISCTG  (0110000)
#define C_ISLNK  (0120000)
#define C_ISSOCK (0140000)
#define MAGIC    ("070707")

#endif /* ! __CPIO_H__ */
