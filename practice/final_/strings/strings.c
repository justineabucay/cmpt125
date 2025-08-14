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

int myStrLen(char *str){
    char* original = str; 
    int length = 0;
    while(*str){
        length++;
        str++;
    }
    str = original;
    return length; 
}

void myStrCopy(char *dest, char *src){
    
    while(*src){
        *dest = *src;
        src++;
        dest++;
    }
    dest[0] = '\0';
}

int myStrCmp(char *str1, char *str2){
    if(str1 == str2) return 0; 

    return -1;
}

char* int2str(unsigned int n){
    unsigned int bit = 10;
    int length = countDigits(n, bit); 

    char* str = malloc(length + 1); 
    str[length] = '\0';

    for(int i = length - 1; i >= 0; i--){
        str[i] = (n % bit) + '0';
        n /= bit; 
    }
    
    return str; 
}

char* int2bin(unsigned int n){
    int bit = 2;
    int length = countDigits(n, bit); 
    
    char* str = malloc(length + 1); 
    str[length] = '\0'; 

    for(int i = 0; i < length; i++){
        str[i] = (n % bit) + '0'; 
        n /= bit; 
    }

    return str;
} 

char* int2hex(unsigned int n){
    int base = 16;
    int length = countDigits(n, base);

    char *str = malloc(length + 1);
    str[length] = '\0';

    for (int i = length - 1; i >= 0; i--)
    {
        int digit = (n % base);
        /* review the line below */
        if(digit<10) str[i] = digit + '0';  // 0-9 -> '0' - '9'
        else str[i] = (digit - 10) + 'A'; // 10-15 become A-F
        n /= base;
    }

    return str;
}

int str2int(char *str){
    int num = 0;

    for(int i = 0; str[i] != '\0'; i++){
        /* review the line below */
        num = num * 10 + str[i] - '0';
    }
    return num;
}

char* buildGreeting(char *name){
    char *word;
    char *message = NULL;
    word = "Hello, "; 
    int length = strlen(word) + strlen(name) + 2;

    message = malloc(length);
    if(!message) return NULL;

    strcpy(message, word);
    strcat(message, name);
    strcat(message, "!");
    return message; 
}

char* formatPerson(char *name, int age, char *city){
    char* age_str = int2str(age); 

    int total_length = strlen(name) + strlen(age_str) + strlen(city);
    char* result = malloc(total_length + 1);
    result[0] = '\0';

    strcat(result, "name: ");
    strcat(result, name); 
    strcat(result, ", age: ");
    strcat(result, age_str);
    strcat(result, ", city: ");
    strcat(result, city);

    free(age_str);
    return result;
}

int countWords(char *str){
    int words = 0; 
    int in_word = 0; 
    
    while(*str){
        if(*str == ' '){
            in_word = 0;        // set in_word to 0 because we are currently on a space
        }
        else
            if(in_word == 0){
                words++;        // start of a new word
                in_word = 1;    // we are inside a word
            }
        str++;
    }

    return words;
}

char *longestWord(char *str)
{
    int maxLen = 0;
    int currLen = 0;
    int maxStart = 0;
    int currStart = 0;
    int i = 0;

    while (str[i])
    {
        if (str[i] == ' ')
        {
            if (currLen > maxLen)
            {
                maxLen = currLen;
                maxStart = currStart;
            }
            currLen = 0;
        }
        else
        {
            if (currLen == 0)
                currStart = i;
            currLen++;
        }
        i++;
    }

    if (currLen > maxLen)
    {
        maxLen = currLen;
        maxStart = currStart;
    }

    char *longest = malloc(maxLen + 1);
    if (longest == NULL)
        return NULL;

    memcpy(longest, &str[maxStart], maxLen);
    longest[maxLen] = '\0';

    return longest;

}

int is_numeric(char *str){

    for(unsigned int i = 0; str[i] != '\0'; i++){
        if(str[i] >= 'A'){
            printf("%c\n", str[i]);
            return 1;
        }
    }

    return 0;
}

int is_valid_identifier(char *str)
{
    // Check if string is NULL or empty
    if (str == NULL || str[0] == '\0')
    {
        return 0;
    }

    // First character must be letter or underscore (not digit)
    if (!((str[0] >= 'a' && str[0] <= 'z') || (str[0] >= 'A' && str[0] <= 'Z') || (str[0] == '_')))
    {
        return 0;
    }

    // Check remaining characters
    for (int i = 1; str[i] != '\0'; i++)
    {
        char c = str[i]; // Just get the character, not a pointer to it
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || (c == '_')))
        {
            return 0; // Invalid character found
        }
    }

    return 1; // All characters are valid
}

int countDigits(unsigned int n, unsigned int bit){
    int length = 0;
    if (n == 0)
    {
        length = 1;
    }
    else
    {
        int temp = n;
        while (temp > 0)
        {
            length++;
            temp = temp / bit;
        }
    }

    return length; 
}



