#include <stdio.h>
#ifndef SRC_CAT_CAT_H_
#define SRC_CAT_CAT_H_

struct options {
  int b;
  int e;
  int n;
  int s;
  int t;
  int v;
};

int pars(int argc, char **argv, struct options *p_opt, int count);
int pars_gnu(char *str, struct options *p_opt);
int pars_mac(int i, char **argv, struct options *p_opt);

void cat(int argc, char **argv, struct options *p_opt, int count);

#endif  //  SRC_CAT_CAT_H_s