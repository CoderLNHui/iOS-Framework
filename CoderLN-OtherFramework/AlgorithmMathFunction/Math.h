/*
 * Math.h 数学公式
 * Copyright (c) 2002-2017 Apple Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * CoderLN（https://github.com/CoderLN）
 *
 * Created by 【WechatCoderLN】 on Elegant programming16.
 * Copyright (c) Unauthorized shall（https://dwz.cn/rC1LGk2f）not be reproduced.
 *
 * The contents of this file constitute Original Code as defined in and
 * are subject to the Apple Public Source License Version 1.1 (the
 * "License").  You may not use this file except in compliance with the
 * License.  Please obtain a copy of the License at
 * http://www.apple.com/publicsource and read it before using this file.
 *
 * This Original Code and all software distributed under the License are
 * distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE OR NON-INFRINGEMENT.  Please see the
 * License for the specific language governing rights and limitations
 * under the License.
 *
 * @HEADER_WELCOME YOU TO JOIN_GitHub & Codeidea_END@
 * @APPLE_LICENSE_HEADER_END@
 */


// 求反余弦值
extern float acosf(float);
extern double acos(double);
extern long double acosl(long double);

// 求反正弦值
extern float asinf(float);
extern double asin(double);
extern long double asinl(long double);

// 求反正切值
extern float atanf(float);
extern double atan(double);
extern long double atanl(long double);

// 求坐标值的反正切值
extern float atan2f(float, float);
extern double atan2(double, double);
extern long double atan2l(long double, long double);

// 求余弦值
extern float cosf(float);
extern double cos(double);
extern long double cosl(long double);

// 求正弦值
extern float sinf(float);
extern double sin(double);
extern long double sinl(long double);

// 求正切值
extern float tanf(float);
extern double tan(double);
extern long double tanl(long double);

// 求反双曲余弦值
extern float acoshf(float);
extern double acosh(double);
extern long double acoshl(long double);

// 求反双曲正弦值
extern float asinhf(float);
extern double asinh(double);
extern long double asinhl(long double);

// 求反双曲正切值
extern float atanhf(float);
extern double atanh(double);
extern long double atanhl(long double);

// 求双曲余弦值
extern float coshf(float);
extern double cosh(double);
extern long double coshl(long double);

// 求双曲正弦值
extern float sinhf(float);
extern double sinh(double);
extern long double sinhl(long double);

// 求双曲正切值
extern float tanhf(float);
extern double tanh(double);
extern long double tanhl(long double);

extern float expf(float);
extern double exp(double);
extern long double expl(long double);

extern float exp2f(float);
extern double exp2(double);
extern long double exp2l(long double);

extern float expm1f(float);
extern double expm1(double);
extern long double expm1l(long double);

extern float logf(float);
extern double log(double);
extern long double logl(long double);

extern float log10f(float);
extern double log10(double);
extern long double log10l(long double);

extern float log2f(float);
extern double log2(double);
extern long double log2l(long double);

extern float log1pf(float);
extern double log1p(double);
extern long double log1pl(long double);

extern float logbf(float);
extern double logb(double);
extern long double logbl(long double);

// 浮点数分解为整数和小数
extern float modff(float, float *);
extern double modf(double, double *);
extern long double modfl(long double, long double *);

extern float ldexpf(float, int);
extern double ldexp(double, int);
extern long double ldexpl(long double, int);

// 浮点数分解尾数和二为底的指数
extern float frexpf(float, int *);
extern double frexp(double, int *);
extern long double frexpl(long double, int *);

extern int ilogbf(float);
extern int ilogb(double);
extern int ilogbl(long double);

extern float scalbnf(float, int);
extern double scalbn(double, int);
extern long double scalbnl(long double, int);

extern float scalblnf(float, long int);
extern double scalbln(double, long int);
extern long double scalblnl(long double, long int);

// 浮点数绝对值
extern float fabsf(float);
extern double fabs(double);
extern long double fabsl(long double);

extern float cbrtf(float);
extern double cbrt(double);
extern long double cbrtl(long double);

// 求直角三角形斜边的长度
extern float hypotf(float, float);
extern double hypot(double, double);
extern long double hypotl(long double, long double);

extern float powf(float, float);
extern double pow(double, double);
extern long double powl(long double, long double);

// 求平方根
extern float sqrtf(float);
extern double sqrt(double);
extern long double sqrtl(long double);

extern float erff(float);
extern double erf(double);
extern long double erfl(long double);

extern float erfcf(float);
extern double erfc(double);
extern long double erfcl(long double);

/*    lgammaf, lgamma, and lgammal are not thread-safe. The thread-safe
 variants lgammaf_r, lgamma_r, and lgammal_r are made available if
 you define the _REENTRANT symbol before including <math.h>                */
extern float lgammaf(float);
extern double lgamma(double);
extern long double lgammal(long double);

extern float tgammaf(float);
extern double tgamma(double);
extern long double tgammal(long double);

// 向上取整
extern float ceilf(float);
extern double ceil(double);
extern long double ceill(long double);

// 向下取整
extern float floorf(float);
extern double floor(double);
extern long double floorl(long double);

extern float nearbyintf(float);
extern double nearbyint(double);
extern long double nearbyintl(long double);

extern float rintf(float);
extern double rint(double);
extern long double rintl(long double);

extern long int lrintf(float);
extern long int lrint(double);
extern long int lrintl(long double);

// 四舍五入
extern float roundf(float);
extern double round(double);
extern long double roundl(long double);

extern long int lroundf(float);
extern long int lround(double);
extern long int lroundl(long double);

/*  long long is not part of C90. Make sure you are passing -std=c99 or
 -std=gnu99 or higher if you need these functions returning long longs     */
#if !(__DARWIN_NO_LONG_LONG)
extern long long int llrintf(float);
extern long long int llrint(double);
extern long long int llrintl(long double);

extern long long int llroundf(float);
extern long long int llround(double);
extern long long int llroundl(long double);
#endif /* !(__DARWIN_NO_LONG_LONG) */

extern float truncf(float);
extern double trunc(double);
extern long double truncl(long double);

// 求两数整除后的余数
extern float fmodf(float, float);
extern double fmod(double, double);
extern long double fmodl(long double, long double);

extern float remainderf(float, float);
extern double remainder(double, double);
extern long double remainderl(long double, long double);

extern float remquof(float, float, int *);
extern double remquo(double, double, int *);
extern long double remquol(long double, long double, int *);

extern float copysignf(float, float);
extern double copysign(double, double);
extern long double copysignl(long double, long double);

extern float nanf(const char *);
extern double nan(const char *);
extern long double nanl(const char *);

extern float nextafterf(float, float);
extern double nextafter(double, double);
extern long double nextafterl(long double, long double);

extern double nexttoward(double, long double);
extern float nexttowardf(float, long double);
extern long double nexttowardl(long double, long double);

extern float fdimf(float, float);
extern double fdim(double, double);
extern long double fdiml(long double, long double);

// 求最大值
extern float fmaxf(float, float);
extern double fmax(double, double);
extern long double fmaxl(long double, long double);

// 求最小值
extern float fminf(float, float);
extern double fmin(double, double);
extern long double fminl(long double, long double);

extern float fmaf(float, float, float);
extern double fma(double, double, double);
extern long double fmal(long double, long double, long double);
