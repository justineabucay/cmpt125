

#include <stdio.h>

int main(void)
{
    const int MIN = 1;
    const int MAX = 20;
    // x inc L->R; y inc B->T
    int x = 0;
    int y = 0;
    int z = 0;

    printf("Please, enter 3 integers between %d and %d (incl.): ", MIN, MAX);
    int result = scanf("%d %d %d", &x, &y, &z);

    // user input (1-20): 3 integers = width (x), breath (y) + height (z)
    if (result > 1)
    {
        if ((x >= MIN && x <= MAX) && (y >= MIN && y <= MAX) && (z >= MIN && z <= MAX))
        {
            // if 0 or max = #, else .
            for (int row = 0; row < y; row++)
            { 
                for (int col = 0; col < x; col++)
                {
                    if (row == 0 || row == y-1 || col == 0 || col == x-1)
                        printf("#");
                    else
                        printf(".");
                }
                printf("\n");
            }
        }
        else
        {
            if (x < MIN || x > MAX)
                printf("Invalid input width (%d)\n", x);
            else if (y < MIN || y >=MAX)
                printf("Invalid input breath (%d)\n", y);
            else if (z < MIN || z > MAX)
                printf("Invalid input height (%d)\n", z);
        }
    }

    // every remaining row, 1 or 2 #'s are drawn to cover the left-most + right-most position

    // any non-boundary area must be filled w/ .
}