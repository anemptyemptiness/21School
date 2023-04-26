#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *result = {0};
  if (c == '\0') {
    result = "";
  }
  c = (char)c;
  s21_size_t len = s21_strlen(str);
  if (len != 0) {
    for (s21_size_t i = len - 1, m = 0; m < len && c != '\0'; i--, m++) {
      if (str[i] == c) {
        result = (char *)&str[i];
        break;
      }
    }
  }
  return result;
}
