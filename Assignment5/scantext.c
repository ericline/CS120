/*******************************************************************************
filename    scantext.c
author      Eric Lin
DP email    eric.lin2@digipen.edu
course      CS120
section     B
assignment  5
due date    11/20/2021

Brief Description:
    This program contains several functions to analyze and modify given strings
    using pointers. The first function mystrlen takes a string and returns its
    length. The second function count_tabs takes a string and returns the number
    of tabs. The third function substitute_char replaces characters in a given
    string. The last function count_words takes a string and returns the number
    of individual words there are in the string. Included are also a few helper
    functions for the count_words functions.

*******************************************************************************/

#define TRUE 1
#define FALSE 0

/*******************************************************************************
   Function: mystrlen

Description: Calculates and returns the length of a given string.

     Inputs: string - A pointer at a string.

    Outputs: Returns the the length (integer) of the string.
*******************************************************************************/
static int mystrlen(const char *string)
{
  int length = 0;  /* The number of characters in the string */
  
    /* Count the characters (not including the NUL) */
  while (*string++)
    length++;

  return length;
}

/*******************************************************************************
      Function: count_tabs

   Description: Counts the number of tabs in a given string.

        Inputs: string - A pointer at a string.

       Outputs: Returns the total number of tabs (integer) in the string.
*******************************************************************************/
int count_tabs(const char *string)
{
    int tabs = 0;  /* number of tabs */

    /* loop while string is not NULL */
    while(*string)
    {   
        /* if the character is a tab, increment number of tabs */
        if(*string == '\t')
            tabs++;

        /* increment the pointer through the string */
        string++;
    }

    return tabs;   /* returns number of tabs */
}

/*******************************************************************************
      Function: substitute_char

   Description: Substitutes old_char with new_char in a given string and returns
                the number of substitutions. 

        Inputs: string   - A pointer at a string.
                old_char - A given character the function is looking for
                new_char - A given character that is replacing old_char

       Outputs: The total number of substitutions (integer) done on the string.
*******************************************************************************/
int substitute_char(char *string, char old_char, char new_char)
{
    int substitutions = 0;  /* number of substitutions */

    /* loop while string is not NULL */
    while(*string)
    {
        /* if the character is the character we are looking for */
        if(*string == old_char)
        {
            /* set the old char to the new char and increment substitutions */
            *string = new_char;
            substitutions++;
            
        }
        /* increment the pointer through the string */
        string++;
    }
    return substitutions;   /* returns number of substitutions */
}

/*******************************************************************************
      Function: calculate_lengths

   Description: Calculates and prints the length of a given string.

        Inputs: string         - A pointer at a string.
                tabsize        - The number of spaces of the tabsize.
                string_length  - The length of the string.
                display_length - The number of characters required to print the
                                 string after tabs are expanded

       Outputs: Returns void.
*******************************************************************************/
void calculate_lengths(const char *string, int tabsize, int *string_length, 
                       int *display_length)
{
    *string_length = mystrlen(string);  /* get the string length */
    *display_length = 0;    /* set display_length to 0 */

    /* loop while string is not NULL */
    while(*string)
    {
        /* add tabsize to display length if it's a tab */
        if(*string == '\t')
        {
            /* increment by tabsize */
            (*display_length) += tabsize;
        }
        else
        {
            /* increment by 1 if it's a character */
            (*display_length)++;
        }

        /* increment the pointer through the string */
        string++;
    }

}

/*******************************************************************************
      Function: not_white_space

   Description: Determines whether a character in a string is or is not a white
                space. 

        Inputs: string   - A pointer at a string.

       Outputs: Returns FALSE or 0 (integer) if it is a whitespace.
                Returns TRUE or 1 (integer) if it is not a whitespace. 
*******************************************************************************/
static int not_white_space(const char *string)
{
    /* checks if character is a whitespace */
    if(*string == ' ' || *string == '\f' || *string == '\n' || *string == '\r'
       || *string == '\t' || *string == '\v')
    {
        /* returns FALSE if string is a whitespace*/
        return FALSE;
    }
    else
    {
        /* returns TRUE if string is not a whitespace */
        return TRUE;
    }
}

/*******************************************************************************
      Function: new_word

   Description: Determines whether a character in a string the start or body of
                a new word.

        Inputs: string   - A pointer at a string.

       Outputs: Returns TRUE or 1 (integer) if it is a part of a new word.
                Returns FALSE or 0 (integer) if it is not a part of a new word. 
*******************************************************************************/
static int new_word(const char *string)
{
    /* checks if the character is not a whitespace 
    AND the character before is a whitespace */
    if(not_white_space(string) && !(not_white_space(string - 1)))
    {
        /* returns TRUE if string is a word */
        return TRUE;
    }

    else
    {
        /* returns FALSE if string is not a word */
        return FALSE;
    }
}

/*******************************************************************************
      Function: count_words

   Description: Counts the number of words in a given string.

        Inputs: string   - A pointer at a string.

       Outputs: Returns the total number of words (integer) in the string.
*******************************************************************************/
int count_words(const char *string)
{
    /* number of words found */
    int words = 0;

    /* looping variable */
    int i = 0;
    
    /* loop while string is not NULL */
    while(*string)
    {
        /* case for the first character of the string */
        /* if the character is not a white space and is the first character,
        increment total words */
        if(not_white_space(string) && i == 0)
        {
            words++;
        }

        /* if the character is a word, increment total words */
        if(new_word(string))
        {
            words++;
        }

        /* increment the pointer through the string */
        string++;

        /* increment i to determine what number of character we are on */
        i++;
    }
    return words;   /* returns number of words */
}
