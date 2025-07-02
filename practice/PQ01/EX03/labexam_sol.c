#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "labexam.h"


bool check_non_decreasing(int* arr, int n) {
  for (int i = 0; i < n-1; i++)
    if (arr[i] > arr[i+1])
      return false;
  
  return true;
}


int* rev_arr(const int* A, int n) {
  int* ret = (int*) malloc(n*sizeof(int));
  if (!ret)
    return NULL;

  for (int i = 0; i < n; i++)
    ret[i] = A[n-1-i];
  
  return ret;
}


int count_distinct(const char** ar, int n) {
  int count = 0;
  bool is_duplicate;
  for (int i = 0; i < n; i++) {
    is_duplicate = false;
    for (int j = 0; j < i; j++) {
      if (strcmp(ar[i],ar[j])==0)
        is_duplicate = true;
    }
    if (!is_duplicate)
      count++;
  }
  
  return count;
}  
