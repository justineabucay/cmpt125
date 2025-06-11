// mystery.c

// function takes in an array of 8 integers and cells (i.e., number of integers in arr)
// stuff[LENGTH=10]

// for loop: length limit (or cells?)
// if not even
// stuff[arr[i]]+*
// else
// stuff[arr[i]]+=2

// now, that im thinking about it, there's an error b/c arr has a size of only 8 integers
// unless i did not remember correctly and the loop limit is set to the size of arr

#include <stdio.h>

int mystery(int arr[], int cells) // Return pointer to array
{
    int const LENGTH = 10;
    int stuff[LENGTH];

    for (int i = 0; i < LENGTH; i++)
        stuff[i] = 100;

    for (int i = 0; i < cells; i++)
    {
        if (arr[i] % 2 != 0)
            stuff[arr[i]]++;
        else
            stuff[arr[i]] += 2;
    }

    for (int i = 0; i < LENGTH; i++)
        printf("%d ", stuff[i]);

    return 1;
}

int main(void)
{
    int const CELLS = 8;
    int arr1[CELLS] = {1, 2, 3, 4, 5, 6, 7, 8};

    printf("here is a mystery: \n");
    mystery(arr1, CELLS);

    printf("\n");

    return 0;
}
