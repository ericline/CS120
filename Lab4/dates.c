/******************************************************************************
filename    dates.c
author      Eric Lin
DP email    eric.lin@digipen.edu
course      CS120
section     B
lab week    4
due date    10/09/2021

Brief Description:
  This program prompts the user for two dates and then prints out if the 
  first date comes before or after the second date or if they are the same.

******************************************************************************/
#include <stdio.h> /* printf, scanf */

int main(void)
{
 
    int month1, month2; /* Month in date */
    int day1, day2;     /* Day in date */
    int year1, year2;   /* Year in date */

    /* Displays the prompt and accept the user input (first date). */
    printf("Enter the first date: (mm/dd/yyyy) ");
    scanf("%d/%d/%d", &month1, &day1, &year1);
    
    /* Display the prompt and accept the user input (second date). */
    printf("Enter the second date: (mm/dd/yyyy) ");
    scanf("%d/%d/%d", &month2, &day2, &year2);

    /* Compares years first */
    if (year1 < year2) 
    {
        printf("%.2d/%.2d/%.2d comes before %.2d/%.2d/%.2d.\n", 
        month1, day1, year1, month2, day2, year2);
    }
    else if (year1 > year2)
    {
        printf("%.2d/%.2d/%.2d comes after %.2d/%.2d/%.2d.\n", 
        month1, day1, year1, month2, day2, year2);
    }
    else if (year1 == year2) 
    {
        /* Compares months second */
        if (month1 < month2)
        {
            printf("%.2d/%.2d/%.2d comes before %.2d/%.2d/%.2d.\n", 
            month1, day1, year1, month2, day2, year2);
        }
        else if (month1 > month2)
        {
            printf("%.2d/%.2d/%.2d comes after %.2d/%.2d/%.2d.\n", 
            month1, day1, year1, month2, day2, year2);
        }
        else if (month1 == month2)
        {
            /* Compares days third */
            if (day1 < day2)
            {
                printf("%.2d/%.2d/%.2d comes before %.2d/%.2d/%.2d.\n", 
                month1, day1, year1, month2, day2, year2);
            }
            else if (day1 > day2)
            {
                printf("%.2d/%.2d/%.2d comes after %.2d/%.2d/%.2d.\n", 
                month1, day1, year1, month2, day2, year2);
            }
            else if (day1 == day2)
            {
                /* Prints out that the first date and second date are
                the same dates */
                printf("%.2d/%.2d/%.2d and %.2d/%.2d/%.2d ",
                month1, day1, year1, month2, day2, year2);
                printf("are the same date.\n");
            }
        }
    }

  return 0; /* Return success to the OS. */
}
