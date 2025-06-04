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

    // pre-decrement
    printf("BEFORE: var 1 = %d and var2 = %d\n", var1, var2);
    result = --var1 + var2; 
    printf("AFTER: var1 = %d, var2 = %d and result = %d\n", var1, var2, result);


    var1 = 1; 
    var2 = 2;

    // post-decrement
    printf("BEFORE: var 1 = %d and var2 = %d\n", var1, var2);
    result = var1-- + var2; 
    printf("AFTER: var1 = %d, var2 = %d and result = %d\n", var1, var2, result);

    /*
    the result from using pre/post increment (or decrement) will always be the same, where in this case it is 0
    */
   
    return 0;

}