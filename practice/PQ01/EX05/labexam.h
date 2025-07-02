#ifndef LAB_EXAM_205_206_H
#define LAB_EXAM_205_206_H

typedef struct {
  char c;
  int n;
} char_int; 

// gets a string, and finds the most frequent char in the string
// returns the most frequent char and the number of times it appears
// in case of a tie, any of the most common chars will be accepted
char_int most_frequent(const char* str);  


// the function gets an array of ints of length n, and a predicate
// for each entry a[i]: if pred(ar[i]) is true, it remains unchanged
// and if pred(ar[i]) is false, then it is changed to zero
// the function returns the number of changed entries
int filter_to_zero(int* ar, int n, bool(*pred)(int)); 


// gets ar1 and ar2 of length n
// returns a new array SUM of length n, where SUM[i] = ar1[i] + ar2[i]
int* sum_arrays(const int* ar1, const int* ar2, int n); 

#endif
