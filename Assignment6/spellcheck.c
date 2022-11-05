/*******************************************************************************
filename    spellcheck.c
author      Eric Lin
DP email    eric.lin2@digipen.edu
course      CS120
section     B
assignment  6
due date    12/02/2021

Brief Description:
    This file contains several functions to analyze a dictionary of words.
    The included functions are remove_newline, mystrupr, words_starting_with,
    word_length, info, and spell_check. 

*******************************************************************************/

#include <string.h> /* strcmp, strcpy, strlen */
#include <stdio.h>  /* FILE, fopen, fgets */

/* FILE_OK, FILE_ERR_OPEN, WORD_OK, WORD_BAD, LONGEST_WORD */
#include "spellcheck.h"

/*******************************************************************************
   Function: remove_newline

Description: Removes the newline at the end of a string by converting the
             newline character to a 0.

     Inputs: string - a pointer to an array of characters.

    Outputs: void.
*******************************************************************************/
static void remove_newline(char *string)
{
    string[strlen(string) - 1] = 0;
}

/*******************************************************************************
   Function: mystrupr

Description: Converts all lowercase letters to uppercase in a given string.

     Inputs: string - a pointer to an array of characters.

    Outputs: Returns pointer to the first character of the modified string.
*******************************************************************************/
char *mystrupr(char *string)
{
    int i;                      /* looping variable */
    char *original = string;    /* pointer to first character of the string */
    int string_length = strlen(string);

    /* loop through the string */
    for(i = 0; i < string_length; i++)
    {
        /* if a character is a lowercase letter */
        if(*string >= 'a' && *string <= 'z')
        {
            /* change lowercase to uppercase */
            *string -= 32;
        }
        
        /* increment pointer through string */
        string++;
    }

    return original;
}

/*******************************************************************************
   Function: words_starting_with

Description: Readings through a dictionary and counts the number of words
             that start with a given letter.

     Inputs: dictionary - a pointer to a file of words.
             letter     - a given letter to find in the dictionary.

    Outputs: Returns the total number of words starting with the given letter.
*******************************************************************************/
int words_starting_with(const char *dictionary, char letter)
{
    FILE *fp;                   /* file to open */
    char buffer[LONGEST_WORD];  /* variable to hold each line from file */
    int total_words = 0;        /* total words starting with letter */

    /* Try to open file for reading */
    fp = fopen(dictionary, "r");

    /* Return error if file cannot be opened */
    if(!fp)
    {
        return FILE_ERR_OPEN;
    }
    else
    {
        /* While not at the of the file */
        while(!feof(fp))
        {
            /* read in each line */
            if(fgets(buffer, LONGEST_WORD, fp))
            {
                /* convert line to all uppercase */
                buffer[LONGEST_WORD - 1] = *mystrupr(buffer);

                /* if letter is lowercase, convert to uppercase */
                if(letter >= 'a' && letter <= 'z')
                {
                    letter -= 32;
                }
                
                /* increment total words if first character matches the letter */
                if(letter == *buffer)
                    total_words++;
            }
        }
        /* close the file and return total words */
        fclose(fp);
        return total_words;
    }
}

/*******************************************************************************
    Function: word_length

Description: Counts the number of words that have length 1 to count

     Inputs: dictionary - a pointer to a file of words.
             lengths    - an array to hold number of words with given lengths.
             count      - max word length

    Outputs: Returns FILE_OK if the file can be opened and FILE_ERR_OPEN if the
             file cannot be opened.
********************************************************************************/
int word_lengths(const char *dictionary, int lengths[], int count)
{
    FILE *fp;                   /* file to open */
    char buffer[LONGEST_WORD];  /* variable to hold each line from file */
    int string_length = 0;      /* length of string */
    int i;                      /* looping variable */

    /* fill lengths array of 0s first */
    for(i = 0; i <= count; i++)
    {
        lengths[i] = 0;
    }

    /* open file for reading */
    fp = fopen(dictionary, "r");

    /* Return error if file cannot be opened */
    if(!fp)
    {
        return FILE_ERR_OPEN;
    }
    else
    {
        /* While not at the of the file */
        while(!feof(fp))
        {
            /* read in each line */
            if(fgets(buffer, LONGEST_WORD, fp))
            {   
                /* remove the newline character of each line */
                remove_newline(buffer);

                string_length = strlen(buffer);

                /* increment corresponding index if word length is less than
                current count */
                if(string_length <= count)
                {
                    lengths[string_length]++;
                }
            }
        }
        /* close the file and return FILE_OK */
        fclose(fp);
        return FILE_OK;
    }
}

