#include "s21_string.h"

char *s21_memset(void *str, int c, s21_size_t n) {
  void *ptr = str;
  for (s21_size_t i = 0; i < n; i++) {
    *(char *)(ptr + i) = c;
  }
  return str;
}
