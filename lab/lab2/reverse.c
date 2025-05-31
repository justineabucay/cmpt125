#include <stdio.h>

int main(void)
{
    int const LENGTH = 10;
    int arr[LENGTH];

    int count = 0; 

    printf("Please, enter 10 integers then press Enter: ");

    for(int i = 0; i < LENGTH; i++){
        if(scanf("%d", &arr[i]) == 1){
            count++;
        } else {
            printf("Your input cannot be read. Please, try again\n");
            break; 
        }
    }
    printf("Content of array before reversing: ");
    for(int i = 0; i < count; i++){
       printf("%d ", arr[i]);
    }

    printf("\nContent of array after reversing: ");
    for(int i = 0; i < count/2; i++)
    {
        int temp = arr[i]; 
        arr[i] = arr[count - 1 - i]; // start
        arr[count - 1 - i] = temp; // end 
    }

    for(int i = 0; i < count; i++){
        printf("%d ", arr[i]);
    }




    return 0;
}