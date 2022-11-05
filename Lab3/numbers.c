/******************************************************************************
filename    numbers.c
author      Eric Lin
DP email    eric.lin@digipen.edu
course      CS120
section     B
lab week    2
due date    10/02/2021

Brief Description:
  This program takes three inputs and displays the outside through 
  serveral trigonometric functions.
  
******************************************************************************/
#include <stdio.h>  /* printf, scanf */
#include <math.h>   /* sin, cos, tan, atan */

/* Prompts user for 3 values before displaying the values
through trigonometric functions */
int main (void) 
{
     
    float input1 = 0;   /* user input #1 */
    float input2 = 0;   /* user input #2 */
    float input3 = 0;   /* user input #3 */

    /* Prompts user for 3 values */
    printf("Enter 3 numbers between 0 and 9.999: \n");

    /* Assigns each user value to the corresponding input variables */
    scanf("%f %f %f", &input1, &input2, &input3);

    /* Displays the results on the screen */
    printf("Number      sin      cos      tan      atan\n");
    printf("-------------------------------------------\n");
    printf("%0.5f %8.3f %8.3f %8.3f %8.3f\n", 
            input1, sin(input1), cos(input1), tan(input1), atan(input1));
    printf("%0.5f %8.3f %8.3f %8.3f %8.3f\n", 
            input2, sin(input2), cos(input2), tan(input2), atan(input2));
    printf("%0.5f %8.3f %8.3f %8.3f %8.3f\n", 
            input3, sin(input3), cos(input3), tan(input3), atan(input3));

    return 0;
}


