#include <stdio.h>
#include <stdlib.h>
#include "strings.h"
#include <string.h>

void stringDemo(){
    char str1[10] = "hello";    // stack allocation
    char *str2 = "world";       // string literal (read-only)
    char *str3;                 // uninitialized pointer

    char* word = "test"; 
    int length = strlen(word);
    str3 = malloc(length + 1);

    printf("#1 copying the word 'test' into an uninitialized pointer, str3:\n");
    approachOne(str3, word);
    printf("\tstr3: %s\n", str3);
    free(str3);

    word = "hello, world";
    length = strlen(word);
    str3 = malloc(length + 1);
    printf("#2 copying the word 'hello, world' into an uninitialized pointer, str3:\n");
    approachTwo(str3, word);
    printf("\tstr3: %s\n", str3);
    free(str3);

    word = "it's a good game!";
    length = strlen(word);
    str3 = malloc(length + 1);
    str3[length] = '\0';
    printf("#3 copying the word 'it's a good game' into an uninitialized pointer, str3:\n");
    printf("the current length of the word: %d\n", length);
    for(int i = 0; i < length; i++)
        str3[i] = word[i];
    printf("\tstr3: %s\n", str3);

    printf("\n\n");
    printf("printing out str1 (stack allocation): %s\n", str1);
    printf("printing out str2 (string literal): %s\n", str2);
    printf("printing out str3 (uninitialized pointer): %s\n", str3);
    free(str3);

    // we can modify the string when it is declared as an array 
    str1[0] = 'H';

    //the line below is a string literal and therefore, we cannot modify (i.e., writing) str2 because it will cause a seg fault
    //str2[0] = 'W';

    // instead we can modify the pointer itself:
    str2 = "goodbye!";
    
    // overwriting is successful!
    str3 = "oh no!";
    
    printf("printing out str1 (stack allocation): %s\n", str1);
    printf("printing out str2 (string literal): %s\n", str2);
    printf("printing out str3 (uninitialized pointer): %s\n", str3);
}

char* approachOne(char* str, char* word){
    // approach #1
    char *start = str; // save the starting position

    while (*word)
    {
        *str = *word;
        str++;
        word++;
    }

    *str = '\0';
    str = start; // reset to the beginning
    return str; 
}

char *approachTwo(char *str, char *word)
{
    int index = 0; 
    while(*word){
        str[index] = *word; 
        index++; 
        word++;
    }

    str[index] = '\0';

    return str;
}
