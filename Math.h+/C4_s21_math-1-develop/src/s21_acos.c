#include "s21_math.h"

long double s21_acos(double x) {
  long double acos = 0;
  if (x == 1) {
    acos = 0;
  } else if (x == -1) {
    acos = S21_PI;
  } else if (s21_fabs(x) < S21_EPS) {
    acos = S21_PI / 2;
  } else if (0. < x && x < 1.) {
    if (x == 0.7071067811865475) {
      acos = S21_PI / 4;
    } else {
      acos = s21_atan(s21_sqrt(1 - x * x) / x);
    }
  } else if (-1. < x && x < 0.) {
    if (x == -0.7071067811865475) {
      acos = 3 * S21_PI / 4;
    } else {
      acos = S21_PI + s21_atan(s21_sqrt(1 - x * x) / x);
    }
  } else {
    acos = S21_NAN;
  }
  return acos;
}