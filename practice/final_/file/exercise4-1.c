#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Write an array of integers to a binary file
int write_int_array(const char *filename, int *arr, int count)
{
    // Open file for binary writing
    FILE *file = fopen(filename, "wb");
    if (file == NULL)
    {
        return -1; // Error: couldn't open file
    }

    // Write the count first (so we know how many integers to read later)
    if (fwrite(&count, sizeof(int), 1, file) != 1)
    {
        fclose(file);
        return -1; // Error: couldn't write count
    }

    // Write all integers (only if count > 0)
    if (count > 0)
    {
        if (fwrite(arr, sizeof(int), count, file) != count)
        {
            fclose(file);
            return -1; // Error: couldn't write all integers
        }
    }

    // Close file
    fclose(file);
    return 0; // Success
}

// Read an array of integers from a binary file
int *read_int_array(const char *filename, int *count)
{
    // Open file for binary reading
    FILE *file = fopen(filename, "rb");
    if (file == NULL)
    {
        *count = 0;
        return NULL; // Error: couldn't open file
    }

    // Read the count of integers first
    if (fread(count, sizeof(int), 1, file) != 1)
    {
        fclose(file);
        *count = 0;
        return NULL; // Error: couldn't read count
    }

    // Handle edge case: empty array
    if (*count == 0)
    {
        fclose(file);
        return malloc(0); // Return valid pointer for empty array
    }

    // Allocate memory for that many integers
    int *arr = malloc((*count) * sizeof(int));
    if (arr == NULL)
    {
        fclose(file);
        *count = 0;
        return NULL; // Error: memory allocation failed
    }

    // Read the integers from file
    if (fread(arr, sizeof(int), *count, file) != *count)
    {
        free(arr); // Clean up allocated memory
        fclose(file);
        *count = 0;
        return NULL; // Error: couldn't read all integers
    }

    // Close file and return array
    fclose(file);
    return arr;
}

// Test function to demonstrate usage
int main()
{
    printf("=== Binary File I/O Test ===\n");

    // Test data: various integer values including edge cases
    int original_data[] = {42, -17, 88, 0, 156, -91, 7, 234, -65, 2147483647};
    int original_count = 10;

    printf("Original data (%d elements): ", original_count);
    for (int i = 0; i < original_count; i++)
    {
        printf("%d ", original_data[i]);
    }
    printf("\n");

    // Test 1: Write and read normal array
    printf("\nTest 1: Normal array\n");
    if (write_int_array("test1.bin", original_data, original_count) == 0)
    {
        printf("✓ Write successful\n");

        int read_count;
        int *read_data = read_int_array("test1.bin", &read_count);

        if (read_data != NULL)
        {
            printf("✓ Read successful (%d elements): ", read_count);
            for (int i = 0; i < read_count; i++)
            {
                printf("%d ", read_data[i]);
            }
            printf("\n");

            // Verify data integrity
            if (read_count == original_count)
            {
                int matches = 1;
                for (int i = 0; i < original_count; i++)
                {
                    if (original_data[i] != read_data[i])
                    {
                        matches = 0;
                        break;
                    }
                }
                printf(matches ? "✓ Data integrity verified\n" : "✗ Data mismatch\n");
            }
            else
            {
                printf("✗ Count mismatch: expected %d, got %d\n", original_count, read_count);
            }

            free(read_data);
        }
        else
        {
            printf("✗ Read failed\n");
        }
    }
    else
    {
        printf("✗ Write failed\n");
    }

    // Test 2: Empty array
    printf("\nTest 2: Empty array\n");
    int empty_data[] = {};
    if (write_int_array("empty.bin", empty_data, 0) == 0)
    {
        printf("✓ Empty array write successful\n");

        int empty_count;
        int *empty_read = read_int_array("empty.bin", &empty_count);
        printf("Read count: %d\n", empty_count);

        if (empty_count == 0)
        {
            printf("✓ Empty array read successful\n");
        }
        else
        {
            printf("✗ Empty array read failed\n");
        }

        if (empty_read != NULL)
        {
            free(empty_read);
        }
    }
    else
    {
        printf("✗ Empty array write failed\n");
    }

    // Test 3: Single element
    printf("\nTest 3: Single element\n");
    int single_data[] = {999};
    if (write_int_array("single.bin", single_data, 1) == 0)
    {
        printf("✓ Single element write successful\n");

        int single_count;
        int *single_read = read_int_array("single.bin", &single_count);

        if (single_read != NULL && single_count == 1)
        {
            printf("✓ Single element read successful: %d\n", single_read[0]);
            free(single_read);
        }
        else
        {
            printf("✗ Single element read failed\n");
        }
    }
    else
    {
        printf("✗ Single element write failed\n");
    }

    // Test 4: Large array
    printf("\nTest 4: Large array\n");
    int large_size = 1000;
    int *large_data = malloc(large_size * sizeof(int));

    if (large_data != NULL)
    {
        // Fill with sequential numbers
        for (int i = 0; i < large_size; i++)
        {
            large_data[i] = i * 2; // Even numbers
        }

        if (write_int_array("large.bin", large_data, large_size) == 0)
        {
            printf("✓ Large array write successful (%d elements)\n", large_size);

            int large_count;
            int *large_read = read_int_array("large.bin", &large_count);

            if (large_read != NULL && large_count == large_size)
            {
                // Check first and last few elements
                printf("✓ Large array read successful\n");
                printf("First 5: %d %d %d %d %d\n",
                       large_read[0], large_read[1], large_read[2], large_read[3], large_read[4]);
                printf("Last 5: %d %d %d %d %d\n",
                       large_read[large_size - 5], large_read[large_size - 4],
                       large_read[large_size - 3], large_read[large_size - 2], large_read[large_size - 1]);
                free(large_read);
            }
            else
            {
                printf("✗ Large array read failed\n");
            }
        }
        else
        {
            printf("✗ Large array write failed\n");
        }

        free(large_data);
    }
    else
    {
        printf("✗ Couldn't allocate memory for large array test\n");
    }

    // Test 5: Error handling - try to read non-existent file
    printf("\nTest 5: Error handling\n");
    int error_count;
    int *error_read = read_int_array("nonexistent.bin", &error_count);
    if (error_read == NULL && error_count == 0)
    {
        printf("✓ Properly handled non-existent file\n");
    }
    else
    {
        printf("✗ Error handling failed\n");
        if (error_read != NULL)
            free(error_read);
    }

    printf("\n=== All Tests Complete ===\n");
    return 0;
}