#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  int equel_check = 0;
  int char_count = 0;

  for (int i = 0; str1[i] != '\0'; i++) {
    for (int j = 0; str2[j] != '\0'; j++) {
      if (str1[i] == str2[j]) {
        equel_check++;
      }
    }
    if (equel_check == 0) {
      char_count++;
    }
  }
  return char_count;
}
