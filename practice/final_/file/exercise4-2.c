#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Read a text file and return all lines as an array of strings
char **read_lines(const char *filename, int *line_count)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        *line_count = 0;
        return NULL;
    }

    // First pass: Count lines in file
    *line_count = 0;
    char buffer[1024]; // Buffer for reading lines

    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        (*line_count)++;
    }

    // Handle empty file
    if (*line_count == 0)
    {
        fclose(file);
        return malloc(0); // Return valid pointer for empty file
    }

    // Rewind to beginning of file for second pass
    rewind(file);

    // Allocate array of char* pointers
    char **lines = malloc((*line_count) * sizeof(char *));
    if (lines == NULL)
    {
        fclose(file);
        *line_count = 0;
        return NULL; // Memory allocation failed
    }

    // Second pass: Read each line and allocate memory for it
    int current_line = 0;
    while (current_line < *line_count && fgets(buffer, sizeof(buffer), file) != NULL)
    {
        // Calculate length needed (including null terminator)
        int len = strlen(buffer);

        // Allocate memory for this line
        lines[current_line] = malloc((len + 1) * sizeof(char));
        if (lines[current_line] == NULL)
        {
            // Memory allocation failed - clean up what we've allocated so far
            for (int i = 0; i < current_line; i++)
            {
                free(lines[i]);
            }
            free(lines);
            fclose(file);
            *line_count = 0;
            return NULL;
        }

        // Copy the line to allocated memory
        strcpy(lines[current_line], buffer);
        current_line++;
    }

    fclose(file);
    return lines;
}

// Free the array of strings
void free_lines(char **lines, int count)
{
    if (lines == NULL)
    {
        return; // Handle NULL pointer gracefully
    }

    // Free each individual string first
    for (int i = 0; i < count; i++)
    {
        if (lines[i] != NULL)
        { // Extra safety check
            free(lines[i]);
        }
    }

    // Free the array of pointers
    free(lines);
}

// Alternative implementation using dynamic buffer sizing
char **read_lines_dynamic(const char *filename, int *line_count)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        *line_count = 0;
        return NULL;
    }

    // Dynamic approach: grow arrays as needed
    int capacity = 10; // Initial capacity
    char **lines = malloc(capacity * sizeof(char *));
    if (lines == NULL)
    {
        fclose(file);
        *line_count = 0;
        return NULL;
    }

    *line_count = 0;
    char *line = NULL;
    size_t line_size = 0;
    ssize_t chars_read;

    // Use getline() for dynamic line reading (POSIX function)
    while ((chars_read = getline(&line, &line_size, file)) != -1)
    {
        // Check if we need to expand capacity
        if (*line_count >= capacity)
        {
            capacity *= 2;
            char **temp = realloc(lines, capacity * sizeof(char *));
            if (temp == NULL)
            {
                // Cleanup on realloc failure
                for (int i = 0; i < *line_count; i++)
                {
                    free(lines[i]);
                }
                free(lines);
                free(line);
                fclose(file);
                *line_count = 0;
                return NULL;
            }
            lines = temp;
        }

        // Allocate memory for this line
        lines[*line_count] = malloc((chars_read + 1) * sizeof(char));
        if (lines[*line_count] == NULL)
        {
            // Cleanup on malloc failure
            for (int i = 0; i < *line_count; i++)
            {
                free(lines[i]);
            }
            free(lines);
            free(line);
            fclose(file);
            *line_count = 0;
            return NULL;
        }

        // Copy the line
        strcpy(lines[*line_count], line);
        (*line_count)++;
    }

    free(line); // Free getline's buffer
    fclose(file);

    // Shrink array to exact size needed
    if (*line_count > 0 && *line_count < capacity)
    {
        char **temp = realloc(lines, (*line_count) * sizeof(char *));
        if (temp != NULL)
        {
            lines = temp;
        }
    }

    return lines;
}

