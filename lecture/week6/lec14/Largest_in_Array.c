/*
 * Filename: Largest_in_Array.c
 *
 * Description: Functions to find largest
 *              and smallest element in array.
 *
 * Author: AL
 * Date: June 2025
 */

#include <stdio.h> // for printf() and scanf()

// Description: Returns the largest element in array
//              using array notation.
int largest_arr( int arr[], unsigned int len ) {

    int largest = arr[0];
	for ( unsigned int i = 1; i < len; i++ )
    	if( arr[i] > largest ) largest = arr[i];

    return largest;
}

// Description: Returns the largest element in array
//              using pointer notation.
int largest_ptr( int * arr, unsigned int len ) {

    int largest = *arr++;   // deferences the first element (i.e., grabbing the actual value) and assigns its value to largest and then increments th epointer
                            // now, largest gets the value of the first element
                            // and arr is moved to point to the second element
	for ( unsigned int i = 1; i < len; i++ ){
    	if( *arr > largest ) largest = *arr;    // *arr = deference of the element at specific index
    	arr++; // increment: changing where the local copy of the pointer (i.e., arr) points. in other words, moving the pointer to the next memory address
	}

    return largest;
}

// Description: Returns the largest element in array
//              using pointer notation.
int largest_ptr_2( int * arr, unsigned int len ) {

    int largest = *arr; // First element of array arr

	for ( unsigned int i = 1; i < len; i++ ){
    	if( *(arr + i) > largest ) largest = *(arr + i);    // adding i to arr (i.e., arr[i]) but we are also deferencing it, meaning that we are grabbing the value at that specific index
	}

    return largest;
}

int main( void ) {

	const unsigned int SIZE = 10;

	// Test Case 1:
    int arr[SIZE] = { 3, 6, 9, 2, 0, 8, 4, 8, 1, 5 };

  // Echo Test Case 1 - test data to stdout
    for ( unsigned int i = 0; i < SIZE; i++ ) {
    	printf( "arr[%u] = %d, ", i, arr[i] );
    }

	printf("\nLargest is\n");
	printf("\tlargest_arr: %d\n", largest_arr( arr, SIZE ));
	printf("\tlargest_ptr: %d\n", largest_ptr( arr, SIZE ));
	printf("\tlargest_ptr_2: %d\n", largest_ptr_2( arr, SIZE ));

    return 0;
}