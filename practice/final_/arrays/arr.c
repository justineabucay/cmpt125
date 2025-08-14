#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ========================================
   COMMON ARRAY OPERATIONS - EXERCISES
   ======================================== */

// Exercise 1: Basic Array Access and Initialization
void exercise_1_basic_operations()
{
    printf("=== Exercise 1: Basic Array Operations ===\n");
    int size = 10;
    // TODO: Declare an array of 10 integers
    int arr[size];

    // TODO: Initialize array with values 0, 1, 2, ..., 9
    int count = 0;
    for(int i = 0; i < size; i++){
        arr[i] = count;
        count++;
    }
    // TODO: Print all elements in the array
    printf("array: [");
    for(int i = 0; i < size; i++){
        printf("%d, ", arr[i]);
        if(i == size - 1)
            printf("%d", arr[i]);
    }
    printf("]\n");
    // TODO: Access and print the element at index 5
    printf("the element at index 5: [%d]\n", arr[5]);
    // TODO: Modify the element at index 3 to value 99
    printf("the element at index 3: [%d]\n", arr[3]);
    arr[3] = 99;
    // TODO: Print the modified array
    printf("the element at index 3: [%d]\n", arr[3]);
}

// Exercise 2: Array Searching
int linear_search(int arr[], int size, int target)
{
    // TODO: Implement linear search
    for(unsigned int i = 0; i < size; i++){
        if(arr[i] == target){
            return i; 
        }
    }
    // Return index if found, -1 if not found
    return -1; // Placeholder
}

int binary_search(int arr[], int left, int right, int target)
{
    // TODO: Implement binary search (assume array is sorted)
    while(left <= right){
        int middle = left + (right - left) / 2; 
        if(arr[middle]== target)
            return middle;
        else if(arr[middle] < target)
            left = middle + 1;  // search right side
        else   
            right = middle - 1; // search left side
    }
    // Return index if found, -1 if not found
    return -1; // Placeholder
}

void exercise_2_searching()
{
    printf("\n=== Exercise 2: Array Searching ===\n");
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int size = sizeof(arr) / sizeof(arr[0]);

    // TODO: Search for element 7 using linear search
    int index = linear_search(arr, size, 7); 
    if(index != -1)
        printf("we have found the number at position %d\n", index);
    else
        printf("we could not find the number at all! :(");

    // TODO: Search for element 7 using binary search
    int left = 0;
    int right = size - 1;
    index = binary_search(arr, left, right, 7);
    if (index != -1)
        printf("we have found the number at position %d\n", index);
    else
        printf("we could not find the number at all! :(");

    // TODO: Search for element 6 (not in array)
    index = linear_search(arr, size, 6);
    if (index != -1)
        printf("we have found the number at position %d\n", index);
    else
        printf("we could not find the number at all! :(");
}

