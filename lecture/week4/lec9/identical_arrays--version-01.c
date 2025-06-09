/*
filename: identical_arrays--version-01.c
description: determines whether two arrays are identical or not
concept: using a flag instead of break to exit out of a loop to preserve info abt loop status
author: justine abucay
date: june 8, 2025
*/

#include <stdio.h>
#define ARRAY_SIZE 5 // defining a constant w/ a value 5

int main(void)
{
    int arrInt1[] = {1, 2, 3, 4, 5};
    int arrInt2[] = {1, 2, 3, 4, 6};

    int identical = 1; // 0 is false, while 1 is true; we start w/ 1 (i.e., true) assuming arrays are identical until proven otherwise

    // approach #1: using a break when the two arrays are not identical
    // problem: break exits the loop immediately, but we lose info abt the loop's completion; that is, we do not know whether the loop has been completed naturally (i.e., success) or it broke early (i.e., failed b/c arrays are different). therefore, it allows us to print out a message that tells us the arrays are identical
    for (unsigned int index = 0; index < ARRAY_SIZE; index++)
    {
        if (arrInt1[index] != arrInt2[index])
        {
            printf("These two arrays are not identical!\n");
            break;
        }
    }

    // approach #2: using a flag instead of a break
    // advantage: a flag allows us to preserve the result (i.e., printing a 'success' msg)
    for (unsigned int index = 0; index < ARRAY_SIZE && identical; index++)
    { // &&: the loop stops when the flag is not true (i.e., 0 or false)
        if (arrInt1[index] != arrInt2[index])
        {
            printf("These two arrays are not identical!\n");
            identical = 0; // set to false
        }
    }


    // prints out a msg oncewe know the two arrays are identical
    if (identical)
        printf("These two arrays are identical!\n");
    else if (!identical)
        printf("These two arrays are different\n");
    return 0;
}
