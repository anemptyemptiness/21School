#include <stdio.h>
#ifndef SRC_GREP_GREP_H_
#define SRC_GREP_GREP_H_

struct flags {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
};

int grep(int *error, char **argv, struct flags *p_struct, char *buff_args,
         char **p_files, int count);

#endif  //  SRC_GREP_GREP_H_s
