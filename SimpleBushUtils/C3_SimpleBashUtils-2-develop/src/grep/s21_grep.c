#include "s21_grep.h"

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int var_l = 0;
int var_n = 0;
int var_c = 0;

int grep(int *error, char **argv, struct flags *p_struct, char *buff_args,
         char **p_files, int count) {
  regex_t reg;  // регекс
  regmatch_t pmatch[1];
  size_t nmatch = 1;

  int read;  // для гетлайна
  size_t len = 0;
  char *buff = NULL;
  FILE *fp;  // указатель на файловый поток

  int status = REG_EXTENDED;

  if (p_struct->i) status = REG_ICASE;

  for (int i = 0; p_files[i] != NULL && *error != 1; i++) {
    fp = fopen(p_files[i], "r");
    if (fp == NULL) {
      fprintf(stderr, "%s: %s: No such file or directory\n", argv[0],
              p_files[i]);
      *error = 1;
      continue;
    }

    while ((read = getline(&buff, &len, fp)) != -1) {
      var_n++;

      regcomp(&reg, buff_args, status);

      int result = regexec(&reg, buff, nmatch, pmatch, 0);

      if (p_struct->e && result == 0) {
        if (count == 1)
          printf("%s", buff);
        else if (count > 1)
          printf("%s:%s", p_files[i], buff);
      }

      if ((p_struct->v) && result != 0) {
        if (count == 1) {
          printf("%s", buff);
          if (buff[strlen(buff) - 1] != '\n') printf("\n");
        } else if (count > 1) {
          printf("%s:%s", p_files[i], buff);
          if (buff[strlen(buff) - 1] != '\n') printf("\n");
        }
      }

      if (p_struct->l && result == 0 && var_l == 0) {
        var_l++;
        printf("%s\n", p_files[i]);
      }

      if (p_struct->n && result == 0) {
        if (count > 1) printf("%s:%d:%s", p_files[i], var_n, buff);
        if (count == 1) printf("%d:%s", var_n, buff);
      }

      if (p_struct->h && result == 0) {
        printf("%s", buff);
      }

      if (p_struct->c && result == 0) {
        var_c++;
      }

      if (p_struct->i && result == 0) {
        if (count == 1) {
          printf("%s", buff);
          if (buff[strlen(buff) - 1] != '\n') printf("\n");
        } else if (count > 1) {
          printf("%s:%s", p_files[i], buff);
          if (buff[strlen(buff) - 1] != '\n') printf("\n");
        }
      }

      if (!p_struct->e && !p_struct->v && !p_struct->l && !p_struct->n &&
          !p_struct->h && !p_struct->c && !p_struct->i && result == 0) {
        if (count == 1)
          printf("%s", buff);
        else if (count > 1)
          printf("%s:%s", p_files[i], buff);
      }
      regfree(&reg);
    }
    if (p_struct->c) {
      if (count > 1)
        printf("%s:%d\n", p_files[i], var_c);

      else
        printf("%d\n", var_c);
      var_c = 0;
    }

    if (fp) fclose(fp);
  }
  free(buff);
  return 0;
}
