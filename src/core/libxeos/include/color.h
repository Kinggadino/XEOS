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

#ifndef __LIBXEOS_COLOR_H__
#define __LIBXEOS_COLOR_H__
#pragma once

#include <xeos/types.h>

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Types
 ******************************************************************************/
 
typedef struct
{
    
    XSFloat red;
    XSFloat green;
    XSFloat blue;
    XSFloat alpha;
    
} XSRGBColor;

typedef struct
{
    
    XSFloat hue;
    XSFloat saturation;
    XSFloat value;
    XSFloat alpha;
    
} XSHSVColor;

typedef struct
{
    
    XSFloat hue;
    XSFloat saturation;
    XSFloat luminance;
    XSFloat alpha;
    
} XSHSLColor;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

XSRGBColor XSMakeRGBColor( XSFloat red, XSFloat green, XSFloat blue, XSFloat alpha );
XSHSVColor XSMakeHSVColor( XSFloat hue, XSFloat saturation, XSFloat value, XSFloat alpha );
XSHSLColor XSMakeHSLColor( XSFloat hue, XSFloat saturation, XSFloat luminance, XSFloat alpha );
XSRGBColor XSColorRGBFromHSV( XSHSVColor hsv );
XSRGBColor XSColorRGBFromHSL( XSHSLColor hsl );
XSHSVColor XSColorHSVFromRGB( XSRGBColor rgb );
XSHSVColor XSColorHSVFromHSL( XSHSLColor hsl );
XSHSLColor XSColorHSLFromRGB( XSRGBColor rgb );
XSHSLColor XSColorHSLFromHSV( XSHSVColor hsv );

#ifdef __cplusplus
}
#endif

#endif /* __LIBXEOS_COLOR_H__ */