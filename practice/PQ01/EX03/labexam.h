#ifndef LAB_EXAM_203_204_H
#define LAB_EXAM_203_204_H

#include <stdbool.h>

// gets an array of ints
// checks if the numbers are sorted in non-decreasing order
bool check_non_decreasing(int* arr, int n);  


// gets an array A of length n
// returns a new array that contains all entries of A in the reverse order
int* rev_arr(const int* A, int n); 


// the function gets an array of strings of length n>0
// and returns the number of distinct strings in the array
int count_distinct(const char** ar, int n); 

#endif
