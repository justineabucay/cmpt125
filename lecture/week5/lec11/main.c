/*
 * Filename: main.c 
 *
 * Description: Test Driver for larger and a smaller functions.
 *
 * Author: AL./
 * Date: June 2025
 */
 
 #include <stdio.h> // for printf() and scanf()
 #include "funcs.h"
 
 int main( void ) {
     int num1 = 0;
     int num2 = 0;
 
     printf("Please, enter two integers: ");
     if ( scanf("%d %d", &num1, &num2 ) == 2) {
         printf( "Larger of %d and %d is %d\n", num1, num2, larger( num1, num2 ));
         printf( "Smaller of %d and %d is %d\n", num1, num2, smaller( num1, num2 ));
     }
 
     return 0;
 }