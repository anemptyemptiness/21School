#include "s21_sprintf.h"

#include "s21_string.h"

#define BUFF_SIZE 4096

long int s21_atoi(const char* str, struct flags* f) {
  long int value_from_string = 0;
  int i = 0;
  f->is_negative = 0;
  while (str[i] == '0' || str[i] == '-') {
    if (str[i] == '-') f->is_negative = 1;
    i++;
  }
  while (str[i] >= '0' && str[i] <= '9') {
    value_from_string = (value_from_string * 10) + (str[i] - '0');
    i++;
  }
  if (f->is_negative) value_from_string = -value_from_string;
  return value_from_string;
}

bool s21_isdigit(const char* format) {
  bool ret = false;
  s21_size_t result = 0;
  for (s21_size_t i = 0; i < s21_strlen(format); i++) {
    if (*format >= '0' && *format <= '9') result++;
  }
  if (result == s21_strlen(format)) ret = true;
  return ret;
}

void s21_itoa(int64_t val, char* ret, int base, struct flags* f) {
  char tmp[BUFF_SIZE] = {'\0'};
  int idx = BUFF_SIZE - 2;
  if (val == 0) {
    ret[0] = '0';
  } else {
    f->is_negative = 0;
    if (val < 0) {
      val = -val;
      f->is_negative = 1;
    }
    while (val > 0) {
      idx--;
      tmp[idx] = "0123456789abcdef"[val % base];
      val /= base;
    }
    if (f->is_negative) {
      idx--;
      tmp[idx] = '-';
    }
    for (int i = idx, j = 0; i < BUFF_SIZE - 1; i++, j++) {
      ret[j] = tmp[i];
    }
  }
}

void s21_utoa(unsigned long long int val, char* ret, struct flags f) {
  if (val == 0) {
    ret[0] = '0';
  } else {
    char tmp[BUFF_SIZE] = {'\0'};
    int idx = BUFF_SIZE - 2;
    while (val > 0) {
      idx--;
      tmp[idx] = "0123456789abcdef"[val % f.base];
      val /= f.base;
    }

    for (int i = idx, j = 0; i < BUFF_SIZE - 1; i++, j++) {
      if (f.specifier == 'X' && tmp[i] >= 'a' && tmp[i] <= 'z') tmp[i] -= 32;
      ret[j] = tmp[i];
    }
  }
}

void s21_ftoa(long double val, char* ret, int precision, struct flags* f) {
  char zeroes[BUFF_SIZE] = {'\0'};
  long double ldleft = 0;
  long double ldright = modfl(val, &ldleft);
  if (precision == 0 && ldright >= 0.5) ldleft += 1;
  if (precision == 0 && ldright <= -0.5) ldleft -= 1;

  ldright = (roundl)(ldright * pow(10, precision));
  long int left = (long int)ldleft;
  long int right = (long int)ldright;

  if (right < 0) {
    right = -right;
  }
  char left_str[BUFF_SIZE] = {'\0'};
  s21_itoa(left, left_str, 10, f);

  char right_str[BUFF_SIZE] = {'\0'};
  if (right == 0) {
    for (int i = 0; i < precision; i++) {
      right_str[i] = '0';
    }
  } else {
    s21_itoa(right, right_str, 10, f);
  }

  s21_strcpy(ret, left_str);
  if (precision) {
    s21_strcat(ret, ".");
    if ((int)s21_strlen(right_str) < precision) {
      for (int i = 0; i < precision - (int)s21_strlen(right_str); i++) {
        zeroes[i] = '0';
      }
      s21_strcat(zeroes, right_str);
      s21_strcat(ret, zeroes);
    } else {
      s21_strcat(ret, right_str);
    }
  } else if (f->sharp) {
    s21_strcat(ret, ".");
  }
}

void format_flags(struct flags f, char* ret) {
  if ((f.sharp && (s21_atoi(ret, &f) != 0) &&
       (f.specifier == 'x' || f.specifier == 'X' || f.specifier == 'o')) ||
      f.specifier == 'p') {
    if (f.specifier != 'o') {
      char x = 'x';
      if (f.specifier == 'X') x = 'X';
      if ((s21_atoi(ret, &f) != 0) || f.specifier == 'p') {
        s21_memmove(ret, &ret[-2], (s21_strlen(ret) + 2) * sizeof(int));
        ret[0] = '0';
        ret[1] = x;
      }
    } else {
      if (ret[0] != '0') {
        s21_memmove(ret, &ret[-1], (s21_strlen(ret) + 1) * sizeof(int));
        ret[0] = '0';
      }
    }
  }
  if (ret[0] == '\0' && f.space && (f.specifier == 'd' || f.specifier == 'i'))
    ret[0] = ' ';
  if (is_digit(ret[0]) && (f.plus || f.space) && f.specifier != 'u' &&
      f.specifier != 'o' && f.specifier != 'x' && f.specifier != 'X') {
    char sign[1] = " ";
    if (f.plus) {
      sign[0] = '+';
    } else {
      sign[0] = ' ';
    }
    s21_memmove(ret, &ret[-1], (s21_strlen(ret) + 1) * sizeof(int));
    ret[0] = sign[0];
  }
}

