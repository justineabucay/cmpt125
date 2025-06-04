/*
filename: Toying_with_Arrays.case
description: toying with arrays.
author: justine abucay
date: june 4, 2025
*/

#include <stdio.h>

int main()
{
    const unsigned int ARRAY_SIZE = 5; // where ARRAY_SIZE must always be positive integer or zero
    int intArray[ARRAY_SIZE];          // declaring the array

    printf("<-- ARRAY WITH NO INITIALIZATION -->\n");

    printf("printing content of intArray without a '&' operator:\n");
    // printing intArray, which has not been initialized but set the length (or the number of elements it holds)
    for (unsigned int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("-> %d\n", intArray[i]);
    }

    // the output of printing out each element of intArray without initializing only returns garbage values 

    // however, when we use the operator '&' it should print out the memory address, as it follows: 

    printf("\nprinting content of intArray with a '&' operator:\n");
    for (unsigned int i = 0; i < ARRAY_SIZE; i++)
    {
        
        printf("-> %d\n", &intArray[i]); // edit: %d -> %p, %p means pointer/address -- or in other words, where the value is stored
    }

    printf("\n<-- ARRAY WITH INITIALIZATION -->\n"); // inititializing intArray
    
    for (unsigned int i = 0; i < ARRAY_SIZE; i++)
    {
        intArray[i] = i; // initizialing intArray w/ i 
    }

    printf("printing initialized intArray: "); // printing initialized intArray

    for (unsigned int i = 0; i < ARRAY_SIZE; i++)
    {
        intArray[i] = i; // initizialing intArray w/ i 
        printf("%d ", intArray[i]);

    }

    printf("\n\n");   

    return 0;
}