#include <stdlib.h>

#include "prototypes.h"

void cat(int argc, char **argv, struct options *p_opt, int count) {
  FILE *fp;

  char buffer;
  int line = 1;
  int newLine = 1;

  for (int i = 1 + count; i < argc; i++)  // проверяем существует ли файл
  {
    if ((fp = fopen(argv[i], "r")) != NULL) {
      while ((buffer = fgetc(fp)) != EOF) {
        if ((buffer == '\n') && (newLine > 1) && (p_opt->s)) {
          continue;
        }
        if ((newLine) && (p_opt->n)) printf("%6d\t", line++);

        if ((buffer != '\n') && (newLine) && (p_opt->b)) {
          printf("%6d\t", line++);
          newLine = 0;
        }

        if ((p_opt->t) && (buffer == '\t')) {
          printf("^I");
          newLine = 0;
          continue;
        }

        if ((buffer == '\n') && (p_opt->e)) printf("$");

        if (p_opt->v) {
          if (((buffer < '\t') || (buffer > '\n')) && (buffer < 32)) {
            printf("%c", '^');
            buffer += 64;
          } else if (buffer == 127) {
            printf("^");
            buffer = '?';
          }
        }
        if (buffer == '\n')
          newLine++;
        else
          newLine = 0;

        putchar(buffer);
      }
      line = 1;
    } else {
      fprintf(stderr, "s_21cat: %s: No such file or directory\n", argv[i]);
      fclose(fp);
    }
  }

  fclose(fp);
}