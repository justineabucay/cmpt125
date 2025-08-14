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
    printf("\n\n");

    // exercise 4.1
    int test_numbers[] = {42, 17, 88, 3, 156, 91, 7, 234, 65, 19};
    int test_count = 10;

    printAll(test_numbers, test_count);
    printf("\nWriting array to binary file 'test_numbers.bin'...\n");
    if (write_int_array("test_numbers.bin", test_numbers, test_count) == 0)
    {
        printf("✓ Successfully wrote binary file\n");
    }
    else
    {
        printf("✗ Failed to write binary file\n");
        return 1;
    }

    // Test reading binary file
    printf("\nReading array from binary file...\n");
    int read_count;
    int *read_numbers = read_int_array("test_numbers.bin", &read_count);

    if (read_numbers != NULL)
    {
        printf("✓ Successfully read binary file\n");
        printf("Read count: %d\n", read_count);
        printf("Read array: ");
        for (int i = 0; i < read_count; i++)
        {
            printf("%d ", read_numbers[i]);
        }
        printf("\n");

        // Verify data integrity
        if (read_count == test_count)
        {
            int match = 1;
            for (int i = 0; i < test_count; i++)
            {
                if (test_numbers[i] != read_numbers[i])
                {
                    match = 0;
                    break;
                }
            }
            if (match)
            {
                printf("✓ Data integrity verified - arrays match!\n");
            }
            else
            {
                printf("✗ Data mismatch detected\n");
            }
        }
        else
        {
            printf("✗ Count mismatch: expected %d, got %d\n", test_count, read_count);
        }

        free(read_numbers); // Don't forget to free allocated memory
    }
    else
    {
        printf("✗ Failed to read binary file\n");
    }
    
    free(arr);
    return 0;
}