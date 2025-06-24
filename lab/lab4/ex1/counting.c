#include <stdio.h>
#include <stdlib.h>

// declare function
int isWordCharacter(int chr);

int main(void)
{
    unsigned long charCount = 0; 
    unsigned long wordCount = 0;
    unsigned long lineCount = 0;  

    int currChar = 0; 
    int isInWord = 0; // use as a flag to track the state of the word, where currently it is false, meaning current character is not in a word

    printf("please, type in a string: ");
    while((currChar = getchar()) != EOF) // count every character except EOF
    {
        charCount++; 

        if(currChar == '\n') // count lines which is separated by newline
            lineCount++;

        // handling the possible states when a character is read
        if(isWordCharacter(currChar)){ // check if current character is a part of a word (whether it is a letter or apostrophe)
            if(!isInWord){  // current charcter is a part of a word   
                wordCount++;   // therefore, increment word count
                isInWord = 1;  // continue reading the word
            }
        } else {
            if(isInWord) // current character is not a part of a word
                isInWord = 0; // finished reading a word
        }
    }

    // printing results
    printf( "results: %lu %lu %lu\n", charCount, wordCount, lineCount ); 

    return 0;
}

int isWordCharacter(int chr)
{
        if(chr >= 'a' && chr <= 'z' || chr >= 'A' && chr <= 'Z' || chr == '\'')
            return 1; 
        else 
            return 0;
}

   
