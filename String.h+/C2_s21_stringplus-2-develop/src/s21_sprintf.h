#ifndef SRC_S21_SPRINTF_H_
#define SRC_S21_SPRINTF_H_
#include "s21_string.h"

#define is_digit(ch) ((ch) >= '0' && (ch) <= '9')

struct flags {
  bool minus;
  bool plus;
  bool space;
  bool sharp;
  bool zero;
  int width;
  int precision;
  int is_precision_set;
  char length;
  char specifier;
  bool is_negative;
  int base;
};

long int s21_atoi(const char* str, struct flags* f);
bool s21_isdigit(const char* format);
void s21_itoa(int64_t val, char* ret, int base, struct flags* f);
void s21_utoa(unsigned long long int val, char* ret, struct flags f);
void s21_ftoa(long double val, char* ret, int precision, struct flags* f);

void format_flags(struct flags f, char* ret);
void format_width(struct flags f, char* ret);
void format_precision(struct flags f, char* ret);

void parse_int(struct flags* f, char* buff, va_list va);
void parse_float(struct flags* f, char* buff, va_list va);
void parse_unsigned(struct flags* f, char* buff, va_list va);
void parse_char(struct flags f, char* buff, va_list va);
void parse_string(struct flags f, char* buff, va_list va);
void parse_ptr(struct flags f, char* buff, va_list va);
void parse_n(va_list va, int counter);

void handle_value(struct flags f, char* buff, va_list va, int counter);

const char* get_flags(struct flags* f, const char* format);
const char* get_width(struct flags* f, const char* format, va_list va);
const char* get_precision(struct flags* f, const char* format, va_list va);
const char* get_length(struct flags* f, const char* format);

int s21_sprintf(char* str, const char* format, ...);

#endif  //  SRC_S21_SPRINTF_H_