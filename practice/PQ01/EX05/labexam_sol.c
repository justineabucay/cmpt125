#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "labexam.h"

int count_c(const char* str, int len, char c) {
  int count = 0;
  for (int i = 0; i < len; i++)
    if (str[i]==c)
      count++;

  return count;
}

char_int most_frequent(const char* str) {
  int len = strlen(str);

  char_int ret;
  ret.c = '\0';
  ret.n = 0;
  for (int i = 0; i < len; i++) {
    int count = count_c(str,len,str[i]);
    if (count > ret.n) {
      ret.c = str[i];
      ret.n = count;
    }
  }
  return ret;
}


int filter_to_zero(int* ar, int n, bool(*pred)(int)) {
  int count = 0;
  for (int i = 0; i < n; i++)
    if (pred(ar[i])==false) {
      ar[i]=0;
      count++;
    }
  
  return count;
}


int* sum_arrays(const int* ar1, const int* ar2, int n) {
  int* ret = (int*) malloc(n*sizeof(int));
  if (!ret)
    return NULL;

  for (int i = 0; i < n; i++)
    ret[i] = ar1[i] + ar2[i];
  
  return ret;
}  
