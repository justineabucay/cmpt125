/*
 * Filename: cffc_v1.c - version 1
 *
 * Description: Ask the user for the conversion type: C -> F or F -> C
 *              Ask the user for a temperature.
 *              Convert this temperature to the other temperature 
 *              based on the selected conversion type.
 *              C -> F conversion: °F = (°C × 9/5) + 32
 *              F -> C conversion: °C = 5/9 × (°F - 32)
 *
 * Author: Justine Abucay
 * Date: May 30, 2025
 */


#include <stdio.h>

int main(void)
{
    float num = 0; 
    char choice; 
    float farTemp = 0.0;
    float celTemp = 0.0;

    printf("To convert temperature from Celsius to Fahrenheit ... Enter F\n"); 
    printf("To convert temperature from Fahrenheit to Celsius ... Enter C\n");
    printf("Your choice: ");
    scanf("%c", &choice);  // Fixed: removed assignment to choice

    if(choice == 'F')  // Fixed: use single quotes for char comparison
    {
        printf("\nPlease, enter a temperature in Celsius: ");
        scanf("%f", &celTemp);  // Fixed: removed assignment to celTemp
        farTemp = celTemp * 9.0/5.0 + 32;  // Fixed: use floating point division
        printf("%.1f Celsius => %.1f Fahrenheit\n", celTemp, farTemp);
        
    }
    else if(choice == 'C')  // Added: handle Celsius to Fahrenheit conversion
    {
        printf("\nPlease, enter a temperature in Fahrenheit: ");
        scanf("%f", &farTemp);
        celTemp = (farTemp - 32) * 5.0/9.0;
        printf("%.1f Fahrenheit => %.1f Celsius\n", farTemp, celTemp);
    }
    else
    {
        printf("Invalid choice! Please enter F or C.\n");
    }

    return 0;
}