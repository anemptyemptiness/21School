#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_grep.h"

int main(int argc, char **argv) {
  struct flags optgrep = {0, 0, 0, 0, 0, 0, 0};

  int flag = 0;  // переменные внутри структуры

  int var = 0;

  char buff_args[4096] = {};

  char *p_files[4096] = {};

  int count = 0;

  int cmp = 0;

  int error = 0;

  while ((var = getopt_long(argc, argv, "-e:ivclnh", 0, 0)) != -1) {
    switch (var) {
      case 'e':
        optgrep.e = 1;
        if (flag == 0) {
          flag = 1;
          strcat(buff_args, optarg);
        } else {
          strcat(buff_args, "|");
          strcat(buff_args, optarg);
        }
        break;
      case 'i':
        optgrep.i = 1;
        break;
      case 'v':
        optgrep.v = 1;
        break;
      case 'c':
        optgrep.c = 1;
        break;
      case 'l':
        optgrep.l = 1;
        break;
      case 'n':
        optgrep.n = 1;
        break;
      case 'h':
        optgrep.h = 1;
        break;
      case 1:
        if (optgrep.e == 0 && cmp == 0) {
          strcat(buff_args, optarg);
          cmp = 1;
        } else
          p_files[count++] = optarg;
        break;
      case '?':
        printf("Error found !\n");
        break;
    }
    p_files[count] = NULL;
  }

  grep(&error, argv, &optgrep, buff_args, p_files, count);

  return 0;
}
