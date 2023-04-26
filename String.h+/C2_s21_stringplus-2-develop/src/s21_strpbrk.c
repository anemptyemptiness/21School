#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *result = {0};
  char c;
  s21_size_t len1 = s21_strlen(str1);
  s21_size_t len2 = s21_strlen(str2);
  s21_size_t index = len1;
  for (s21_size_t s = 0; s < len2; s++) {
    c = str2[s];
    for (s21_size_t i = 0; i < len1; i++) {
      if (str1[i] == c && i < index) {
        index = i;
        result = (char *)&str1[i];
        break;
      }
    }
  }
  return result;
}
