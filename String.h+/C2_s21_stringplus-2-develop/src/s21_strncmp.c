#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int flag = 0;

  while (n--) {
    if (*str1 == *str2) {
      str1++;
      str2++;
    } else if (*str1 != *str2) {
      if (*str1 > *str2)
        flag = 1;
      else
        flag = -1;
    }
  }

  return flag;
}