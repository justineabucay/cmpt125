#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // function declaration
    char* int2str(unsigned int n);
    char* int2bin(unsigned int n);
    char* array2str(const int* arr, int n);

    const int arr[] = {2, 123, 103};
    char *result1 = array2str(arr, 3);
    printf("array->str: result = %s\n", result1);

    char *result = int2str(5444);
    printf("result: %s\n", result);
    //printf("result: %s\n", int2bin(100));

    free(result);
    free(result1);
    return 0;
}

char* array2str(const int* arr, int n){
    int length = 2; 
    for(unsigned int i = 0; i < n; i++){
        if(i>0) length++; 
        if(arr[i] == 0)
            length += 1;
        else{
            int temp = arr[i];
            while (temp > 0)
            {
                length++;
                temp = temp / 10;
            }
        }

    }

    printf("length: %d\n", length);
    char* str = malloc(length * sizeof(char) + 1); 
    str[length] = '\0';
    str[0] = '[';
    int pos = 1;
    for(int i = 0; i < n; i++){
        if(i > 0){
            str[pos] = ',';
            pos++;
        }

        char *num_str = int2str(arr[i]);
        strcpy(str + pos, num_str); // Copy into str starting at pos
        pos += strlen(num_str);     // Move pos forward
        free(num_str);
    }
    str[length - 1] = ']';
    return str; 
}

char* int2str(unsigned int n){
    int length = 0; 

    // count how many digits
    if(n == 0) length = 1; 
    else{
        int temp = n;
        while(temp > 0){
            length++;
            temp = temp / 10;
        }
    }

    char* str = malloc(length * sizeof(char) + 1);
    str[length] = '\0';
    for(int i = length - 1; i >= 0; i--){
        str[i] = (n % 10) + '0';
        n = n / 10;
        
    }

    return str;
}

char* int2bin(unsigned int n){
    int length = 0;

    // count how many digits
    if (n == 0)
        length = 1;
    else
    {
        int temp = n;
        while (temp > 0)
        {
            length++;
            temp = temp / 2;
        }
    }

    char *str = malloc(length * sizeof(char) + 1);
    str[length] = '\0';
    for(int i = length - 1; i >= 0; i--){
        int bit = n % 2;
        str[i] = '0' + bit;
        n /= 2; 
    }

    return str;
}