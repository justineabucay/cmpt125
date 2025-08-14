#ifndef POINTER_H
#define POINTER_H

void basic_pointer();
void addressVsValue();
void doubleVal(int *x);
void swapVal(int *a, int *b);
void findMinMax(int a, int b, int c, int *min_val, int *max_val);
int sumArr(int *arr, int size);
void doubleArray(int *arr, int size);  // Fixed: removed void* return, simplified parameter
void printAll(int *arr, int size);     // Fixed: removed void* return, simplified parameter
int *findNegative(int *arr, int size); // Fixed: simplified parameter
int *getRandomArray(int *reportSize);
void resetVal(unsigned int *x);
void increment(unsigned int *ptr);
int *getLarger(int *a, int *b);
int stringLength(char *str);
void stringCopy(char *dest, char *src);
int *findMinAddress(int *arr, int size);
int *reverseArr(int *arr, int size);
int arraysEqual(int *arr1, int *arr2, int size);

#endif