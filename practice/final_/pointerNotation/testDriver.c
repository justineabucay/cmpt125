#include <stdio.h>
#include <stdlib.h>
#include <time.h> // for time()
#include "pointer.h"

int main(void)
{
    basic_pointer();

    printf("\n\n");
    addressVsValue();

    printf("\n\n");
    int num = 5;
    doubleVal(&num);
    printf("after doubling the value: %d\n", num);

    int x = 3, y = 7;
    swapVal(&x, &y);
    printf("after swap: x=%d, y=%d\n", x, y);

    printf("\n\n");
    int min, max;
    findMinMax(5, 2, 8, &min, &max);
    printf("Min: %d, Max: %d\n", min, max);

    int numbers[] = {1, 2, 3, 4, 5};
    int size1 = 5;                       // Fixed: changed to int
    int result = sumArr(numbers, size1); // Fixed: removed &

    printf("Sum: %d\n", result); // Should print 15
    doubleArray(numbers, size1); // Fixed: removed & and simplified parameter
    printAll(numbers, size1);    // Fixed: removed & and simplified parameter

    printf("\n\n");
    srand(time(0));

    int size = 0;
    int *anArray = getRandomArray(&size);
    printf("the array that we are working on: ");
    printAll(anArray, size); // Fixed: removed & from anArray

    // Test findNegative with array containing negative numbers

    int *negPtr = findNegative(anArray, size);
    if (negPtr != NULL)
    {
        printf("First negative number found: %d\n", *negPtr);
    }
    else
    {
        printf("No negative numbers found\n");
    }

    printf("\n\n");
    unsigned int x1 = 20;
    printf("before resetting the value: %d\n", x1);
    resetVal(&x1);
    printf("after resetting the value: %d\n", x1);

    printf("\n\n");
    x1 = 20;
    printf("before resetting the value: %d\n", x1);
    increment(&x1);
    printf("after resetting the value: %d\n", x1);

    printf("\n\n");
    int num1 = 2; 
    int num2 = 4; 
    printf("the larger number %d:", *(getLarger(&num1, &num2)));

    printf("\n\n");
    char theStr[] = "hello, world";
    int length = stringLength(theStr);
    printf("length of string: %d", length);

    printf("\n\n");
    const int LENGTH = 100;
    char dest[LENGTH] = "";

    (stringCopy(dest, theStr));
    printf("Source: %s\n", theStr);
    printf("Destination: %s\n", dest);

    printf("\n\n");
    int sizeArr1 = 0; 
    int* testArr1 = getRandomArray(&sizeArr1);
    int* minVal = findMinAddress(testArr1, sizeArr1);
    printf("min value in the ");
    printAll(testArr1, sizeArr1); 
    printf("min value in the array: %d\n", *minVal);
    printf("the address of the min value in the array: %p", &minVal);

    printf("\n\n");
    int sizeArr2 = 0;
    int* testArr2 = getRandomArray(&sizeArr2);
    printf("array before reversing:");
    printAll(testArr2, sizeArr2);
    printf("result: "); 
    printAll(reverseArr(testArr2, sizeArr2), sizeArr2); 

    free(anArray);
    free(testArr2);
    free(testArr1);
    return 0;
}