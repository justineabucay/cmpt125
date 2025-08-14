#include <stdio.h>

int main(void){
    int n = 6;
    int result = 2; // Start with base case value

    // Keep going while n > 1
    while (n > 1)
    {
        printf("%d ", n); // Print current n
        n = n - 2;        // Reduce n by 2
        result += 3;      // Add 3 for this step
    }

    printf("result: %d\n", result);
    return 0;
}