#ifndef MEMORY_H
#define MEMORY_H
// part 1: dynamic memory allocation
// exercise 1.1: build malloc/free
int *create_int_array(int size);

// resize an existing array (like realloc but manual)
int* resize_array(int* old_array, int old_size, int new_size);

void printAll(int *arr, int size);

#endif