// Exercise 3: Array Sorting
void bubble_sort(int arr[], int size)
{
    // TODO: Implement bubble sort
    for(unsigned int i = 0; i < size - 1; i++){
        for(unsigned int j = 0; j < size - i - 1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selection_sort(int arr[], int size)
{
    // TODO: Implement selection sort
    for (int i = 0; i < size - 1; i++)
    {
        int min_index = i; // ← Track INDEX, not value

        for (int j = i + 1; j < size; j++)
        { // ← Start from i+1
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }

        // Actually SWAP the elements!
        if (min_index != i)
        {
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}

void insertion_sort(int arr[], int size)
{
    // TODO: Implement insertion sort
    for(unsigned int i = 0; i < size; i++){
        int insert = arr[i]; 
        int j = i - 1;      // prev

        while(j >= 0 && arr[j] > insert){
            arr[j + 1] = arr[j]; 
            j--;
        }

        arr[j+1] = insert;
    }
}

// **REVIEW**
void exercise_3_sorting()
{
    printf("\n\n=== Exercise 3: Array Sorting ===\n");
    int arr1[] = {64, 34, 25, 12, 22, 11, 90};
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    int arr3[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr1) / sizeof(arr1[0]);

    printf("Original array: ");
    // TODO: Print original array
    printf("array: [");
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", arr1[i]);
        if (i == size - 1)
            printf("%d", arr1[i]);
    }
    printf("]\n");

    // TODO: Sort arr1 using bubble sort and print
    printf("bubble sort...\n");
    bubble_sort(arr1, size); 
    printf("array: [");
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", arr1[i]);
        if (i == size)
            printf("%d", arr1[i]);
    }
    printf("]\n");

    printf("array (reversed): [");
    for (int i = size - 1; i >= 0; i--)
    {
        printf("%d", arr1[i]);
        if(i>0)
            printf(", ", arr1[i]);

    }
    printf("]\n\n");

    // TODO: Sort arr2 using selection sort and print
    printf("selection sort...\n");
    printf("original array: [");
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", arr2[i]);
        if (i == size - 1)
            printf("%d", arr2[i]);
    }
    printf("]\n");

    selection_sort(arr2, size);
    printf("array: [");
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", arr2[i]);
        if (i == size)
            printf("%d", arr2[i]);
    }
    printf("]\n");

    printf("array (reversed): [");
    for (int i = size - 1; i >= 0; i--)
    {
        printf("%d", arr2[i]);
        if (i > 0)
            printf(", ", arr2[i]);
    }
    printf("]\n\n");

    // TODO: Sort arr3 using insertion sort and print
    printf("insertion sort...\n");
    printf("original array: [");
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", arr3[i]);
        if (i == size - 1)
            printf("%d", arr3[i]);
    }
    printf("]\n");

    insertion_sort(arr3, size);
    printf("array: [");
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", arr3[i]);
        if (i == size)
            printf("%d", arr3[i]);
    }
    printf("]\n");

    printf("array (reversed): [");
    for (int i = size - 1; i >= 0; i--)
    {
        printf("%d", arr3[i]);
        if (i > 0)
            printf(", ", arr3[i]);
    }
    printf("]\n\n");
}

