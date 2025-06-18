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



