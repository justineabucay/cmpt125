#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "labexam.h"


min_max get_min_max(int* arr, int n) { 
  // implement me
  min_max ret;
  ret.min = arr[0];
  ret.max = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] < ret.min)
      ret.min = arr[i];
    else if (arr[i] > ret.max)
      ret.max = arr[i];
  }

  return ret;
}


bool equal_cols(int height, int width, const int ar[height][width], int c1, int c2) {
  for (int i = 0; i < height; i++)
    if (ar[i][c1] != ar[i][c2])
      return false;

  return true;  
}
bool has_equal_columns(int height, int width, const int ar[height][width]) {
  for (int c1 = 0; c1 < width; c1++)
    for (int c2 = c1+1; c2 < width; c2++)
      if (equal_cols(height, width, ar, c1, c2))
        return true;

  return false;
}


int* map_to_new_array(const int* ar, int n, int(*foo)(int)) {
  int* ret = (int*) malloc(n*sizeof(int));
  if (!ret)
    return NULL; 

  for (int i = 0; i < n; i++)
    ret[i] = foo(ar[i]);
  
  return ret;
}  
