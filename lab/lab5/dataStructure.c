/*
 * dataStructure.c
 *
 * Provides a bound-checked data structure made of an array of integers
 * in which duplicated elements are allowed.
 *
 * The interface of this data structure includes several utility
 * functions that operate on this array of integers as well as
 * file i/o functions: saving into and loading from json files.
 *
 * Do not change the dataStructure.h file.
 *
 * Author: RV + AL
 * Modified Date: July 2025
 */

#include <stdlib.h> // for malloc()
#include <stdio.h>  // for file i/o calls
#include <string.h> // for strlen()

#include "dataStructure.h"

/*
 * Description: Creates a new intArray_t data structure
 *              with initial array size "size". If successful
 *              (i.e. size is > 0 and memory allocation succeeds),
 *              returns a pointer to a newly-allocated intArray_t.
 *              If unsuccessful, returns a NULL pointer.
 * Time Efficiency: O(1)
 */
intArray_t *intArray_create(unsigned int size)
{

    // Validate the parameter "size"
    if (size == 0)
        return NULL;

    // Allocate memory on the heap for intArray_t struct
    intArray_t *ia = malloc(sizeof(intArray_t));
    if (ia != NULL)
    {

        // Set its field "size"
        ia->size = size;

        // Allocate memory on the heap for array
        ia->data = malloc(size * sizeof(int));
        if (ia->data == NULL)
        {
            free(ia);
            ia = NULL;
        }
        else
            // Set its field "elementCount" to zero -> empty array
            ia->elementCount = 0;
    }
    return ia;
}

/*
 * Description: Frees all memory allocated for "ia".
 *              If the pointer "ia->data" is NULL, it does not attempt
 *              to free it. Returns INTARR_OK.
 *              If the pointer "ia" is NULL, it returns INTARR_BADPARAM.
 * Time Efficiency: O(1)
 */
intArrayResult_t intArray_destroy(intArray_t *ia)
{

    intArrayResult_t result = INTARR_BADPARAM;

    // If heap memory has been allocated for intArray_t struct ...
    if (ia != NULL)
    {

        // If heap memory has been allocated for array ...
        if (ia->data != NULL)
        {
            // ... then free it
            free(ia->data); // check returned value from free(...)
            ia->data = NULL;
        }

        // ... then free it.
        free(ia); // check returned value from free(...)
        ia = NULL;
        result = INTARR_OK;
    }

    return result;
}

/* Description: Appends "newElement" and returns INTARR_OK.
 *              If "newElement" cannot be appended, leaves the
 *              data structure unmodified and returns INTARR_ERROR.
 *              If "ia" is NULL, returns INTARR_BADPARAM.
 *              If "ia->data" is NULL, returns INTARR_BADPARAM.
 * Time efficiency: O(1)
 */
intArrayResult_t intArray_append(intArray_t *ia, int newElement)
{

    // Put your code here
    // check if ia is NULL
    if(ia == NULL) return INTARR_BADPARAM;
    // check if ia->data is NULL
    if (ia->data == NULL) return INTARR_BADPARAM; 

    // check if array is full
    if(ia->elementCount >= ia->size) return INTARR_ERROR;

    // append the new element
    ia->data[ia->elementCount] = newElement;
    ia->elementCount++;
   
    return INTARR_OK; // You are free to modify this return statement or not.
}

/* Description: Removes the element at "indexToBeRemoved" in the data structure
 *              and returns INTARR_OK. If the data structure was initially sorted,
 *              it does not remain sorted after removing the element at "indexToBeRemoved".
 *              If "ia" is NULL or "indexToBeRemoved" is out of bounds, returns INTARR_BADPARAM.
 *              If "ia->data" is NULL, returns INTARR_BADPARAM.
 *              If "ia->elementCount" is 0, returns INTARR_BADPARAM.
 * Time efficiency: O(1)
 */
intArrayResult_t intArray_remove(intArray_t *ia, unsigned int indexToBeRemoved)
{

    // Put your code here
    // check if ia is NULL
    if (ia == NULL)
        return INTARR_BADPARAM;
    // check if ia->data is NULL
    if (ia->data == NULL)
        return INTARR_BADPARAM;

    // check if array is empty
    if (ia->elementCount == 0)
        return INTARR_BADPARAM;

    // check if index is out of bounds
    if (indexToBeRemoved >= ia->elementCount)
        return INTARR_BADPARAM;

    // move last element to the position being removed
    ia->data[indexToBeRemoved] = ia->data[ia->elementCount - 1];
    ia->elementCount--;

    return INTARR_OK; // You are free to modify this return statement or not.
}

