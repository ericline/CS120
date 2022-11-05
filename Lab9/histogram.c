/*******************************************************************************
filename    histogram.c
author      Eric Lin
DP email    eric.lin2@digipen.edu
course      CS120
section     B
lab         9
due date    11/13/2021

Brief Description:
  This file contains three functions to calculate and store the information
  used in a histogram, and then print the histogram.

*******************************************************************************/

#include <stdio.h>     /* printf      */
#include <ctype.h>     /* toupper     */
#include <string.h>    /* strlen      */
#include "histogram.h" /* lab defines */

/*******************************************************************************
      Function: GetCounts

   Description: Scans through a sentence string and counts the number of 
                letters, spaces, and other characters in the string.

        Inputs: sentence - A pointer at the string of characters.
                letters  - An array of integers that stores the number of
                           occurances of each letter.
                spaces   - A pointer to an integer that stores the number of
                           spaces.
                other    - A pointer to an integer that stores the number of
                           other characters.

       Outputs: Returns the array of integers that contain the number of
                occurances per letter, and pointers at the number of occurances
                of spaces, and other characters.
*******************************************************************************/
int GetCounts(const char *sentence, int letters[], int *spaces, int *other)
{
    int i;
    int total = 0;
    *spaces = 0;
    *other = 0;

    for(i = 0; i < NUM_LETTERS; i++)
    {
        letters[i] = 0;
    }

    /* loop through sentence array */
    while(*sentence)
    {   
        /* set all characters to the same case */
        /* if element is a character between a and z */
        if(tolower(*sentence) >= 'a' && tolower(*sentence) <= 'z')
        {
            
            /* stores number of occurances of a letter */
            letters[tolower(*sentence) - 'a']++;
            total++;
        }
        /* if element is a space */
        else if(*sentence == SPACE)
        {
            (*spaces)++; /* increment spaces */
        }
        /* otherwise, element is considered other */
        else
        {
            (*other)++; /* increment other */
        }
        
        sentence++; /* increment through array */
    }

    return total;   /* return the total occurances of letters */
}

/*******************************************************************************
      Function: PrintHistogram

   Description: Prints a histogram using the given information in the letters
                array.

        Inputs: letters  - An array of integers that stores the number of
                           occurances of each letter.
                
       Outputs: Returns void, but prints a full histogram.
*******************************************************************************/
void PrintHistogram(const int letters[])
{
    int i;  /* looping variable */
    int j;  /* second looping variable */

    /* loops through the Alphabet */
    for(i = 0; i < NUM_LETTERS; i++)
    {
        /* prints out each leter of the Alphabet */
        printf("%c:", 'A' + i);

        /* loops through the total stored in each letter element */
        for(j = 1; j <= letters[i]; j++)
        {
            /* prints out asterisk depending on the value per letter */
            printf("*");
        }
        /* print new line to separate each character */
        printf("\n");
    }
}

/*******************************************************************************
      Function: GetStatistics

   Description: Calculates the average score of a histogram and the most
                occurring letter and its count.

        Inputs: letters    - An array of integers that stores the number of
                           occurances of each letter.
                average    - A pointer to an double that stores the average
                           score of the histogram.
                max_letter - A pointer to a char that stores the most occurring
                             letter in the sring.
                max_count  - A pointer to an integer that stores the number of
                             times max_letter has occurred in the string.
                
       Outputs: Returns void, but prints a full histogram.
*******************************************************************************/
void GetStatistics(const int letters[], double *average, char *max_letter, 
                   int *max_count)
{
    int i;  /* looping variable */
    double total = 0; /* total sum of characters */
    *max_letter = 'A';  /* set first letter to max */
    *max_count = letters[0];    /* set first letter to max */

    /* loop through all 0-26 */
    for(i = 0; i < NUM_LETTERS; i++)
    {
        /* total is equal to sum of letters multipled by their corresponding
        element number */
        total += (letters[i] * (i + 1));
    }

    /* calculate average by dividing total by number of letters */
    *average = total / NUM_LETTERS;
    
    /* loop through all letters starting at B */
    for(i = 1; i < NUM_LETTERS; i++)
    {
        /* if letter is greater than the current max */
        if(letters[i] > *max_count)
        {   
            /* set found letter as max_letter */
            *max_letter = i + 'A';
            /* set the value of the found letter as max_count */
            *max_count = letters[i];
        }
    }
}