void format_width(struct flags f, char* ret) {
  if (f.width > (int)s21_strlen(ret)) {
    char spaces[BUFF_SIZE] = {'\0'};
    int len = f.width - (int)s21_strlen(ret);
    for (int i = 0; i < len; i++) {
      if (f.zero && f.specifier != 'c' && f.specifier != 's' && !f.minus) {
        spaces[i] = '0';
      } else {
        spaces[i] = ' ';
      }
    }
    if (f.minus) {
      s21_strcat(ret, spaces);
    } else {
      if (f.zero) {
        int shift = 0;
        if (f.is_negative || f.plus) shift = 1;
        char* ret_copy = s21_insert(ret, spaces, shift);
        s21_memmove(ret, ret_copy, s21_strlen(ret_copy));
        free(ret_copy);
      } else {
        char* ret_copy = s21_insert(ret, spaces, 0);
        ret[s21_strlen(ret_copy)] = '\0';
        s21_memmove(ret, ret_copy, s21_strlen(ret_copy));
        free(ret_copy);
      }
    }
  }
}

void format_precision(struct flags f, char* ret) {
  if (f.specifier == 's') {
    if (f.precision < (int)s21_strlen(ret)) ret[f.precision] = '\0';
  } else {
    if (f.is_precision_set && f.precision == 0 && ret[0] == '0') ret[0] = '\0';
    if (f.precision >= (int)s21_strlen(ret)) {
      char zeros[BUFF_SIZE] = {'\0'};
      int ret_len = (int)s21_strlen(ret);
      for (int i = 0; i < f.precision - (ret_len - f.is_negative); i++)
        zeros[i] = '0';
      char* ret_copy = s21_insert(ret, zeros, f.is_negative);
      s21_memmove(ret, ret_copy, s21_strlen(ret_copy));
      free(ret_copy);
    }
  }
}

void parse_int(struct flags* f, char* buff, va_list va) {
  if (!f->is_precision_set) f->precision = 1;
  long int val_long = 0;
  int val = 0;
  short int val_short = 0;
  int base_of_num = 10;
  switch (f->length) {
    case 'h':
      val_short = (short int)va_arg(va, int);
      s21_itoa(val_short, buff, base_of_num, f);
      break;
    case 'l':
      val_long = va_arg(va, long int);
      s21_itoa(val_long, buff, base_of_num, f);
      break;
    default:
      val = va_arg(va, int);
      s21_itoa(val, buff, base_of_num, f);
  }
  format_precision(*f, buff);
  format_flags(*f, buff);
  format_width(*f, buff);
}

void parse_float(struct flags* f, char* buff, va_list va) {
  if (!f->is_precision_set) f->precision = 6;
  long double val_long = 0;
  double val = 0;
  if (f->length == 'L') {
    val_long = va_arg(va, long double);
    s21_ftoa(val_long, buff, f->precision, f);
  } else {
    val = va_arg(va, double);
    s21_ftoa(val, buff, f->precision, f);
  }
  if (buff[0] == '-') f->is_negative = 1;
  format_flags(*f, buff);
  format_width(*f, buff);
}

void parse_unsigned(struct flags* f, char* buff, va_list va) {
  if (!f->is_precision_set) f->precision = 1;
  unsigned long int val_long = 0;
  unsigned int val = 0;
  unsigned short int val_short = 0;
  //  int base_of_num = 10;
  switch (f->length) {
    case 'h':
      val_short = (unsigned short int)va_arg(va, unsigned int);
      s21_utoa(val_short, buff, *f);
      break;
    case 'l':
      val_long = va_arg(va, unsigned long int);
      s21_utoa(val_long, buff, *f);
      break;
    default:
      val = va_arg(va, unsigned int);
      s21_utoa(val, buff, *f);
  }

  format_precision(*f, buff);
  format_flags(*f, buff);
  format_width(*f, buff);
}

void parse_char(struct flags f, char* buff, va_list va) {
  if (f.length == 'l') {
    wchar_t wch = va_arg(va, wchar_t);
    wchar_t wstr[BUFF_SIZE] = {'\0'};
    wstr[0] = wch;
    wcstombs(buff, wstr, BUFF_SIZE);
  } else {
    int ch = va_arg(va, int);
    buff[0] = (char)ch;
  }
  format_width(f, buff);
}

