## patterns found in the lab assignments
**lab3-scrambled.c**

description: counting the number of times the value occurs in an array

        int count[LENGTH] = {0};    // we are counting until LENGTH
        int size = sizeof(arr1)/sizeof(arr1[0]);    // finding how many elements are in the array

        for(unsigned int i = 0; i < size; i++)  count[arr1[i]]++;   // counting the number of times the value occurs in an array


**lab3-reverse.c**

description: let users enter as many integers as they would like before hitting the set amount (i.e., 10) or pressing ctrl+d. also, counting the actual number of integers entered if under 10.

        int const LENGTH = 10;
        int arr[LENGTH];
        int count = 0;

        for(unsigned int i = 0; i < LENGTH; i++)
        {
            if(scanf("%d", &arr[i]) == 1)
                count ++
        }

description: reversing the content of an array

        for(unsigned int i = 0; i < count/2; i++)   // find the middle
        {
            int temp = arr[i];  // remember the current position
            arr[i] - arr[count - 1 - i];    // swap the start position with the end position
            arr[count - 1 - i] = temp;  // finally, swap the end position with the position saved
        }


**lab3-values.c**

description: using the math functions, like ceil, round + floor

when writing the command to compile your program using the math functions:

        gcc values.c -o values -lm

## patterns found in the lecture demos

