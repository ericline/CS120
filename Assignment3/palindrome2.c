/*******************************************************************************
filename    palindrome2.c
author      Eric Lin
DP email    eric.lin@digipen.edu
course      CS120
section     B
assignment  3
due date    11/04/2021
Brief Description:
    This program contains a function to determine whether or not an array
    of characters represents a palindrome.

*******************************************************************************/

/*******************************************************************************
      Function: is_palindrome2

   Description: Given an array of characters, determine if it's a 
                palindrome using pointers

        Inputs: phrase – A pointer at a given phrase.
                length - The length of the given phrase.

       Outputs: Returns 1 (true) if the phrase is a palindrome 
                and 0 if not.
*******************************************************************************/

int is_palindrome2(const char *phrase, int length)
{
    const char *first;  /* address of first character */
    const char *last;   /* address of last character */

    /* loops from both front and back */
    for(first = phrase, last = phrase + (length - 1); first < last; first++, last--) 
    {
        /* compare pointers to return 0 if they are not equal */
        if(*first != *last)
        {
            return 0;   /* return false if values are not equal */
        }
    }
    return 1;   /* return true otherwise */
}
