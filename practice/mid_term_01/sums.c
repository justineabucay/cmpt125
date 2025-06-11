// float user input -- one at a time 
// sum and smallest - functions 

#include <stdio.h>


int getSmallest(int num)
{
    int smallest = 0; 
    if(num < smallest ) smallest = num; 

    return num;
}

int main(void)
{
    float const MIN = -100.0;
    float const MAX = 100.0;

    float input = 0.0; 
    int result = 0; 

    float sum = 0;
    float smallest = 0; 

    printf("Please, enter float integers from %f to %f: ", MIN, MAX); 
    
    while((result = scanf("%f ", &input)) != -1)
    {
        if(input <= MIN && input >= MAX)
        {
            printf("\nyou have entered an invalid number. please, try again: ");
        }
        else 
        {
            sum += input;
            smallest = getSmallest(input);
        }
    }

    printf("All inputs are successful. Now, printing results!\n");
    
    printf("Sum: %.2f\n", sum);
    printf("Smallest: %.2f\n", smallest);
    
    

    
    
}