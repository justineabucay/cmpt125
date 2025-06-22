/* Header Comment Block */

#include <stdio.h>

int isUpperCaseLetter( char theChar ) {

    if( theChar >= 'A' && theChar <= 'Z' )
        return 1;

    return 0;
}

int main( void ) {
    
    char aChar = 1;
    unsigned long charCount = 0;
    unsigned long upperCaseLetterCount = 0;

    while ( ( aChar = getchar() ) != EOF ) {

        charCount++;
        
        if ( isUpperCaseLetter( aChar ) ) {
            printf( "%c is an upper letter.\n", aChar );
            upperCaseLetterCount++;
        }
        // else printf( "%c is NOT an upper letter.\n", aChar );
    }
  
    printf( "Read %lu characters from stdin and %lu characters were upper case letters.\n", charCount, upperCaseLetterCount );

    return 0;
}