#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
char* create_message(){
    char* msg = malloc(50); 
    strcpy(msg, "hello");
    free(msg); 

    msg = malloc(100); 
    // strcpy() allows you to copy a string to another, which returns a pointer to dest string
    strcpy(msg, "hello world"); 

    return msg; 
}

int *create_and_modify_array(int start_value)
{
    int *arr = malloc(4 * sizeof(int));

    for (int i = 0; i < 4; i++)
    {
        arr[i] = start_value + i * i; // Like your midterm: 0, 1, 4, 9
    }

    return arr;
}

void printAll(int *arr, int size)
{
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