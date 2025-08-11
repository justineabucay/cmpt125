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

    return 0; 
}