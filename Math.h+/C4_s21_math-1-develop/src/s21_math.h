#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#include <errno.h>
#include <stdio.h>

#define S21_EPS 1e-16
#define S21_EPS_TEST 1e-6
#define S21_PI 3.1415926535897932384626433832795028841971693993751058209749445923
#define S21_INF 1.0 / 0.0
#define S21_NAN __builtin_nanf("0x7fc00000")
#define S21_DBL_MAX 1.7976931348623158e+308
#define s21_LOG_10 2.30258509299
#define s21_LOG_2 0.69314718056
#define s21_isfin(x) __builtin_isfinite(x)
#define s21_isnan(x) __builtin_isnan(x)
#define s21_isinf(x) __builtin_isinf(x)

int s21_abs(int x);             
long double s21_fabs(double x);  
long double s21_ceil(double x);
long double s21_fmod(double x, double y);
long double s21_floor(double x);
long double s21_sqrt(double x);
long double s21_exp(double x);
long double s21_log(double x);
long double s21_pow(double x, double y);
long double s21_acos(double x); 
long double s21_asin(double x);  
long double s21_atan(double x); 
long double s21_cos(double x); 
long double s21_sin(double x);  
long double s21_tan(double x);  

#endif
