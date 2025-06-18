/*
 * Filename: testDriver.c
 *
 * Description: This file tests the function scrambled(…).  
 * 
 * Author: AL
 * Date: June 2025
 */

#include <stdio.h>
#include "scrambled.h"

int main( void ) {

  unsigned int size = 3;
  unsigned int result = 0;

  printf( "\nTesting the function scrambled(...)\n\n" );
	  
  // Test case 1 - Both arrays are scrambled version of each other!
  int arr1[] = { 11, 12, 20 };
  int arr2[] = { 10, 20, 15 };   
  
  // Add more test cases here

  if ( ( result = scrambled( arr1, arr2, size ) ) == 1 )
  	printf( "%d means that both arrays are scrambled version of each other.\n", result );
  else
  	printf( "%d means that both arrays are NOT scrambled version of each other.\n", result );

  return 0;
}
