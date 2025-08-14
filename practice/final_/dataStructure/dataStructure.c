#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dataStructure.h"

// Create a dynamic array with given capacity
dynamic_array *create_array(int capacity){ 
    if(capacity == 0) return NULL; 

    // allocate memory on the heap for dynamic_array struct
    dynamic_array *ia = malloc(sizeof(dynamic_array));

    if(ia != NULL){

        // sets its field "capacity"
        ia->capacity = capacity;

        // allocate memory on the heap for array
        ia->data = malloc(capacity * sizeof(int));
        if(ia->data == NULL){
            free(ia); 
            ia = NULL;
        } else 
            ia->count = 0;
    }

    return ia;
}

// Add element to array (if space available)
int add_element(dynamic_array *arr, int value){
    if(arr == NULL) return 0; 
    if(arr->data == NULL) return 0; 

    if(arr->count == arr->capacity) return 0; 

    arr->data[(arr->count)++] = value;

    return 1;

}

int coord_to_index(int x, int y, int width)
{
    // Formula: index = x + y * width
    return x + y * width;
}

// Convert 1D index back to 2D coordinates
void index_to_coord(int index, int width, int *x, int *y)
{
    // x = index % width (remainder gives column position)
    // y = index / width (integer division gives row position)
    *x = index % width;
    *y = index / width;
}

// Work with a "2D" image stored as 1D array
void image_processing_demo()
{
    int width = 8, height = 7;
    int *image = malloc(width * height * sizeof(int));

    // Set pixel at (6, 3) to value 255
    int index = coord_to_index(6, 3, width);
    image[index] = 255;

    // Read pixel at (6, 3)
    int value = image[index];
    printf("Pixel at (6,3) has value: %d\n", value);

    // Convert index back to coordinates
    int x, y;
    index_to_coord(index, width, &x, &y);
    printf("Index %d corresponds to coordinates (%d, %d)\n", index, x, y);

    free(image);
}

// Print array information
void print_array_info(dynamic_array *arr)
{
    printf("Capacity: %d, Count: %d\n", arr->capacity, arr->count);
    printf("Elements: ");
    for (int i = 0; i < arr->count; i++)
    {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}
