#include <stdio.h>

int main(void)
{
    const int SIZE_OF_ARRAY = 80;
    int arr1[SIZE_OF_ARRAY];

    int count = 0;
    int maxHeight = 0; 

    printf("Please, enter integers (>=0) then press Enter and CTRL d: ");
    for (int i = 0; i < SIZE_OF_ARRAY; i++)
    {
        if (scanf("%d", &arr1[i]) == 1){
            if(arr1[i]>maxHeight) maxHeight = arr1[i];
            count++;
        }
    }



    printf("\n%d\n", count);

    for (int row = maxHeight; row >= 1; row--) {  // Start from top row
        for (int col = 0; col < count; col++) {   // For each column
            if (arr1[col] >= row) {
                printf("#");  // Print # if this column is tall enough
            } else {
                printf(" ");  // Print space if column is shorter
            }
        }
        printf("\n");  // End of row
    }

    return 0;
}