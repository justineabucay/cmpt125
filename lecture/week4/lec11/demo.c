/*
filename: demo.c
description: write a program that takes 8 integers from the user and calculates the summ of all odd integers
author: justine 30150426
date: june 9, 2025
*/

#include <stdio.h>
#define ARRAY_SIZE 8

int getIntegers(int arr[])
{
    int count = 0; 
    printf("Please, enter 8 integers. Press enter and ctrl+d to stop: ");
    for(int i = 0; i < ARRAY_SIZE; i++)
        if(scanf("%d", &arr[i])==1) count++; 
    return count;
}


int getSum(int *arr, int count)
{
    int sum = 0;
    for(int i = 0; i < count; i++)
        if(*(arr + i) % 2 == 1) sum += *(arr + i);
        

    return sum;
}

int main(void)
{
    
    int arr[ARRAY_SIZE];
    
    int count = 0;

    count = getIntegers(arr);
    

    printf("\nthe total sum of all odd integers is %d\n", getSum(arr, count));

    return 0;

}