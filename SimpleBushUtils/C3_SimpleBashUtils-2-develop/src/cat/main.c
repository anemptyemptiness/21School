#include <stdio.h>
#include <stdlib.h>

#include "prototypes.h"

int main(int argc, char *argv[]) {
  struct options opt = {0};
  int count = 0;
  char ch;

  if (argc == 1) {
    while ((ch = getchar()) != EOF) putchar(ch);
  }

  if (argc > 1) {
    count = pars(
        argc, argv, &opt,
        count);  // ПАРСЕР - возвращает понимание с какого аргв начинаются файлы

    cat(argc, argv, &opt, count);  // передача файла и структуры с флагами

    return 0;
  }
}