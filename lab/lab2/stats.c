#include <stdio.h>

int main(void)
{
    const float MIN = -100000.00;
    const float MAX = 100000.00;

    int arr_length = 0;
    float arr[1000];
    float num = 0.0; 

    float maxNum;
    float minNum;
    float mean = 0.0; 

    printf("Please, enter a number between %.2f and %.2f: ", MIN, MAX);

    while((scanf("%f", &num)) == 1)
    {
        if(num < MIN || num > MAX){
            printf("%.2f is invalid!\n", num);
        } else {
            // appending user input to array
            arr[arr_length] = num;
            arr_length++; 
        }

        printf("Please, enter a number between %.2f and %.2f: ", MIN, MAX);
    }

    if (arr_length < 1) 
        printf("\nNo number entered! Nothing to report!\n");

    // initialize min and max with first element
    if(arr_length > 0) {
        minNum = arr[0];
        maxNum = arr[0];
    
        // finding max, min + the sum of the elements inside array 
        for(int i = 0; i < arr_length; i++)
        {
            if(arr[i] > maxNum)
                maxNum = arr[i];
            if(arr[i] < minNum)
                minNum = arr[i];
            mean += arr[i];
        }
    
        printf("\nMin: %.2f, max: %.2f, mean: %.2f\n", minNum, maxNum, (float) mean/arr_length);
    }

    return 0; 

}