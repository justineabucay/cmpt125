
## exercise 1.1
```c
char str[10];
```

the line above is a string array with a set length, which is limited to 10 characters (i.e., 9 + null terminator). however this method is not memory efficient and/or flexible, as we do know how much memory we need.  

for example, we must set length of the string to take in 100 characters. however, we might not use all the memory space if our word has 4 characters.  

to take care of this issue, we can use dynamic memory allocation by calling the function malloc() and have some word copied into an uninitialized pointer, as such:  

```c
char *str3;                     // uninitialized pointer 
char *word = "test"; 
int length = strlen(word);
str3 = malloc(length + 1);      // +1 for null terminator
str3[length] = '\0';
for(int i = 0; i < length; i++)
    str3[i] = word[i];
free(str3);                     // always need to free memory when you want to  modify
```

```c
char *str1 = "hello";           // string literal (points to read-only memory)
char str2[] = "hello"           // an array that can be modified
```

the two declarations of strings are different: first one is points string literal, where it cannot be modified. if we try to access/modify it through array notation (i.e., ```c str1[0] = "bye"```), it oftens leads to a segmentation fault, where compiler crashes.      

instead, we can modify the pointer instead, as such:

```c
char* str1 = "hello"; 
str1 = "goodbye";
```