// Exercise 4: Array Manipulation
void reverse_array(int arr[], int size)
{
    // TODO: Reverse array in-place
    for(unsigned int i = 0; i < size/2; i++){   // do not forgot about / 2
        int temp = arr[i]; 
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

void rotate_left(int arr[], int size, int positions)
{
    positions = positions % size;

    for (int p = 0; p < positions; p++)
    {

        // Save first element
        int first = arr[0];

        // Shift all elements left by 1
        for (int i = 0; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }

        // Put saved element at end
        arr[size - 1] = first;
    }
}

void rotate_right(int arr[], int size, int positions)
{
    positions = positions % size;

    for (int p = 0; p < positions; p++)
    {

        // Save last element
        int last = arr[size - 1];

        // Shift all elements right by 1
        for (int i = size - 1; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }

        // Put saved element at end
        arr[0] = last;
    }
}

void exercise_4_manipulation()
{
    printf("\n=== Exercise 4: Array Manipulation ===\n");
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
  
    // TODO: Print original array
    printf("original array: [");
    for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("]\n");

    // TODO: Reverse the array and print
    reverse_array(arr, size);
    printf("reversed array: [");
    for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("]\n");

    // TODO: Rotate left by 3 positions and print
    printf("\noriginal array: [");
    for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("]\n");

    rotate_left(arr, size, 3);
    printf("rotate left: [");
    for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("]\n");

    // TODO: Rotate right by 2 positions and print
    printf("\noriginal array: [");
    for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("]\n");

    rotate_right(arr, size, 2);
    printf("rotate right: [");
    for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("]\n");
}

// Exercise 5: Array Statistics
int find_maximum(int arr[], int size)
{
    // TODO: Find and return maximum element
    int max = arr[0];
    for(unsigned int i = 0; i < size; i++){
        
        if(max < arr[i])
            max = arr[i];
    }
    return max; // Placeholder
}

int find_minimum(int arr[], int size)
{
    int min = arr[0];
    for (unsigned int i = 0; i < size; i++)
    {
        if (min > arr[i])
            min = arr[i];
    }
    return min; // Placeholder
}

float calculate_average(int arr[], int size)
{
    // TODO: Calculate and return average
    float sum = 0.0;
    float average = 0.0;
    for(unsigned int i = 0; i < size; i++){
        sum += arr[i];
    }

    average = (sum/size);
    return average; // Placeholder
}

int count_occurrences(int arr[], int size, int value)
{
    int count = 0;
    for(unsigned int i = 0; i < size; i++){
        if(arr[i] == value)
            count++;
    }

    return count;
}

void exercise_5_statistics()
{
    printf("\n=== Exercise 5: Array Statistics ===\n");
    int arr[] = {3, 7, 2, 9, 2, 1, 7, 2, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    // TODO: Print array
    
    printf("printing the array: [");
    for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("]\n");

    // TODO: Find and print maximum
    printf("the max integer is...[%d]\n", find_maximum(arr, size));

    // TODO: Find and print minimum
    printf("the min integer is...[%d]\n", find_minimum(arr, size));
    // TODO: Calculate and print average
    printf("the average is...[%.2f]\n", calculate_average(arr, size));

    // TODO: Count occurrences of number 2
    printf("the number of occurences that '2' appears is...[%d]\n", count_occurrences(arr, size, 2));
}

// Exercise 6: Dynamic Arrays
typedef struct
{
    int *data;
    int size;
    int capacity;
} DynamicArray;

DynamicArray *create_dynamic_array(int initial_capacity)
{
    if(initial_capacity < 0) return NULL;
    DynamicArray *arr = malloc(sizeof(DynamicArray));
    if(arr == NULL) return NULL;

    arr->data = malloc(initial_capacity * sizeof(int));
    if(arr->data == NULL){
        free(arr);
        return NULL;
    }
    arr->size = initial_capacity;
    arr->capacity = initial_capacity;

    for(unsigned int i = 0; i < initial_capacity; i++)
        arr->data[i] = 0;

    return arr; // Placeholder
}

int append_element(DynamicArray *arr, int value)
{
    if (arr == NULL)
        return 0;

    if (arr->size == arr->capacity)
    {
        int new_capacity = arr->capacity * 2;
        int *new_data = realloc(arr->data, new_capacity * sizeof(int));
        if(new_data == NULL) return 0;

        arr->capacity = new_capacity;
        arr->data = new_data;
        
    }
    
    arr->data[(arr->size)++] = value;

    return 1; // Placeholder
}

// review this !
int insert_element(DynamicArray *arr, int index, int value)
{
    // TODO: Insert element at specific index
    if(arr == NULL) return 0; 
    if(arr->data == NULL) return 0; 

    if(index < 0 || index > arr->size) return 0; 

    // shifting elements to the right
    for(unsigned int i = arr->size; i > index; i--)
        arr->data[i] = arr->data[i-1];
    
    arr->data[index] = value;
    arr->size++; 

    return 1; // Placeholder
}

int remove_element(DynamicArray *arr, int index)
{
    if(arr == NULL || index < 0 || index > arr->size || arr->data == NULL) return 0; 

    // remove element
    int removed = arr->data[index];

    // shift to the left
    for(unsigned int i = 0; i < index; i++){ 
        arr->data[i] = arr->data[i + 1];
    }

    arr->size--;

    return 1;
}

void free_dynamic_array(DynamicArray *arr)
{
    if(arr != NULL){
        free(arr);
        arr = NULL;
    }
}

// **REVIEW**
void exercise_6_dynamic_arrays()
{
    printf("\n=== Exercise 6: Dynamic Arrays ===\n");

    // TODO: Create dynamic array with capacity 2
    DynamicArray *arr = create_dynamic_array(2);
    printf("printing the current array: [");
    for(unsigned int i = 0; i < arr->size; i++){
        printf("%d", arr->data[i]);
        if(i < arr->size-1)
            printf(", ");
    }
    printf("]\n");

    // TODO: Append elements 10, 20, 30 (should trigger resize)
    append_element(arr, 10);
    append_element(arr, 20);
    append_element(arr, 30);

    // TODO: Insert element 15 at index 1
    insert_element(arr, 1, 15);

    // TODO: Remove element at index 2
    remove_element(arr, 2);

    // TODO: Print final array
    printf("printing the current array: [");
    for (unsigned int i = 0; i < arr->size; i++)
    {
        printf("%d", arr->data[i]);
        if (i < arr->size - 1)
            printf(", ");
    }
    printf("]\n");
    printf("size: %d, capacity: %d", arr->size, arr->capacity);

    // TODO: Free memory
    free_dynamic_array(arr);
}

// Exercise 7: 2D Arrays
// **REVIEW**
void exercise_7_2d_arrays()
{
    const int ROWS = 3;
    const int COLS = 4;

    int arr[ROWS][COLS];

    // Initialize with values (row*4 + col)
    printf("\nInitializing true 2D array...\n");
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            arr[row][col] = row * 4 + col;
            printf("arr[%d][%d] = %d\n", row, col, arr[row][col]);
        }
    }
    printf("\n");

    // Print the 2D array in matrix format
    printf("Matrix format:\n");
    for (int row = 0; row < ROWS; row++)
    {
        printf("Row %d: [", row);
        for (int col = 0; col < COLS; col++)
        {
            printf("%2d", arr[row][col]);
            if (col < COLS - 1)
                printf(", ");
        }
        printf("]\n");
    }
    printf("\n");

    // Find sum of all elements
    int sum = 0;
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            sum += arr[row][col];
        }
    }
    printf("Sum of all elements: %d\n\n", sum);

    // Transpose the matrix (swap)
    printf("Transposing matrix (3x4 → 4x3):\n");
    int transposed[COLS][ROWS]; // 4x3 array

    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            transposed[col][row] = arr[row][col];
        }
    }

    printf("Transposed matrix:\n");
    for (int row = 0; row < COLS; row++)
    {
        printf("Row %d: [", row);
        for (int col = 0; col < ROWS; col++)
        {
            printf("%2d", transposed[row][col]);
            if (col < ROWS - 1)
                printf(", ");
        }
        printf("]\n");
    }
    printf("\n");
}


