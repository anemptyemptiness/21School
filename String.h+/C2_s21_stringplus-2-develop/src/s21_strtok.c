#include "s21_string.h"

unsigned int is_delim(char c, const char *delim) {
  unsigned int flag = 0;
  while (*delim != '\0') {
    if (c == *delim) {
      flag = 1;
      break;
    }
    delim++;
  }
  return flag;
}
char *s21_strtok(char *str, const char *delim) {
  static char *prev_ptr = S21_NULL;
  char *result;
  if (!str) {
    str = prev_ptr;
  }
  if (!*str) {
    result = S21_NULL;
  } else {
    while (is_delim(*str, delim)) {
      ++str;
    }
    if (!*str) {
      str = S21_NULL;
    }
    result = str;
    while (str && *str && !is_delim(*str, delim)) {
      str++;
    }
    if (str && !*str) {
      prev_ptr = str;
    } else if (str && is_delim(*str, delim)) {
      *str = '\0';
      prev_ptr = str + 1;
    }
  }
  return result;
}
