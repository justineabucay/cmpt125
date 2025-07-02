#ifndef LAB_EXAM_207_208_H
#define LAB_EXAM_207_208_H

#include <stdbool.h>

// the function gets an array of strings of length n
// and modifies each string by changing all *lower case* vowels into asterisk
// the function returns the total number of modified chars
// The vowels are: {a,e,i,o,u} 
int hide_vowels(char** arr, int n);


// gets a 2d array of ints
// it returns an array SUM
// such that SUM[i] contains the sum of all values in the i'th column
int* sum_columns(int height, int width, const int ar[height][width]);


// the function gets an array of ints of length n>0
// and returns the length of the longest increasing subarray
// for example, on input [3,1,2,4,7,1,1,8,8,10,1,2,9]
// the function returns 3 because the longest increasing subarray is [1,2,4,7]
int longest_increasing_seq(const int* ar, int n); 

#endif
