#ifndef __STDINT_H__
#define __STDINT_H__

#ifdef __GNUC__

typedef __INT8_TYPE__ int8_t;
typedef __INT16_TYPE__ int16_t;
typedef __INT32_TYPE__ int32_t;
typedef __INT64_TYPE__ int64_t;

typedef __UINT8_TYPE__ uint8_t;
typedef __UINT16_TYPE__ uint16_t;
typedef __UINT32_TYPE__ uint32_t;
typedef __UINT64_TYPE__ uint64_t;

#else

typedef char int8_t;
typedef short int int16_t;
typedef long int int32_t;
typedef long long int int64_t;

typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned long int uint32_t;
typedef unsigned long long int uint64_t;

#endif

#endif
