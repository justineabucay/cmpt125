/*
 * Filename: CtoF_v3.c - version 3
 *
 * Description: Read in user provided Celsius temperature.
 *              Validate it (valid range: -273.15°C to 200.00°C
 *              then convert it to a Fahrenheit temperature.
 *
 * Author: AL
 * Date: May 2025
 */

#include <stdio.h>

int main(void)
{

    const float MINCELLTEMP = -273.15;
    const float MAXCELLTEMP = 200.00;

    float celTemp = 0.0;
    float fahTemp = 0.0;

    int result = 0;

    printf("Enter a valid temperature in Celsius (valid Celsius range is %f to %f).\n", MINCELLTEMP, MAXCELLTEMP);

    if((result = scanf("%f", &celTemp )) == 1){
        if (celTemp >= MINCELLTEMP && celTemp <= MAXCELLTEMP)
        { // valid Celsius temperature
            // Convert celTemp to fahTemp
            fahTemp = celTemp * (9.0 / 5) + 32;

            printf("%f Celsius degree => %f Fahrenheit.\n", celTemp, fahTemp);
        }
        else
        { // invalid Celsius temperature
            printf("%f Celsius degree is outside valid range ().\n", celTemp);
        }
    } else 
        // if the user's input cannot be read - invalid input format
        printf("Temperature cannot be read. Try again!\n");

    printf("result from scanf = %d\n", result);
    return 0;
}