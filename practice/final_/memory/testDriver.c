#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

int main(void){
    //exercise 1.1: basic malloc/free
    int size = 5;
    int new_size = 10;
    int *arr = create_int_array(size);
    printAll(arr, size);
    
    arr = resize_array(arr, size, new_size);
    printAll(arr, new_size);
    printf("\n\n");
    
    // exercise 2.1: find + fix memory leaks
    printf("%s\n", create_message());

    free(arr);
    return 0;
}