// Exercise 8: Array of Strings
void exercise_8_string_arrays()
{
    printf("\n=== Exercise 8: Array of Strings ===\n");

    char *names[] = {"Alice", "Bob", "Charlie", "Eve", "Diana"};
    int count = sizeof(names) / sizeof(names[0]);

    // TODO: Print all names
    for(unsigned int i = 0; i < count; i++)
        printf("%s ", names[i]);
    printf("\n");
    // TODO: Find longest name
    char *longest = names[0];
    for(unsigned int i = 0; i < count; i++){
        if(strlen(longest) < strlen(names[i]))
            longest = names[i];
    }

    printf("the longest name in the list is... %s\n", longest);

    // **REVIEW**
    // TODO: Sort names alphabetically
    for (int i = 0; i < count - 1; i++)
    {
        int min_index = i;

        // Start from i+1, not 0
        for (int j = i + 1; j < count; j++)
        {
            // Use strcmp instead of just first character
            if (strcmp(names[j], names[min_index]) < 0)
            {
                min_index = j;
            }
        }

        // Actually swap the elements!
        if (min_index != i)
        {
            char *temp = names[i];
            names[i] = names[min_index];
            names[min_index] = temp;
        }
    }

    printf("Fixed result: ");
    for (int i = 0; i < count; i++)
    {
        printf("%s ", names[i]);
    }
    printf("\n\n");

    char* name_to_find = "Lulu";
    int index = -1;
    // TODO: Search for a specific name
    for(unsigned int i = 0; i < count; i++){
        if(names[i] == name_to_find)
            index = i;
    }

    if(index == -1)
        printf("oh no! we could not find '%s'", name_to_find);
    else
        printf("perfect! we found '%s' at position %d", name_to_find, index);
}

