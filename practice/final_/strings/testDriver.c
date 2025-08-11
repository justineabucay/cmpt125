#include <stdio.h> 
#include <stdlib.h>
#include "strings.h"

int main (void){
    // exercise 1.1
    stringDemo();

    // exercise 1.2
    char source[] = "hello";
    char dest[10];

    printf("\n\n");
    // finding the length of the string
    printf("Length: %d\n", myStrLen(source)); // Should be 5

    // copying from one string to another
    myStrCopy(dest, source);
    printf("Copied: %s\n", dest);                     // Should be "hello"
   
    // comparing strings
    int result = 0;
    result = myStrCmp("bye", "hello");

    if(result == 0)
        printf("strings are the same!\n");
    else
        printf("strings are different");

    // part 2: number to strong conversion
    // exercise 2.1

    printf("\n\n");
    char *result1;
    result1 = int2str(0);
    printf("int2str(0) = '%s'\n", result1); // Should be "0"
    free(result1);

    result1 = int2str(5);
    printf("int2str(5) = '%s'\n", result1); // Should be "5"
    free(result1);

    result1 = int2str(123);
    printf("int2str(123) = '%s'\n", result1); // Should be "123"
    free(result1);

    result1 = int2str(999);
    printf("int2str(999) = '%s'\n", result1); // Should be "999"
    free(result1);

    // exercise 2.2
    // integer -> binary
    printf("\n\n");

    char *result2; 
    result2 = int2bin(0); 
    printf("int2str(0) = '%s'\n", result2); 
    free(result2);

    result2 = int2bin(5);
    printf("int2str(5) = '%s'\n", result2);
    free(result2);

    result2 = int2bin(123);
    printf("int2str(123) = '%s'\n", result2);
    free(result2);

    result2 = int2bin(999);
    printf("int2str(999) = '%s'\n", result2);
    free(result2);

    return 0; 
}