/* Description: Modifies (overwrites) the element at "index" with "newElement"
 *              and returns INTARR_OK. If "ia" is NULL or "index" is out of bounds,
 *              returns INTARR_BADPARAM.
 *              If "ia->data" is NULL, returns INTARR_BADPARAM.
 * Time Efficiency: O(1)
 */

intArrayResult_t intArray_modify(intArray_t *ia, int newElement, unsigned int index)
{
    // check if ia is NULL
    if (ia == NULL)
        return INTARR_BADPARAM;

    // check if ia->data is NULL
    if (ia->data == NULL)
        return INTARR_BADPARAM; // FIXED: Added return

    // check if index is out of bounds
    if (index >= ia->elementCount)
        return INTARR_BADPARAM;

    // modify the element at the given index
    ia->data[index] = newElement;

    return INTARR_OK;
}

/* Description: Finds the first occurrence of "targetElement" in the data structure,
 *              sets "*index" to its index and returns INTARR_OK. If "targetElement"
 *              does not occur in the data structure, leaves "*index" unmodified
 *              and returns INTARR_NOTFOUND. If "ia" is NULL, returns INTARR_BADPARAM.
 *              If "ia->data" is NULL, returns INTARR_BADPARAM.
 * Time efficiency: O(n)
 */

intArrayResult_t intArray_find(intArray_t *ia, int targetElement, unsigned int *index)
{
    // check if ia is NULL
    if (ia == NULL)
        return INTARR_BADPARAM;

    // check if ia->data is NULL
    if (ia->data == NULL)
        return INTARR_BADPARAM; // FIXED: Added return

    // check if index is NULL
    if (index == NULL)
        return INTARR_BADPARAM; // FIXED: Added return

    // linear search for target element
    for (unsigned int i = 0; i < ia->elementCount; i++)
    {
        if (ia->data[i] == targetElement)
        {
            *index = i;
            return INTARR_OK;
        }
    }
    return INTARR_NOTFOUND;
}

/* Description: Sorts the data structure by value in ascending sort order
 *              (smallest to largest), such that data[i] < data[i+1] for all valid i,
 *              then returns INTARR_OK. If "ia" is NULL, returns INTARR_BADPARAM.
 *              If "ia->data" is NULL, returns INTARR_BADPARAM.
 *              Works in-place: content of "ia" is sorted on return.
 *              Sorts the array using the Bubble Sort algorithm.
 * Time efficiency: O(n^2)
 * Space efficiency: O(1) - Bubble Sort is an "in-place" algorithm.
 */
intArrayResult_t intArray_sort(intArray_t *ia)
{
    // Put your code here
    // check if ia is NULL
    if (ia == NULL)
        return INTARR_BADPARAM;

    // check if ia->data is NULL
    if (ia->data == NULL)
        return INTARR_BADPARAM;

    for(unsigned int i = 0; i < ia->elementCount ; i++){
        for(unsigned int j = 0; j < ia->elementCount - i - 1; j++){
            if(ia->data[j] > ia->data[j+1]){
                int temp = ia->data[j];
                ia->data[j] = ia->data[j+1];
                ia->data[j+1] = temp;
            }
        }
    }

    return INTARR_OK; // You are free to modify this return statement or not.
}

/* Description: Returns a copy of "ia", allocating new storage
 *              for this copy data (we call this a "deep copy").
 *              If unsuccessful (i.e. memory allocation for the copy fails,
 *              or "ia" is NULL), returns a NULL pointer.
 *              If "ia->data" is NULL, returns a NULL pointer.
 */

intArray_t *intArray_copy(const intArray_t *ia)
{
    // check if ia is NULL
    if (ia == NULL)
        return NULL; // FIXED: Return NULL instead of INTARR_BADPARAM

    // check if ia->data is NULL
    if (ia->data == NULL)
        return NULL; // FIXED: Return NULL instead of INTARR_BADPARAM

    intArray_t *copy = intArray_create(ia->size);
    if (copy == NULL)
        return NULL;

    // copy all elements
    for (unsigned int i = 0; i < ia->elementCount; i++)
        copy->data[i] = ia->data[i];

    // set element count
    copy->elementCount = ia->elementCount;

    return copy;
}

/* Description: Prints the content of the struct to which "ia" points
 *              using the following format (if "ia" was pointing to
 *              a struct of data type intArray_t containing an array of
 *              size 10 with 6 elements: 8, -45, 27, 0, -22 and 13):
 *              Printing intArray_t of size 10 with 6 elements
 *                  array: 8 -45 27 0 -22 13 (end)
 *              Note that the string "array: " is printed with an indentation
 *              of one tab. Then, returns INTARR_OK.
 *              If "ia" is NULL, returns INTARR_BADPARAM.
 *              If "ia->data" is NULL, returns INTARR_BADPARAM.
 * Time Efficiency: O(n)
 */
