/*******************************************************************************
filename    bytes.c
author      Eric Lin
DP email    eric.lin2@digipen.edu
course      CS120
section     B
assignment  4
due date    11/13/2021

Brief Description:
    This file contains seven different functions to manipulating pointers to find,
    analyze, and move elements around. The functions are find_byte, find_any_byte,
    count_bytes, count_any_bytes, compare_bytes, exchange_bytes, and copy_bytes.

*******************************************************************************/

#include <stddef.h> /* NULL */

/*******************************************************************************
      Function: *find_byte

   Description: Scans through a given range determined by the given pointers
                from and to, searching for the first occurance of byte.

        Inputs: from - A pointer that defines the lower bound of the range.
                to   - A pointer that defines the upper bound of the range.
                byte - The character that the function is searching for.

       Outputs: The pointer to the located character byte within the bounds.
*******************************************************************************/
const char *find_byte(const char *from, const char *to, char byte)
{
    /* pointer at from */
    const char *head = from;

    /* scan through the given range */
    while (head <= to)
    {
        /* deference head and compare it to byte */
        if (*head == byte)
            /* return pointer when head is equal to byte */
            return head;
        head++;
    }
    /* return NULL otherwise */
    return NULL;
}

/*******************************************************************************
      Function: *find_any_byte

   Description: Scans through a given range determined by the given pointers
                from and to, searching for the first occurance of any character
                byte in the given bytes array.

        Inputs: from  - A pointer that defines the lower bound of the range.
                to    - A pointer that defines the upper bound of the range.
                bytes - A pointer at the array of characters that the function 
                        is searching for.
                count - The number of values in the given array.

       Outputs: the pointer to the located character byte within the bounds.
*******************************************************************************/
const char *find_any_byte(const char *from, const char *to, const char *bytes, 
                          int count)
{   
    int i;  /* looping variable */

    /* pointer at from */ 
    const char *head = from;

    /* scan through the given range */
    while (head <= to)
    {
        /* loop through count */
        for(i = 0; i < count; i++) 
        {   
            /* deference head and compare to each valuable of the array byte */
            if(*head == *(bytes + i))
                /* return pointer when head is equal to byte */
                return head;
        }
        head++;
    }
    /* return NULL otherwise */
    return NULL;
}

/*******************************************************************************
      Function: count_bytes

   Description: Scans through a given range determined by the given pointers
                from and to, counting the total number of occurances of byte.

        Inputs: from - A pointer that defines the lower bound of the range.
                to   - A pointer that defines the upper bound of the range.
                byte - The character that the function is searching for.

       Outputs: The number of occurances of byte (integer).
*******************************************************************************/
int count_bytes(const char *from, const char *to, char byte)
{
    int total = 0;  /* total number of occurances of byte */

    /* pointer at from */
    const char *head = from;

    /* scan through the given range */
    while (head < to)
    {
        /* deference head and compare it to byte */
        if (*head == byte)
            /* if equal, add one to the total */
            total++;
        head++;
    }
    /* return the total occurances */
    return total;
}

/*******************************************************************************
      Function: count_any_bytes

   Description: Scans through a given range determined by the given pointers
                from and to, counting the occurances of any character byte in
                the given bytes array.

        Inputs: from  - A pointer that defines the lower bound of the range.
                to    - A pointer that defines the upper bound of the range.
                bytes - A pointer at the array of characters that the function 
                        is searching for.
                count - The number of values in the given array.

       Outputs: The number of occurances of any character from the bytes array.
*******************************************************************************/
int count_any_bytes(const char *from, const char *to, const char *bytes, int count)
{
    int i;  /* looping variable */
    int total = 0;  /* total number of occurances of byte */

    /* pointer at from */ 
    const char *head = from;

    /* scan through the given range */
    while (head < to)
    {
        /* loop through count */
        for(i = 0; i < count; i++) 
        {
            /* deference head and compare to each valuable of the array byte */
            if(*head == *(bytes + i))
                /* if equal, add one to the total */
                total++;
        }
        head++;
    }
    /* return the total occurances */
    return total;
}

/*******************************************************************************
      Function: compare_bytes

   Description: Scans through two pointers and compares each character to
                determine if characters occur in the same order.

        Inputs: location1 - A pointer at the first array of characters.
                location2 - A pointer at the second array of characters.
                count     - The number of bytes in each array to compare.

       Outputs: Returns 0 if the bytes are all the same. 
                Returns -1 if the bytes in location1 are less than the bytes 
                in location2.
                Returns 1 otherwise.
*******************************************************************************/
int compare_bytes(const char *location1, const char *location2, int count)
{
    int i;  /* looping variable */

    /* loop through count */
    for(i = 0; i < count; i++)
    {   
        /* if location1 is less than location 2, return negative */
        if(*(location1 + i) < *(location2 + i))
        {
            return -1;
        }
        /* if location1 is greater than location 2, return positive */
        else if(*(location1 + i) > *(location2 + i))
        {
            return 1;
        }
    }
    /* Return 0 otherwise, they are the same */
    return 0;
}

/*******************************************************************************
      Function: exchange_bytec

   Description: Swaps the character bytes of two given pointers.

        Inputs: p1    - A pointer at the first array of characters.
                p2    - A pointer at the second array of characters.
                count - The number of bytes in each array to swap.

       Outputs: Returns void, but swaps elements in each array according to
                the given conditions.
*******************************************************************************/
void exchange_bytes(char *p1, char *p2, int length)
{
    int i;  /* looping variable */
    char temp;  /* temporary storing variable */
    
    /* loop through the length in which to copy */
    for(i = 0; i < length; i++)
    {
        /* perform a swap function */
        temp = *(p1 + i);
        *(p1 + i) = *(p2 + i);
        *(p2 + i) = temp;
    }
}

/*******************************************************************************
      Function: copy_bytes

   Description: Copies the character bytes from a pointer to another pointer.

        Inputs: from   - A pointer at the first array of characters.
                to     - A pointer at the second array of characters.
                length - The number of character bytes to copy over.

       Outputs: Returns void, but copies elements from the *from pointer to the
                *to pointer depending on the integer length.
*******************************************************************************/
void copy_bytes(char *from, char *to, int length)
{
    int i;  /* looping variable */

    /* traverse the arrays backwards to avoid overlapping bugs */
    for(i = length - 1; i >= 0; i--)
    {
        /* deference and copy elements from the variable from to the variable to */
        *(to + i) = *(from + i);
    }
}
