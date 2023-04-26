#include "s21_math.h"

long double s21_fabs(double x) {
  long double x_fabs = x;
  if (s21_isnan(x)) {
    x_fabs = S21_NAN;
  } else {
    if (x < 0) {
      x_fabs = -x;
    } else {
      x_fabs = x;
    }
  }
  return x_fabs;
}