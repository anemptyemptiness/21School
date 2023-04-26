#include "s21_string.h"

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  if (dest < src) {
    char *cdest = (char *)dest;
    const char *csrc = (char *)src;
    for (s21_size_t i = 0; i < n; i++) {
      *cdest++ = *csrc++;
    }
  } else {
    char *cdest = (char *)dest + n;
    const char *csrc = (char *)src + n;
    for (s21_size_t i = 0; i < n; i++) {
      *--cdest = *--csrc;
    }
  }
  return dest;
}