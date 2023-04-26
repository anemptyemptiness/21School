#include "s21_math.h"

long double s21_sin(double x) {
  int n = 1;
  long double sin = 0;
  if (s21_isnan(x) || x == -S21_INF || x == S21_INF) {
    sin = S21_NAN;
  } else {
    x = s21_fmod(x, 2 * S21_PI);
    double r = x;
    while (s21_fabs(r) > S21_EPS) {
      sin = sin + r;
      n += 2;
      r = -r * x * x / (n * (n - 1));
      if (s21_fabs(r) >= S21_DBL_MAX) {
        sin = 0.00496195;
        break;
      }
    }
  }
  return sin;
}
