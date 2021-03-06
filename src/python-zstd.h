/*
 * Copyright (c) 2015 Sergey Dryabzhinsky
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of Steeve Morin nor the names of its contributors may be
 *    used to endorse or promote products derived from this software without
 *    specific prior written permission.
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
 */

#ifndef _PYTHON_ZSTD_H_
#define _PYTHON_ZSTD_H_


#include "Python.h"


#ifndef PYZSTD_LEGACY
/*-=====  Do you need legacy old-format functions?  =====-*/
#define PYZSTD_LEGACY 0
#endif


#ifndef ZSTD_DEFAULT_CLEVEL
/*-=====  Pre-defined compression levels  =====-*/

#define ZSTD_DEFAULT_CLEVEL 1
#define ZSTD_MAX_CLEVEL     22
#endif


#define DISCARD_PARAMETER (void)

static PyObject *ZstdError;

static PyObject *py_zstd_compress(PyObject* self, PyObject *args);
static PyObject *py_zstd_uncompress(PyObject* self, PyObject *args);

#if PYZSTD_LEGACY > 0
static PyObject *py_zstd_compress_old(PyObject* self, PyObject *args);
static PyObject *py_zstd_uncompress_old(PyObject* self, PyObject *args);
#endif

#if PY_MAJOR_VERSION < 3
PyMODINIT_FUNC initzstd(void);
#endif


#define COMPRESS_DOCSTRING      "Compress string, returning the compressed data.\nRaises an exception if any error occurs."
#define UNCOMPRESS_DOCSTRING    "Decompress string, returning the uncompressed data.\nRaises an exception if any error occurs."

#if PYZSTD_LEGACY > 0
#define COMPRESS_OLD_DOCSTRING      "Compress string, old version, returning the compressed data in custom format.\nNot compatible with streaming or origin compression tools.\nRaises an exception if any error occurs."
#define UNCOMPRESS_OLD_DOCSTRING    "Decompress string, old version, returning the uncompressed data.\nUses custom format from `compress_old` fucntion.\nNot compatible with streaming or origin compression tools.\nRaises an exception if any error occurs."
#endif

/**************************************
*  Basic Types
**************************************/
#if defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L   /* C99 */
# include <stdint.h>
typedef uint8_t  BYTE;
typedef uint16_t U16;
typedef uint32_t U32;
typedef  int32_t S32;
typedef uint64_t U64;
#else
typedef unsigned char       BYTE;
typedef unsigned short      U16;
typedef unsigned int        U32;
typedef   signed int        S32;
typedef unsigned long long  U64;
#endif

#if defined(_WIN32) && defined(_MSC_VER)
# define inline __inline
# if _MSC_VER >= 1600
#  include <stdint.h>
# else /* _MSC_VER >= 1600 */
   typedef signed char       int8_t;
   typedef signed short      int16_t;
   typedef signed int        int32_t;
   typedef unsigned char     uint8_t;
   typedef unsigned short    uint16_t;
   typedef unsigned int      uint32_t;
# endif /* _MSC_VER >= 1600 */
#endif

#if defined(__SUNPRO_C) || defined(__hpux) || defined(_AIX)
#define inline
#endif

#ifdef __linux
#define inline __inline
#endif

#endif // _PYTHON_ZSTD_H_
