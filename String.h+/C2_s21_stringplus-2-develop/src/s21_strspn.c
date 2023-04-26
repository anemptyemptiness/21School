#include "s21_string.h"

s21_size_t s21_strspn(const char *str1, const char *str2) {
  char c;
  int flag = 1;
  s21_size_t result = 0;
  s21_size_t len1 = s21_strlen(str1);
  s21_size_t len2 = s21_strlen(str2);
  for (s21_size_t i = 0; i < len1; i++) {
    if (flag == 0) {
      break;
    }
    flag = 0;
    for (s21_size_t s = 0; s < len2; s++) {
      c = str2[s];
      if (str1[i] == c) {
        result += 1;
        flag = 1;
        break;
      }
    }
  }
  return result;
}
