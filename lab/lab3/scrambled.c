/*
filename: scrambled.c
description: write a function that returns 1 if arr1 and arr2 contain the same values or 0 otherwise
date: june 9, 2025
author: Justine Abucay 301540624
*/

#include <stdio.h>
#define LENGTH 100

unsigned int scrambled(int arr1[], int arr2[], unsigned int size)
{
    int count[LENGTH] = {0};
    for (unsigned int i = 0; i < size; i++)
    {
        count[arr1[i]]++; // counting how many times the value occurs
        count[arr2[i]]--; // subtract count for each value that occurs in the second array
    }

    for (int i = 0; i < LENGTH; i++) // check if all counts are zero
    {
        if (count[i] != 0)
            return 0;   // if not all counts are zero, arrays are different
    }

    return 1; // all counts are zero and therefore, arrays have identical values
}

void printArray(int arr[], unsigned int size, char *arrayName)
{
    printf("%s = {", arrayName);
    for(unsigned int i = 0; i < size; i++)
    {
        printf("%d", arr[i]); 
        if(i < size - 1) printf(", "); // every element but the last one, add a comma
    }
    printf("}");
}

void getResults(int arr1[], int arr2[], unsigned int size1, unsigned int size2)
{
    // printing out the arrays 
    printArray(arr1, size1, "arr1");
    printf(", ");
    printArray(arr2, size2, "arr2");
    
    if(size1 == size2) { // checking if arrays have identical size
        if (scrambled(arr1, arr2, size1) == 1)
            printf(" have the same values and therefore, are identical.\n");
        else  
            printf(" have different values and therefore, not identical.\n");
    } else {   // if their size is different, let users know
        printf(" have different sizes and therefore, not identical.\n");
    }
    printf("\n");
}

int main(void)
{
    // test case 1: the two arrays are not identical (different values)
    printf("test case #1\n");
    int test1_arr1[] = {1, 1};
    int test1_arr2[] = {1, 2};

    /* 
    finding the number of elements in the array:
    https://www.w3schools.com/c/c_arrays_size.php
    */
   
    unsigned int test1_size1 = sizeof(test1_arr1) / sizeof(test1_arr1[0]); 
    unsigned int test1_size2 = sizeof(test1_arr2) / sizeof(test1_arr2[0]);
    
    getResults(test1_arr1, test1_arr2, test1_size1, test1_size2);

    // test case 2: arrays are identical but scrambled
    printf("test case #2\n");
    int test2_arr1[] = {24, 0, 1};
    int test2_arr2[] = {0, 24, 1};
    unsigned int test2_size1 = sizeof(test2_arr1) / sizeof(test2_arr1[0]);
    unsigned int test2_size2 = sizeof(test2_arr2) / sizeof(test2_arr2[0]);
    
    getResults(test2_arr1, test2_arr2, test2_size1, test2_size2);

    // test case 3: arrays with different sizes
    printf("test case #3\n");
    int test3_arr1[] = {1, 2, 3};
    int test3_arr2[] = {1, 2};
    unsigned int test3_size1 = sizeof(test3_arr1) / sizeof(test3_arr1[0]);
    unsigned int test3_size2 = sizeof(test3_arr2) / sizeof(test3_arr2[0]);
    
    getResults(test3_arr1, test3_arr2, test3_size1, test3_size2);

    // test case #4: arrays are empty (i.e., length = 0)
    printf("test case #4\n");
    int test4_arr1[] = {};
    int test4_arr2[] = {};
    unsigned int test4_size1 = sizeof(test4_arr1) / sizeof(test4_arr1[0]);
    unsigned int test4_size2 = sizeof(test4_arr2) / sizeof(test4_arr2[0]);
    
    getResults(test4_arr1, test4_arr2, test4_size1, test4_size2);

    return 0;
}