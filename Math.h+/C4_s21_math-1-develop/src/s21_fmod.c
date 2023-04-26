#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long long int mod = x / y;
  long double res = (long double)x - mod * (long double)y;
  if (!s21_isfin(x) || s21_isnan(y)) {
    res = S21_NAN;
  } else if (s21_isinf(y)) {
    res = x;
  } else if (s21_fabs(y) < S21_EPS) {
    res = S21_NAN;
  } else if (s21_fabs(x) < S21_EPS) {
    res = 0;
  }
  return res;
}
