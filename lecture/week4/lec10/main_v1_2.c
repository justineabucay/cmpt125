/*
filename: main_v1_2.c
description: create a largest function and a smallest function. largest returns the larget of its twoparameters. smallest returns the smaller of its two parameters
author: justine abucay
date: june 8, 2025
*/

#include <stdio.h>

int largest(int int1, int int2); // function declaration
int smallest(int int1, int int2);

int main (void)
{
    int num1 = 0; 
    int num2 = 0; 

    // ask users to input 2 integets 
    printf("Please, enter two integers: ");
    if (scanf("%d %d", &num1, &num2)==2)
    {
         // print results
         printf("Largest of %d and %d is %d\n", num1, num2, largest(num1, num2));
         printf("Smallest of %d and %d is %d\n", num1, num2, smallest(num1, num2));
    
    }

    return 0; 
}

// returns the largest of its two parameters
int largest(int int1, int int2)
{
    int largest = int2; 
    if(int1 > int2) largest = int1; 
    
    return largest;
}
// returns the smallest of its two parameters
int smallest(int int1, int int2)
{
    int smallest = int2; 
    if(int1 < int2) smallest = int1; 
    
    return smallest;
}