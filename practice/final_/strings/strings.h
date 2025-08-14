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
char *int2hex(unsigned int n);
int str2int(char *str);
char *buildGreeting(char *name);
char *formatPerson(char *name, int age, char *city);
int countDigits(unsigned int n, unsigned int bit);
int countWords(char *str);
char *longestWord(char *str);
int is_numeric(char *str);
int is_valid_identifier(char *str);
#endif