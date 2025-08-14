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
    result2 = int2bin(8); 
    printf("int2str(0) = '%s'\n", result2); 
    free(result2);

    result2 = int2bin(5);
    printf("int2str(5) = '%s'\n", result2);
    free(result2);

    // integer -> hexadecimal
    printf("\n\n");

    char *result3;
    result3 = int2hex(235);
    printf("int2hex(255) = '%s'\n", result3);
    free(result3);

    result3 = int2hex(16);
    printf("int2hex(16) = '%s'\n", result3);
    free(result3);

    // reverse: string to number
    printf("\n\n");
    int result4 = str2int("123");
    printf("str2int = %d\n", result4);
   
    // part 3: string building + c ancatenation
    // exercise 3.1
    char *greeting = buildGreeting("World");
    printf("%s\n", greeting);
    free(greeting);

    // exercise 3.3
    printf("%s\n", formatPerson("Alice", 25, "Vancouver"));

    // part 4
    // exercise 4.1
    /* review this function */
    printf("the number of words found in this string: %d\n", countWords("hello ny name"));

    /* review this function */
    printf("the longest word from this string ('hello my name'): %s\n", longestWord("hello my name"));

    printf("\n\n");
    printf("checking if this string is numeric:\n"); 
    int result5 = is_numeric("15255"); 
    if(result5 == 0)
        printf("this string is numeric");
    else
        printf("this string is not numeric");

    printf("\n\n");
    printf("checking if this string is a valid identifier:\n");
    int result6 = is_valid_identifier("valid");
    if(result6 == 1)
        printf("this string is a valid identifier");
    else
        printf("this string is not a valid identifier");

    return 0;
}