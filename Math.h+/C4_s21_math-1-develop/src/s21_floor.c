#include "s21_math.h"

long double s21_floor(double x) {
  long double floor_x = (long long int)x;
  if (!s21_isfin(x)) {
    floor_x = x;
  } else if (s21_fabs(x) > 0. && x != floor_x) {
    if (x != S21_DBL_MAX) {
      if (x < 0.) {
        floor_x -= 1;
      }
    } else {
      floor_x = S21_DBL_MAX;
    }
  }
  return floor_x;
}