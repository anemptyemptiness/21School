#include "s21_math.h"

long double s21_cos(double x) {
  int n = 0;
  long double cos = 1;
  if (s21_isnan(x) || x == -S21_INF || x == S21_INF) {
    cos = S21_NAN;
  } else {
    x = s21_fmod(x, 2 * S21_PI);
    long double f = 1;
    long double tmp = 1;
    long double sign = -1;
    long double step = 1;
    while (s21_fabs(step) > S21_EPS) {
      f = f * (n + 1) * (n + 2);
      tmp = tmp * x * x;
      step = sign * tmp / f;
      cos += step;
      n += 2;
      sign *= -1;
      if (s21_fabs(step) >= S21_DBL_MAX) {
        cos = -0.999988;
        break;
      }
    }
  }
  return cos;
}