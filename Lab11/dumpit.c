#include <stdio.h>  /* printf, fopen, fclose, sprintf */
#include <string.h> /* strcat, strcpy */

/* Longest formatted line is 75 characters */
#define MAXLEN 75

/* Example: (This example has Unix end-of-line character: 0x0A)
 *
 *  If inbuf contains the first 16 characters from the poem.txt file and outbuf
 *  is an empty array large enough to hold the formatted string, this is how 
 *  you would call the format function:
 *   
 *     format(inbuf, outbuf, 16, 0);
 *  
 *  and this is what outbuf would contain when it returned:
 *  
 * 000000 52 6F 73 65 73 20 61 72  65 20 72 65 64 2E 0A 56   Roses are red..V
 *
 *
 *  The second 16 bytes would be formatted like this:
 *
 *     format(inbuf, outbuf, 16, 16);
 *
 *  and outbuf would look like this:
 *
 * 000010 69 6F 6C 65 74 73 20 61  72 65 20 62 6C 75 65 2E   iolets are blue.
 *
 */
 
/*******************************************************************************
   Function: format

Description: Given an array of characters, format the characters as a line of
             hexadecimal numbers, including file offset and ASCII letters. Only
             the printable ASCII characters are displayed. Non-printable 
             characters are displayed as a period. The file offset is shown
             as a hexadecimal number.

     Inputs:  inbuf - The array of characters to format.
             outbuf - The formatted array, including offset and ASCII letters. 
              count - The number of characters in the input array.
             offset - The value of the 6-digit offset.

    Outputs: None. However, the outbuf parameter has been modified for the
             client.
*******************************************************************************/
void format(const char* inbuf, char *outbuf, int count, int offset)
{
    int i;  /* loop variable */
    int j;
    char byte[3];
  
    /* e.g. 000010 */
    sprintf(outbuf, "%06X ", offset);

    /* e.g. 52 6F 73 65 73 20 61 72  65 20 72 65 64 2E 0A 56 */
    for (i = 0; i < count; i++)
    {
        /* Format each byte as a hex number using sprintf */

        sprintf(byte, "%02X", (unsigned char)inbuf[i]);

        /* Add the hex number to the end of buffer using strcat */  

        strcat(outbuf, byte);
        strcat(outbuf, " ");

        /* Don't forget the extra space between the 8th and 9th number */  

        if(i == 7)
        {
            strcat(outbuf, " ");
        }

    }

    /* If you didn't get 16 characters, you have to add extra spaces */  

    if (i < 16)
    {
        while(i < 16)
        {
            strcat(outbuf, "   ");

            if(i == 7)
            {
                strcat(outbuf, " ");
            }

            i++;
      }
  }

  strcat(outbuf, "  ");

    /* Using another loop, append the ASCII representation of the chars */  

    for(j = 0; j < count; j++)
    {
        if(31 < inbuf[j] && inbuf[j] < 127)
        {
            sprintf(byte, "%c", inbuf[j]);
            strcat(outbuf, byte);
        }
        else
        {
            strcat(outbuf, ".");
        }
    }
}

/*******************************************************************************
   Function: dump

Description: Given a filename, read in the bytes and print their hexadecimal
             values to the screen. If the character is printable, print the
             character as well.
             
     Inputs: filename - The name of the file to dump in hex.

    Outputs: N/A
*******************************************************************************/
void dump(const char *filename)
{
    /* Variable declarations */
    FILE *fp;

    char buffer[16] = { 0 };    /* array of characters to format */
    char formatted[MAXLEN];     /* the formatted characters */
    int char_read;              /* the fread characters */
    int offset = 0;             /* value of bytes to format */
    int i;                      /* looping variable */

    /* Open the file for read/binary, "rb"  (Text mode will not work) */
    /* If the file couldn't be opened, print error message and return */

    fp = fopen(filename, "rb");

    if(!fp)
    {
        printf("Can't open %s for binary read.", filename);
    }
    else
    {
        /* Print the filename to the screen followed by a colon */
        
        printf("\n");
        printf("%s:\n", filename);

        /* Print the first header line (offsets in hexadecimal) */

        printf("%7c", ' ');
        for(i = 0; i < 16; i ++)
        {

            printf("%02X ", i);

            if(i == 8)
            {
                printf(" ");
            }
        }
        printf("\n");

        /* Print the second header line (dashes) */

        for(i = 0; i < 74; i++)
        {
            printf("-");
        }
        printf("\n");

        /* For all bytes in the file */
        while (!feof(fp))
        {
            /* Read in bytes (16 at a time) using fread */

            char_read = fread(buffer, 1, 16, fp);

            /* Format bytes using the format function above */

            format(buffer, formatted, char_read, offset);

            /* Print formatted string using printf or puts  */

            printf("%s\n", formatted);

            /* Read 16 bytes at a time */

            offset += 16;

        }

        /* Close the file */

        fclose(fp);

    }
}
