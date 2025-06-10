/*
filename: scrambled.c
description: write a function that returns 1 if arr1 and 2 contain the same values or 0 otherwise
date: june 9, 2025
author: justine abucay 30150426
*/

#include <stdio.h>
#define LENGTH 100

unsigned scrambled(int arr1[], int arr2[], unsigned int size)
{
    int count[LENGTH] = {0};
    for (int i = 0; i < size; i++)
    {
        count[arr1[i]]++; // counting how many times the value occurs
        count[arr2[i]]--; // subtract count for each value that occurs in the second array
    }

    for (int i = 0; i < LENGTH; i++) // check if all counts are zero
    {
        if (count[i] != 0)
            return 0;   // if not all counts are zero, array are different
    }

    return 1; // all counts are zero and therefore, arrays have identical values
}

int main(void)
{
    int arr1[] = {1, 1};
    int arr2[] = {1, 1, 3};

    //  counting how many elements in each array
    int size1 = sizeof(arr1) / sizeof(arr1[0]); 
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    // checking if arrays have identical size
    if (size1 == size2)
    {
        printf("Result: %d\n", scrambled(arr1, arr2, size1));
    }
    else
    // if their size is different, let users know
        printf("The size of arr1 and arr2 are not identical.\n");

    return 0;
}
