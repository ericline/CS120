/**************************************************************************
Function: print_cubes
          print_pythagorean_triples

    Description: Calculates and prints all integers with the cube property
                 up to 1000 and all Pythagorean triples up to 100.

    Inputs: The range (integer) to print Pythagorean triples.

    Outputs: All integers with the cube property and all possible
             Pythagorean triples (integer).

**************************************************************************/
#include <stdio.h> /* printf */

void print_cubes(void)
{
    int i; /* loop counter */

    /* loop digits 100 to 999 */
    for (i = 100; i <= 999; i++) {
        /* Extract first, second, and third digits */
        int firstDigit = i / 100;
        int secondDigit = i / 10 % 10;
        int thirdDigit = i % 10;

        /* Cube each digit */
        int firstCubed = firstDigit * firstDigit * firstDigit;
        int secondCubed = secondDigit * secondDigit * secondDigit;
        int thirdCubed = thirdDigit * thirdDigit * thirdDigit;

        /* Add up the cubes and test if the sum is equal to i */
        int sum = firstCubed + secondCubed + thirdCubed;
        if (sum == i) {
            printf("%i has the cube property. ", i);
            printf("(%i + %i + %i)\n", firstCubed, secondCubed, thirdCubed);
        }
    }
}

void print_pythagorean_triples(int low, int high)
{
    /* Loop three values starting at low to high (exclusive) */  
    int i;
    int j;
    int k;
    int number = 0;
    for (i = low; i < high; i++) {
        for (j = i; j < high; j++) {
            for (k = j; k < high; k++) {
                /* Test Pythagorean Theorem */
                int firstSquared = i * i;
                int secondSquared = j * j;
                int thirdSquared = k * k;
                if (firstSquared + secondSquared == thirdSquared) {
                    number++;
                    /* Print Triples */
                    printf("Triple #%3i: %3i,%3i,%3i --> %4i + %4i = %4i\n", 
                    number, i, j, k, firstSquared, secondSquared, thirdSquared);
                }
            }
        }
    }

}
