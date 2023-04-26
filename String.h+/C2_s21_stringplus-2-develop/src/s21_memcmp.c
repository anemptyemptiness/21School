#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const unsigned char *cstr1 = str1;
  const unsigned char *cstr2 = str2;
  int diff = 0;
  for (s21_size_t i = 0; i < n; i++) {
    if (cstr1[i] != cstr2[i]) {
      diff = (cstr1[i] - cstr2[i]);
      break;
    }
  }
  return diff;
}