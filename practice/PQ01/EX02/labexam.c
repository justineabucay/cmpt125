#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "labexam.h"


min_max get_min_max(int* arr, int n) { 
  // implement me
  int min = arr[0]; 
  int max = arr[0]; 

  for(int i = 0; i < n; i++)
  {

    int curr = arr[i];
    if(curr < min) min = curr;
  }

  for(int i = 0; i < n; i++)
  {

    int curr = arr[i];
    if(curr > max) max = curr;
  }

  return (min_max){min, max};
}

bool has_equal_columns(int height, int width, const int ar[height][width]) {
  // implement me
  const int *arr = &ar[0][0];
  for(int col1 = 0; col1<  width; col1++)
  {

    for(int col2 = col1+1; col2 < width; col2++){
      if(compareCol1D(arr, height, width, col1, col2)) return true;
    }
  }

  return false;
}

bool compareCol1D(const int *ar, int height, int width, int col1, int col2)
{
 
  for(int row = 0; row < height; row++){
    // covert 2D to 1D
    int index1 = row * width + col1; 
    int index2 = row * width + col2; 

    if(ar[index1] != ar[index2]) return false;  // basically, index1 and index2 act as a marker in the arr to indicate the start of each row. now, we are comparing if these columns are the same. 
  }

  return true;
}


int* map_to_new_array(const int* ar, int n, int(*foo)(int)) {
  // implement me
  int *result = malloc(n * sizeof(int));

  if(result == NULL) perror("oh no! allocation was unsuccessful.");
   
  for(int i = 0; i < n; i++){
   result[i] = foo(ar[i]);
  }
  return result;
}  
