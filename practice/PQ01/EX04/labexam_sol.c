#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "labexam.h"


bool is_vowel(char c) {
  return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}
int hide_vowels(char** arr, int n) {
  int count = 0;
  for (int i = 0; i < n; i++) {
    int len = strlen(arr[i]);
    for (int j = 0; j < len; j++)
      if (is_vowel(arr[i][j])) {
        arr[i][j] = '*';
        count++;
      }
  }
  
  return count;
}

int sum_ith_column(int height, int width, const int ar[height][width], int i) {
  int sum = 0;
  for (int j = 0; j < height; j++)
    sum += ar[j][i];
  
  return sum;
}


int* sum_columns(int height, int width, const int ar[height][width]) {
  int* sum = (int*) malloc(width*sizeof(int));
  if (!sum)
    return NULL;

  for (int i = 0; i < width; i++)
    sum[i] = sum_ith_column(height, width, ar, i);
  
  return sum; 
}


int longest_increasing_seq(const int* ar, int n) {
  int max = 0;
  int current_seq = 1;
  for (int i = 1; i < n; i++) {
    if (ar[i] > ar[i-1])
      current_seq++;
    else {
      if (current_seq>max)
        max = current_seq;
      current_seq = 1; // reset to 1
    }
  }
  
  return max;
}  
