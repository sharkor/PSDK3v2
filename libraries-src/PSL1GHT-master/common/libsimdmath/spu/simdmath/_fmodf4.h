/* fmodf4 - for each of four float slots, compute remainder of x/y defined as x - truncated_integer(x/y) * y.
   Copyright (C) 2006, 2007 Sony Computer Entertainment Inc.
   All rights reserved.

   Redistribution and use in source and binary forms,
   with or without modification, are permitted provided that the
   following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the Sony Computer Entertainment Inc nor the names
      of its contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
   ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
   POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef ___SIMD_MATH_FMODF4_H___
#define ___SIMD_MATH_FMODF4_H___

#include <simdmath.h>
#include <spu_intrinsics.h>

#include <simdmath/_divf4.h>
#include <simdmath/_fabsf4.h>
#include <simdmath/_copysignf4.h>

//
// This returns an accurate result when |divf4(x,y)| < 2^20 and |x| < 2^128, and otherwise returns zero.
// If x == 0, the result is 0.
// If x != 0 and y == 0, the result is undefined.

static inline vector float
_fmodf4 (vector float x, vector float y)
{
  vec_float4 q, xabs, yabs, qabs, xabs2;
  vec_int4   qi0, qi1, qi2;
  vec_float4 i0, i1, i2, r1, r2, i;
  vec_uint4  inrange;

  // Find i = truncated_integer(|x/y|)

  // If |divf4(x,y)| < 2^20, the quotient is at most off by 1.0.
  // Thus i is either the truncated quotient, one less, or one greater.

  q = _divf4( x, y );
  xabs = _fabsf4( x );
  yabs = _fabsf4( y );
  qabs = _fabsf4( q );
  xabs2 = spu_add( xabs, xabs );
    
  inrange = spu_cmpabsgt( (vec_float4)spu_splats(0x49800000), q );
  inrange = spu_and( inrange, spu_cmpabsgt( (vec_float4)spu_splats(0x7f800000), x ) );

  qi1 = spu_convts( qabs, 0 );
  qi0 = spu_add( qi1, -1 );
  qi2 = spu_add( qi1, 1 );

  i0 = spu_convtf( qi0, 0 );
  i1 = spu_convtf( qi1, 0 );
  i2 = spu_convtf( qi2, 0 );

  // Correct i will be the largest one such that |x| - i*|y| >= 0.  Can test instead as 
  // 2*|x| - i*|y| >= |x|:
  // 
  // With exact inputs, the negative-multiply-subtract gives the exact result rounded towards zero.  
  // Thus |x| - i*|y| may be < 0 but still round to zero.  However, if 2*|x| - i*|y| < |x|, the computed
  // answer will be rounded down to < |x|.  2*|x| can be represented exactly provided |x| < 2^128.

  r1 = spu_nmsub( i1, yabs, xabs2 );
  r2 = spu_nmsub( i2, yabs, xabs2 );

  i = i0;
  i = spu_sel( i1, i, spu_cmpgt( xabs, r1 ) );
  i = spu_sel( i2, i, spu_cmpgt( xabs, r2 ) );
   
  i = _copysignf4( i, q );

  return spu_sel( spu_splats(0.0f), spu_nmsub( i, y, x ), inrange );
}

#endif
