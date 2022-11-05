/**************************************************************************
filename    primes1.c
author      Eric Lin
DP email    eric.lin@digipen.edu
course      CS120
section     B
lab         6
due date    10/23/2021

   Brief Description:
     This program contains the function to determine prime numbers given
     an integer (is_prime) and the function to print the Goldbach
     conjecture given a specified integer range.
**************************************************************************/
#include <stdio.h> /* printf */

/* For easier readability */
#define FALSE 0
#define TRUE  1

/**************************************************************************
      Function: is_prime

   Description: Determines whether a given number is prime.

        Inputs: number - an integer value to be test for whether or not it
                is prime

       Outputs: 1 (TRUE, integer) if number is prime, otherwise 
                0 (FALSE, integer) if number is not prime.
**************************************************************************/
int is_prime(int number)
{
  /* speical case: 2 is a prime number */
  if (number == 2) {
    return TRUE;
  }
  /* special case: 1 or any number divisible by 2 is not a prime number */
  else if (number == 1 || number % 2 == 0) {
    return FALSE;
  }
  else
  {
    int i;
    /* testing all odd values from 3 and up to number divided by 2 */
    for (i = 3; i <= number / 2; i += 2)
    {
      /* if number can be divided evenly, then return false */
      if (number % i == 0) 
      return FALSE;
    }
  }
  /* otherwise return true */
  return TRUE;
}

/**************************************************************************
      Function: conjecture

   Description: Prints Goldbach conjecture over a given range.

        Inputs: low - the lowest value in the range.
                high - the highest value in the range.

       Outputs: Prints every even number equal to the sum of two prime
                numbers, but returns void. 
**************************************************************************/
void conjecture(int low, int high)
{
  int sum;  /* the sum of the two prime numbers */
  int firstNumber;  /* the first prime number */

  /* loops even numbers over the given range */
  for (sum = low; sum <= high; sum += 2) 
  {
    /* loops first number */
    for(firstNumber = low; firstNumber <= sum; firstNumber++) 
    {
      /* finds second number using difference between sum and addend */
      int secondNumber = sum - firstNumber;

      /* tests if the first number and second number are prime */
      if (is_prime(firstNumber) == TRUE && is_prime(secondNumber) == TRUE)
      {
        /* print Goldbach conjecture */
        printf("%3i = %3i + %3i\n", sum, firstNumber, secondNumber);
        break;  /* break after pair is printed */
      }
    }
  }
}