// Exercise 9: Array Utilities
void print_array(int arr[], int size)
{
    for(unsigned int i = 0; i < size; i++){
        printf("%d", arr[i]);
        if(i < size - 1)
            printf(", ");
    }
}

void copy_array(int source[], int dest[], int size)
{
    // TODO: Copy elements from source to destination
    for(unsigned int i = 0; i < size; i++){
        dest[i] = source[i];
    }
}

int arrays_equal(int arr1[], int arr2[], int size)
{
    // TODO: Check if two arrays are equal

    // sort first
    bubble_sort(arr1, size);
    bubble_sort(arr2, size);

    for(unsigned int i = 0; i < size; i++){
        if(arr1[i] != arr2[i])
            return 0;
    }
    return 1; // Placeholder
}

void merge_arrays(int arr1[], int size1, int arr2[], int size2, int result[])
{
    printf("=== MERGING SORTED ARRAYS ===\n");
    printf("Array 1: ");
    print_array(arr1, size1);
    printf("\nArray 2: ");
    print_array(arr2, size2);
    printf("\n\n");

    int i = 0, j = 0, k = 0;

    printf("Merge process:\n");

    // Merge elements while both arrays have elements remaining
    while (i < size1 && j < size2)
    {
        printf("Compare arr1[%d]=%d with arr2[%d]=%d: ", i, arr1[i], j, arr2[j]);

        if (arr1[i] <= arr2[j])
        {
            result[k] = arr1[i];
            printf("Take %d from arr1\n", arr1[i]);
            i++;
        }
        else
        {
            result[k] = arr2[j];
            printf("Take %d from arr2\n", arr2[j]);
            j++;
        }
        k++;
    }

    // Copy remaining elements from arr1 (if any)
    while (i < size1)
    {
        printf("Copy remaining arr1[%d]=%d\n", i, arr1[i]);
        result[k] = arr1[i];
        i++;
        k++;
    }

    // Copy remaining elements from arr2 (if any)
    while (j < size2)
    {
        printf("Copy remaining arr2[%d]=%d\n", j, arr2[j]);
        result[k] = arr2[j];
        j++;
        k++;
    }

    printf("Merged result: ");
    print_array(result, size1 + size2);
    printf("\n\n");
}

/* ========================================
   EXERCISE 9: TESTING UTILITIES
   ======================================== */

void exercise_9_utilities()
{
    printf("\n=== Exercise 9: Array Utilities ===\n\n");

    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8};
    int size1 = 4, size2 = 4;

    // Test copy_array function
    printf("🔸 TESTING copy_array function:\n");
    int copied[4];
    copy_array(arr1, copied, size1);

    printf("Original: ");
    print_array(arr1, size1);
    printf("\nCopied:   ");
    print_array(copied, size1);
    printf("\nArrays equal after copy: %s\n\n",
           arrays_equal(arr1, copied, size1) ? "YES" : "NO");

    // Test arrays_equal function
    printf("🔸 TESTING arrays_equal function:\n");
    int arr3[] = {1, 3, 5, 7}; // Same as arr1
    int arr4[] = {1, 3, 5, 9}; // Different from arr1

    printf("arr1: ");
    print_array(arr1, size1);
    printf("\narr3: ");
    print_array(arr3, size1);
    printf("\narr1 == arr3: %s\n", arrays_equal(arr1, arr3, size1) ? "YES" : "NO");

    printf("arr4: ");
    print_array(arr4, size1);
    printf("\narr1 == arr4: %s\n\n", arrays_equal(arr1, arr4, size1) ? "YES" : "NO");

    // Test merge_arrays function
    printf("🔸 TESTING merge_arrays function:\n");
    int merged[8]; // size1 + size2
    merge_arrays(arr1, size1, arr2, size2, merged);
}

