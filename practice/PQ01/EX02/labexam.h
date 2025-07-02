#ifndef LAB_EXAM_201_202_H
#define LAB_EXAM_201_202_H

#include <stdbool.h>

typedef struct {
  int min;
  int max;
} min_max;

// gets an array of ints
// and returns the minimum and the maximum of the array
// the returned values are stored using the struct min_max
min_max get_min_max(int* arr, int n); 


// gets a 2d array of ints
// returns true if the array contains two equal columns
bool has_equal_columns(int height, int width, const int ar[height][width]);
bool compareCol1D(const int *ar, int height, int width, int col1, int col2);
// the function gets an array of ints of length n, and a function foo
// and returns a new array (on the heap) of the same length
// where ret[i] = foo(ar[i]) for all i
int* map_to_new_array(const int* ar, int n, int(*foo)(int));

#endif
