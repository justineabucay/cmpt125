/*
 * Filename: Dynamic_Arrays.c
 *
 * Description: Demonstating dynamic memory allocation.
 *
 * Author: AL
 * Date: June 2025
 */

#include <stdlib.h>
#include <stdio.h>

int * getArray( unsigned int maxsize ) {

  // Dynamically allocate memory for array          // CORRECT: the function malloc() allocates 20 bytes on the heap and assigns the address of allocated memory in the pointer variabe, anArray
  int * anArray = malloc( maxsize * sizeof(int) ); // INCORRECT: calling a stack frame for the function malloc(), which we are passing 20 bytes of memory and assigning it to the memory address at which an integer is stored

  // Check pointer validity: make sure that malloc() was successful. otherwise, it returns a NULL 
  if ( anArray == NULL ) {
    perror( "allocating a maxsize * sizeof(int) array failed" );  // or printf(...)
    exit(1);
  }
	
  // Initialize the array
  for( unsigned int index = 0; index < maxsize; index++ )
    anArray[index] = index;

  return anArray; // return the memory address of the first byte
}

void printArray( int anArray[ ], unsigned int arraySize ) {

  for ( unsigned int index = 0; index < arraySize; index++ ) 
    printf( "array[%d] = %d\n", index, anArray[index] );

  return;
}

int main( void ) { 

  const unsigned int SIZE = 5; 
  int * intArray = NULL; // pointer to an integer (i.e., memory address which has a size of 8 bytes)

  // Allocate intArray
  printf("Allocate and initialize intArray!\n");
  intArray = getArray( SIZE );

/*  or   
	// Allocate intArray
    printf("Allocate intArray before initializing it:\n");
    int * intArray = getArray( intArray, SIZE );
*/	
	
  // Printing intArray
  printf("Printing intArray:\n");
  printArray( intArray, SIZE );
	
  // Deallocate array
  free( intArray );
  
  // Avoid dangling pointer
  intArray = NULL;
    
  return 0;
}