/* ========================================
   EXERCISE 10: REMOVE DUPLICATES
   ======================================== */

void remove_duplicates(int arr[], int *size)
{
    printf("=== REMOVING DUPLICATES ===\n");
    printf("Original array: ");
    print_array(arr, *size);
    printf(" (size=%d)\n", *size);

    if (*size <= 1)
    {
        printf("Array has 0 or 1 elements - no duplicates possible\n\n");
        return;
    }

    int write_index = 0; // Position to write next unique element

    printf("\nProcess:\n");

    // First element is always unique
    write_index = 1;
    printf("Keep arr[0] = %d (first element always unique)\n", arr[0]);

    // Check each element starting from index 1
    for (int read_index = 1; read_index < *size; read_index++)
    {
        int current = arr[read_index];
        int is_duplicate = 0;

        printf("Check arr[%d] = %d: ", read_index, current);

        // Check if current element already exists in unique portion
        for (int j = 0; j < write_index; j++)
        {
            if (arr[j] == current)
            {
                is_duplicate = 1;
                printf("Duplicate of arr[%d] - skip\n", j);
                break;
            }
        }

        if (!is_duplicate)
        {
            arr[write_index] = current;
            printf("Unique - keep at position %d\n", write_index);
            write_index++;
        }
    }

    *size = write_index;
    printf("\nArray after removing duplicates: ");
    print_array(arr, *size);
    printf(" (size=%d)\n\n", *size);
}

/* ========================================
   EXERCISE 10: FIND INTERSECTION
   ======================================== */

void find_intersection(int arr1[], int size1, int arr2[], int size2, int result[], int *result_size)
{
    printf("=== FINDING INTERSECTION ===\n");
    printf("Array 1: ");
    print_array(arr1, size1);
    printf("\nArray 2: ");
    print_array(arr2, size2);
    printf("\n\nFinding common elements:\n");

    *result_size = 0;

    // Check each element in arr1
    for (int i = 0; i < size1; i++)
    {
        int current = arr1[i];
        printf("Check %d from arr1: ", current);

        // See if it exists in arr2
        int found_in_arr2 = 0;
        for (int j = 0; j < size2; j++)
        {
            if (arr2[j] == current)
            {
                found_in_arr2 = 1;
                break;
            }
        }

        if (found_in_arr2)
        {
            // Check if we already added this element to result (avoid duplicates)
            int already_in_result = 0;
            for (int k = 0; k < *result_size; k++)
            {
                if (result[k] == current)
                {
                    already_in_result = 1;
                    break;
                }
            }

            if (!already_in_result)
            {
                result[*result_size] = current;
                (*result_size)++;
                printf("Found in arr2 - added to intersection\n");
            }
            else
            {
                printf("Found in arr2 but already in result\n");
            }
        }
        else
        {
            printf("Not found in arr2\n");
        }
    }

    printf("\nIntersection: ");
    print_array(result, *result_size);
    printf(" (size=%d)\n\n", *result_size);
}

/* ========================================
   EXERCISE 10: FIND UNION
   ======================================== */

