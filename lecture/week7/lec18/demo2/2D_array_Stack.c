/*
 * Filename: 2D_array_Stack.c
 *
 * Description: This program manipulates arrays.
 *
 * Author: AL
 * Date: June 2025
 */

#include <stdio.h>  // printf()
#include <stdlib.h> // for rand() and atoi()
#include <time.h>   // for time()
#include <stdint.h>

void fillRandom(unsigned int rows, unsigned int cols, uint8_t theArray[][cols])
{

    const unsigned int LIMIT = 256;

    // Intialize the random number generator with the current time in seconds
    srand(time(NULL));

    // Fill the array with random numbers
    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < cols; j++)
        {
            theArray[i][j] = rand() % LIMIT;
        }
    }

    return;
}

void printArray(unsigned int rows, unsigned int cols, uint8_t theArray[][cols])
{

    // Print the array
    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < cols; j++)
        {
            printf("%d ", theArray[i][j]); // direct 2D indexing
        }
        printf("\n");   // printing out a new line each row
    }

    return;
}

int main(int argc, char *argv[])
{

    if (argc < 3)
    {

        puts("Expecting rows and cols of array as arguments! Try again!");
    }
    else
    {

        // Convert the user input into unsigned int
        unsigned int rows = atoi(argv[1]);
        printf("There are %d rows in this array.\n", rows);
        unsigned int cols = atoi(argv[2]);
        printf("There are %d cols in this array.\n", cols);

        // Declare an array on the stack (main's stack frame)
        uint8_t theArray[rows][cols];   // VLA: determines the size of the array

        // Fill the array with random shades of grey
        printf("\ntheArray filled with random shades of grey from 0 to 255:\n");
        fillRandom(rows, cols, theArray);
        printArray(rows, cols, theArray);
    }

    return 0;
}