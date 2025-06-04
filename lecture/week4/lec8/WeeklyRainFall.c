/*
filename: WeeklyRainfall.c
description: sum the daily rainfall for a week and print the resulting total weekly rainfall.
author: justine abucay
date: june 3, 2025
*/

#include <stdio.h>

int main()
{
    const int DAYS_PER_WEEK = 7;
    float dailyRainfall = 0.0;
    float currRainfallSum = 0.0; // edit: weekRainFall

    // prompt users and read daily rainfall from user
    for (unsigned int day = 1; day <= DAYS_PER_WEEK; day++)
    {

        printf("Please, input the daily rainful for day %d in cm: ", day);
        // check if valid input
        if (scanf("%f", &dailyRainfall) == 1)
        {
            // add daily rainfall to sum
            currRainfallSum += dailyRainfall;
        }
        else
        { // if invalid input
            // notify user
            printf("Invalid input. Please, try again\n");
            break;
        }
    }

    // print the resulting total weekly rainfall
    printf("Weekly rainfall is %0.2f cm\n", currRainfallSum);

    return 0;
}