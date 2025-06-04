/*
filename: Array_Notation_to_Pointer_Notation.c
description: converting array notation to pointer notation
author: justine abucay
date: june 4, 2025
*/

#include <stdio.h>

int main()
{
    const unsigned int ARRAY_SIZE = 5; 
    int arr[ARRAY_SIZE];

    printf("\nprinting arr using array notation"); // print arr using array notation
    for(int unsigned i = 0; i < ARRAY_SIZE; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\nprinting arr using pointer notation:");
    for(int unsigned i = 0; i < ARRAY_SIZE; i++)
    {
        printf("%d ", *(arr + i));
    }

    printf("\nboth versions will print out the same results"); 
    printf("\n\n");

    return 0; 
    
}