// Test function to demonstrate usage
int main()
{
    printf("=== Text File I/O Test ===\n");

    // Create a test file with various line types
    FILE *test_file = fopen("test_text.txt", "w");
    if (test_file != NULL)
    {
        fprintf(test_file, "Hello, World!\n");
        fprintf(test_file, "This is line 2 with numbers: 123\n");
        fprintf(test_file, "Short line\n");
        fprintf(test_file, "This is a much longer line with lots of text to test buffer handling and memory allocation\n");
        fprintf(test_file, "Line with special chars: !@#$%%^&*()\n");
        fprintf(test_file, "\n");                         // Empty line
        fprintf(test_file, "Final line without newline"); // No \n at end
        fclose(test_file);
        printf("✓ Created test file 'test_text.txt'\n");
    }
    else
    {
        printf("✗ Failed to create test file\n");
        return 1;
    }

    // Test 1: Read the file
    printf("\nTest 1: Reading text file\n");
    int line_count;
    char **lines = read_lines("test_text.txt", &line_count);

    if (lines != NULL)
    {
        printf("✓ Successfully read %d lines:\n", line_count);
        for (int i = 0; i < line_count; i++)
        {
            printf("  [%d]: '%s'", i, lines[i]);
            // Check if line ends with newline
            int len = strlen(lines[i]);
            if (len > 0 && lines[i][len - 1] != '\n')
            {
                printf(" (no newline)");
            }
            printf("\n");
        }

        // Free the memory
        free_lines(lines, line_count);
        printf("✓ Memory freed successfully\n");
    }
    else
    {
        printf("✗ Failed to read file\n");
    }

    // Test 2: Empty file
    printf("\nTest 2: Empty file\n");
    FILE *empty_file = fopen("empty.txt", "w");
    if (empty_file != NULL)
    {
        fclose(empty_file); // Create empty file

        int empty_count;
        char **empty_lines = read_lines("empty.txt", &empty_count);

        printf("Empty file line count: %d\n", empty_count);
        if (empty_count == 0)
        {
            printf("✓ Empty file handled correctly\n");
        }
        else
        {
            printf("✗ Empty file not handled correctly\n");
        }

        if (empty_lines != NULL)
        {
            free_lines(empty_lines, empty_count);
        }
    }

    // Test 3: Non-existent file
    printf("\nTest 3: Non-existent file\n");
    int error_count;
    char **error_lines = read_lines("nonexistent.txt", &error_count);

    if (error_lines == NULL && error_count == 0)
    {
        printf("✓ Non-existent file handled correctly\n");
    }
    else
    {
        printf("✗ Non-existent file not handled correctly\n");
        if (error_lines != NULL)
        {
            free_lines(error_lines, error_count);
        }
    }

    // Test 4: Large file (create programmatically)
    printf("\nTest 4: Large file\n");
    FILE *large_file = fopen("large.txt", "w");
    if (large_file != NULL)
    {
        for (int i = 0; i < 1000; i++)
        {
            fprintf(large_file, "This is line number %d with some additional text\n", i);
        }
        fclose(large_file);

        int large_count;
        char **large_lines = read_lines("large.txt", &large_count);

        if (large_lines != NULL && large_count == 1000)
        {
            printf("✓ Large file read successfully (%d lines)\n", large_count);
            printf("First line: %s", large_lines[0]);
            printf("Last line: %s", large_lines[large_count - 1]);

            free_lines(large_lines, large_count);
            printf("✓ Large file memory freed\n");
        }
        else
        {
            printf("✗ Large file read failed\n");
            if (large_lines != NULL)
            {
                free_lines(large_lines, large_count);
            }
        }
    }

// Test 5: Test dynamic version (if getline is available)
#ifdef _GNU_SOURCE
    printf("\nTest 5: Dynamic version\n");
    int dynamic_count;
    char **dynamic_lines = read_lines_dynamic("test_text.txt", &dynamic_count);

    if (dynamic_lines != NULL)
    {
        printf("✓ Dynamic version read %d lines\n", dynamic_count);
        free_lines(dynamic_lines, dynamic_count);
    }
    else
    {
        printf("✗ Dynamic version failed\n");
    }
#endif

    printf("\n=== All Tests Complete ===\n");
    return 0;
}

/*
 * Key Implementation Notes:
 *
 * 1. Two-pass approach:
 *    - First pass: Count lines to know how much memory to allocate
 *    - Second pass: Actually read and store the lines
 *
 * 2. Memory management:
 *    - Allocate array of char* pointers first
 *    - Then allocate memory for each individual line
 *    - free_lines() must free both levels: each string, then the array
 *
 * 3. Error handling:
 *    - Check every malloc() and file operation
 *    - Clean up partial allocations on failure
 *    - Handle edge cases (empty files, long lines, etc.)
 *
 * 4. Buffer size considerations:
 *    - Fixed buffer (1024 chars) should handle most lines
 *    - For very long lines, consider getline() or dynamic buffers
 *    - Lines longer than buffer will be split (but this is rare)
 *
 * 5. Newline handling:
 *    - fgets() includes the \n character in the string
 *    - This preserves original file format
 *    - Caller can remove \n if needed with: line[strlen(line)-1] = '\0'
 */