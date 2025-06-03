/*
 * Filename: values.c
 *
 * Description: a program that reads a floating point value then outputs results from
 * using math functions
 *
 * Author: Justine Abucay 30150624
 * Date: May 27, 2025
 */

#include <stdio.h>
#include <math.h>

int main(void) {

    float num = 0.0;

    // prompt user
    printf("please, enter a floating point value: ");
    scanf("%f", &num);

    // print results
    printf("the smallest integer larger than or equal to %.6f is %.f.\n", num, ceil(num));
    printf("the nearest integer to %.6f is %.f.\n", num, round(num));
    printf("the largest integer smallet than or equal to %.6f is %.f.", num, floor(num));
    
    return (0);
}
