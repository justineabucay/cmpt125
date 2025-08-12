#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

// part 1: dynamic memory allocation
// exercise 1.1: build malloc/free 

int* create_int_array(int size){
    int *arr = malloc(size * sizeof(int)); 
    if(arr == NULL){
        perror("oh no! allocation was not successful."); 
        exit(1);
    }

    for(unsigned int i = 0; i < size; i++)
        arr[i] = 0;     // initialize all elements to 0
    
    return arr;
        
}

int *resize_array(int *old_array, int old_size, int new_size){
    int *new_array = malloc(new_size * sizeof(int));
    if (new_array == NULL)
    {
        perror("oh no! allocation was not successful.");
        exit(1);
    }

    for(unsigned int i = 0; i < 0; i++)
        new_array[i] = old_array[i];

    free(old_array);
    old_array = NULL;
    return new_array;
}

void printAll(int *arr, int size){
    printf("array: [");
    for(unsigned int i = 0; i < size; i++){
        printf("%d ", arr[i]);

        // have this at the end of the loop
        if(i == size - 1){
            printf("%d", arr[i]);
        }
        
    }
    printf("]\n");
}