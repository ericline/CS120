/*******************************************************************************
filename    calendar.c
author      Eric Lin
DP email    eric.lin2@digipen.edu
course      CS120
section     B
lab         8
due date    11/06/2021

Brief Description:
  This file contains three functions: a function to determine whether or not a
  given year is a leap year; a function to determine the day of the week a date
  is on; and a function to print the calendar of a month and year.

*******************************************************************************/

#include <stdio.h>  /* printf */

#define TRUE  1
#define FALSE 0

/**************************************************************************
      Function: is_leapyear

   Description: Determines whether a given year is a leap year.

        Inputs: year – A given year. 

       Outputs: TRUE or FALSE (integer) depending on whether or not the
       input year is a leap year.
**************************************************************************/
int is_leapyear(int year)
{
    /* Leap Year if year is divisible by 4 AND not divisble by 100 
    OR if year is divisible by 400 */
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) 
        return TRUE;

    /* otherwise not a leap year */
    else
        return FALSE;

}

/**************************************************************************
      Function: day_of_the_week

   Description: Finds the day of the week of a given date

        Inputs: day - the day of the month
                month - the month of the year
                year - the given year 

       Outputs: The day of the week (integer) as a number from 1 - 7.
**************************************************************************/
int day_of_the_week(int day, int month, int year)
{
    /* month key values */
    int month_keys[] = {1, 4, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6};
    
    /* century code values */
    int year_keys[] = {4, 2, 0, 6};

    /* Extract last 2 digits and divide by 4 */
    int dayOfWeek = (year % 100) / 4;

    /* Add day of month */
    dayOfWeek += day;

    /* Add key value based on month */
    dayOfWeek += month_keys[month - 1];

    /* If month is January or February and is a leap year, subtract 1 */
    if((month - 1 == 0 || month - 1 == 1) && is_leapyear(year))
        dayOfWeek -= 1;
    
    /* if year is above 2099, subtract 400 until it is below 2099 */
    if (year > 2099) 
    {
        while(year > 2099) 
        {
            year -= 400;
        }
    }

    /* Add century code based on year */
    else if (year >= 1700 && year <= 1799) 
    {
        dayOfWeek += year_keys[0];
    }
    else if (year >= 1800 && year <=1899)
    {
        dayOfWeek += year_keys[1];
    }
    else if (year >= 1900 && year <= 1999)
    {
        dayOfWeek += year_keys[2];
    }
    else if (year >= 2000 && year <= 2099)
    {
        dayOfWeek += year_keys[3];
    }

    /* Add last two digits of the year */
    dayOfWeek += year % 100;

    /* Take remainder of 7 */
    dayOfWeek = (dayOfWeek % 7);

    /* return Saturday for 0 instead */
    if (dayOfWeek == 0)
        return 7;
    else
        return dayOfWeek;   /* otherwise return normally */
}

/**************************************************************************
      Function: print_calendar

   Description: Prints the calendar of a given date.

        Inputs: month - the month of the year
                year - the given year 

       Outputs: Returns void, but prints the calendar based on the given
                month and year.
**************************************************************************/
void print_calendar(int month, int year)
{
    /* number of days in each month */
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 

    /* pointer for the names of each month */ 
    char *months[] = {"January",   "February", "March",    "April", 
                    "May",       "June",     "July",     "August",
                    "September", "October",  "November", "December"};

    /* Calculates number of days in the given month */
    int numberOfDays = days_in_month[month - 1];

    /* Calculates first day of the given month depending on year */
    int firstDay = day_of_the_week(1, month, year);

    /* looping variable */
    int i;

    /* Conditions for valid inputs */
    if (month < 1 || month > 12) 
    {
        printf("Month must be between 1 and 12.");
    }
    else if (year < 0)
    {
        printf("Year must be a positive number");
    }
    else
    {
        /* Print calendar header */
        printf("%s, %i\n", months[month - 1], year);
        printf("Su Mo Tu We Th Fr Sa\n");
        printf("---------------------\n");

        switch (firstDay)
        {
            /* if first day is on Sunday */
            case 1:
                printf("%2d%3d%3d%3d%3d%3d%3d \n", 1, 2, 3, 4, 5, 6, 7);
                break;

            /* if first day is on Monday */
            case 2:
                printf("%5d%3d%3d%3d%3d%3d \n", 1, 2, 3, 4, 5, 6);
                break;
            
            /* if first day is on Tuesday */
            case 3:
                printf("%8d%3d%3d%3d%3d \n", 1, 2, 3, 4, 5);
                break;

            /* if first day is on Wednesday */
            case 4:
                printf("%11d%3d%3d%3d \n", 1, 2, 3, 4);
                break;

            /* if first day is on Thursday */
            case 5:
                printf("%14d%3d%3d \n", 1, 2, 3);
                break;
            
            /* if first day is on Friday */
            case 6:
                printf("%17d%3d \n", 1, 2);
                break;

            /* if first day is on Saturday */
            case 7:
                printf("%20d \n", 1);
                break;
        }

        for(i = 9 - firstDay; i <= numberOfDays; i++)
        {
            /* if day is Sunday */
            if(day_of_the_week(i, month, year) == 1)
                printf("%2d", i);
            
            /* if day is Saturday but not the last day */
            else if(day_of_the_week(i, month, year) == 7 && i != numberOfDays)
                printf("%3d \n", i);
            
            /* otherwise, print day */
            else
                printf("%3d", i);

            /* stop at the last day */
            if (i == numberOfDays)
                printf(" \n");
        }
    }
}
