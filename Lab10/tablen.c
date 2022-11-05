/*******************************************************************************
filename    tablen.c
author      Eric Lin
DP email    eric.lin2@digipen.edu
course      CS120
section     B
lab         10
due date    11/23/2021

Brief Description:
  This file contains three function: count_tabs and line_length which are the
  helper functions to the function tablen.

*******************************************************************************/

#include <stdio.h>              /* printf, fopen, fclose, fgets*/
#include <string.h>             /*strlen */
#define MAX_LINE_LENGTH 1000    /* max char in each lines */

/*******************************************************************************
      Function: count_tabs

   Description: Calculates and prints the number of tabs per line and a summary
                of overall tabs in the file.

       Inputs: filename - a pointer to a given file.

       Outputs: Returns void, but prints out the number of tabs per line and an 
                overall summary of lines containing tabs.
*******************************************************************************/
static void count_tabs(const char *filename)
{
    FILE *fp;

    char buffer[MAX_LINE_LENGTH]; /* buffer with max_length to hold each line */
    int tabs_per_line = 0;        /* tabs in each line */
    int total_tabs = 0;           /* total tabs in the file */
    int line_num = 1;             /* line number */
    
    int i;                        /* looping variable */

    /* Open file for reading */
    fp = fopen(filename, "r");

    /* Check if file is available for reading */
    if(fp)
    {
        /* While there are more lines in the file */
        while(!feof(fp))
        {
            /* Read in a line */
            /* if next line is not NULL, put into buffer */
            if (fgets(buffer, MAX_LINE_LENGTH, fp) != NULL)
            {
                /* resets tabs per line per iteration */
                tabs_per_line = 0;

                /* iterate through line */
                for (i = 0; i < (signed)strlen(buffer); i++)
                {
                    /* if there are tabs, increment the tab counts */
                    if (buffer[i] == '\t')
                    {
                        tabs_per_line++;
                        total_tabs++;
                    }
                }
            }

            /* if the line has at least one tab */
            if(tabs_per_line > 0)
            {
                /* Removes and overwrites newline character with NULL */
                buffer[strlen(buffer) - 1] = '\0';

                /* Print line with tab information */
                printf("#%3i: (tabs:%2i) |%s|\n", 
                line_num, tabs_per_line, buffer);
            }
            line_num++; /* increment line number each line read */
        }
        /* close the file */
        fclose(fp);
    }
    else    /* else return error */
    {
        printf("Can't open %s for read.\n", filename);
        fclose(fp);
        return;
    }

    if(total_tabs > 0)
    {
        /* print summary of total tabs */
        printf("*****  TABS IN USE  *****: Number of tabs in the file is %i.\n",
        total_tabs);
    }
}

/*******************************************************************************
      Function: line_length

   Description: Finds and prints the character number and text of all lines 
                with over 80 characters in a file.

       Inputs: filename - a pointer to a given file.

       Outputs: Returns void, but prints out the number of characters per line
                and an overall summary of line over 80 characters.
*******************************************************************************/
static void line_length(const char *filename)
{
    FILE *fp;

    char buffer[MAX_LINE_LENGTH];/* buffer with max_length to hold each line */
    int length_per_line = 0;     /* tabs in each line */ 
    int long_lines = 0;          /* number of lines longer than 80 characters */
    int longest_line = 80;       /* assume 80 is longest line length */
    int longest_line_num = 1;    /* line number containing the longest line */
    int line_num = 1;            /* line number */

    /* Open file for reading */
    fp = fopen(filename, "r");

    /* Check if file is unable to open for reading */
    if(fp)
    {
        /* While there are more lines in the file */
        while(!feof(fp))
        {
            /* Read in a line */
            /* if next line is not NULL, put into buffer */
            if (fgets(buffer, MAX_LINE_LENGTH, fp) != NULL)
            {
                length_per_line = strlen(buffer) - 1;

                /* check length of line to see if it is greater than 80 */
                if(length_per_line > 80)
                {      
                    /* Removes and overwrites newline character with NULL */
                    buffer[strlen(buffer) - 1] = '\0';

                    /* If it is, print line with length information */
                    printf("#%3i: (%3i) |%s|\n", 
                    line_num, length_per_line, buffer);

                    /* increment number of long lines */
                    long_lines++;

                    /* if the line length is longerthan current longest line */
                    /* set the current line length to the longest line and 
                    set the current line number to the longest line number */
                    if(length_per_line > longest_line)
                    {   
                        longest_line = length_per_line;
                        longest_line_num = line_num;
                    }   
                }
            }
            line_num++;
        }
        /* close the file */
        fclose(fp);

    }
    else    /* else return error */
    {
        printf("Can't open %s for read.\n", filename);
        fclose(fp);
        return;
    }   
    
    if(long_lines > 0)
    {
        /* print summary of total tabs */
        printf("***** LINE TOO LONG *****: ");
        printf("%i lines longer than 80. Longest line is %i at %i chars.\n",
        long_lines, longest_line_num, longest_line);
    }
}

/*******************************************************************************
      Function: tablen

   Description: Calls the two functions count_tabs and line_length.

       Inputs: filename - a pointer to a given file.

       Outputs: void.
*******************************************************************************/
void tablen(const char *filename)
{
    count_tabs(filename);
    line_length(filename);
}
