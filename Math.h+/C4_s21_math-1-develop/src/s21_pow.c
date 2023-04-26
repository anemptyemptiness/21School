#include "s21_math.h"

long double s21_pow(double base, double e) {
  long double res = 0;
  long double copy = base;
  if (s21_isnan(s21_fabs(copy))) {
    if (s21_fabs(e) != 0) {
      res = S21_NAN;
    } else {
      res = 1;
    }
  } else if (s21_fabs(copy) == S21_INF) {
    if (copy == S21_INF) {
      if (s21_isnan(s21_fabs(e))) {
        res = S21_NAN;
      } else if (e > 0) {
        res = S21_INF;
      } else if (e < 0) {
        res = 0;
      } else {
        res = 1;
      }
    } else {
      if (s21_isnan(s21_fabs(e))) {
        res = S21_NAN;
      } else if (e > 0) {
        res = S21_INF;
        if (s21_fmod(e, 2) != 0 && s21_fabs(e) != S21_INF) res *= -1;
      } else if (e < 0) {
        res = 0;
        if (s21_fmod(e, 2) != 0 && s21_fabs(e) != S21_INF) res *= -1;
      } else {
        res = 1;
      }
    }
  } else if (s21_fabs(copy) == 1) {
    if (copy == 1) {
      res = 1;
    } else {
      if (s21_isnan(s21_fabs(e))) {
        res = S21_NAN;
      } else {
        res = 1;
        if (s21_fmod(e, 1) != 0 && s21_fabs(e) != S21_INF) {
          res = S21_NAN;
        } else if (s21_fmod(e, 2) != 0 && s21_fabs(e) != S21_INF)
          res *= -1;
      }
    }
  } else if (s21_fabs(copy) == 0) {
    if (s21_isnan(s21_fabs(e))) {
      res = S21_NAN;
    } else if (e < 0) {
      res = S21_INF;
    } else if (e > 0) {
      res = 0;
    } else {
      res = 1;
    }
  } else {
    if (copy < 0) {
      copy = -copy;
      if ((long long int)e == e) {
        res = s21_exp(e * s21_log(copy));
        if (s21_fmod(e, 2) != 0) {
          res = -res;
        }
      }
    } else {
      res = s21_exp(e * s21_log(copy));
    }
  }
  return res;
}
