#include "InRectangle.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    {
        // Define a rectangle from (1,1) to (2,2)
        float rect[CORNERS] = {1.0, 1.0, 2.0, 2.0};

        // Test Case 1
        // Define a point that is inside the rectangle
        float p_in[POINTS] = {1.5, 1.5};
        printf("Test Case 1\n");
        printf("\tTest Data: rectangle: (1.0,1.0) and (2.0,2.0), point: (1.5,1.5)\n");
        printf("\tExpected Result: point is in the rectangle!\n");
        if (InRectangle(p_in, rect) == 0)
        {
            puts("\nTest Case 1 - error: should return true for point (1.5,1.5).");
            return 1; // indicate error
        }
        else
            printf("\tActual Result: point is in the rectangle!\n");
    }

    {
        // Test Case 2
        // Define a point that is outside the rectangle
        float rect[CORNERS] = {1.0, 1.0, 3.0, 3.0};
        float p_in[POINTS] = {5.0, 5.0};
        printf("Test Case 2\n");
        printf("\tTest Data: rectangle: (%.2f,%.2f) and (%.2f,%.2f, point: (%.2f,%.2f)\n", rect[0], rect[1], rect[2], rect[3], p_in[0], p_in[1]);
        printf("\tExpected Result: point is outside the rectangle!\n");
        if (InRectangle(p_in, rect) == 1)
        {
            printf("\nTest Case 2 - error: should return true for point (%.2f,%.2f).\n", p_in[0], p_in[1]);
            return 1; // indicate error
        }
        else
            printf("\tActual Result: point is outside the rectangle!\n");
    }

    {
        // Test Case 3
        // Define a point that is on the left edge of the rectangle
        float rect[CORNERS] = {2.0, 2.0, 5.0, 4.0};
        float p_in[POINTS] = {2.0, 3.0};
        printf("Test Case 3\n");
        printf("\tTest Data: rectangle: (%.2f,%.2f) and (%.2f,%.2f, point: (%.2f,%.2f)\n", rect[0], rect[1], rect[2], rect[3], p_in[0], p_in[1]);
        printf("\tExpected Result: point is on the left edge of the rectangle!\n");
        if (InRectangle(p_in, rect) == 0)
        {
            printf("\nTest Case 3 - error: should return true for point (%.2f,%.2f).\n", p_in[0], p_in[1]);
            return 1; // indicate error
        }
        else
            printf("\tActual Result: point is on the left edge the rectangle!\n");
    }

    {
        // Test Case 4
        // Define a point that is on the right edge of the rectangle
        float rect[CORNERS] = {1.0, 1.0, 4.0, 3.0};
        float p_in[POINTS] = {4.0, 2.0};
        printf("Test Case 4\n");
        printf("\tTest Data: rectangle: (%.2f,%.2f) and (%.2f,%.2f, point: (%.2f,%.2f)\n", rect[0], rect[1], rect[2], rect[3], p_in[0], p_in[1]);
        printf("\tExpected Result: point is on the right edge of the rectangle!\n");
        if (InRectangle(p_in, rect) == 0)
        {
            printf("\nTest Case 4 - error: should return true for point (%.2f,%.2f).\n", p_in[0], p_in[1]);
            return 1; // indicate error
        }
        else
            printf("\tActual Result: point is on the right edge the rectangle!\n");
    }

    {
        // Test Case 5
        // Define a point that is on the bottom edge of the rectangle
        float rect[CORNERS] = {1.0, 2.0, 4.0, 5.0};
        float p_in[POINTS] = {2.5, 2.0};
        printf("Test Case 5\n");
        printf("\tTest Data: rectangle: (%.2f,%.2f) and (%.2f,%.2f, point: (%.2f,%.2f)\n", rect[0], rect[1], rect[2], rect[3], p_in[0], p_in[1]);
        printf("\tExpected Result: point is on the bottom edge of the rectangle!\n");
        if (InRectangle(p_in, rect) == 0)
        {
            printf("\nTest Case 5 - error: should return true for point (%.2f,%.2f).\n", p_in[0], p_in[1]);
            return 1; // indicate error
        }
        else
            printf("\tActual Result: point is on the bottom edge the rectangle!\n");
    }

    // Feel free to add more test cases!

    return 0; // all tests passed
}