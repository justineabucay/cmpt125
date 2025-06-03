/*
 * Filename: apples.c
 *
 * Description: a program that calculates how many apples are left over and how many bags were produced
 * from the given data 
 *
 * Author: Justine Abucay 30150624
 * Date: May 27, 2025
 */


#include <stdio.h>
#include <math.h>

int main(void)
{
    int apples = 0;
    int applesPerBag = 0;
    int result = 0;

    // ask for input
    while (result != EOF)
    {
        printf("Please, enter the number of apples available and the number of apples each bag holds: ");
        result = scanf("%d %d", &apples, &applesPerBag);

        if(result == 2){
            printf("Number of apples available => %d, number of apples each bag holds => %d\n", apples, applesPerBag);
            printf("Number of bags produced => %d, number of apples left over => %d\n", (int)round(apples / applesPerBag), (int)apples % applesPerBag);
        }
    }

    printf("\nDone.\n");

    return 0;
}
