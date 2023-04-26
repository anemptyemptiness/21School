#include <check.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

#define BUFF_SIZE 512

// memset ->
START_TEST(memset_test0) {
  s21_size_t n1 = 6;
  int c1 = '7';
  char str1[BUFF_SIZE] = "Charles Leclerc";
  char str11[BUFF_SIZE] = "Charles Leclerc";
  ck_assert_pstr_eq(memset(str1, c1, n1), s21_memset(str11, c1, n1));
  s21_size_t n2 = 4;
  int c2 = '4';
  char str2[BUFF_SIZE] = " LECLERC!";
  char str22[BUFF_SIZE] = " LECLERC!";
  ck_assert_pstr_eq(memset(str2, c2, n2), s21_memset(str22, c2, n2));
  s21_size_t n3 = 6;
  int c3 = '3';
  char str3[BUFF_SIZE] = " Leclerc";
  char str33[BUFF_SIZE] = " Leclerc";
  ck_assert_pstr_eq(memset(str3, c3, n3), s21_memset(str33, c3, n3));
}
END_TEST

START_TEST(memset_heiss_test) {
  char res[] = "heissheissheiss";
  char expected[] = "heissheissheiss";
  char replace = 'g';
  s21_size_t n_byte = 5;
  s21_memset(res, replace, n_byte);
  memset(expected, replace, n_byte);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(memset_zero_byte) {
  char res[] = "heissheissheiss";
  char expected[] = "heissheissheiss";
  char replace = 'g';
  s21_size_t n_byte = 0;
  s21_memset(res, replace, n_byte);
  memset(expected, replace, n_byte);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(memset_empty) {
  char res[] = "";
  char expected[] = "";
  char replace = '\0';
  s21_size_t n_byte = 0;
  s21_memset(res, replace, n_byte);
  memset(expected, replace, n_byte);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(memset_replace_on_register_sim) {
  char res[] = "heissheissheiss";
  char expected[] = "heissheissheiss";
  char replace = 'A';
  s21_size_t n_byte = 3;
  s21_memset(res, replace, n_byte);
  memset(expected, replace, n_byte);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(memset_replace_on_register_num) {
  char res[] = "a1bcD";
  char expected[] = "a1bcD";
  char replace = '1';
  s21_size_t n_byte = 5;
  s21_memset(res, replace, n_byte);
  memset(expected, replace, n_byte);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(memset_long_string) {
  char res[] =
      "a1oas[pifjaosidfj oapisjdfpoi asjdfoij ouh12oi3 uh12i3 "
      "hiajhIOUAHSDiouAHSdu1).bA";
  char expected[] =
      "a1oas[pifjaosidfj oapisjdfpoi asjdfoij ouh12oi3 uh12i3 "
      "hiajhIOUAHSDiouAHSdu1).bA";
  char replace = '1';
  s21_size_t n_byte = 5;
  s21_memset(res, replace, n_byte);
  memset(expected, replace, n_byte);
  ck_assert_str_eq(res, expected);
}
END_TEST
// memset <-

// strcmp ->
START_TEST(strcmp_1) {
  char *str_1_1 = "Leclerc";
  char *str_1_2 = "Leclerc";
  int s21_c = s21_strcmp(str_1_1, str_1_2);
  int s_c = strcmp(str_1_1, str_1_2);
  if (s21_c > 0)
    s21_c = 1;
  else if (s21_c < 0)
    s21_c = -1;

  if (s_c > 0)
    s_c = 1;
  else if (s_c < 0)
    s_c = -1;
  ck_assert_int_eq(s21_c, s_c);
}
END_TEST

START_TEST(strcmp_2) {
  char *str_2_1 = "Charles Perceval Leclerc";
  char *str_2_2 = "Charles Leclerc";
  int s21_c = s21_strcmp(str_2_1, str_2_2);
  int s_c = strcmp(str_2_1, str_2_2);
  if (s21_c > 0)
    s21_c = 1;
  else if (s21_c < 0)
    s21_c = -1;

  if (s_c > 0)
    s_c = 1;
  else if (s_c < 0)
    s_c = -1;
  ck_assert_int_eq(s21_c, s_c);
}
END_TEST

START_TEST(strcmp_3) {
  char *str_3_1 = "Leclerc is the best";
  char *str_3_2 = "Leclerc";
  int s21_c = s21_strcmp(str_3_1, str_3_2);
  int s_c = strcmp(str_3_1, str_3_2);
  if (s21_c > 0)
    s21_c = 1;
  else if (s21_c < 0)
    s21_c = -1;

  if (s_c > 0)
    s_c = 1;
  else if (s_c < 0)
    s_c = -1;
  ck_assert_int_eq(s21_c, s_c);
}
END_TEST

START_TEST(strcmp_Heloboba_Heloboba) {
  char a[] = "Heloboba";
  char b[] = "Heloboba";
  int got = s21_strcmp(a, b);
  int expected = strcmp(a, b);
  if (got > 0) got = 1;
  if (expected > 0) expected = 1;
  if (got < 0) got = -1;
  if (expected < 0) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(strcmp_HEloboba_Heloboba) {
  char a[] = "HEloboba";
  char b[] = "Heloboba";
  int got = s21_strcmp(a, b);
  int expected = strcmp(a, b);
  if (got > 0) got = 1;
  if (expected > 0) expected = 1;
  if (got < 0) got = -1;
  if (expected < 0) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(strcmp_Hel0boba_Helob0ba) {
  char a[] = "Hel0boba";
  char b[] = "Helob0ba";
  int got = s21_strcmp(a, b);
  int expected = strcmp(a, b);
  if (got > 0) got = 1;
  if (expected > 0) expected = 1;
  if (got < 0) got = -1;
  if (expected < 0) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(strcmp_Heloboba_) {
  char a[] = "Heloboba";
  char b[] = "";
  int got = s21_strcmp(a, b);
  int expected = strcmp(a, b);
  if (got > 0) got = 1;
  if (expected > 0) expected = 1;
  if (got < 0) got = -1;
  if (expected < 0) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(strcmp__Heloboba) {
  char a[] = "";
  char b[] = "Heloboba";
  int got = s21_strcmp(a, b);
  int expected = strcmp(a, b);
  if (got > 0) got = 1;
  if (expected > 0) expected = 1;
  if (got < 0) got = -1;
  if (expected < 0) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(strcmp_Heloboba) {
  char a[] = "L(8)L";
  char b[] = "L(8)L";
  int got = s21_strcmp(a, b);
  int expected = strcmp(a, b);
  if (got > 1) got = 1;
  if (expected > 1) expected = 1;
  if (got < -1) got = -1;
  if (expected < -1) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(strcmp_empty) {
  char a[] = "";
  char b[] = "";
  int got = s21_strcmp(a, b);
  int expected = strcmp(a, b);
  if (got > 1) got = 1;
  if (expected > 1) expected = 1;
  if (got < -1) got = -1;
  if (expected < -1) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(strcmp_only_num) {
  char a[] = "1234567890";
  char b[] = "1234567890";
  int got = s21_strcmp(a, b);
  int expected = strcmp(a, b);
  if (got > 1) got = 1;
  if (expected > 1) expected = 1;
  if (got < -1) got = -1;
  if (expected < -1) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST
// strcmp <-

// strncmp ->
START_TEST(strncmp_1) {
  s21_size_t n = 3;
  char *str_1_1 = "LUGANO!";
  char *str_1_2 = "LUGANO!";
  int s21_c = s21_strncmp(str_1_1, str_1_2, n);
  int s_c = strncmp(str_1_1, str_1_2, n);
  if (s21_c > 0)
    s21_c = 1;
  else if (s21_c < 0)
    s21_c = -1;

  if (s_c > 0)
    s_c = 1;
  else if (s_c < 0)
    s_c = -1;
  ck_assert_int_eq(s21_c, s_c);
}
END_TEST

START_TEST(strncmp_2) {
  s21_size_t n = 3;
  char *str_2_1 = "LUGANO THE BEST!";
  char *str_2_2 = "LU GANO OF THE BEST!!";
  int s21_c = s21_strncmp(str_2_1, str_2_2, n);
  int s_c = strncmp(str_2_1, str_2_2, n);
  if (s21_c > 0)
    s21_c = 1;
  else if (s21_c < 0)
    s21_c = -1;

  if (s_c > 0)
    s_c = 1;
  else if (s_c < 0)
    s_c = -1;
  ck_assert_int_eq(s21_c, s_c);
}
END_TEST

START_TEST(strncmp_3) {
  s21_size_t n = 3;
  char *str_3_1 = " LUGANO OF THE BEST!!";
  char *str_3_2 = "LUGANO!";
  int s21_c = s21_strncmp(str_3_1, str_3_2, n);
  int s_c = strncmp(str_3_1, str_3_2, n);
  if (s21_c > 0)
    s21_c = 1;
  else if (s21_c < 0)
    s21_c = -1;

  if (s_c > 0)
    s_c = 1;
  else if (s_c < 0)
    s_c = -1;
  ck_assert_int_eq(s21_c, s_c);
}
END_TEST

START_TEST(strncmp_empty) {
  char str1[] = "";
  char str2[] = "";
  s21_size_t n_byte = 0;
  int got = s21_strncmp(str1, str2, n_byte);
  int expected = strncmp(str1, str2, n_byte);
  if (got > 1) got = 1;
  if (expected > 1) expected = 1;
  if (got < -1) got = -1;
  if (expected < -1) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(strncmp_floppa_) {
  char str1[] = "floppa";
  char str2[] = "";
  s21_size_t n_byte = 0;
  int got = s21_strncmp(str1, str2, n_byte);
  int expected = strncmp(str1, str2, n_byte);
  if (got > 1) got = 1;
  if (expected > 1) expected = 1;
  if (got < -1) got = -1;
  if (expected < -1) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(strncmp__floppa) {
  char str1[] = "";
  char str2[] = "floppa";
  s21_size_t n_byte = 0;
  int got = s21_strncmp(str1, str2, n_byte);
  int expected = strncmp(str1, str2, n_byte);
  if (got > 1) got = 1;
  if (expected > 1) expected = 1;
  if (got < -1) got = -1;
  if (expected < -1) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(strncmp_floppa_floppa) {
  char str1[] = "floppa";
  char str2[] = "floppa";
  s21_size_t n_byte = 6;
  int got = s21_strncmp(str1, str2, n_byte);
  int expected = strncmp(str1, str2, n_byte);
  if (got > 1) got = 1;
  if (expected > 1) expected = 1;
  if (got < -1) got = -1;
  if (expected < -1) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(strncmp_floppa_floppa_zero_byte) {
  char str1[] = "floppabazbazkotya";
  char str2[] = "floppabaz";
  s21_size_t n_byte = 10;
  int got = s21_strncmp(str1, str2, n_byte);
  int expected = strncmp(str1, str2, n_byte);
  if (got > 1) got = 1;
  if (expected > 1) expected = 1;
  if (got < -1) got = -1;
  if (expected < -1) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(strncmp_floppa_floppa_one_byte) {
  char str1[] = "floppa";
  char str2[] = "floppa";
  s21_size_t n_byte = 1;
  int got = s21_strncmp(str1, str2, n_byte);
  int expected = strncmp(str1, str2, n_byte);
  if (got > 1) got = 1;
  if (expected > 1) expected = 1;
  if (got < -1) got = -1;
  if (expected < -1) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST
// strncmp <-

// strstr ->
START_TEST(strstr_1) {
  char str[] = "";
  ck_assert_pstr_eq(strstr(str, ""), s21_strstr(str, ""));
}
END_TEST

START_TEST(strstr_2) {
  char str2[] = "john.smith@mic\0rosoft.com";
  ck_assert_pstr_eq(strstr(str2, "sm"), s21_strstr(str2, "sm"));
}
END_TEST

START_TEST(strstr_3) {
  char str3[] = {'q', 'r', 's', 't', 'w', 's', 'a', 's', '\0'};
  ck_assert_pstr_eq(strstr(str3, "woo"), s21_strstr(str3, "woo"));
}
END_TEST

START_TEST(strstr_empty_string_haystack_and_needle) {
  char haystack[] = "";
  char needle[] = "";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_empty_string_haystack) {
  char haystack[] = "";
  char needle[] = "jho1faQsdkjnSa3aefwf8hiuJafeHioj";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_empty_string_needle) {
  char haystack[] = "safQhilufas7MaSef2345wknwefnkjHawe2fhilu";
  char needle[] = "";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_toxic_test) {
  char haystack[] = "You are toxic!";
  char needle[] = "toxic";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_not_word_in_haystack) {
  char haystack[] = "There is no right word in this test!";
  char needle[] = "NOT";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_words_with_any_register) {
  char haystack[] = "AbOBosNyTSa";
  char needle[] = "aBoboSNYTsa";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_repeated_words) {
  char haystack[] = "AD AD AD";
  char needle[] = "AD";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_word_at_end) {
  char haystack[] = "22 321 123";
  char needle[] = "123";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_one_simbol_in_needle_and_haystack) {
  char haystack[] = "1";
  char needle[] = "1";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_one_simbol_in_needle) {
  char haystack[] =
      "13625523478437263475984675342345sdghyftrg freshtsyASFWEt wEafe";
  char needle[] = " ";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_one_simbol_in_haystack) {
  char haystack[] = "-";
  char needle[] = "1234567890qwertyuiopasdfghjk-";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST
// strstr <-

// strlen ->
START_TEST(strlen_test0) {
  char *str_1 = "STEPAN\0";
  ck_assert_int_eq(strlen(str_1), s21_strlen(str_1));
  char *str_2 = "STEPAN \0IS OUR GOD";
  ck_assert_int_eq(strlen(str_2), s21_strlen(str_2));
  char *str_3 = "\0";
  ck_assert_int_eq(strlen(str_3), s21_strlen(str_3));
}
END_TEST

START_TEST(strlen_empty) {
  char src[] = "";
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(strlen_meow) {
  char src[] = "meow";
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(strlen_num) {
  char src[] = "987623456124678";
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(strlen_string) {
  char src[] =
      "987623456124678qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(strlen_meow_meow_meow) {
  char src[] = "meow\0meow_meow";
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(strlen_i_leven_maier) {
  char src[] = "i_leven_maier(321321)...123...123";
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(strlen_i_leven_maier2) {
  char src[] = "I_Leven_Maier";
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(strlen_so_heiss) {
  char src[] = "Mir ist so heiss";
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(strlen_abbey_downton) {
  char src[] = "abbey Downton";
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(strlen_school) {
  char src[] = "school";
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST
// strlen <-

// memcpy ->
START_TEST(memcpy_test0) {
  s21_size_t n1 = 3;
  char b1[BUFF_SIZE] = "";
  char b11[BUFF_SIZE] = "";
  char str_1_2[BUFF_SIZE] = "Mir ist so heiss!";
  ck_assert_pstr_eq(memcpy(b1, str_1_2, n1), s21_memcpy(b11, str_1_2, n1));
  s21_size_t n2 = 5;
  char b2[BUFF_SIZE] = "";
  char b22[BUFF_SIZE] = "";
  char str_2_2[BUFF_SIZE] = "MIR IST SO \0HEISS!!";
  ck_assert_pstr_eq(memcpy(b2, str_2_2, n2), s21_memcpy(b22, str_2_2, n2));
  s21_size_t n3 = 4;
  char b3[BUFF_SIZE] = "000 ";
  char b33[BUFF_SIZE] = "000 ";
  char str_3_2[BUFF_SIZE] = "SHINOXY!";
  ck_assert_pstr_eq(memcpy(b3, str_3_2, n3), s21_memcpy(b33, str_3_2, n3));
  s21_size_t n4 = 4;
  char b4[BUFF_SIZE] = "Death 666 Grips";
  char b44[BUFF_SIZE] = "Death 666 Grips";
  ck_assert_pstr_eq(memcpy(b4, b4 + 7, n4), s21_memcpy(b44, b44 + 7, n4));
}
END_TEST

START_TEST(memcpy_love_test) {
  char src[] = "Alisa turn on Death Grips";
  s21_size_t kByte = 12;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy_zero_test_string) {
  char src[] = "heissheissheiss";
  s21_size_t kByte = 0;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy_any_empty) {
  char src[] = "";
  s21_size_t kByte = 0;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy_zero_test_string_with_register) {
  char src[] = "Alisa turn on Death Grips";
  s21_size_t kByte = 0;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy_zero_test_num) {
  char src[] = "123";
  s21_size_t kByte = 1;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy_one_byte_string) {
  char src[] = "meowmeow";
  s21_size_t kByte = 1;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy_one_byte_string_with_register) {
  char src[] = "Leclerc";
  s21_size_t kByte = 1;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy_one_byte_num) {
  char src[] = "09";
  s21_size_t kByte = 1;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy_basic_long_string) {
  char src[] = "meowmeowsdafoijasdofjas asdopij";
  s21_size_t kByte = 28;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy_long_string_with_register) {
  char src[] = "aposkd AOSIjFasodijpaoisdjf poisdjfg";
  s21_size_t kByte = 36;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy_long_string_with_register_and_num) {
  char src[] = "aodasf ieuwfh luhasdfLIAUSHD liuh 12li3uh 12i4ouhsdfh";
  s21_size_t kByte = 53;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy_long_string_with_register_and_num_and_symbol) {
  char src[] =
      "()()(((())):!,....aodasf ieuwfh luhasdfLIAUSHD liuh 12li3uh 12i4ouhsdfh";
  s21_size_t kByte = 71;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST
// memcpy <-

// memcmp ->
START_TEST(memcmp_test0) {
  s21_size_t n = 4;
  void *str1 = " THE TESTS ARE DEDICATED TO CHARLES";
  void *str2 = "LEECLEERC!";
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_test1) {
  s21_size_t n = 8;
  void *str1 = "LEEEEE CLEEEEERC!";
  void *str2 = "THE TESTS ARE DEDICATED TO CHARLES";
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_test2) {
  s21_size_t n = 6;
  void *str1 = "LECLERC!";
  void *str2 = "LECLERC!";
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_zero_byte) {
  char str1[] = "meowmeow";
  char str2[] = "meowmeow";
  int n = 0;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_first_byte_in_string) {
  char str1[] = "meowmeow";
  char str2[] = "meowmeow";
  int n = 3;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_register_test) {
  char str1[] = "meowmeow";
  char str2[] = "meowmeow";
  int n = 1;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_zero_byte_in_num) {
  char str1[] = "1";
  char str2[] = "1";
  int n = 0;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_first_byte_in_num) {
  char str1[] = "1";
  char str2[] = "1234";
  int n = 1;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_two_byte_in_num) {
  char str1[] = "1234";
  char str2[] = "1234";
  int n = 2;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_two_byte_long_two_num) {
  char str1[] = "13";
  char str2[] = "1234";
  int n = 2;
  int got = s21_memcmp(str1, str2, n);
  int expected = memcmp(str1, str2, n);
  if (got > 1) got = 1;
  if (expected > 1) expected = 1;
  if (got < -1) got = -1;
  if (expected < -1) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(memcmp_two_byte_long_first_num) {
  char str1[] = "134567";
  char str2[] = "1234";
  int n = 2;
  int got = s21_memcmp(str1, str2, n);
  int expected = memcmp(str1, str2, n);
  if (got > 1) got = 1;
  if (expected > 1) expected = 1;
  if (got < -1) got = -1;
  if (expected < -1) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(memcmp_eq_long_string) {
  char str1[] =
      "111111111111111111112312312312312312434524563567adsfe 4rafa ewfseASDASD";
  char str2[] =
      "111111111111111111112312312312312312434524563567adsfe 4rafa ewfseASDASD";
  int n = 71;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_not_eq_long_string) {
  char str1[] =
      "111111111111111111112312312312312312434524563567adsfe 4rafa ewfseASDASD";
  char str2[] =
      "111111111111111111112312312312312312434524563567adsfe 4rafa ewfseASDASd";
  int n = 71;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST
// memcmp <-

// memmove ->
START_TEST(memmove_test0) {
  s21_size_t n1 = 3;
  char b1[BUFF_SIZE] = "CHARLES LECLERC";
  char b11[BUFF_SIZE] = "CHARLES LECLERC";
  ck_assert_pstr_eq(memmove(b1, b1 + 5, n1), s21_memmove(b11, b1 + 5, n1));
  s21_size_t n2 = 4;
  char b2[BUFF_SIZE] = "420 2734420";
  char b22[BUFF_SIZE] = "420 2734420";
  ck_assert_pstr_eq(memmove(b2, b2, n2), s21_memmove(b22, b2, n2));
  s21_size_t n3 = 4;
  char b3[BUFF_SIZE] = "27 Leclerc";
  char b33[BUFF_SIZE] = "27 Leclerc";
  ck_assert_pstr_eq(memmove(b3, b3, n3), s21_memmove(b33, b33, n3));
  s21_size_t n4 = 4;
  char b4[BUFF_SIZE] = "27 Leclerc";
  char b44[BUFF_SIZE] = "27 Leclerc";
  ck_assert_pstr_eq(memmove(b4, b4, n4), s21_memmove(b44, b44, n4));
}
END_TEST

START_TEST(memmove_empty_dest_and_src) {
  char src[200] = "";
  char src2[200] = "";
  s21_size_t copy_kByte = 0;
  char *res = src;
  char *expected = src2;
  s21_size_t check_kByte = 0;
  s21_memmove(res, src, copy_kByte);
  memmove(expected, src2, copy_kByte);
  ck_assert_mem_eq(res, expected, check_kByte);
}
END_TEST

START_TEST(memmove_empty_dest) {
  char src[200] = "123SDFAZ`ESFsdfsdf";
  char src2[200] = "123SDFAZ`ESFsdfsdf";
  s21_size_t copy_kByte = 10;
  char res[200] = "";
  char expected[200] = "";
  s21_size_t check_kByte = 10;
  s21_memmove(res, src, copy_kByte);
  memmove(expected, src2, copy_kByte);
  ck_assert_mem_eq(res, expected, check_kByte);
}
END_TEST

START_TEST(memmove_empty_src) {
  char src[200] = "";
  char src2[200] = "";
  s21_size_t copy_kByte = 0;
  char res[200] = "i love school";
  char expected[200] = "i love school";
  s21_size_t check_kByte = 13;
  s21_memmove(res, src, copy_kByte);
  memmove(expected, src2, copy_kByte);
  ck_assert_mem_eq(res, expected, check_kByte);
}
END_TEST

START_TEST(memmove_write_in_left) {
  char src[200] = "Love";
  char src2[200] = "Love";
  s21_size_t copy_kByte = 4;
  char res[200] = "i love school";
  char expected[200] = "i love school";
  s21_size_t check_kByte = 17;
  s21_memmove(res, src, copy_kByte);
  memmove(expected, src2, copy_kByte);
  ck_assert_mem_eq(res, expected, check_kByte);
}
END_TEST

START_TEST(memmove_write_in_right) {
  char src[200] = "Love";
  char src2[200] = "Love";
  s21_size_t copy_kByte = 4;
  char res[200] = "i love school";
  char expected[200] = "i love school";
  s21_size_t check_kByte = 17;
  s21_memmove(res + 13, src, copy_kByte);
  memmove(expected + 13, src2, copy_kByte);
  ck_assert_mem_eq(res, expected, check_kByte);
}
END_TEST

START_TEST(memmove_write_in_mid) {
  char src[200] = "Love";
  char src2[200] = "Love";
  s21_size_t copy_kByte = 4;
  char res[200] = "i love school";
  char expected[200] = "i love school";
  s21_size_t check_kByte = 17;
  s21_memmove(res + 5, src, copy_kByte);
  memmove(expected + 5, src2, copy_kByte);
  ck_assert_mem_eq(res, expected, check_kByte);
}
END_TEST

START_TEST(memmove_overlap_write_in_left) {
  char src[200] = "Leclerc is love.";
  char src2[200] = "Leclerc is love.";
  s21_size_t copy_kByte = 17;
  char *res = src;
  char *expected = src2;
  s21_size_t check_kByte = 34;
  s21_memmove(res, src, copy_kByte);
  memmove(expected, src2, copy_kByte);
  ck_assert_mem_eq(res, expected, check_kByte);
}
END_TEST

START_TEST(memmove_overlap_write_in_right) {
  char src[200] = "Leclerc is love.";
  char src2[200] = "Leclerc is love.";
  s21_size_t copy_kByte = 17;
  char *res = src + 17;
  char *expected = src2 + 17;
  s21_size_t check_kByte = 34;
  s21_memmove(res, src, copy_kByte);
  memmove(expected, src2, copy_kByte);
  ck_assert_mem_eq(res, expected, check_kByte);
}
END_TEST

START_TEST(memmove_overlap_write_in_mid) {
  char src[200] = "Leclerc is life.";
  char src2[200] = "Leclerc is life.";
  s21_size_t copy_kByte = 17;
  char *res = src + 5;
  char *expected = src2 + 5;
  s21_size_t check_kByte = 34;
  s21_memmove(res, src, copy_kByte);
  memmove(expected, src2, copy_kByte);
  ck_assert_mem_eq(res, expected, check_kByte);
}
END_TEST

START_TEST(memmove_zero_test_string) {
  char src[] = "meowmeow";
  s21_size_t kByte = 0;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memmove(res, src, kByte);
  memmove(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memmove_any_empty) {
  char src[] = "";
  s21_size_t kByte = 0;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memmove(res, src, kByte);
  memmove(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memmove_zero_test_string_with_register) {
  char src[] = "i love leclerc";
  s21_size_t kByte = 0;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memmove(res, src, kByte);
  memmove(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memmove_zero_test_num) {
  char src[] = "123";
  s21_size_t kByte = 1;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memmove(res, src, kByte);
  memmove(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memmove_one_byte_string) {
  char src[] = "meowmeow";
  s21_size_t kByte = 1;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memmove(res, src, kByte);
  memmove(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memmove_one_byte_string_with_register) {
  char src[] = "Maier";
  s21_size_t kByte = 1;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memmove(res, src, kByte);
  memmove(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memmove_one_byte_num) {
  char src[] = "09";
  s21_size_t kByte = 1;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memmove(res, src, kByte);
  memmove(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memmove_basic_long_string) {
  char src[] = "meowmeowsdafoijasdofjas asdopij";
  s21_size_t kByte = 28;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memmove(res, src, kByte);
  memmove(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memmove_long_string_with_register) {
  char src[] = "aposkd AOSIjFasodijpaoisdjf poisdjfg";
  s21_size_t kByte = 36;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memmove(res, src, kByte);
  memmove(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memmove_long_string_with_register_and_num) {
  char src[] = "aodasf ieuwfh luhasdfLIAUSHD liuh 12li3uh 12i4ouhsdfh";
  s21_size_t kByte = 53;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memmove(res, src, kByte);
  memmove(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memmove_long_string_with_register_and_num_and_symbol) {
  char src[] =
      "()()(((())):!,....aodasf ieuwfh luhasdfLIAUSHD liuh 12li3uh 12i4ouhsdfh";
  s21_size_t kByte = 71;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memmove(res, src, kByte);
  memmove(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memmove_ints) {
  int src[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21_size_t kByte = 4;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memmove(res, src, kByte);
  memmove(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memmove_floats) {
  float src[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21_size_t kByte = 8;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memmove(res, src, kByte);
  memmove(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST
// memmove <-

// memchr ->
START_TEST(memchr_1) {
  char str[] = "Hello w\0orld\0";
  ck_assert_pstr_eq(memchr(str, 'r', 5), s21_memchr(str, 'r', 5));
}
END_TEST

START_TEST(memchr_2) {
  char str2[] = "john.smith@microsoft.com";
  ck_assert_pstr_eq(memchr(str2, 's', 6), s21_memchr(str2, 's', 6));
}
END_TEST

START_TEST(memchr_3) {
  char str3[] = {'q', 'r', 's', 't', 'w', '\0'};
  ck_assert_pstr_eq(memchr(str3, 's', 5), s21_memchr(str3, 's', 5));
}
END_TEST

START_TEST(memchr_empty_str) {
  s21_size_t n_byte = 0;
  char str[10] = "";
  int find_byte = '\0';
  ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                   memchr(str, find_byte, n_byte));
}
END_TEST

START_TEST(memchr_find_zero_in_string) {
  s21_size_t n_byte = 7;
  char str[10] = "string";
  int find_byte = '\0';
  ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                   memchr(str, find_byte, n_byte));
}
END_TEST

START_TEST(memchr_find_simbol_in_string_in_start) {
  s21_size_t n_byte = 6;
  char str[10] = "Atring";
  int find_byte = 'A';
  ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                   memchr(str, find_byte, n_byte));
}
END_TEST

START_TEST(memchr_find_simbol_in_string_in_end) {
  s21_size_t n_byte = 7;
  char str[10] = "StringA";
  int find_byte = 'A';
  ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                   memchr(str, find_byte, n_byte));
}
END_TEST

START_TEST(memchr_find_num_in_string_in_mid) {
  s21_size_t n_byte = 15;
  char str[16] = "Str55333222ingA";
  int find_byte = '3';
  ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                   memchr(str, find_byte, n_byte));
}
END_TEST

START_TEST(memchr_find_num_in_array_num) {
  int array[] = {1, 2, 3, 666, 5, 99, 100};
  s21_size_t n_byte = sizeof(int) * 7;
  int find_byte = 666;
  ck_assert_ptr_eq(s21_memchr(array, find_byte, n_byte),
                   memchr(array, find_byte, n_byte));
}
END_TEST

START_TEST(memchr_find_float_in_array) {
  float array[] = {1, 2, 3, 666, 5, 99, 100};
  s21_size_t n_byte = sizeof(float) * 7;
  int find_byte = 666;
  ck_assert_ptr_eq(s21_memchr(array, find_byte, n_byte),
                   memchr(array, find_byte, n_byte));
}
END_TEST

START_TEST(memchr_easy_test_string) {
  s21_size_t n_byte = 5;
  char str[10] = "meowmeow";
  int find_byte = 'c';
  ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                   memchr(str, find_byte, n_byte));
}
END_TEST
// memchr <-

// strcat ->
START_TEST(strcat_hello_world) {
  char src[] = " world!";
  char res[5 + 9] = "Hello,";
  char expected[5 + 9] = "Hello,";
  s21_strcat(res, src);
  strcat(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(strcat_zero_first) {
  char src[] = " meowmeow!!!";
  char res[0 + 13] = "";
  char expected[0 + 13] = "";
  s21_strcat(res, src);
  strcat(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(strcat_zero_last) {
  char src[] = "";
  char res[] = "Hello";
  char expected[] = "Hello";
  s21_strcat(res, src);
  strcat(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(strcat_any_letters_with_register) {
  char src[] = "asdfj  asdf aisdfjaiushdfASD SAD asDSad ASDAsdwqqeAS";
  char res[5 + 53] = "Hello";
  char expected[5 + 53] = "Hello";
  s21_strcat(res, src);
  strcat(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(strcat_any_letters_with_register_and_num) {
  char src[] = "asd0fj  asd1f aisdfjw6234A1241SD SA5 asDSad 89SDAsdw7qqeAS";
  char res[5 + 59] = "Hello";
  char expected[5 + 59] = "Hello";
  s21_strcat(res, src);
  strcat(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(strcat_any_letters_with_register_and_num_and_sim) {
  char src[] =
      "asd0fj  asd1f aisdfjw6234A1241SD SA5 asDSad 89SDAsdw7qqeAS)(?!.,";
  char res[5 + 65] = "Hello";
  char expected[5 + 65] = "Hello";
  s21_strcat(res, src);
  strcat(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST
// strcat <-

// strrchr ->
START_TEST(strrchr_1) {
  char str[] = "0163456769";
  ck_assert_pstr_eq(strrchr(str, '6'), s21_strrchr(str, '6'));
}
END_TEST

START_TEST(strrchr_2) {
  char str2[] = "john.smith@microsoft.com";
  ck_assert_pstr_eq(strrchr(str2, 'o'), s21_strrchr(str2, 'o'));
}
END_TEST

START_TEST(strrchr_3) {
  char str3[] = "john.smith@microsoft.com";
  ck_assert_pstr_eq(strrchr(str3, 'h'), s21_strrchr(str3, 'h'));
}
END_TEST

START_TEST(strrchr_4) {
  char str4[] = "";
  ck_assert_pstr_eq(strrchr(str4, 'd'), s21_strrchr(str4, 'd'));
}
END_TEST

START_TEST(strrchr_5) {
  char str5[] = {""};
  ck_assert_pstr_eq(strrchr(str5, 'z'), s21_strrchr(str5, 'z'));
}
END_TEST

START_TEST(strrchr_empty) {
  char str1[] = "";
  char str2 = '\0';
  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST

START_TEST(strrchr_6) {
  char str1[] = "leclerc";
  char str2 = '\0';
  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST

START_TEST(strrchr_7) {
  char str1[] = "";
  char str2 = 'c';
  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST

START_TEST(strrchr_poki_doki_o) {
  char str1[] = "poki doki";
  char str2 = 'o';
  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST

START_TEST(strrchr_poki_doki_i) {
  char str1[] = "poki doki";
  char str2 = 'i';
  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST

START_TEST(strrchr_poki_doki_p) {
  char str1[] = "poki p dokip";
  char str2 = 'p';
  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST

START_TEST(strrchr_find_big_P) {
  char str1[] = "ppPpppppppppP";
  char str2 = 'P';
  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST

START_TEST(strrchr_find_zero) {
  char str1[] = "123456789";
  char str2 = '0';
  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST
// strrchr <-

// strchr ->
START_TEST(strchr_1) {
  char str[] = "Hello world";
  ck_assert_pstr_eq(strchr(str, ' '), s21_strchr(str, ' '));
}
END_TEST

START_TEST(strchr_2) {
  char str2[] = "john.smith\0@microsoft.com";
  ck_assert_pstr_eq(strchr(str2, 'm'), s21_strchr(str2, 'm'));
}
END_TEST

START_TEST(strchr_3) {
  char str3[] = "john.smith@microsoft.com";
  ck_assert_pstr_eq(strchr(str3, 'h'), s21_strchr(str3, 'h'));
}
END_TEST

START_TEST(strchr_mcavoy_find_a) {
  char src[] = "mcavoyisfcnawesome";
  char find = 'a';
  ck_assert_pstr_eq(s21_strchr(src, find), strchr(src, find));
}
END_TEST

START_TEST(strchr_mcavoy_find_A) {
  char src[] = "mcavoyisfcnAwesome";
  char find = 'A';
  ck_assert_pstr_eq(s21_strchr(src, find), strchr(src, find));
}
END_TEST

START_TEST(strchr_mcavoy_find_1) {
  char src[] = "mcavoyisfcn1awesome";
  char find = '1';
  ck_assert_pstr_eq(s21_strchr(src, find), strchr(src, find));
}
END_TEST

START_TEST(strchr_mcavoy_find_Z) {
  char src[] = "mcavoyisfcnawesome";
  char find = 'Z';
  ck_assert_pstr_eq(s21_strchr(src, find), strchr(src, find));
}
END_TEST

START_TEST(strchr_mcavoy_find_3) {
  char src[] = "mcavoyisfcnawesome";
  char find = '3';
  ck_assert_pstr_eq(s21_strchr(src, find), strchr(src, find));
}
END_TEST

START_TEST(strchr_empty_src) {
  char src[] = "";
  char find = '3';
  ck_assert_pstr_eq(s21_strchr(src, find), strchr(src, find));
}
END_TEST
// strchr <-

// strpbrk ->
START_TEST(strpbrk_1) {
  char str[] = "this_is_a_";
  ck_assert_pstr_eq(strpbrk(str, "369"), s21_strpbrk(str, "369"));
}
END_TEST

START_TEST(strpbrk_2) {
  char str2[] = "sshinoxy@gma\0il.com";
  ck_assert_pstr_eq(strpbrk(str2, "fzx"), s21_strpbrk(str2, "fzx"));
}
END_TEST

START_TEST(strpbrk_3) {
  char str3[] = {'q', 'r', 's', 't', 'w', 's', 'a', 's', '\0'};
  ck_assert_pstr_eq(strpbrk(str3, "saq"), s21_strpbrk(str3, "saq"));
}
END_TEST

START_TEST(strpbrk_empty) {
  char str1[] = "";
  char str2[] = "";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_floppy_) {
  char str1[] = "leclerc";
  char str2[] = "";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk__floppy) {
  char str1[] = "";
  char str2[] = "leclerc";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_poki_doki_o) {
  char str1[] = "poki doki";
  char str2[] = "o";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_poki_doki_i) {
  char str1[] = "poki doki";
  char str2[] = "i";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_poki_doki_p) {
  char str1[] = "poki doki";
  char str2[] = "p";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_find_big_P) {
  char str1[] = "ppppppppppppP";
  char str2[] = "P";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_find_zero) {
  char str1[] = "ppppppppppppP";
  char str2[] = "\0";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST
// strpbrk <-

// strncpy ->
START_TEST(strncpy_1) {
  s21_size_t n1 = 3;
  char b1[BUFF_SIZE] = "1111111111";
  char b11[BUFF_SIZE] = "1111111111";
  char str_1_2[BUFF_SIZE] = "123\0";
  ck_assert_pstr_eq(strncpy(b1, str_1_2, n1), s21_strncpy(b11, str_1_2, n1));
}
END_TEST

START_TEST(strncpy_2) {
  s21_size_t n2 = 5;
  char b2[BUFF_SIZE] = "1111111111";
  char b22[BUFF_SIZE] = "1111111111";
  char str_2_2[BUFF_SIZE] = "12345\0006789";
  ck_assert_pstr_eq(strncpy(b2, str_2_2, n2), s21_strncpy(b22, str_2_2, n2));
}
END_TEST

START_TEST(strncpy_3) {
  s21_size_t n3 = 5;
  char b3[BUFF_SIZE] = "11";
  char b33[BUFF_SIZE] = "11";
  char str_3_2[BUFF_SIZE] = "12345\0006789";
  ck_assert_pstr_eq(strncpy(b3, str_3_2, n3), s21_strncpy(b33, str_3_2, n3));
}
END_TEST

START_TEST(strncpy_empty) {
  char src[] = "";
  char res[] = "";
  char exp[] = "";
  s21_size_t n_byte = 0;
  s21_strncpy(res, src, n_byte);
  strncpy(exp, src, n_byte);
  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(strncpy_zero_byte) {
  char src[] = "123";
  char res[] = "123";
  char exp[] = "123";
  s21_size_t n_byte = 0;
  s21_strncpy(res, src, n_byte);
  strncpy(exp, src, n_byte);
  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(strncpy_empty_src) {
  char src[] = "";
  char res[] = "123";
  char exp[] = "123";
  s21_size_t n_byte = 0;
  s21_strncpy(res, src, n_byte);
  strncpy(exp, src, n_byte);
  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(strncpy_one_byte) {
  char src[] = "123";
  char res[5] = "123";
  char exp[5] = "123";
  s21_size_t n_byte = 1;
  s21_strncpy(res, src, n_byte);
  strncpy(exp, src, n_byte);
  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(strncpy_two_byte) {
  char src[] = "123";
  char res[7] = "123";
  char exp[7] = "123";
  s21_size_t n_byte = 2;
  s21_strncpy(res, src, n_byte);
  strncpy(exp, src, n_byte);
  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(strncpy_string) {
  char src[] = "Str1ng";
  char res[7 + 7] = "Str1ng";
  char exp[7 + 7] = "Str1ng";
  s21_size_t n_byte = 7;
  s21_strncpy(res, src, n_byte);
  strncpy(exp, src, n_byte);
  ck_assert_str_eq(res, exp);
}
END_TEST
// strncpy <-

// strncat ->
START_TEST(strncat_1) {
  s21_size_t n1 = 2;
  char b1[BUFF_SIZE] = "";
  char b11[BUFF_SIZE] = "";
  char str_1_2[BUFF_SIZE] = "LECLERC IS THE BEST!";
  ck_assert_pstr_eq(strncat(b1, str_1_2, n1), s21_strncat(b11, str_1_2, n1));
}
END_TEST

START_TEST(strncat_2) {
  s21_size_t n2 = 2;
  char b2[BUFF_SIZE] = "THE";
  char b22[BUFF_SIZE] = "THE";
  char str_2_2[BUFF_SIZE] = " BEST!";
  ck_assert_pstr_eq(strncat(b2, str_2_2, n2), s21_strncat(b22, str_2_2, n2));
}
END_TEST

START_TEST(strncat_3) {
  s21_size_t n3 = 2;
  char b3[BUFF_SIZE] = "777";
  char b33[BUFF_SIZE] = "777";
  char str_3_2[BUFF_SIZE] = " LECLERC";
  ck_assert_pstr_eq(strncat(b3, str_3_2, n3), s21_strncat(b33, str_3_2, n3));
}
END_TEST

START_TEST(strncat_all_empty) {
  char src[] = "";
  char res[] = "";
  char expected[] = "";
  s21_size_t n_byte = 0;
  s21_strncat(res, src, n_byte);
  strncat(expected, src, n_byte);
  ck_assert_mem_ge(res, expected, n_byte);
}
END_TEST

START_TEST(strncat_zero_byte) {
  char src[] = "abosal";
  char res[10] = "";
  char expected[10] = "";
  s21_size_t n_byte = 0;
  s21_strncat(res, src, n_byte);
  strncat(expected, src, n_byte);
  ck_assert_mem_ge(res, expected, n_byte);
}
END_TEST

START_TEST(strncat_empty_src) {
  char src[] = "";
  char res[10] = "cd";
  char expected[10] = "cd";
  s21_size_t n_byte = 0;
  s21_strncat(res, src, n_byte);
  strncat(expected, src, n_byte);
  ck_assert_mem_ge(res, expected, n_byte);
}
END_TEST

START_TEST(strncat_cd_abosa) {
  char src[] = "abosal";
  char res[10] = "cd";
  char expected[10] = "cd";
  s21_size_t n_byte = 5;
  s21_strncat(res, src, n_byte);
  strncat(expected, src, n_byte);
  ck_assert_mem_ge(res, expected, n_byte);
}
END_TEST

START_TEST(strncat_string) {
  char src[] = "abosal";
  char res[25] = "verstappena";
  char expected[25] = "verstappena";
  s21_size_t n_byte = 6;
  s21_strncat(res, src, n_byte);
  strncat(expected, src, n_byte);
  ck_assert_mem_ge(res, expected, n_byte);
}
END_TEST

START_TEST(strncat_school) {
  char src[] = "LOVEschool";
  char res[25] = "LOVEschool";
  char expected[25] = "LOVEschool";
  s21_size_t n_byte = 5;
  s21_strncat(res, src, n_byte);
  strncat(expected, src, n_byte);
  ck_assert_mem_ge(res, expected, n_byte);
}
END_TEST

START_TEST(strncat_school2) {
  char src[] = "LOVEschool";
  char res[25] = "LOVEschool";
  char expected[25] = "LOVEschool";
  s21_size_t n_byte = 0;
  s21_strncat(res, src, n_byte);
  strncat(expected, src, n_byte);
  ck_assert_mem_ge(res, expected, n_byte);
}
END_TEST

START_TEST(strncat_school3) {
  char src[] = "LOVEschool";
  char res[25] = "LOVEschool";
  char expected[25] = "LOVEschool";
  s21_size_t n_byte = 1;
  s21_strncat(res, src, n_byte);
  strncat(expected, src, n_byte);
  ck_assert_mem_ge(res, expected, n_byte);
}
END_TEST

START_TEST(strncat_school4) {
  char src[] = "LOVEschool";
  char res[25] = "LOVEschool";
  char expected[25] = "LOVEschool";
  s21_size_t n_byte = 10;
  s21_strncat(res, src, n_byte);
  strncat(expected, src, n_byte);
  ck_assert_mem_ge(res, expected, n_byte);
}
END_TEST

START_TEST(strncat_zero_char) {
  char src[] = "\0";
  char res[25] = "LOVEschool";
  char expected[25] = "LOVEschool";
  s21_size_t n_byte = 1;
  s21_strncat(res, src, n_byte);
  strncat(expected, src, n_byte);
  ck_assert_mem_ge(res, expected, n_byte);
}
END_TEST
// strncat <-

// strspn ->
START_TEST(strspn_1) {
  char str[] = "27-lucky";
  ck_assert_int_eq(strspn(str, "1234567890"), s21_strspn(str, "1234567890"));
}
END_TEST

START_TEST(strspn_2) {
  char str2[] = "this is a test";
  ck_assert_int_eq(strspn(str2, "shit "), s21_strspn(str2, "shit "));
}
END_TEST

START_TEST(strspn_3) {
  char str3[] = {'q', 'r', 's', 't', 'w', 's', 'a', 's'};
  ck_assert_int_eq(strspn(str3, "01234"), s21_strspn(str3, "01234"));
}
END_TEST

START_TEST(strspn_empty) {
  char src[] = "";
  char res[] = "";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn_dima_) {
  char src[] = "dima";
  char res[] = "";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn__dima) {
  char src[] = "";
  char res[] = "dima";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn_any_register) {
  char src[] = "dima";
  char res[] = "diMa";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn_num_num) {
  char src[] = "123";
  char res[] = "123";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn_long_num_num) {
  char src[] = "12345";
  char res[] = "123";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn_num_long_num) {
  char src[] = "123";
  char res[] = "12345";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn_any_num) {
  char src[] = "1234567890";
  char res[] = "0987654321";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn_num_with_letter) {
  char src[] = "1A2A3A4A5A";
  char res[] = "123";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn_num_with_letter2) {
  char src[] = "a1aaa23aaa41235";
  char res[] = "123";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn_basic_test) {
  char src[] = "absD";
  char res[] = "aD";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn_any_sim) {
  char src[] = "32ASDASDPare[0g9jf m07y271234567890";
  char res[] = "0987654321";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn_upper_letter) {
  char src[] = "32ASDASDPare[0g9jf m07y271234567890";
  char res[] = "1234567890QWERTYUIOPASDFGHJKLZXCVBNM";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn_lower_letter) {
  char src[] = "32jersASDASDPare[0g9jf m07y271234567890";
  char res[] = "1234567890qwertyuiopasdfghjklczxcvbnm";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn_not_uniq_sim) {
  char src[] =
      "333333333333333333333333333333333333333333333333333333333333333333333333"
      "33333333333333";
  char res[] =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "11111111111113";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST
// strspn <-

// strcspn ->
START_TEST(strcspn_1) {
  char str1[] = "this is a test";
  ck_assert_int_eq(strcspn(str1, "ab"), s21_strcspn(str1, "ab"));
}
END_TEST

START_TEST(strcspn_2) {
  char str2[] = "LOST: 4-8-15-16-23-42";
  ck_assert_int_eq(strcspn(str2, "1234567890"),
                   s21_strcspn(str2, "1234567890"));
}
END_TEST

START_TEST(strcspn_3) {
  char str3[] = {'q', 'r', 's', 't', 'w', 's', 'a', 's', '\0'};
  ck_assert_int_eq(strcspn(str3, "zx"), s21_strcspn(str3, "zx"));
}
END_TEST

START_TEST(strcspn_empty) {
  char src[] = "";
  char res[] = "";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_dima2) {
  char src[] = "dima";
  char res[] = "";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_dima1) {
  char src[] = "";
  char res[] = "dima";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_any_register) {
  char src[] = "dima";
  char res[] = "diMa";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_num_num) {
  char src[] = "123";
  char res[] = "123";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_long_num_num) {
  char src[] = "12345";
  char res[] = "123";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_num_long_num) {
  char src[] = "123";
  char res[] = "12345";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_any_num) {
  char src[] = "1234567890";
  char res[] = "0987654321";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_num_with_letter) {
  char src[] = "1A2A3A4A5A";
  char res[] = "123";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_num_with_letter2) {
  char src[] = "a1aaa23aaa41235";
  char res[] = "123";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_basic_test) {
  char src[] = "absD";
  char res[] = "aD";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_any_sim) {
  char src[] = "32ASDASDPare[0g9jf m07y271234567890";
  char res[] = "0987654321";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_upper_letter) {
  char src[] = "32ASDASDPare[0g9jf m07y271234567890";
  char res[] = "1234567890QWERTYUIOPASDFGHJKLZXCVBNM";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_lower_letter) {
  char src[] = "32jersASDASDPare[0g9jf m07y271234567890";
  char res[] = "1234567890qwertyuiopasdfghjklczxcvbnm";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_not_uniq_sim) {
  char src[] =
      "333333333333333333333333333333333333333333333333333333333333333333333333"
      "33333333333333";
  char res[] =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "11111111111113";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST
// strcspn <-

// strcpy ->
START_TEST(strcpy_1) {
  char b1[BUFF_SIZE] = "";
  char b11[BUFF_SIZE] = "";
  char str_1_2[BUFF_SIZE] = "LECLERC IS THE BEST!";
  ck_assert_pstr_eq(strcpy(b1, str_1_2), s21_strcpy(b11, str_1_2));
  char str_2_2[BUFF_SIZE] = "LECLERC IS THE \0BEST!!";
  ck_assert_pstr_eq(strcpy(b1, str_2_2), s21_strcpy(b11, str_2_2));
  char b3[BUFF_SIZE] = "777 ";
  char b33[BUFF_SIZE] = "777 ";
  char str_3_2[BUFF_SIZE] = "SHINOXY";
  ck_assert_pstr_eq(strcpy(b3, str_3_2), s21_strcpy(b33, str_3_2));
}
END_TEST

START_TEST(strcpy_charles_leclerc) {
  char src[] = " Leclerc!!!";
  char res[5 + 15] = "Charles ";
  char expected[5 + 15] = "Charles ";
  s21_strcpy(res, src);
  strcpy(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(strcpy_leclerc) {
  char src[] = "Leclerc!!!";
  char res[5 + 15] = "";
  char expected[5 + 15] = "";
  s21_strcpy(res, src);
  strcpy(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(strcpy_meowmeow) {
  char src[] = "";
  char res[5 + 15] = "meowmeows";
  char expected[5 + 15] = "meowmeows";
  s21_strcpy(res, src);
  strcpy(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(strcpy_empty) {
  char src[] = "";
  char res[5 + 15] = "";
  char expected[5 + 15] = "";
  s21_strcpy(res, src);
  strcpy(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(strcpy_empty_num) {
  char src[] = "1";
  char res[5 + 15] = "";
  char expected[5 + 15] = "";
  s21_strcpy(res, src);
  strcpy(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(strcpy_hello) {
  char src[] = " my dear friend\"";
  char res[5 + 15] = "Hello";
  char expected[5 + 15] = "Hello";
  s21_strcpy(res, src);
  strcpy(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(strcpy_over_string) {
  char src[] = "ab\0ba";
  char res[10 + 9] = "Gre\0t";
  char expected[10 + 9] = "Gre\0t";
  s21_strcpy(res, src);
  strcpy(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(strcpy_hard_test) {
  char src[] = "ad[sofijpoiajsdf pj98981h23 p9h school!!!";
  char res[49 + 42] = "as[oidjf paijsdf j9oqh2837o4h hUW auhduash W8awd";
  char expected[49 + 42] = "as[oidjf paijsdf j9oqh2837o4h hUW auhduash W8awd";
  s21_strcpy(res, src);
  strcpy(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST
// strcpy <-

// strtok ->
START_TEST(strtok_1) {
  char str4_1[] = "/testing/with/original/string.h/";
  char str4_2[] = "/testing/with/original/string.h/";
  char del4[3] = "/";
  char *nstr_1, *nstr_2;
  nstr_1 = strtok(str4_1, del4);
  nstr_2 = s21_strtok(str4_2, del4);
  while (nstr_1 != S21_NULL) {
    ck_assert_pstr_eq(nstr_1, nstr_2);
    nstr_1 = strtok(S21_NULL, del4);
    nstr_2 = s21_strtok(S21_NULL, del4);
  }
}
END_TEST

START_TEST(strtok_2) {
  char str4_1[] = ". . testing with original string.h";
  char str4_2[] = ". . testing with original string.h";
  char del4[3] = ". ";
  char *nstr_1, *nstr_2;
  nstr_1 = strtok(str4_1, del4);
  nstr_2 = s21_strtok(str4_2, del4);
  while (nstr_1 != S21_NULL) {
    ck_assert_pstr_eq(nstr_1, nstr_2);
    nstr_1 = strtok(S21_NULL, del4);
    nstr_2 = s21_strtok(S21_NULL, del4);
  }
}
END_TEST

START_TEST(strtok_3) {
  char str4_1[] = "testing with original string.h";
  char str4_2[] = "testing with original string.h";
  char del4[3] = ". ";
  char *nstr_1, *nstr_2;
  nstr_1 = strtok(str4_1, del4);
  nstr_2 = s21_strtok(str4_2, del4);
  while (nstr_1 != S21_NULL) {
    ck_assert_pstr_eq(nstr_1, nstr_2);
    nstr_1 = strtok(S21_NULL, del4);
    nstr_2 = s21_strtok(S21_NULL, del4);
  }
}
END_TEST

START_TEST(strtok_correct_token_string) {
  char str1[] = "School!!21!String++ I====!Love_It";
  char str2[] = "School!!21!String++ I====!Love_It";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got && expected) {
    got = s21_strtok(S21_NULL, delims);
    expected = strtok(S21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(strtok_hard_token_string) {
  char str1[] = "++i++saw_! Jesus===!In+++ Berlin +";
  char str2[] = "++i++saw_! Jesus===!In+++ Berlin +";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got && expected) {
    got = s21_strtok(S21_NULL, delims);
    expected = strtok(S21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(strtok_unary_delimiters) {
  char str1[] = "200k+300k_500k_Million!Easy_come";
  char str2[] = "200k+300k_500k_Million!Easy_come";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got && expected) {
    got = s21_strtok(S21_NULL, delims);
    expected = strtok(S21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(strtok_no_delims) {
  char str1[] = "ThisStringHasNoDelims";
  char str2[] = "ThisStringHasNoDelims";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got && expected) {
    got = s21_strtok(S21_NULL, delims);
    expected = strtok(S21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(strtok_only_delims) {
  char str1[] = "++++++++";
  char str2[] = "++++++++";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_ptr_null(got);
  ck_assert_ptr_null(expected);
}
END_TEST

START_TEST(strtok_too_many_uses_non_segfault) {
  char str1[] = "leclerc_charlec_Leclerc";
  char str2[] = "leclerc_charlec_Leclerc";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  int i = 5;
  while (i) {
    got = s21_strtok(S21_NULL, delims);
    expected = strtok(S21_NULL, delims);
    i--;
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(strtok_even_n_of_delims) {
  char str1[] = "Vika++++Sh++A++++B__C";
  char str2[] = "Vika++++Sh++A++++B__C";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got && expected) {
    got = s21_strtok(S21_NULL, delims);
    expected = strtok(S21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(strtok_odd_n_of_delims) {
  char str1[] = "nauchniy__+regress_  Sainz";
  char str2[] = "nauchniy__+regress_  Sainz";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got && expected) {
    got = s21_strtok(S21_NULL, delims);
    expected = strtok(S21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(strtok_mixed_n_of_delims) {
  char str1[] = "nauchniy__regress_+++Carlos_S";
  char str2[] = "nauchniy__regress_+++Carlos_S";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got && expected) {
    got = s21_strtok(S21_NULL, delims);
    expected = strtok(S21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(strtok_hard_mixed) {
  char str1[] = "     science__+ or! maybe_   Sainz+";
  char str2[] = "     science__+ or! maybe_   Sainz+";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got || expected) {
    got = s21_strtok(S21_NULL, delims);
    expected = strtok(S21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(strtok_mixed_hard_incorrect) {
  char str1[] = "!Formula__ !1!Ch r____Rl+es!!!Leclerc";
  char str2[] = "!Formula__ !1!Ch r____Rl+es!!!Leclerc";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got || expected) {
    got = s21_strtok(S21_NULL, delims);
    expected = strtok(S21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(strtok_very_hard_mixed) {
  char str1[] = "!       A!B!C!D!E!!F!!G";
  char str2[] = "!       A!B!C!D!E!!F!!G";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got || expected) {
    got = s21_strtok(S21_NULL, delims);
    expected = strtok(S21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
      ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST
// strtok <-

// to_upper ->
START_TEST(to_upper_test0) {
  void *str1_1 = "hEllO, WoRLD!";
  char *str1_2 = s21_to_upper(str1_1);
  ck_assert_pstr_eq((str1_2), "HELLO, WORLD!");
  if (str1_2) free(str1_2);
  void *str2_1 = "hEllO, WoRLD! 27 420";
  char *str2_2 = s21_to_upper(str2_1);
  ck_assert_pstr_eq((str2_2), "HELLO, WORLD! 27 420");
  if (str2_2) free(str2_2);
}
END_TEST

START_TEST(to_upper_test1) {
  char str[] = "charles leclerc";
  char *result = s21_to_upper(str);
  ck_assert_str_eq(result, "CHARLES LECLERC");
  if (result) free(result);
}
END_TEST

START_TEST(to_upper_test2) {
  char str[] = "formula";
  char *result = s21_to_upper(str);
  ck_assert_str_eq(result, "FORMULA");
  if (result) free(result);
}
END_TEST

START_TEST(to_upper_test3) {
  char str[] = "1+1*1";
  char *result = s21_to_upper(str);
  ck_assert_str_eq(result, "1+1*1");
  if (result) free(result);
}
END_TEST

START_TEST(to_upper_test4) {
  char str[] = " ";
  char *result = s21_to_upper(str);
  ck_assert_str_eq(result, " ");
  if (result) free(result);
}
END_TEST

START_TEST(to_upper_test5) {
  char str[] = "";
  char *result = s21_to_upper(str);
  ck_assert_str_eq(result, "");
  if (result) free(result);
}
END_TEST

START_TEST(to_upper_test6) {
  char *str = S21_NULL;
  char *result = (char *)s21_to_upper(str);
  ck_assert_ptr_null(result);
  if (result) free(result);
}
END_TEST
// to_upper <-

// to_lower ->
START_TEST(to_lower_test0) {
  void *str1_1 = "hEllO, WoRLD!";
  char *str1_2 = s21_to_lower(str1_1);
  ck_assert_pstr_eq((str1_2), "hello, world!");
  if (str1_2) free(str1_2);
  void *str2_1 = "hEllO, WoRLD! 27 420";
  char *str2_2 = s21_to_lower(str2_1);
  ck_assert_pstr_eq((str2_2), "hello, world! 27 420");
  if (str2_2) free(str2_2);
}
END_TEST

START_TEST(to_lower_test1) {
  char str[] = "ChArLeS LeClErC";
  char *got = s21_to_lower(str);
  ck_assert_str_eq(got, "charles leclerc");
  if (got) free(got);
}
END_TEST

START_TEST(to_lower_test2) {
  char str[] = "123456789Q";
  char *got = s21_to_lower(str);
  ck_assert_str_eq(got, "123456789q");
  if (got) free(got);
}
END_TEST

START_TEST(to_lower_test3) {
  char str[] = "Charles Leclerc";
  char *got = s21_to_lower(str);
  ck_assert_str_eq(got, "charles leclerc");
  if (got) free(got);
}
END_TEST

START_TEST(to_lower_test4) {
  char str[] = "";
  char *got = s21_to_lower(str);
  ck_assert_str_eq(got, "");
  if (got) free(got);
}
END_TEST

START_TEST(to_lower_test5) {
  char str[] = "";
  char *got = s21_to_lower(str);
  ck_assert_str_eq(got, "");
  if (got) free(got);
}
END_TEST

START_TEST(to_lower_test6) {
  char *str = S21_NULL;
  char *got = s21_to_lower(str);
  ck_assert_ptr_null(got);
  if (got) free(got);
}
END_TEST
// to_lower <-

// insert ->
START_TEST(insert_test0) {
  char *str1_1 = "diary";
  char *str1_2 = s21_insert(str1_1, "ction", 2);
  ck_assert_pstr_eq(str1_2, "dictionary");
  free(str1_2);
  char *str2_1 = "diary";
  char *str2_2 = s21_insert(str2_1, "ction", 9);
  ck_assert_pstr_eq(str2_2, S21_NULL);
  free(str2_2);
  char *str3_1 = S21_NULL;
  char *str3_2 = s21_insert(str3_1, "ction", 2);
  ck_assert_pstr_eq(str3_2, S21_NULL);
  free(str3_2);
}
END_TEST

START_TEST(insert_test1) {
  char str[] = "Charles Leclerc";
  char src[] = "I love . He would be a champion in 2023!";
  s21_size_t index = 7;
  char expected[] = "I love Charles Leclerc. He would be a champion in 2023!";
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(insert_test2) {
  char str[] = "Charles ";
  char src[] = "Leclerc";
  s21_size_t index = 0;
  char expected[] = "Charles Leclerc";
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(insert_test3) {
  char str[] = "";
  char src[] = "";
  s21_size_t index = 100;
  char *expected = S21_NULL;
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_pstr_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(insert_test4) {
  char *src = S21_NULL;
  char *str = S21_NULL;
  s21_size_t index = 100;
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_ptr_null(got);
  if (got) free(got);
}
END_TEST

START_TEST(insert_test5) {
  char str[] = "Maier!";
  char src[] = "Leven  ";
  s21_size_t index = 6;
  char expected[] = "Leven Maier! ";
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(insert_test6) {
  char *str = S21_NULL;
  char src[] = "Zoolander  ";
  s21_size_t index = 0;
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_ptr_null(got);
  if (got) free(got);
}
END_TEST
// insert <-

// trim ->
START_TEST(trim_all_empty) {
  char str[] = "";
  char trim_ch[] = "";
  char *expected = "";
  char *got = s21_trim(str, trim_ch);
  ck_assert_pstr_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_str_empty) {
  char str[] = "";
  char trim_ch[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char expected[] = "";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_empty) {
  char str[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char trim_ch[] = "";
  char *expected = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_and_str_eq) {
  char str[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char trim_ch[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char expected[] = "";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_test1) {
  char str[] = "+!!++Abo+ba++00";
  char trim_ch[] = "+!0-";
  char expected[] = "Abo+ba";
  char *got = (char *)s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_test2) {
  char str[] = "Ab000cd0";
  char trim_ch[] = "003";
  char expected[] = "Ab000cd";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_test3) {
  char str[] = "DoNotTouch";
  char trim_ch[] = "Not";
  char expected[] = "DoNotTouch";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_test4) {
  char str[] = "&* !!sc21 * **";
  char trim_ch[] = "&!* ";
  char expected[] = "sc21";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_test5) {
  char str[] = " Give it to me!    ";
  char trim_ch[] = " ";
  char expected[] = "Give it to me!";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_empty_spaces) {
  char str[] = "        abc         ";
  char trim_ch[] = "";
  char *expected = "abc";
  char *got = s21_trim(str, trim_ch);
  ck_assert_pstr_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_null_ptr_trim_chars) {
  char str[] = "        abc         ";
  char *trim_ch = S21_NULL;
  char expected[] = "abc";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST
// trim <-

// sprintf ->
START_TEST(sprintf_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "This is a simple value %d";
  int val = 27;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_int_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.5i";
  int val = 27;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  // s21_sprintf(str1, format, val);
  // sprintf(str2, format, val);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_int_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%5d";
  int val = 27;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_int_minus_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5i";
  int val = 27;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_int_plus_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%+12d";
  int val = 27;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_int_zero_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%012i";
  int val = 42;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_int_star_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%0*d";
  int val = 27;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_int_zero_star_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%0.*i";
  int val = 27;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_int_many_flags_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char format[] = "%0.*i %d %4.*i %013d %d";
  int val = 27;
  ck_assert_int_eq(
      s21_sprintf(str1, format, 5, val, -10431, 13, 5311, 0, -581813581),
      sprintf(str2, format, 5, val, -10431, 13, 5311, 0, -581813581));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_int_long_all_specifiers) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%+5.31ld";
  long int val = -2147483647;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_int_short_all_specifiers) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%16.9hi";
  short int val = 2758;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_int_long_zero_star_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%0.*ld";
  long val = 8581385185;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_int_zero_value_precision_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.0d";
  int val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_int_space_flag) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "% d";
  int val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-16u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_many_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%+5.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_short) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%hu";
  unsigned short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lu";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lu, %u, %hu, %.5u, %5.u";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(
      s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
      sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
              (unsigned)14414, (unsigned)9681));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%u";
  ck_assert_int_eq(s21_sprintf(str1, format, (unsigned)0),
                   sprintf(str2, format, (unsigned)0));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.13Lf";
  long double val = 513515.000131513515151351;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%10Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  // s21_sprintf(str1, format, val);
  // sprintf(str2, format, val);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_precision_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.0Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  // s21_sprintf(str1, format, val);
  // sprintf(str2, format, val);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_precision_empty) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_precision_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_precision_huge_negative) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15Lf";
  long double val = -15.35581134;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%Lf";
  long double val = 72537572375.1431341;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% f";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% .0f %.lf %Lf %f %lf %Lf";
  float val = 0;
  double val1 = 0;
  long double val2 = 3515315.153151;
  float val3 = 5.5;
  double val4 = 9851.51351;
  long double val5 = 95919539159.53151351131;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val1, val2, val3, val4, val5),
                   sprintf(str2, format, val, val1, val2, val3, val4, val5));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%c";
  char val = 'X';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_char_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.5c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_char_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "% -5c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_char_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_char_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5.3c%c%c%c%c Hello! meowmeow";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val, 'c', 'a', 'b', 'b'),
                   sprintf(str2, format, val, 'c', 'a', 'b', 'b'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_char_many_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5.3c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_char2) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%c", '\t'), sprintf(str2, "%c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_char_many2) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'),
                   sprintf(str2, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s";
  char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.15s";
  char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15s";
  char *val = "27 IS MY FAVORITE NUMBER";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%+15.9s";
  char *val = "27 IS MY FAVORITE NUMBER";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s";
  char *val = "IF U SEE US IN THE CLUB WE'LL BE ACTING REAL NICE";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s%s%s%s";
  char *val = "IF U SEE US ON THE FLOOR YOU'LL BE WATCHING ALL NIGHT";
  char *s1 = "";
  char *s2 = "87418347813748913749871389480913";
  char *s3 = "HAHAmeowmeowSUCKER";
  ck_assert_int_eq(s21_sprintf(str1, format, val, s1, s2, s3),
                   sprintf(str2, format, val, s1, s2, s3));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_width_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *val = "kjafdiuhfjahfjdahf";
  char *format = "%120s";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_one) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%s", "Give it to me"),
                   sprintf(str2, "%s", "Give it to me"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_many2) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%s%s%s%s%s", "Kislenko", " ", "Racing", " ", "F1"),
      sprintf(str2, "%s%s%s%s%s", "Kislenko", " ", "Racing", " ", "F1"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-16o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.51o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_many_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5.51o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%o";
  ck_assert_int_eq(s21_sprintf(str1, format, 0), sprintf(str2, format, 0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_hash) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#o";
  int val = 57175;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_short) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%hd";
  short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lo";
  long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lo, %o, %ho, %.5o, %5.o";
  long int val = 949149114140;
  ck_assert_int_eq(
      s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
      sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
              (unsigned)14414, (unsigned)9681));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lo";
  long int val = 84518;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%5x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#-10x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.15x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#-10x%x%X%#x%#X%5.5x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val, val, val, val, val),
                   sprintf(str2, format, val, val, val, val, val, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_many_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#-5.10x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#x";
  unsigned val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%#x";
  unsigned val = 18571;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_short) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%#hx";
  unsigned short val = 12352;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%#lx";
  unsigned long val = 18571757371571;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_one_longer_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%#2x";
  unsigned val = 1;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_two_longer_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%#30x";
  unsigned val = 1;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_ptr) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_ptr_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%15p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_ptr_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.5p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_ptr_null) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%p";
  char *ptr = S21_NULL;
  ck_assert_int_eq(s21_sprintf(str1, format, ptr), sprintf(str2, format, ptr));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_n_specifier) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  int ret1 = 0;
  int ret2 = 0;
  char *format = "Hello %n world";
  s21_sprintf(str1, format, &ret1);
  sprintf(str2, format, &ret2);
  ck_assert_int_eq(ret1, ret2);
}
END_TEST

START_TEST(sprintf_e_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.17Le";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_precision_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.0Le";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_precision_empty) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.Le";
  long double val = 15.000009121;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_precision_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15Le";
  long double val = 0.000000000000000123;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_precision_huge_negative) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15Le";
  long double val = -15.35581134;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%Le";
  long double val = 72537572375.1431341;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%015E";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%15e";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% .0e %.le %Le %e %le %Le";
  float val = 0;
  double val1 = 0;
  long double val2 = 3515315.153151;
  float val3 = 5.5;
  double val4 = 0.094913941;
  long double val5 = 95919539159.53151351131;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val1, val2, val3, val4, val5),
                   sprintf(str2, format, val, val1, val2, val3, val4, val5));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_E_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.17LE";
  long double val = 4134121;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

// strerror ->
START_TEST(strerror1) { ck_assert_pstr_eq(strerror(1), s21_strerror(1)); }
END_TEST

START_TEST(strerror2) { ck_assert_pstr_eq(strerror(7), s21_strerror(7)); }
END_TEST

START_TEST(strerror3) { ck_assert_pstr_eq(strerror(404), s21_strerror(404)); }
END_TEST

START_TEST(strerror4) { ck_assert_pstr_eq(strerror(0), s21_strerror(0)); }
END_TEST

START_TEST(strerror5) {
  for (int i = -1000; i < 150; i++) {
    char *got = s21_strerror(i);
    char *expected = strerror(i);
    ck_assert_str_eq(got, expected);
  }
}
END_TEST

START_TEST(strerror6) {
  const char *got = s21_strerror(-1);
  char *expected = strerror(-1);
  ck_assert_str_eq(got, expected);
}
END_TEST
// strerror <-

Suite *suite_insert(void) {
  Suite *s = suite_create("suite_insert");
  TCase *tc = tcase_create("insert_tc");

  tcase_add_test(tc, sprintf_int);
  tcase_add_test(tc, sprintf_int_precision);
  tcase_add_test(tc, sprintf_int_width);
  tcase_add_test(tc, sprintf_int_minus_width);
  tcase_add_test(tc, sprintf_int_plus_width);
  tcase_add_test(tc, sprintf_int_zero_width);
  tcase_add_test(tc, sprintf_int_star_width);
  tcase_add_test(tc, sprintf_int_zero_star_precision);
  tcase_add_test(tc, sprintf_int_many_flags_many);
  tcase_add_test(tc, sprintf_int_long_all_specifiers);
  tcase_add_test(tc, sprintf_int_short_all_specifiers);
  tcase_add_test(tc, sprintf_int_long_zero_star_precision);
  tcase_add_test(tc, sprintf_int_zero_value_precision_zero);
  tcase_add_test(tc, sprintf_int_space_flag);

  tcase_add_test(tc, sprintf_unsigned_val);
  tcase_add_test(tc, sprintf_unsigned_val_width);
  tcase_add_test(tc, sprintf_unsigned_val_flags);
  tcase_add_test(tc, sprintf_unsigned_val_precision);
  tcase_add_test(tc, sprintf_unsigned_val_many_flags);
  tcase_add_test(tc, sprintf_unsigned_val_short);
  tcase_add_test(tc, sprintf_unsigned_val_long);
  tcase_add_test(tc, sprintf_unsigned_val_many);
  tcase_add_test(tc, sprintf_unsigned_zero);

  tcase_add_test(tc, sprintf_float_precision);
  tcase_add_test(tc, sprintf_float_width);
  tcase_add_test(tc, sprintf_float_precision_zero);
  tcase_add_test(tc, sprintf_float_precision_empty);
  tcase_add_test(tc, sprintf_float_precision_huge);
  tcase_add_test(tc, sprintf_float_precision_huge_negative);
  tcase_add_test(tc, sprintf_float_huge);
  tcase_add_test(tc, sprintf_float_flags);
  tcase_add_test(tc, sprintf_float_many);

  tcase_add_test(tc, sprintf_char);
  tcase_add_test(tc, sprintf_char_precision);
  tcase_add_test(tc, sprintf_char_flags);
  tcase_add_test(tc, sprintf_char_width);
  tcase_add_test(tc, sprintf_char_many);
  tcase_add_test(tc, sprintf_char_many_flags);
  tcase_add_test(tc, sprintf_char2);
  tcase_add_test(tc, sprintf_char_many2);

  tcase_add_test(tc, sprintf_string);
  tcase_add_test(tc, sprintf_string_precision);
  tcase_add_test(tc, sprintf_string_width);
  tcase_add_test(tc, sprintf_string_flags);
  tcase_add_test(tc, sprintf_string_long);
  tcase_add_test(tc, sprintf_string_many);
  tcase_add_test(tc, sprintf_string_width_huge);
  tcase_add_test(tc, sprintf_string_one);
  tcase_add_test(tc, sprintf_string_many2);
  tcase_add_test(tc, sprintf_string_width_huge);

  tcase_add_test(tc, sprintf_octal_width);
  tcase_add_test(tc, sprintf_octal_flags);
  tcase_add_test(tc, sprintf_octal_precision);
  tcase_add_test(tc, sprintf_octal_many_flags);
  tcase_add_test(tc, sprintf_octal_short);
  tcase_add_test(tc, sprintf_octal_long);
  tcase_add_test(tc, sprintf_octal_many);
  tcase_add_test(tc, sprintf_octal);
  tcase_add_test(tc, sprintf_octal_zero);
  tcase_add_test(tc, sprintf_octal_hash);

  tcase_add_test(tc, sprintf_hex_width);
  tcase_add_test(tc, sprintf_hex_flags);
  tcase_add_test(tc, sprintf_hex_precision);
  tcase_add_test(tc, sprintf_hex_many);
  tcase_add_test(tc, sprintf_hex_many_flags);
  tcase_add_test(tc, sprintf_hex_zero);
  tcase_add_test(tc, sprintf_hex_huge);
  tcase_add_test(tc, sprintf_hex_short);
  tcase_add_test(tc, sprintf_hex_long);
  tcase_add_test(tc, sprintf_hex_one_longer_width);
  tcase_add_test(tc, sprintf_hex_two_longer_width);

  tcase_add_test(tc, sprintf_ptr);
  tcase_add_test(tc, sprintf_ptr_width);
  tcase_add_test(tc, sprintf_ptr_precision);
  tcase_add_test(tc, sprintf_ptr_null);

  tcase_add_test(tc, sprintf_n_specifier);

  tcase_add_test(tc, strlen_test0);
  tcase_add_test(tc, strlen_empty);
  tcase_add_test(tc, strlen_meow);
  tcase_add_test(tc, strlen_num);
  tcase_add_test(tc, strlen_string);
  tcase_add_test(tc, strlen_meow_meow_meow);
  tcase_add_test(tc, strlen_i_leven_maier);
  tcase_add_test(tc, strlen_i_leven_maier2);
  tcase_add_test(tc, strlen_school);
  tcase_add_test(tc, strlen_abbey_downton);
  tcase_add_test(tc, strlen_so_heiss);

  tcase_add_test(tc, strcmp_1);
  tcase_add_test(tc, strcmp_2);
  tcase_add_test(tc, strcmp_3);
  tcase_add_test(tc, strcmp_Heloboba_Heloboba);
  tcase_add_test(tc, strcmp_HEloboba_Heloboba);
  tcase_add_test(tc, strcmp_Hel0boba_Helob0ba);
  tcase_add_test(tc, strcmp_Heloboba_);
  tcase_add_test(tc, strcmp__Heloboba);
  tcase_add_test(tc, strcmp_Heloboba);
  tcase_add_test(tc, strcmp_empty);
  tcase_add_test(tc, strcmp_only_num);

  tcase_add_test(tc, strncmp_1);
  tcase_add_test(tc, strncmp_2);
  tcase_add_test(tc, strncmp_3);
  tcase_add_test(tc, strncmp_empty);
  tcase_add_test(tc, strncmp_floppa_);
  tcase_add_test(tc, strncmp__floppa);
  tcase_add_test(tc, strncmp_floppa_floppa);
  tcase_add_test(tc, strncmp_floppa_floppa_zero_byte);
  tcase_add_test(tc, strncmp_floppa_floppa_one_byte);

  tcase_add_test(tc, strstr_1);
  tcase_add_test(tc, strstr_2);
  tcase_add_test(tc, strstr_3);
  tcase_add_test(tc, strstr_empty_string_haystack_and_needle);
  tcase_add_test(tc, strstr_empty_string_haystack);
  tcase_add_test(tc, strstr_empty_string_needle);
  tcase_add_test(tc, strstr_toxic_test);
  tcase_add_test(tc, strstr_not_word_in_haystack);
  tcase_add_test(tc, strstr_words_with_any_register);
  tcase_add_test(tc, strstr_repeated_words);
  tcase_add_test(tc, strstr_word_at_end);
  tcase_add_test(tc, strstr_one_simbol_in_needle_and_haystack);
  tcase_add_test(tc, strstr_one_simbol_in_needle);
  tcase_add_test(tc, strstr_one_simbol_in_haystack);

  tcase_add_test(tc, memcmp_test0);
  tcase_add_test(tc, memcmp_test1);
  tcase_add_test(tc, memcmp_test2);
  tcase_add_test(tc, memcmp_zero_byte);
  tcase_add_test(tc, memcmp_first_byte_in_string);
  tcase_add_test(tc, memcmp_register_test);
  tcase_add_test(tc, memcmp_zero_byte_in_num);
  tcase_add_test(tc, memcmp_first_byte_in_num);
  tcase_add_test(tc, memcmp_two_byte_in_num);
  tcase_add_test(tc, memcmp_two_byte_long_two_num);
  tcase_add_test(tc, memcmp_two_byte_long_first_num);
  tcase_add_test(tc, memcmp_eq_long_string);
  tcase_add_test(tc, memcmp_not_eq_long_string);

  tcase_add_test(tc, memcpy_test0);
  tcase_add_test(tc, memcpy_love_test);
  tcase_add_test(tc, memcpy_zero_test_string);
  tcase_add_test(tc, memcpy_any_empty);
  tcase_add_test(tc, memcpy_zero_test_string_with_register);
  tcase_add_test(tc, memcpy_zero_test_num);
  tcase_add_test(tc, memcpy_one_byte_string);
  tcase_add_test(tc, memcpy_one_byte_string_with_register);
  tcase_add_test(tc, memcpy_one_byte_num);
  tcase_add_test(tc, memcpy_basic_long_string);
  tcase_add_test(tc, memcpy_long_string_with_register);
  tcase_add_test(tc, memcpy_long_string_with_register_and_num);
  tcase_add_test(tc, memcpy_long_string_with_register_and_num_and_symbol);

  tcase_add_test(tc, memmove_test0);
  tcase_add_test(tc, memmove_empty_dest_and_src);
  tcase_add_test(tc, memmove_empty_dest);
  tcase_add_test(tc, memmove_empty_src);
  tcase_add_test(tc, memmove_write_in_left);
  tcase_add_test(tc, memmove_write_in_right);
  tcase_add_test(tc, memmove_write_in_mid);
  tcase_add_test(tc, memmove_overlap_write_in_left);
  tcase_add_test(tc, memmove_overlap_write_in_right);
  tcase_add_test(tc, memmove_overlap_write_in_mid);
  tcase_add_test(tc, memmove_zero_test_string);
  tcase_add_test(tc, memmove_any_empty);
  tcase_add_test(tc, memmove_zero_test_string_with_register);
  tcase_add_test(tc, memmove_zero_test_num);
  tcase_add_test(tc, memmove_one_byte_string);
  tcase_add_test(tc, memmove_one_byte_string_with_register);
  tcase_add_test(tc, memmove_one_byte_num);
  tcase_add_test(tc, memmove_basic_long_string);
  tcase_add_test(tc, memmove_long_string_with_register);
  tcase_add_test(tc, memmove_long_string_with_register_and_num);
  tcase_add_test(tc, memmove_long_string_with_register_and_num_and_symbol);
  tcase_add_test(tc, memmove_ints);
  tcase_add_test(tc, memmove_floats);

  tcase_add_test(tc, memchr_1);
  tcase_add_test(tc, memchr_empty_str);
  tcase_add_test(tc, memchr_find_zero_in_string);
  tcase_add_test(tc, memchr_find_simbol_in_string_in_start);
  tcase_add_test(tc, memchr_find_simbol_in_string_in_end);
  tcase_add_test(tc, memchr_find_num_in_string_in_mid);
  tcase_add_test(tc, memchr_find_num_in_array_num);
  tcase_add_test(tc, memchr_find_float_in_array);
  tcase_add_test(tc, memchr_easy_test_string);

  tcase_add_test(tc, memset_test0);
  tcase_add_test(tc, memset_heiss_test);
  tcase_add_test(tc, memset_zero_byte);
  tcase_add_test(tc, memset_empty);
  tcase_add_test(tc, memset_replace_on_register_sim);
  tcase_add_test(tc, memset_replace_on_register_num);
  tcase_add_test(tc, memset_long_string);

  tcase_add_test(tc, strcat_hello_world);
  tcase_add_test(tc, strcat_zero_first);
  tcase_add_test(tc, strcat_zero_last);
  tcase_add_test(tc, strcat_any_letters_with_register);
  tcase_add_test(tc, strcat_any_letters_with_register_and_num);
  tcase_add_test(tc, strcat_any_letters_with_register_and_num_and_sim);

  tcase_add_test(tc, strrchr_1);
  tcase_add_test(tc, strrchr_2);
  tcase_add_test(tc, strrchr_3);
  tcase_add_test(tc, strrchr_4);
  tcase_add_test(tc, strrchr_5);
  tcase_add_test(tc, strrchr_6);
  tcase_add_test(tc, strrchr_7);
  tcase_add_test(tc, strrchr_empty);
  tcase_add_test(tc, strrchr_poki_doki_o);
  tcase_add_test(tc, strrchr_poki_doki_i);
  tcase_add_test(tc, strrchr_poki_doki_p);
  tcase_add_test(tc, strrchr_find_big_P);
  tcase_add_test(tc, strrchr_find_zero);

  tcase_add_test(tc, strchr_1);
  tcase_add_test(tc, strchr_2);
  tcase_add_test(tc, strchr_3);
  tcase_add_test(tc, strchr_mcavoy_find_a);
  tcase_add_test(tc, strchr_mcavoy_find_A);
  tcase_add_test(tc, strchr_mcavoy_find_1);
  tcase_add_test(tc, strchr_mcavoy_find_Z);
  tcase_add_test(tc, strchr_mcavoy_find_3);
  tcase_add_test(tc, strchr_empty_src);

  tcase_add_test(tc, strpbrk_1);
  tcase_add_test(tc, strpbrk_2);
  tcase_add_test(tc, strpbrk_3);
  tcase_add_test(tc, strpbrk_empty);
  tcase_add_test(tc, strpbrk_floppy_);
  tcase_add_test(tc, strpbrk__floppy);
  tcase_add_test(tc, strpbrk_poki_doki_o);
  tcase_add_test(tc, strpbrk_poki_doki_i);
  tcase_add_test(tc, strpbrk_poki_doki_p);
  tcase_add_test(tc, strpbrk_find_big_P);
  tcase_add_test(tc, strpbrk_find_zero);

  tcase_add_test(tc, strncpy_1);
  tcase_add_test(tc, strncpy_2);
  tcase_add_test(tc, strncpy_3);
  tcase_add_test(tc, strncpy_empty);
  tcase_add_test(tc, strncpy_zero_byte);
  tcase_add_test(tc, strncpy_empty_src);
  tcase_add_test(tc, strncpy_one_byte);
  tcase_add_test(tc, strncpy_two_byte);
  tcase_add_test(tc, strncpy_string);

  tcase_add_test(tc, strncat_1);
  tcase_add_test(tc, strncat_2);
  tcase_add_test(tc, strncat_3);
  tcase_add_test(tc, strncat_all_empty);
  tcase_add_test(tc, strncat_zero_byte);
  tcase_add_test(tc, strncat_empty_src);
  tcase_add_test(tc, strncat_cd_abosa);
  tcase_add_test(tc, strncat_string);
  tcase_add_test(tc, strncat_school);
  tcase_add_test(tc, strncat_school2);
  tcase_add_test(tc, strncat_school3);
  tcase_add_test(tc, strncat_school4);
  tcase_add_test(tc, strncat_zero_char);

  tcase_add_test(tc, strspn_1);
  tcase_add_test(tc, strspn_2);
  tcase_add_test(tc, strspn_3);
  tcase_add_test(tc, strspn_empty);
  tcase_add_test(tc, strspn_dima_);
  tcase_add_test(tc, strspn__dima);
  tcase_add_test(tc, strspn_any_register);
  tcase_add_test(tc, strspn_num_num);
  tcase_add_test(tc, strspn_long_num_num);
  tcase_add_test(tc, strspn_num_long_num);
  tcase_add_test(tc, strspn_any_num);
  tcase_add_test(tc, strspn_num_with_letter);
  tcase_add_test(tc, strspn_num_with_letter2);
  tcase_add_test(tc, strspn_basic_test);
  tcase_add_test(tc, strspn_any_sim);
  tcase_add_test(tc, strspn_upper_letter);
  tcase_add_test(tc, strspn_lower_letter);
  tcase_add_test(tc, strspn_not_uniq_sim);

  tcase_add_test(tc, strcspn_1);
  tcase_add_test(tc, strcspn_2);
  tcase_add_test(tc, strcspn_3);
  tcase_add_test(tc, strcspn_empty);
  tcase_add_test(tc, strcspn_dima2);
  tcase_add_test(tc, strcspn_dima1);
  tcase_add_test(tc, strcspn_any_register);
  tcase_add_test(tc, strcspn_num_num);
  tcase_add_test(tc, strcspn_long_num_num);
  tcase_add_test(tc, strcspn_num_long_num);
  tcase_add_test(tc, strcspn_any_num);
  tcase_add_test(tc, strcspn_num_with_letter);
  tcase_add_test(tc, strcspn_num_with_letter2);
  tcase_add_test(tc, strcspn_basic_test);
  tcase_add_test(tc, strcspn_any_sim);
  tcase_add_test(tc, strcspn_upper_letter);
  tcase_add_test(tc, strcspn_lower_letter);
  tcase_add_test(tc, strcspn_not_uniq_sim);

  tcase_add_test(tc, strcpy_1);
  tcase_add_test(tc, strcpy_charles_leclerc);
  tcase_add_test(tc, strcpy_leclerc);
  tcase_add_test(tc, strcpy_meowmeow);
  tcase_add_test(tc, strcpy_empty);
  tcase_add_test(tc, strcpy_empty_num);
  tcase_add_test(tc, strcpy_hello);
  tcase_add_test(tc, strcpy_over_string);
  tcase_add_test(tc, strcpy_hard_test);

  tcase_add_test(tc, strtok_1);
  tcase_add_test(tc, strtok_2);
  tcase_add_test(tc, strtok_3);
  tcase_add_test(tc, strtok_correct_token_string);
  tcase_add_test(tc, strtok_hard_token_string);
  tcase_add_test(tc, strtok_unary_delimiters);
  tcase_add_test(tc, strtok_no_delims);
  tcase_add_test(tc, strtok_only_delims);
  tcase_add_test(tc, strtok_too_many_uses_non_segfault);
  tcase_add_test(tc, strtok_even_n_of_delims);
  tcase_add_test(tc, strtok_odd_n_of_delims);
  tcase_add_test(tc, strtok_mixed_n_of_delims);
  tcase_add_test(tc, strtok_hard_mixed);
  tcase_add_test(tc, strtok_mixed_hard_incorrect);
  tcase_add_test(tc, strtok_very_hard_mixed);

  tcase_add_test(tc, to_upper_test0);
  tcase_add_test(tc, to_upper_test1);
  tcase_add_test(tc, to_upper_test2);
  tcase_add_test(tc, to_upper_test3);
  tcase_add_test(tc, to_upper_test4);
  tcase_add_test(tc, to_upper_test5);
  tcase_add_test(tc, to_upper_test6);

  tcase_add_test(tc, to_lower_test0);
  tcase_add_test(tc, to_lower_test1);
  tcase_add_test(tc, to_lower_test2);
  tcase_add_test(tc, to_lower_test3);
  tcase_add_test(tc, to_lower_test4);
  tcase_add_test(tc, to_lower_test5);
  tcase_add_test(tc, to_lower_test6);

  tcase_add_test(tc, insert_test0);
  tcase_add_test(tc, insert_test1);
  tcase_add_test(tc, insert_test2);
  tcase_add_test(tc, insert_test3);
  tcase_add_test(tc, insert_test4);
  tcase_add_test(tc, insert_test5);
  tcase_add_test(tc, insert_test6);

  tcase_add_test(tc, trim_all_empty);
  tcase_add_test(tc, trim_str_empty);
  tcase_add_test(tc, trim_empty);
  tcase_add_test(tc, trim_and_str_eq);
  tcase_add_test(tc, trim_test1);
  tcase_add_test(tc, trim_test2);
  tcase_add_test(tc, trim_test3);
  tcase_add_test(tc, trim_test4);
  tcase_add_test(tc, trim_test5);
  tcase_add_test(tc, trim_empty_spaces);
  tcase_add_test(tc, trim_null_ptr_trim_chars);

  tcase_add_test(tc, strerror1);
  tcase_add_test(tc, strerror2);
  tcase_add_test(tc, strerror3);
  tcase_add_test(tc, strerror4);
  tcase_add_test(tc, strerror5);
  tcase_add_test(tc, strerror6);

  suite_add_tcase(s, tc);
  return s;
}

int main(void) {
  setlocale(LC_ALL, "");
  int nf;
  Suite *s1;
  SRunner *sr;
  s1 = suite_insert();
  sr = srunner_create(s1);
  srunner_run_all(sr, CK_ENV);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_VERBOSE);

  nf = srunner_ntests_failed(sr);
  srunner_free(sr);
  return nf == 0 ? 0 : 1;
}