void find_union(int arr1[], int size1, int arr2[], int size2, int result[], int *result_size)
{
    printf("=== FINDING UNION ===\n");
    printf("Array 1: ");
    print_array(arr1, size1);
    printf("\nArray 2: ");
    print_array(arr2, size2);
    printf("\n\nBuilding union (all unique elements):\n");

    *result_size = 0;

    // Add all elements from arr1
    printf("Adding elements from arr1:\n");
    for (int i = 0; i < size1; i++)
    {
        int current = arr1[i];
        printf("  %d: ", current);

        // Check if already in result
        int already_exists = 0;
        for (int j = 0; j < *result_size; j++)
        {
            if (result[j] == current)
            {
                already_exists = 1;
                break;
            }
        }

        if (!already_exists)
        {
            result[*result_size] = current;
            (*result_size)++;
            printf("Added (new)\n");
        }
        else
        {
            printf("Skipped (duplicate)\n");
        }
    }

    // Add elements from arr2 that aren't already in result
    printf("Adding new elements from arr2:\n");
    for (int i = 0; i < size2; i++)
    {
        int current = arr2[i];
        printf("  %d: ", current);

        // Check if already in result
        int already_exists = 0;
        for (int j = 0; j < *result_size; j++)
        {
            if (result[j] == current)
            {
                already_exists = 1;
                break;
            }
        }

        if (!already_exists)
        {
            result[*result_size] = current;
            (*result_size)++;
            printf("Added (new)\n");
        }
        else
        {
            printf("Skipped (already in union)\n");
        }
    }

    printf("\nUnion: ");
    print_array(result, *result_size);
    printf(" (size=%d)\n\n", *result_size);
}

/* ========================================
   EXERCISE 10: TESTING ADVANCED OPERATIONS
   ======================================== */

void exercise_10_advanced()
{
    printf("\n=== Exercise 10: Advanced Operations ===\n\n");

    // Test remove_duplicates
    printf("🔸 TESTING remove_duplicates:\n");
    int arr_with_duplicates[] = {1, 2, 2, 3, 4, 4, 5};
    int size_with_duplicates = 7;
    remove_duplicates(arr_with_duplicates, &size_with_duplicates);

    // Test find_intersection
    printf("🔸 TESTING find_intersection:\n");
    int set1[] = {1, 2, 3, 4, 5};
    int set2[] = {3, 4, 5, 6, 7};
    int intersection[10];
    int intersection_size;
    find_intersection(set1, 5, set2, 5, intersection, &intersection_size);

    // Test find_union
    printf("🔸 TESTING find_union:\n");
    int union_result[10];
    int union_size;
    find_union(set1, 5, set2, 5, union_result, &union_size);

    // Additional test with duplicates within arrays
    printf("🔸 ADDITIONAL TEST - Arrays with internal duplicates:\n");
    int arr_a[] = {1, 2, 2, 3};
    int arr_b[] = {2, 3, 3, 4};
    int result[10];
    int result_size;

    printf("Test intersection with duplicates:\n");
    find_intersection(arr_a, 4, arr_b, 4, result, &result_size);

    printf("Test union with duplicates:\n");
    find_union(arr_a, 4, arr_b, 4, result, &result_size);
}

/* ========================================
   SOLUTION TEMPLATES
   ======================================== */

// Example solution for Exercise 1
void solution_1_basic_operations()
{
    printf("=== SOLUTION 1: Basic Array Operations ===\n");

    // Declare an array of 10 integers
    int arr[10];

    // Initialize array with values 0, 1, 2, ..., 9
    for (int i = 0; i < 10; i++)
    {
        arr[i] = i;
    }

    // Print all elements
    printf("Array elements: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Access element at index 5
    printf("Element at index 5: %d\n", arr[5]);

    // Modify element at index 3
    arr[3] = 99;

    // Print modified array
    printf("Modified array: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    printf("ARRAY OPERATIONS PRACTICE EXERCISES\n");
    printf("====================================\n\n");

    // Uncomment each exercise as you complete them

    exercise_1_basic_operations();
    exercise_2_searching();
    exercise_3_sorting();
    exercise_4_manipulation();
    exercise_5_statistics();
    exercise_6_dynamic_arrays();
    exercise_7_2d_arrays();
    exercise_8_string_arrays();
    exercise_9_utilities();
    exercise_10_advanced();

    //printf("\n--- Example Solution ---\n");
    //solution_1_basic_operations();

    return 0;
}