/*******************************************************************************
   Function: info

Description: Counts the total number of words in a dictionary and finds the
             longest and shortest word.

     Inputs: dictionary - a pointer to a file of words.
             dinfo      - a pointer to a struct.

    Outputs: Returns FILE_OK if the file can be opened and FILE_ERR_OPEN if the
             file cannot be opened.
*******************************************************************************/
int info(const char *dictionary, struct DICTIONARY_INFO *dinfo)
{
    FILE *fp;                   /* file to open */
    char buffer[LONGEST_WORD];  /* variable to hold each line */
    int word_length = 0;        /* length of word */            

    /* pointer at longest word in dictionary */
    dinfo->longest = 0;
    /* pointer at shortest word, assume shortest is longest at first */
    dinfo->shortest = LONGEST_WORD;
    /* pointer at total word count */
    dinfo->count = 0;

    /* open file for reading */
    fp = fopen(dictionary, "r");

    /* Return error if file cannot be opened */
    if(!fp)
    {
        return FILE_ERR_OPEN;
    }
    else
    {
        /* While not at the of the file */
        while(!feof(fp))
        {
            /* read in each line */
            if(fgets(buffer, LONGEST_WORD, fp))
            {   
                /* remove the newline character of each line */
                remove_newline(buffer);

                /* increment total number of words each line */ 
                dinfo->count++;

                word_length = strlen(buffer);

                /* if word length is greater than the longest word,
                assign the longest word to the current word */
                if(word_length > dinfo->longest)
                {
                    dinfo->longest = word_length;
                }

                /* if word length is less than the shortest word,
                assign the shortest word to the current word */
                if(word_length < dinfo->shortest)
                {
                    dinfo->shortest = word_length;
                }
            }
        }
        /* close the file and return FILE_OK */
        fclose(fp);
        return FILE_OK;
    }
}

/*******************************************************************************
   Function: spell_check

Description: Determines whether a given word is contained in a dictionary.

     Inputs: dictionary - a pointer to a file of words.
             word - a pointer to an array characters that make up a word.

    Outputs: Returns WORD_OK if the word was found and WOrD_BAD if the word was
             not found.
*******************************************************************************/
int spell_check(const char *dictionary, const char *word)
{
    FILE *fp;                   /* file to open */
    char line[LONGEST_WORD];  /* variable to hold each line from file */
    char given_word[LONGEST_WORD]; /* variable to hold given word */

    /* put word in variable */
    strcpy(given_word, word);

    /* Try to open file for reading */
    fp = fopen(dictionary, "r");

    /* Return error if file cannot be opened */
    if(!fp)
    {
        return FILE_ERR_OPEN;
    }
    else
    {
        /* While not at the of the file */
        while(!feof(fp))
        {
            /* read in each line */
            if(fgets(line, LONGEST_WORD, fp))
            {
                
                /* remove the newline character of each line */
                remove_newline(line);

                /* convert line to all uppercase */
                line[LONGEST_WORD - 1] = *mystrupr(line);
                given_word[LONGEST_WORD - 1] = *mystrupr(given_word);
                
                /* compare the line vs the given word */
                if(strcmp(line, given_word) == 0)
                {
                    /* if true, return WORD_OK and stop searching */
                    fclose(fp);
                    return WORD_OK;
                    break;
                }
            }
        }
        fclose(fp);
        return WORD_BAD;
    }
}
