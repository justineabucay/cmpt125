/*
 * Filename: funcs.c
 *
 * Description: Create a larger functions and a smaller function.
 *              larger returns the larger of its two parameters
 *              smaller returns the smaller of its two parameters
 *
 * Author: AL
 * Date: June 2025
 */

// Description: Returns the larger of its two parameters
int larger( int int1, int int2 ) {

    int larger = int2;

    if ( int1 > int2 ) larger = int1;

    return larger;
}

// Description: Returns the smaller of its two parameters
int smaller( int int1, int int2 ) {

    int smaller = int2;

    if ( int1 < int2 ) smaller = int1;

    return smaller;
}
