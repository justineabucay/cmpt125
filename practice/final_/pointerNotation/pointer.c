#include <stdio.h>
#include <stdlib.h>
#include "pointer.h"

/* practicing pointer notations */
void basic_pointer()
{
    int a = 5;
    int b = 10;

    int *ptrA = &a;
    printf("printing the value of 'a': %d\n", *ptrA);
    *ptrA = 20;
    printf("printing the value of 'a' after changing the value to 20: %d\n", *ptrA);
    ptrA = &b;
    printf("printing the value of 'a' after making it point to 'b': %d\n", *ptrA);
    return;
}

void addressVsValue()
{
    int x = 42;
    int *ptr;

    ptr = &x;

    printf("value of x: %d\n", x);
    printf("address of x: %p\n", &x);
    printf("value of ptr: %p\n", ptr);
    printf("value pointed to by ptr: %d\n", *ptr);

    *ptr = 100;
    printf("new value of x: %d\n", x);

    return;
}

// function parameters w/ pointers
void doubleVal(int *x)
{
    *x *= 2;
}

void swapVal(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void findMinMax(int a, int b, int c, int *min_val, int *max_val)
{
    int arr[] = {a, b, c};

    // Initialize min and max to first element
    int min = arr[0];
    int max = arr[0];

    // Only need one loop to find min and max
    for (int i = 1; i < 3; i++)
    {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    *min_val = min;
    *max_val = max;
}

// arrays and pointers
// array access w/ pointers

int sumArr(int *arr, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    { // Changed from unsigned int
        sum += *(arr + i);
    }
    return sum;
}

// modify array elements
void doubleArray(int *arr, int size)
{                                  // Fixed: removed void* return type, changed parameter
    for (int i = 0; i < size; i++) // Fixed: removed unsigned int, simplified parameter
    {
        *(arr + i) *= 2;
    }
}

int *findNegative(int *arr, int size)
{                                  // Fixed: simplified parameter
    for (int i = 0; i < size; i++) // Fixed: removed complex condition
    {
        if (*(arr + i) < 0)
        {
            return &arr[i]; // Return pointer to first negative number found
        }
    }
    return NULL; // Return NULL if no negative number found
}

int *getRandomArray(int *reportSize)
{
    printf("enter the size of the array as an integer: ");
    unsigned int size = 0;
    if (scanf("%u", &size) != 1)
    { // Fixed: use %u for unsigned int
        perror("reading an integer (size failed)");
        exit(1);
    }

    int *theArray = malloc(size * sizeof(int));
    if (theArray == NULL)
    { // Added: check for malloc failure
        perror("malloc failed");
        exit(1);
    }

    for (unsigned int i = 0; i < size; i++)
        theArray[i] = (rand() % 101) - 50; // -50 to 50

    *reportSize = size;
    return theArray;
}

void resetVal(unsigned int* x){
    *x = 0; 
}

void increment(unsigned int *ptr){
    (*ptr)++;

}

int* getLarger(int* a, int *b){
    if(*a>*b)
        return a;
    else
        return b; 
}

// string pointer
int stringLength(char* str){
    int count = 0; 
    // validate string
    if(str == NULL) return 0; 
    while(*str){
        count++;    // increments
        str++;      // move forward to next character
    }

    return count; 
}

void stringCopy(char *dest, char *src){
    while(*src){
        *dest = *src;
        dest++;
        src++;
    }
 
    *dest = '\0';
}

int* findMinAddress(int* arr, int size){
    if(arr == NULL || size == 0) return NULL;
  
    int* returnMin = &arr[0]; // start at first element
    for(int i = 1; i < size; i++){
        if (arr[i] < *returnMin)
            returnMin = &arr[i]; // update to current min

    }
    return returnMin;
}
int* reverseArr(int* arr, int size){
    if (arr == NULL || size == 0)
        return NULL;
    for(unsigned int i = 0; i < size / 2; i++){
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }

    return arr;
}

int arraysEqual(int* arr1, int* arr2, int size);

void printAll(int *arr, int size)
{ // Fixed: removed void* return type, simplified parameter
    printf("array: {");
    for (int i = 0; i < size; i++)
    { // Fixed: simplified parameter usage
        if (i == size - 1)
            printf("%d", *(arr + i));
        else
            printf("%d, ", *(arr + i)); // Added comma for better formatting
    }
    printf("}\n"); // Added newline
}