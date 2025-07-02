#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function prototypes
void printArray(int *arr, int numElements, int arraySize);
bool insertElement(int *arr, int *numElements, int arraySize, int newElement);
bool removeElement(int *arr, int *numElements, int elementToRemove);
int searchElement(int *arr, int numElements, int target);
void traverseArray(int *arr, int numElements);
int findSum(int *arr, int numElements);
int findMax(int *arr, int numElements);
int findAllOccurrences(int *arr, int numElements, int target, int *indices);
void printDuplicates(int *arr, int numElements);
void removeDuplicates(int *arr, int *numElements);
int removeAllOccurrences(int *arr, int *numElements, int elementToRemove);

int main()
{
    // Initialize our dynamic array
    int arraySize = 10;
    int *grades = (int *)malloc(arraySize * sizeof(int));
    int numOfGrades = 0;

    if (grades == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("=== ARRAY OPERATIONS DEMO ===\n\n");

    // 1. INSERT OPERATION (with some duplicates)
    printf("1. INSERT OPERATIONS (including duplicates):\n");
    printf("Inserting elements: 85, 92, 78, 88, 92, 72, 88, 95, 78\n");

    insertElement(grades, &numOfGrades, arraySize, 85);
    insertElement(grades, &numOfGrades, arraySize, 92);
    insertElement(grades, &numOfGrades, arraySize, 78);
    insertElement(grades, &numOfGrades, arraySize, 88);
    insertElement(grades, &numOfGrades, arraySize, 92); // duplicate
    insertElement(grades, &numOfGrades, arraySize, 72);
    insertElement(grades, &numOfGrades, arraySize, 88); // duplicate
    insertElement(grades, &numOfGrades, arraySize, 95);
    insertElement(grades, &numOfGrades, arraySize, 78); // duplicate

    printArray(grades, numOfGrades, arraySize);

    // 2. SEARCH OPERATION (including finding all occurrences)
    printf("\n2. SEARCH OPERATIONS:\n");
    int target = 88;
    int index = searchElement(grades, numOfGrades, target);
    if (index != -1)
    {
        printf("First occurrence of %d found at index %d\n", target, index);
    }
    else
    {
        printf("Element %d not found\n", target);
    }

    // Find all occurrences
    int indices[10]; // Assuming max 10 occurrences
    int count = findAllOccurrences(grades, numOfGrades, target, indices);
    printf("Element %d appears %d times at indices: ", target, count);
    for (int i = 0; i < count; i++)
    {
        printf("%d ", indices[i]);
    }
    printf("\n");

    target = 100;
    index = searchElement(grades, numOfGrades, target);
    if (index != -1)
    {
        printf("Element %d found at index %d\n", target, index);
    }
    else
    {
        printf("Element %d not found\n", target);
    }

    // 3. TRAVERSE OPERATION
    printf("\n3. TRAVERSE OPERATIONS:\n");
    printf("All elements: ");
    traverseArray(grades, numOfGrades);

    printf("Sum of all elements: %d\n", findSum(grades, numOfGrades));
    printf("Maximum element: %d\n", findMax(grades, numOfGrades));

    // Find and display duplicates
    printf("\n3a. FINDING DUPLICATES:\n");
    printDuplicates(grades, numOfGrades);

    // 4. REMOVE OPERATION
    printf("\n4. REMOVE OPERATIONS:\n");
    printf("Removing first occurrence of element 78...\n");
    if (removeElement(grades, &numOfGrades, 78))
    {
        printf("Element 78 removed successfully\n");
    }
    else
    {
        printf("Element 78 not found for removal\n");
    }
    printArray(grades, numOfGrades, arraySize);

    printf("\nRemoving ALL occurrences of element 92...\n");
    int removedCount = removeAllOccurrences(grades, &numOfGrades, 92);
    printf("Removed %d occurrences of element 92\n", removedCount);
    printArray(grades, numOfGrades, arraySize);

    printf("\nRemoving element 100 (doesn't exist)...\n");
    if (removeElement(grades, &numOfGrades, 100))
    {
        printf("Element 100 removed successfully\n");
    }
    else
    {
        printf("Element 100 not found for removal\n");
    }

    // 5. DUPLICATE REMOVAL
    printf("\n5. DUPLICATE REMOVAL:\n");
    printf("Before removing duplicates:\n");
    printArray(grades, numOfGrades, arraySize);

    removeDuplicates(grades, &numOfGrades);
    printf("After removing duplicates (keeping only one of each):\n");
    printArray(grades, numOfGrades, arraySize);

    // Try to insert when array gets full
    printf("\n6. TESTING ARRAY LIMITS:\n");
    printf("Filling array to capacity...\n");
    for (int i = numOfGrades; i < arraySize; i++)
    {
        insertElement(grades, &numOfGrades, arraySize, 60 + i);
    }
    printArray(grades, numOfGrades, arraySize);

    printf("Trying to insert when array is full...\n");
    if (!insertElement(grades, &numOfGrades, arraySize, 99))
    {
        printf("Cannot insert - array is full!\n");
    }

    // Clean up memory
    free(grades);
    return 0;
}

// Print array contents
void printArray(int *arr, int numElements, int arraySize)
{
    printf("Array contents (size: %d, elements: %d): [", arraySize, numElements);
    for (int i = 0; i < numElements; i++)
    {
        printf("%d", arr[i]);
        if (i < numElements - 1)
            printf(", ");
    }
    printf("]\n");
}

// INSERT: Add element to end of array
bool insertElement(int *arr, int *numElements, int arraySize, int newElement)
{
    // Check if array is full
    if (*numElements >= arraySize)
    {
        printf("Error: Array is full, cannot insert %d\n", newElement);
        return false;
    }

    // Insert element at the end
    arr[*numElements] = newElement;
    (*numElements)++;

    return true;
}

// REMOVE: Remove first occurrence of element
bool removeElement(int *arr, int *numElements, int elementToRemove)
{
    // Check if array is empty
    if (*numElements == 0)
    {
        printf("Error: Array is empty, cannot remove element\n");
        return false;
    }

    // Search for the element
    int foundIndex = -1;
    for (int i = 0; i < *numElements; i++)
    {
        if (arr[i] == elementToRemove)
        {
            foundIndex = i;
            break;
        }
    }

    // If element not found
    if (foundIndex == -1)
    {
        return false;
    }

    // Remove element by replacing it with the last element
    // This is the efficient O(1) method shown in your lecture
    arr[foundIndex] = arr[*numElements - 1];
    (*numElements)--;

    return true;
}

// Alternative remove function that maintains order (O(n) complexity)
bool removeElementMaintainOrder(int *arr, int *numElements, int elementToRemove)
{
    if (*numElements == 0)
    {
        return false;
    }

    int foundIndex = -1;
    for (int i = 0; i < *numElements; i++)
    {
        if (arr[i] == elementToRemove)
        {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1)
    {
        return false;
    }

    // Shift all elements after the found index to the left
    for (int i = foundIndex; i < *numElements - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    (*numElements)--;

    return true;
}

// SEARCH: Linear search for an element
int searchElement(int *arr, int numElements, int target)
{
    for (int i = 0; i < numElements; i++)
    {
        if (arr[i] == target)
        {
            return i; // Return index where element is found
        }
    }
    return -1; // Element not found
}

// TRAVERSE: Visit each element (simple print)
void traverseArray(int *arr, int numElements)
{
    for (int i = 0; i < numElements; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// TRAVERSE: Calculate sum of all elements
int findSum(int *arr, int numElements)
{
    int sum = 0;
    for (int i = 0; i < numElements; i++)
    {
        sum += arr[i];
    }
    return sum;
}

// TRAVERSE: Find maximum element
int findMax(int *arr, int numElements)
{
    if (numElements == 0)
    {
        printf("Error: Cannot find max of empty array\n");
        return -1;
    }

    int max = arr[0];
    for (int i = 1; i < numElements; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

// SEARCH: Find all occurrences of an element
int findAllOccurrences(int *arr, int numElements, int target, int *indices)
{
    int count = 0;
    for (int i = 0; i < numElements; i++)
    {
        if (arr[i] == target)
        {
            indices[count] = i;
            count++;
        }
    }
    return count;
}

// TRAVERSE: Find and print all duplicate elements
void printDuplicates(int *arr, int numElements)
{
    printf("Duplicate elements found:\n");
    bool foundDuplicates = false;

    for (int i = 0; i < numElements; i++)
    {
        int count = 0;
        int indices[10]; // Assuming max 10 occurrences

        // Count occurrences of current element
        for (int j = 0; j < numElements; j++)
        {
            if (arr[j] == arr[i])
            {
                indices[count] = j;
                count++;
            }
        }

        // If element appears more than once and we haven't reported it yet
        if (count > 1)
        {
            // Check if we've already reported this value
            bool alreadyReported = false;
            for (int k = 0; k < i; k++)
            {
                if (arr[k] == arr[i])
                {
                    alreadyReported = true;
                    break;
                }
            }

            if (!alreadyReported)
            {
                printf("  Element %d appears %d times at indices: ", arr[i], count);
                for (int k = 0; k < count; k++)
                {
                    printf("%d ", indices[k]);
                }
                printf("\n");
                foundDuplicates = true;
            }
        }
    }

    if (!foundDuplicates)
    {
        printf("  No duplicates found.\n");
    }
}

// REMOVE: Remove all occurrences of an element
int removeAllOccurrences(int *arr, int *numElements, int elementToRemove)
{
    int removedCount = 0;
    int writeIndex = 0;

    // Use two pointers approach: read from readIndex, write to writeIndex
    for (int readIndex = 0; readIndex < *numElements; readIndex++)
    {
        if (arr[readIndex] != elementToRemove)
        {
            // Keep this element
            arr[writeIndex] = arr[readIndex];
            writeIndex++;
        }
        else
        {
            // Skip this element (effectively removing it)
            removedCount++;
        }
    }

    *numElements = writeIndex;
    return removedCount;
}

// REMOVE: Remove duplicates, keeping only one occurrence of each element
void removeDuplicates(int *arr, int *numElements)
{
    int writeIndex = 0;

    for (int readIndex = 0; readIndex < *numElements; readIndex++)
    {
        // Check if current element already exists in the "kept" portion
        bool isDuplicate = false;
        for (int j = 0; j < writeIndex; j++)
        {
            if (arr[j] == arr[readIndex])
            {
                isDuplicate = true;
                break;
            }
        }

        // If not a duplicate, keep it
        if (!isDuplicate)
        {
            arr[writeIndex] = arr[readIndex];
            writeIndex++;
        }
    }

    *numElements = writeIndex;
}