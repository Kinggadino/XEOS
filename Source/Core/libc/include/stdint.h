/*******************************************************************************
 * XEOS - x86 Experimental Operating System
 * 
 * Copyright (C) 2010 Jean-David Gadina (macmade@eosgarden.com)
 * All rights reserved
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 *  -   Redistributions of source code must retain the above copyright notice,
 *      this list of conditions and the following disclaimer.
 *  -   Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *  -   Neither the name of 'Jean-David Gadina' nor the names of its
 *      contributors may be used to endorse or promote products derived from
 *      this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 ******************************************************************************/

/* $Id$ */

#ifndef __LIBC_STDINT_H__
#define __LIBC_STDINT_H__
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/* Exact width integer types (signed) */
typedef signed char         int8_t;
typedef signed short        int16_t;
typedef signed int          int32_t;
typedef signed long long    int64_t;

/* Exact width integer types (unsigned) */
typedef unsigned char       uint8_t;
typedef unsigned short      uint16_t;
typedef unsigned int        uint32_t;
typedef unsigned long long  uint64_t;

/* Minimum width integer types (signed) */
typedef signed char         int_least8_t;
typedef short               int_least16_t;
typedef int                 int_least32_t;
typedef long long           int_least64_t;

/* Minimum width integer types (unsigned) */
typedef unsigned char       uint_least8_t;
typedef unsigned short      uint_least16_t;
typedef unsigned int        uint_least32_t;
typedef unsigned long long  uint_least64_t;

/* Fastest minimum width integer types (signed) */
typedef signed char         int_fast8_t;
typedef signed short        int_fast16_t;
typedef signed int          int_fast32_t;
typedef signed long long    int_fast64_t;

/* Fastest minimum width integer types (unsigned) */
typedef unsigned char       uint_fast8_t;
typedef unsigned short      uint_fast16_t;
typedef unsigned int        uint_fast32_t;
typedef unsigned long long  uint_fast64_t;

/* Integer types capable of holding object pointers */
typedef signed int          intptr_t;
typedef unsigned int        uintptr_t;

/* Greatest width integer types */
typedef long long           intmax_t;
typedef unsigned long long  uintmax_t;

/* Limits of exact-width integer types */
#define INT8_MIN            ( -INT8_MAX - 1 )
#define INT16_MIN           ( -INT16_MAX - 1 )
#define INT32_MIN           ( -INT32_MAX - 1 )
#define INT64_MIN           ( -INT64_MAX - 1 )
#define INT8_MAX            127
#define INT16_MAX           32767
#define INT32_MAX           2147483647
#define INT64_MAX           9223372036854775807LL
#define UINT8_MAX           255U
#define UINT16_MAX          65535U
#define UINT32_MAX          4294967295U
#define UINT64_MAX          18446744073709551615ULL

/* Limits of minimum-width integer types */
#define INT_LEAST8_MIN      ( -INT8_MAX - 1 )
#define INT_LEAST16_MIN     ( -INT16_MAX - 1 )
#define INT_LEAST32_MIN     ( -INT32_MAX - 1 )
#define INT_LEAST64_MIN     ( -INT64_MAX - 1 )
#define INT_LEAST8_MAX      127
#define INT_LEAST16_MAX     32767
#define INT_LEAST32_MAX     2147483647
#define INT_LEAST64_MAX     9223372036854775807LL
#define UINT_LEAST8_MAX     255U
#define UINT_LEAST16_MAX    65535U
#define UINT_LEAST32_MAX    4294967295U
#define UINT_LEAST64_MAX    18446744073709551615ULL

/* Limits of fastest minimum-width integer types */
#define INT_FAST8_MIN       ( -INT8_MAX - 1 )
#define INT_FAST16_MIN      ( -INT16_MAX - 1 )
#define INT_FAST32_MIN      ( -INT32_MAX - 1 )
#define INT_FAST64_MIN      ( -INT64_MAX - 1 )
#define INT_FAST8_MAX       127
#define INT_FAST16_MAX      32767
#define INT_FAST32_MAX      2147483647
#define INT_FAST64_MAX      9223372036854775807LL
#define UINT_FAST8_MAX      255U
#define UINT_FAST16_MAX     65535U
#define UINT_FAST32_MAX     4294967295U
#define UINT_FAST64_MAX     18446744073709551615ULL

/* Limits of integer types capable of holding object pointers */
#define INTPTR_MIN          ( -INTPTR_MAX - 1 )
#define INTPTR_MAX          2147483647
#define UINTPTR_MAX         4294967295U

/* Limits of greatest-width integer types */
#define INTMAX_MIN          ( -INTMAX_MAX - 1 )
#define INTMAX_MAX          9223372036854775807LL
#define UINTMAX_MAX         18446744073709551615ULL

/* Limits of other integer types */
#define PTRDIFF_MIN         0
#define PTRDIFF_MAX         0
#define SIG_ATOMIC_MIN      0
#define SIG_ATOMIC_MAX      0
#define SIZE_MAX            0
#define WCHAR_MIN           0
#define WCHAR_MAX           0
#define WINT_MIN            0
#define WINT_MAX            0

/* Macros for minimum-width integer constant expressions */
#define INT8_C( value )     value
#define INT16_C( value )    value
#define INT32_C( value )    value
#define INT64_C( value )    value##LL
#define UINT8_C( value )    value##U
#define UINT16_C( value )   value##U
#define UINT32_C( value )   value##U
#define UINT64_C( value )   value##ULL

/* Macros for greatest-width integer constant expressions */
#define INTMAX_C( value )   INT64_C( val )
#define UINTMAX_C( value )  UINT64_C( val )

#ifdef __cplusplus
}
#endif

#endif /* __LIBC_STDINT_H__ */