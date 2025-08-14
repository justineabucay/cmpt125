#include <stdio.h>
#include <stdlib.h>
#include "dataStructure.h"

int main (void){
    dynamic_array *arr = create_array(10); // Capacity = 10
    add_element(arr, 5);                   // Count = 1
    add_element(arr, 3);                   // Count = 2
    add_element(arr, 8);                   // Count = 3

    print_array_info(arr); // Should show capacity=10, count=3

    printf("\n\n");
    printf("Testing 2D to 1D array mapping:\n");

    // Test coord_to_index
    int width = 8;
    printf("Coordinate (6, 3) with width %d maps to index: %d\n",
           width, coord_to_index(6, 3, width));

    // Test index_to_coord
    int x, y;
    index_to_coord(30, width, &x, &y);
    printf("Index 30 with width %d maps to coordinates: (%d, %d)\n",
           width, x, y);

    printf("\nRunning image processing demo:\n");
    image_processing_demo();

    free(arr);
    return 0;
}