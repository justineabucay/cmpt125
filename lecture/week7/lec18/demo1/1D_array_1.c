/*
 * Filename: 1D_array_1.c
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

void fillRandom(uint8_t theArray[], unsigned int rows, unsigned int cols)
{

    const unsigned int LIMIT = 256;

    // Intialize the random number generator with the current time in seconds
    srand(time(NULL));

    // Fill the array with random numbers
    for (unsigned int i = 0; i < rows * cols; i++)
    {
        theArray[i] = rand() % LIMIT; // grabbing random number 0-255
    }

    return;
}

void printArray(uint8_t theArray[], unsigned int rows, unsigned int cols)
{

    // Print the array
    for (unsigned int y = 0; y < rows; y++)
    {
        for (unsigned int x = 0; x < cols; x++)
        {
            printf("%d ", theArray[x + y * cols]); // access the raster image
        }
        printf("\n");
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
        printf("There are %d rows in this array.\n", rows); // echoing the input
        unsigned int cols = atoi(argv[2]);
        printf("There are %d cols in this array.\n", cols);

        // Declare a pointer
        uint8_t *theArray = NULL;

        // Dynamically allocate memory
        theArray = malloc(rows * cols * sizeof(uint8_t));
        // Check to see if malloc(...) was successful
        if (theArray != NULL)
        {

            // Fill the array with random shades of grey
            printf("\ntheArray filled with random shades of grey from 0 to 255:\n");
            fillRandom(theArray, rows, cols);
            printArray(theArray, rows, cols);
        }
    }

    return 0;
}
