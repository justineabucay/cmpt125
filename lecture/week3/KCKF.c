#include <stdio.h>

int main(void)
{
    float kelTemp = 0.0;
    float celTemp = 0.0;
    float farTemp = 0.0;
    char choice;

    printf("Please, enter a temperature in Kelvin: ");
    scanf("%f", &kelTemp);

    while (kelTemp < 0)
    {
        printf("%.1f Kelvin is an invalid temperature! Try again!\n", kelTemp);
        printf("Please, enter a temperature in Kelvin: ");
        scanf("%f", &kelTemp);
    }

    printf("To concert it to Fahrenheit ... Enter F\n");
    printf("To convert it to Celsius ... Enter C\n");
    printf("Your choice: ");
    scanf(" %c", &choice);

    if(choice == 'F'){
        farTemp = (kelTemp - 273.15) * (9.0/5.0) + 32.0;
        printf("%.1f Kelvin => %.1f Fahrenheit\n", kelTemp, farTemp);
    } else if (choice == 'C') {
        celTemp = kelTemp - 273.15;
        printf("%.1f Kelvin => %.1f Celsius", kelTemp, celTemp);
    }


    return 0;
}