/*
 * Filename: GradeBook_while.c
 *
 * Description: Grade book application: given a grade, prints the corresponding letter grade.
 *
 * Author: Justine Abucay
 * Date: May 30, 2025
 */

#include <stdio.h>

int main(void)
{
    const int MINGRADE = 0;
    const int MAXGRADE = 100;
    // grab input from user from 0-100 (inclusively)
    // inclusive = from 1 to 5: 1, 2, 3, 4, 5

    int grade = 0;
    int result = 0;

    printf("Please, enter a grade from 0 to 100 (inclusively): ");
    
    while ((result =scanf("%d", &grade)) == 1)
    {
        if ((grade < MINGRADE) || grade > MAXGRADE)
            printf("%d is an invalid grade. Range of valid grades is [%d .. %d]. Please, try again!\n", grade, MINGRADE, MAXGRADE);
        else if (grade >= 90)
            printf("%d => A\n", grade);
        else if (grade >= 80)
            printf("%d => B\n", grade);
        else if (grade >= 70)
            printf("%d => C\n", grade);
        else if (grade >= 60)
            printf("%d => D\n", grade);
        else if (grade >= 50)
            printf("%d => E\n", grade);
        else
            printf("%d => F\n", grade);

        printf("Please, enter a grade from 0 to 100 (inclusively): ");
        
    }

    printf("\nDone\n");

    return 0;
}