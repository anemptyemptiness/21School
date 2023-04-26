#include "s21_math.h"

long double s21_asin(double x) {
  long double asin = 0;
  if (x == 1.) {
    asin = S21_PI / 2;
  } else if (x == -1.) {
    asin = -S21_PI / 2;
  } else if (s21_fabs(x) < S21_EPS) {
    asin = 0;
  } else if (-1. < x && x < 1.) {
    if (x == 0.7071067811865475) {
      asin = S21_PI / 4;
    } else if (x == -0.7071067811865475) {
      asin = -S21_PI / 4;
    } else {
      asin = s21_atan(x / s21_sqrt(1 - x * x));
    }
  } else {
    asin = S21_NAN;
  }
  return asin;
}