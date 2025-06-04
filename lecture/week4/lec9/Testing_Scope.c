/*
filename: Testing_Scope.c 
decription: testing how variable/constant scope works
author: justine abucay
date: june 4, 2025
*/

#include <stdio.h>

int main( void ) {
  const int LIMIT = 10;
  int test = 99;

  for ( unsigned int step = 0; step < LIMIT; step++ ) {
    short twice = 0;  // Declare twice outside the if block
    
    if ( step % 2 == 0 ) {
      twice = step * 2;
      printf( "1: step %d is even, and twice = %hi ... and ", step, twice );
    } else {
      twice = -1;  // Or some default value for odd steps
    }
    
    // Now twice is accessible here
    printf( "2: step %d, twice = %hi ... and ", step, twice );
    printf( "test = %d.\n", test );
  }

  // These variables are out of scope here, so we need to handle them differently
  printf( "3: Loop completed. LIMIT is %d and the last test = %d.\n", LIMIT, test );
  return 0;
}