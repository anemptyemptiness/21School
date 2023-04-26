#include "s21_math.h"

long double s21_ceil(double x) {
  long double ceil_x = (long long int)x;
  if (!s21_isfin(x)) {
    ceil_x = x;
  } else if (s21_fabs(x) > 0. && x != ceil_x) {
    if (x != S21_DBL_MAX) {
      if (x > 0.) {
        ceil_x += 1;
      }
    } else {
      ceil_x = S21_DBL_MAX;
    }
  }
  return ceil_x;
}
