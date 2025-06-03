
/*
filename: reverse.c
description: write a program that reverses the contents of an array in place
author: justine abucay 30150426
date: june 3, 2025
*/

#include <stdio.h>

int main(void)
{
    int const LENGTH = 10;

    int arr[LENGTH];

    int count = 0; 

    // ask for user input 
    printf("Please, enter 10 integers then press Enter: ");


    for(int i = 0; i < LENGTH; i++){
        if(scanf("%d", &arr[i]) == 1)
            count++;
    }

    printf("Content of array before reversing: ");
    for(int i = 0; i < count; i++){
       printf("%d ", arr[i]);
    }

    printf("\nContent of array after reversing: ");
    for(int i = 0; i < count/2; i++) // find the middle
    {
        int temp = arr[i]; // remember the current position 
        arr[i] = arr[count - 1 - i]; // swap the start position with the end position
        arr[count - 1 - i] = temp; //  finally, swap the end position with the position saved
    }

    for(int i = 0; i < count; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}