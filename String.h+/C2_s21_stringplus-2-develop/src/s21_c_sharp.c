#include "s21_string.h"

void *s21_to_upper(const char *str) {
  char *cstr = S21_NULL;
  if (str != S21_NULL) {
    cstr = malloc(sizeof(char) * (s21_strlen(str) + 1));
  }
  if (cstr) {
    s21_size_t i = 0;
    for (i = 0; i < s21_strlen(str); i++) {
      if (str[i] >= 'a' && str[i] <= 'z') {
        cstr[i] = str[i] - 32;
      } else {
        cstr[i] = str[i];
      }
    }
    cstr[i] = '\0';
  }
  return cstr;
}

void *s21_to_lower(const char *str) {
  char *cstr = S21_NULL;
  if (str != S21_NULL) {
    cstr = malloc(sizeof(char) * (s21_strlen(str) + 1));
  }
  if (cstr) {
    s21_size_t i = 0;
    for (i = 0; i < s21_strlen(str); i++) {
      if (str[i] >= 'A' && str[i] <= 'Z') {
        cstr[i] = str[i] + 32;
      } else {
        cstr[i] = str[i];
      }
    }
    cstr[i] = '\0';
  }
  return cstr;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *new_str = S21_NULL;
  if (src != S21_NULL && str != S21_NULL && start_index <= s21_strlen(src)) {
    new_str = malloc(sizeof(char) * (s21_strlen(src) + s21_strlen(str) + 1));
    if (new_str) {
      s21_size_t i_src = 0;
      s21_size_t i_str = 0;
      s21_size_t i_new = 0;
      while (i_new < start_index) {
        new_str[i_new] = src[i_src];
        i_new++;
        i_src++;
      }
      while (i_str < s21_strlen(str)) {
        new_str[i_new] = str[i_str];
        i_new++;
        i_str++;
      }
      while (i_new < (s21_strlen(src) + (s21_strlen(str)))) {
        new_str[i_new] = src[i_src];
        i_new++;
        i_src++;
      }
      new_str[i_new] = '\0';
    }
  }
  return new_str;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *new_str = S21_NULL;
  if (src) {
    if (trim_chars && *trim_chars) {
      s21_size_t len = s21_strlen(src);
      s21_size_t chars_len = s21_strlen(trim_chars);
      s21_trim_left(&src, trim_chars, &len, chars_len);
      if (len) {
        s21_trim_right(&src, trim_chars, &len, chars_len);
      }
      new_str = (char *)malloc(sizeof(char) * (len + 1));
      if (new_str) {
        for (s21_size_t i = 0; i < len + 1; i++) {
          if (i < len) {
            new_str[i] = src[i];
          } else {
            new_str[i] = '\0';
          }
        }
      }
    } else {
      new_str = s21_trim(src, " \t\n");
    }
  }
  return new_str;
}

void s21_trim_left(const char **src, const char *trim_chars,
                   s21_size_t *src_len, const s21_size_t trim_chars_len) {
  s21_size_t len = 0;
  while (src && len != trim_chars_len) {
    if ((**src) == trim_chars[len]) {
      (*src)++;
      (*src_len) -= 1;
      len = 0;
      continue;
    }
    len++;
  }
}

void s21_trim_right(const char **src, const char *trim_chars,
                    s21_size_t *src_len, const s21_size_t trim_chars_len) {
  s21_size_t len = 0;
  s21_size_t i = (*src_len) - 1;
  while (src && len != trim_chars_len) {
    if ((*src)[i] == trim_chars[len]) {
      i--;
      (*src_len)--;
      len = 0;
      continue;
    }
    len++;
  }
}
