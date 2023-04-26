#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *cdest = (char *)dest;
  const char *csrc = (char *)src;
  for (s21_size_t i = 0; i < n; i++) {
    *cdest++ = *csrc++;
  }
  return dest;
}