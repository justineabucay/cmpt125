/*
 * Filename: testDriver.c
 *
 * Description: This program tests the functions fillArray(...) and sumOfOdd(...).  
 * 
 * Author: AL
 * Date: June 2025
 */

#include <stdio.h>     // for printf()
#include <stdlib.h>    // for atoi()
#include "oddArrays.h"

int main( int argc, char * argv[] ) {
    
  if ( argc != 2 ) { 
    printf( "Missing an argument. Try again!\n"); 
    return 1; 
  } 
  unsigned int size = atoi( argv[1] );
  int arrayOfInt[size];

  // Filling the array with integers entered by the user
  fillArray( arrayOfInt, size );

  printf( "Content of array: ");
  for ( unsigned int index = 0; index < size; index++ ) {
    printf( "%d ", arrayOfInt[index] );
  }
  printf( "\n" );
  
  // Sum up all odd integers entered in the array 
  printf( "The sum up all odd integers entered in the array is %d.\n", 
          sumOfOdd( arrayOfInt, size ) );
  
  return 0;
}