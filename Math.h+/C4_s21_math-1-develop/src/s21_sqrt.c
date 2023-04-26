#include "s21_math.h"

long double s21_sqrt(double x) {
  long double left = 0;
  long double right = 0;
  long double middle = 0;
  if (x < 0) {
    middle = S21_NAN;
  } else {
    if (x < 1) {
      right = 1;
    } else {
      right = x;
    }
    middle = (left + right) / 2;
    while ((middle - left) > S21_EPS) {
      if ((middle * middle) > x) {
        right = middle;
      } else {
        left = middle;
      }
      middle = (left + right) / 2;
    }
  }
  return middle;
}