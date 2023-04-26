#include <stdio.h>
#include <string.h>

#include "prototypes.h"

int pars(int argc, char **argv, struct options *p_opt, int count) {
  for (int i = 1; i < argc - 1; i++) {
    if (argv[i][0] == '-') {
      count++;  // счетчик дефисов
      if (pars_gnu(argv[i], p_opt)) {
        if (pars_mac(i, argv, p_opt)) {
          i = argc;
        }
      }
    }
  }
  if (p_opt->b == 1) p_opt->n = 0;

  return count;
}

int pars_gnu(char *str, struct options *p_opt)  // длинные флаги
{
  int flag = 0;

  if (!strcmp(str, "--number-nonblank")) {
    p_opt->b = 1;
  } else {
    if (!strcmp(str, "-E")) {
      p_opt->e = 1;
    } else {
      if (!strcmp(str, "--number")) {
        p_opt->n = 1;
      } else {
        if (!strcmp(str, "--squeeze-blank")) {
          p_opt->s = 1;
        } else {
          if (!strcmp(str, "-T")) {
            p_opt->t = 1;
          } else {
            flag = 1;
          }
        }
      }
    }
  }

  return flag;
}

int pars_mac(int i, char **argv,
             struct options *p_opt)  //кор флаги - цикл если их много
{
  int flag = 0;

  for (size_t j = 1; j < strlen(argv[i]); j++) switch (argv[i][j]) {
      case 'b':
        p_opt->b = 1;
        break;
      case 'e':
        p_opt->e = 1;  // если е,то и в
        p_opt->v = 1;
        break;
      case 'n':
        p_opt->n = 1;
        break;
      case 's':
        p_opt->s = 1;
        break;
      case 't':
        p_opt->t = 1;
        p_opt->v = 1;  // если е,то и в
        break;
      case 'v':
        p_opt->v = 1;
        break;
      default:
        printf("s21_cat: illegal option -- %c\n", argv[i][j]);
        printf("usage: s21_cat [-benstv] [file ...]\n");
        j = strlen(argv[i]);  // закончить обработку
        flag = 1;
    }

  return flag;
}
