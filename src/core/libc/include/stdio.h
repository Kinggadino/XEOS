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

#ifndef __LIBC_STDIO_H__
#define __LIBC_STDIO_H__
#pragma once

#include "private/__null.h"
#include "private/__size_t.h"
#include "stdarg.h"

/**
 * Size of buffer used by setbuf.
 */
#define BUFSIZ          1024

/**
 * Value used to indicate end-of-stream or to report an error.
 */
#define EOF             -1

/**
 * Maximum length required for array of characters to hold a filename.
 */
#define FILENAME_MAX    1024

/**
 * Maximum number of files which may be open simultaneously.
 */
#define FOPEN_MAX       20

/**
 * Number of characters required for temporary filename generated by tmpnam.
 */
#define L_tmpnam        ( sizeof( "/tmp/" ) + FILENAME_MAX )

/**
 * Value for origin argument to fseek specifying current file position.
 */
#define SEEK_CUR        0x01

/**
 * Value for origin argument to fseek specifying end of file.
 */
#define SEEK_END        0x02

/**
 * Value for origin argument to fseek specifying beginning of file.
 */
#define SEEK_SET        0x00

/**
 * Minimum number of unique filenames generated by calls to tmpnam.
 */
#define TMP_MAX         20

/**
 * Value for mode argument to setvbuf specifying full buffering.
 */
#define _IOFBF          0x01

/**
 * Value for mode argument to setvbuf specifying line buffering.
 */
#define _IOLBF          0x02

/**
 * Value for mode argument to setvbuf specifying no buffering.
 */
#define _IONBF          0x03

/**
 * Type of object holding information necessary to control a stream.
 */
typedef struct
{
    
    int desc;               /* File descriptor */
    unsigned long pos;      /* Current stream position */
    int eof;                /* End-of-file indicator */
    int error;              /* Error indicator */
    char * buf;             /* Pointer to the stream's buffer, if applicable */
    int std;                /* Whether is stdin, stdout or stderr */
    int open;               /* Whether the file is open or not */
    int mode;               /* Open mode */
    char modeStr[ 4 ];      /* 2nd parameter to fopen */
    
} FILE;

/**
 * File pointer for standard input stream. Automatically opened when program
 * execution begins.
 */
extern FILE * stdin;

/**
 * File pointer for standard output stream. Automatically opened when program
 * execution begins.
 */
extern FILE * stdout;

/**
 * File pointer for standard error stream. Automatically opened when program
 * execution begins.
 */
extern FILE * stderr;

/**
 * Type for objects declared to store file position information.
 */
typedef unsigned long int fpos_t;


/**
 * 
 */
FILE * fopen( const char * filename, const char * mode );

/**
 * 
 */
FILE * freopen( const char * filename, const char * mode, FILE * stream );

/**
 * 
 */
int fflush( FILE * stream );

/**
 * 
 */
int fclose( FILE * stream );

/**
 * 
 */
int remove( const char * filename );

/**
 * 
 */
int rename( const char * oldname, const char * newname );

/**
 * 
 */
FILE * tmpfile( void );

/**
 * 
 */
char * tmpnam( char s[ L_tmpnam ] );

/**
 * 
 */
int setvbuf( FILE * stream, char * buf, int mode, size_t size );

/**
 * 
 */
void setbuf( FILE * stream, char * buf );

/**
 * 
 */
int fprintf( FILE * stream, const char * format, ... );

/**
 * 
 */
int printf( const char * format, ... );

/**
 * 
 */
int sprintf( char * s, const char * format, ... );

/**
 * 
 */
int vfprintf (FILE * stream, const char * format, va_list arg );

/**
 * 
 */
int vprintf( const char * format, va_list arg );

/**
 * 
 */
int vsprintf( char * s, const char * format, va_list arg );

/**
 * 
 */
int fscanf( FILE * stream, const char * format, ... );

/**
 * 
 */
int scanf( const char * format, ... );

/**
 * 
 */
int sscanf( char * s, const char * format, ... );

/**
 * 
 */
int fgetc( FILE * stream );

/**
 * 
 */
char * fgets( char * s, int n, FILE * stream );

/**
 * 
 */
int fputc( int c, FILE * stream );

/**
 * 
 */
char * fputs( const char * s, FILE * stream );

/**
 * 
 */
int getc( FILE * stream );

/**
 * 
 */
int getchar( void );

/**
 * 
 */
char * gets( char * s );

/**
 * 
 */
int putc( int c, FILE * stream );

/**
 * 
 */
int putchar( int c );

/**
 * 
 */
int puts( const char * s );

/**
 * 
 */
int ungetc( int c, FILE * stream );

/**
 * 
 */
size_t fread( void * ptr, size_t size, size_t nobj, FILE * stream );

/**
 * 
 */
size_t fwrite( const void * ptr, size_t size, size_t nobj, FILE * stream );

/**
 * 
 */
int fseek( FILE * stream, long offset, int origin );

/**
 * 
 */
long ftell( FILE * stream );

/**
 * 
 */
void rewind( FILE * stream );

/**
 * 
 */
int fgetpos( FILE * stream, fpos_t * ptr );

/**
 * 
 */
int fsetpos( FILE * stream, const fpos_t * ptr );

/**
 * 
 */
void clearerr( FILE * stream );

/**
 * 
 */
int feof( FILE * stream );

/**
 * 
 */
int ferror( FILE * stream );

/**
 * 
 */
void perror( const char * s );

#endif /* __LIBC_STDIO_H__ */

