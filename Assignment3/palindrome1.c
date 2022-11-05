/*******************************************************************************
filename    palindrome1.c
author      Eric Lin
DP email    eric.lin2@digipen.edu
course      CS120
section     B
assignment  3
due date    11/04/2021

Brief Description:
  This file contains the function to find palindromes using arrays.

*******************************************************************************/

/*******************************************************************************
      Function: is_palindrome1

   Description: Given an array of characters, determine if it's a 
                palindrome using array logic.

        Inputs: phrase – An array of a given phrase.
                length - The length of the given phrase.

       Outputs: Returns 1 (true) if the phrase is a palindrome 
                and 0 if not.
*******************************************************************************/
#include <stdio.h>

int is_palindrome1(const char phrase[], int length)
{
    int first;  /* first character of the array */
    int last;   /* last character of the array */

    /* loops from both front and back */
    for(first = 0, last = length - 1; first < last; first++, last--) 
    {
        /* compares elements to return 0 if they are not equal */
        if(phrase[first] != phrase[last])
        {
            return 0;   /* return false if values are not equal */
        }
    }
    return 1;   /* return true otherwise */
}
