/*
 * Filename: CtoF_Table_for.c
 *
 * Description: Create a table of Celsius temperatures 
 *              and corresponding Fahrenheit temperatures.
 *              
 * Author: AL
 * Date: June 2025
 */

 #include <stdio.h>

 int main( void ) {   
   const float LOWER = 0.0;     // Lower limit of temperature table
   const float UPPER = 150.00;  // Upper limit of temperature table
   int step = 10;               // Size of step - could be a constant
   float fahTemp = 0.0;
 
   // Print column headings
   printf( "Celsius\tFahrenheit\n");
     
   // While celTemp has not reached the upper limit of T table
   for ( float celTemp = LOWER; celTemp <= UPPER; celTemp += step ) {   // Condition
       
     // Convert celTemp to fahTemp
     fahTemp = celTemp * (9.0/5) + 32;
     
     // Print T's in a row
     printf("%0.2f\t%0.2f\n", celTemp, fahTemp);
   } 
   
   return 0;
 }
 