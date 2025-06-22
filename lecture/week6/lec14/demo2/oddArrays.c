/*
 * Filename: oddArrays.c
 *
 * Description:                 
 *
 * Author: AL
 * Date: June 2025
 */

#include <stdio.h>

void fillArray( int intArray[], unsigned int arraySize ) {

  // Initialize the array using user input
  printf( "Please, enter %d integers then press ENTER: ", arraySize );
  for ( unsigned int index = 0; index < arraySize; index++ ) {
    scanf( "%d", &intArray[index] );
  }
  return;
} 

int sumOfOdd( int intArray[], unsigned int arraySize ) {
	int sum = 0;
	
  // Running sum of all odd integers in array
  for ( unsigned int index = 0; index < arraySize; index++ ) {
    if ( intArray[index] % 2 == 1 ) sum += intArray[index];
  }
  
  // Since this function does not print the sum, this implies it returns it!
  // Returning the sum would be one way to share this function's result, i.e.,
  // the sum, with the caller -> main(...)
  return sum;
} 