intArrayResult_t intArray_print(intArray_t *ia)
{

    // Put your code here
    // check if ia is NULL
    if (ia == NULL)
        return INTARR_BADPARAM;

    // check if ia->data is NULL
    if (ia->data == NULL)
        return INTARR_BADPARAM;

    printf("Printing intArray_t of size %u with %u elements\n", ia->size, ia->elementCount);

    // print tab indentation
    printf("\tarray: ");
    for(unsigned int i = 0; i < ia->elementCount; i++)
        printf("%d ", ia->data[i]);
        
    printf("(end)\n");

    return INTARR_OK; // You are free to modify this return statement or not.
}

/* Description: If the array is not empty, writes (saves) "ia->elementCount"
 *              then the entire array "ia->data" into a file called by the
 *              value of the parameter "filename" in a JSON text file format
 *              (explained below) which can be loaded by the function
 *              intArray_load_from_json(...). Returns INTARR_OK on success.
 *              Returns INTARR_ERROR on failure, for example, when attempting
 *              to write (save) an empty array in the output file.
 *              If "ia" or "filename" is NULL, returns INTARR_BADPARAM.
 *              If "ia->data" is NULL, returns INTARR_BADPARAM.
 */
intArrayResult_t intArray_write_to_json(intArray_t *ia, const char *filename)
{
    if (ia == NULL || filename == NULL)
        return INTARR_BADPARAM;

    if (ia->data == NULL)
        return INTARR_BADPARAM;

    // check if array is empty
    if (ia->elementCount == 0)
        return INTARR_ERROR;

    // open file for writing
    FILE *theFile = fopen(filename, "w");
    if (theFile == NULL)
        return INTARR_ERROR;

    // write JSON format directly using fprintf
    if (fprintf(theFile, "{\n  \"elementCount\": %u,\n  \"data\": [", ia->elementCount) < 0)
    {
        fclose(theFile);
        return INTARR_ERROR;
    }

    // write array elements
    for (unsigned int i = 0; i < ia->elementCount; i++)
    {
        if (i > 0)
        {
            if (fprintf(theFile, ", %d", ia->data[i]) < 0)
            {
                fclose(theFile);
                return INTARR_ERROR;
            }
        }
        else
        {
            if (fprintf(theFile, "%d", ia->data[i]) < 0)
            {
                fclose(theFile);
                return INTARR_ERROR;
            }
        }
    }

    if (fprintf(theFile, "]\n}\n") < 0)
    {
        fclose(theFile);
        return INTARR_ERROR;
    }

    fclose(theFile);
    return INTARR_OK;

}

/* Description: Loads a new intArray_t data structure from the file called
 *              by the value of the parameter "filename", that was previously
 *              saved using intArray_write_to_json(...). Note that the file
 *              cannot contain an intArray_t data structure with an empty array.
 *              Returns a pointer to a newly allocated data structure on success
 *              or NULL on failure.
 *              If "filename" is NULL, returns NULL (not INTARR_BADPARAM).
 */
intArray_t *intArray_load_from_json(const char *filename)
{
    if (filename == NULL)
        return NULL;

    // ppen file for reading
    FILE *theFile = fopen(filename, "r");
    if (theFile == NULL)
        return NULL;

    unsigned int elementCount;

    // read JSON format
    if (fscanf(theFile, "{ \"elementCount\": %u,", &elementCount) != 1)
    {
        fclose(theFile);
        return NULL;
    }

    if (fscanf(theFile, " \"data\": [") != 0)
    {
        fclose(theFile);
        return NULL;
    }

    // create data structure with enough size for the elements
    intArray_t *ia = intArray_create(elementCount);
    if (ia == NULL)
    {
        fclose(theFile);
        return NULL;
    }

    // read the elements from JSON array
    for (unsigned int i = 0; i < elementCount; i++)
    {
        int value;
        if (i == 0)
        {
            if (fscanf(theFile, "%d", &value) != 1)
            {
                intArray_destroy(ia);
                fclose(theFile);
                return NULL;
            }
        }
        else
        {
            if (fscanf(theFile, ", %d", &value) != 1)
            {
                intArray_destroy(ia);
                fclose(theFile);
                return NULL;
            }
        }
        ia->data[i] = value;
    }

    if (fscanf(theFile, "]") != 0)
    {
        intArray_destroy(ia);
        fclose(theFile);
        return NULL;
    }

    // update data structure with actual elementCount
    ia->elementCount = elementCount;
    fclose(theFile);
    return ia;
}