/*
filename: incremnt_decrement _demo.case

description: demo the pre.post increment and the pre/post decrement operators

date: june 3, 2025
*/

#include <stdio.h>

int main(){
    int var1 = 1; 
    int var2 = 2; 
    int result = 0; 

    printf("BEFORE: var 1 = %d and var2 = %d\n", var1, var2);
    result = --var1 + var2; 
    printf("AFTER: var1 = %d, var2 = %d and result = %d\n", var1, var2, result);
    
    return 0;
}