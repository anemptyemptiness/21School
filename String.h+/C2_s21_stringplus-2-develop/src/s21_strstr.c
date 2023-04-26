#include "s21_string.h"

char* s21_strstr(const char* haystack, const char* needle) {
  char* result = S21_NULL;

  if (*needle == '\0') result = (char*)haystack;

  for (s21_size_t i = 0; i < s21_strlen(haystack); i++) {
    char* haystack_copy = (char*)haystack;
    char* needle_copy = (char*)needle;
    if (haystack_copy[i] == *needle_copy) {
      char* tmp = &haystack_copy[i];
      if (s21_strncmp(tmp, needle_copy, s21_strlen(needle_copy)) == 0) {
        result = tmp;
        break;
      }
    }
  }
  return result;
}
