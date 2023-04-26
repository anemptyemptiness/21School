#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  char *result = {0};
  if (c == '\0') {
    result = "";
  }
  c = (char)c;

  s21_size_t len = s21_strlen(str);
  for (s21_size_t i = 0; i < len; i++) {
    if (str[i] == c) {
      result = (char *)&str[i];
      break;
    }
  }
  return result;
}
