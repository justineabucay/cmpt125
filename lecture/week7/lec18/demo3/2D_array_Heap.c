/*
 * Filename: 2D_array_Heap.c
 *
 * Description: This program manipulates 2D arrays (matrices)
 *
 * Author: AL
 * Date: June 2025
 */

#include <stdio.h>  // printf()
#include <stdlib.h> // for rand() and atoi()
#include <time.h>   // for time()

void fillRandom(unsigned int rows, unsigned int cols, char theArray[][cols])
{

    const unsigned int LIMIT = 10;

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

void fillDiagonal(unsigned int rows, unsigned int cols, char theArray[][cols])
{

    const unsigned int OFF_DIAGONAL = 0;
    const unsigned int ON_DIAGONAL = 1;

    // Fill the array with a diagonal
    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < cols; j++)
        {
            if (i == j)
                theArray[i][j] = ON_DIAGONAL;
            else
                theArray[i][j] = OFF_DIAGONAL;
        }
    }

    return;
}

// Possible Solution to Lecture 19 Flipped Class - Exercise 1
void fillDiagonal2(unsigned int rows, unsigned int cols, char theArray[][cols])
{

    const unsigned int OFF_DIAGONAL = 0;
    const unsigned int ON_DIAGONAL = 1;

    // Fill the array
    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < cols; j++)
        {
            theArray[i][j] = OFF_DIAGONAL;
        }
    }

    // Create the diagonal
    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < cols; j++)
        {
            if (i == j)
                theArray[rows - 1 - i][j] = ON_DIAGONAL;
        }
    }

    return;
}

void printArray(unsigned int rows, unsigned int cols, char theArray[][cols])
{

    // Print the array
    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < cols; j++)
        {
            printf("%d ", theArray[i][j]);
        }
        printf("\n");
    }

    return;
}

int sumDiagonal(unsigned int rows, unsigned int cols, char theArray[][cols])
{

    int sum = 0;

    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < cols; j++)
        {
            if (i == j)
                sum += theArray[i][j];
        }
    }

    return sum;
}

int main(int argc, char *argv[])
{

    if (argc < 2)
    {

        puts("Expecting dimension of matrix as argument! Try again!");
    }
    else
    {

        // Convert the user input into an int
        unsigned int dim = atoi(argv[1]);
        printf("dimension = %d\n", dim);

        // Declare a 2D array on the heap
        char *theArray = malloc(dim * dim * sizeof(char));
        if (theArray != NULL)
        {

            // Fill the array with random numbers
            printf("\n%d by %d matrix filled with random numbers:\n", dim, dim);
            fillRandom(dim, dim, theArray);

            printArray(dim, dim, theArray);

            // Sum the numbers in the "top left to bottom right" diagonal
            // and report back to user
            printf("Sum of the numbers making up the top left to bottom right diagonal = %d\n", sumDiagonal(dim, dim, theArray));

            free(theArray);
            theArray = NULL;
        }
    }

    return 0;
}

/* OUTPUT:

$ ./2D4 4
dimension = 4

4 by 4 matrix filled with random numbers:
5 6 2 4
7 7 5 6
1 6 0 0
0 7 7 8
Sum of the numbers making up the top left to bottom right diagonal = 20

*/

/* OUTPUT: (boundary case)

$ ./2D4 0
dimension = 0

0 by 0 matrix filled with random numbers:
Sum of the numbers making up the top left to bottom right diagonal = 0

*/
