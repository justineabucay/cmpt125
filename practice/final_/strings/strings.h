#ifndef STRINGS_H
#define STRINGS_H
void stringDemo();
char *approachOne(char *str, char *word);
char *approachTwo(char *str, char *word);
int myStrLen(char *str);
void myStrCopy(char *dest, char *src);
int myStrCmp(char *str1, char *str2);
char *int2str(unsigned int n);
char *int2bin(unsigned int n);
int countDigits(unsigned int n, unsigned int bit);
#endif