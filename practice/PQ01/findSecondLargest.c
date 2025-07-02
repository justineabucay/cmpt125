/*
 * Filename: findSecondLargest.c
 *
 * Description: create a function that find the second largest in the array
 *
 * Author: AL
 * Date: June 2025
 */

 // step through each element in an array
 // declare two variables: first, which will hold the largest value and then second, which will hold the second largest

// take the first element of the array and set it to first, and take the second element and assign it to second. 

// condition: 
// - if the current element is smaller than first but bigger second, set second to the current element
// - if the current element is bigger than first, then set first to the current element and set the prev. first to the second element

#include <stdio.h>  // printf()

int findSecondLargest(int arr[], unsigned int size){
    
    int first = arr[0];
    int second = arr[1];

    if(second > first) first = second;
    
    for(int i = 0; i < size; i++)
    {
        int temp = first; 
        int curr = arr[i];
        if(curr > second && curr < first)
            second = curr; 
        else if(curr > first){
            first = curr;
            second = temp;
        } 
    }

    if(first == second) return -1;

    return second;
}

int main(void)
{
    int test1_arr1[] = {5, 2, 8, 1, 9};
    int size = 5;

    printf("current array we are testing: ");
    for(int i = 0; i < size; i++) printf("%d ", test1_arr1[i]);
    printf("\nthe second largest number in the array: %d\n", findSecondLargest(test1_arr1, size));

    int test2_arr1[] = {3, 3, 3};
    size = 3;

    printf("current array we are testing: ");
    for(int i = 0; i < size; i++) printf("%d ", test2_arr1[i]);
    printf("\nthe second largest number in the array: %d\n", findSecondLargest(test2_arr1, size));

    int test3_arr1[] = {10, 5, 5, 3, 10};
    size = 5;

    printf("current array we are testing: ");
    for(int i = 0; i < size; i++) printf("%d ", test3_arr1[i]);
    printf("\nthe second largest number in the array: %d\n", findSecondLargest(test3_arr1, size));
}