void parse_string(struct flags f, char* buff, va_list va) {
  if (f.length == 'l') {
    wchar_t* wstr = va_arg(va, wchar_t*);
    if (wstr == S21_NULL) {
      buff[0] = '(';
      buff[1] = 'n';
      buff[2] = 'u';
      buff[3] = 'l';
      buff[4] = 'l';
      buff[5] = ')';
      format_width(f, buff);
    } else {
      char str[BUFF_SIZE] = {"\0"};
      wcstombs(str, wstr, BUFF_SIZE);
      s21_strcat(buff, str);
    }
  } else {
    char* str = va_arg(va, char*);
    if (str == S21_NULL) {
      buff[0] = '(';
      buff[1] = 'n';
      buff[2] = 'u';
      buff[3] = 'l';
      buff[4] = 'l';
      buff[5] = ')';
      format_width(f, buff);
    } else {
      s21_strcat(buff, str);
    }
  }
  if (!f.is_precision_set) f.precision = (int)s21_strlen(buff);

  format_precision(f, buff);
  format_width(f, buff);
}

void parse_ptr(struct flags f, char* buff, va_list va) {
  int* val = va_arg(va, int*);
  if (val == S21_NULL) {
    buff[0] = '0';
    buff[1] = 'x';
    buff[2] = '0';
    format_width(f, buff);
  } else {
    s21_utoa((uint64_t)val, buff, f);

    format_precision(f, buff);
    format_flags(f, buff);
    format_width(f, buff);
  }
}

void parse_n(va_list va, int counter) {
  int* arg = va_arg(va, int*);
  *arg = counter;
}

void handle_value(struct flags f, char* buff, va_list va, int counter) {
  switch (f.specifier) {
    case '%':
      buff[0] = '%';
      break;
    case 'd':
    case 'i':
      parse_int(&f, buff, va);
      break;
    case 'f':
      parse_float(&f, buff, va);
      break;
    case 'c':
      parse_char(f, buff, va);
      break;
    case 's':
      parse_string(f, buff, va);
      break;
    case 'u':
      f.base = 10;
      parse_unsigned(&f, buff, va);
      break;
    case 'o':
      f.base = 8;
      parse_unsigned(&f, buff, va);
      break;
    case 'x':
    case 'X':
      f.base = 16;
      parse_unsigned(&f, buff, va);
      break;
    case 'p':
      f.base = 16;
      parse_ptr(f, buff, va);
      break;
    case 'n':
      parse_n(va, counter);
      break;
  }
}

const char* get_flags(struct flags* f, const char* format) {
  while (*format == '-' || *format == '+' || *format == ' ' || *format == '0' ||
         *format == '#') {
    switch (*format) {
      case '-':
        f->minus = true;
        break;
      case '+':
        f->plus = true;
        break;
      case ' ':
        f->space = true;
        break;
      case '#':
        f->sharp = true;
        break;
      case '0':
        f->zero = true;
        break;
    }
    format++;
  }
  return format;
}

const char* get_width(struct flags* f, const char* format, va_list va) {
  if (s21_isdigit(format)) {
    char tmp[BUFF_SIZE] = {'\0'};
    int i = 0;
    while (s21_isdigit(format)) {
      tmp[i] = *format;
      i++;
      format++;
    }
    f->width = (int)s21_atoi(tmp, f);
  } else if (*format == '*') {
    format++;
    f->width = va_arg(va, int);
  }
  return format;
}

const char* get_precision(struct flags* f, const char* format, va_list va) {
  if (*format == '.') {
    f->is_precision_set = 1;
    format++;
    if (*format == '*') {
      format++;
      f->precision = va_arg(va, int);
    } else {
      char tmp[BUFF_SIZE] = {'\0'};
      int i = 0;
      while (s21_isdigit(format)) {
        tmp[i] = *format;
        i++;
        format++;
      }
      f->precision = (int)s21_atoi(tmp, f);
    }
  }
  return format;
}

const char* get_length(struct flags* f, const char* format) {
  switch (*format) {
    case 'h':
      f->length = 'h';
      format++;
      break;
    case 'l':
      f->length = 'l';
      format++;
      break;
    case 'L':
      f->length = 'L';
      format++;
      break;
  }
  return format;
}

int s21_sprintf(char* str, const char* format, ...) {
  struct flags f = {0};
  va_list va;
  va_start(va, format);
  char* str_beginning = str;
  int counter = 0;
  while (*format) {
    if (*format != '%') {
      *str++ = *format++;
      counter++;
      continue;
    } else {
      format++;
      s21_memset(&f, 0, sizeof(struct flags));
    }
    format = get_flags(&f, format);
    format = get_width(&f, format, va);
    format = get_precision(&f, format, va);
    format = get_length(&f, format);

    f.specifier = *format;
    format++;
    char buff[BUFF_SIZE] = {'\0'};
    handle_value(f, buff, va, counter);
    for (int i = 0; buff[i]; i++, str++) {
      *str = buff[i];
    }
  }
  *str = '\0';
  va_end(va);
  return (int)(str - str_beginning);
}