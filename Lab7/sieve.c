/**************************************************************************
filename    sieve.c
author      Eric Lin
DP email    eric.lin@digipen.edu
course      CS120
section     B
lab         7
due date    10/30/2021

   Brief Description:
     This program contains three functions. The first function finds prime
     numbers using Sieve of Eratosthenes algorithm. The second function 
     finds twin primes. The third function calculates Brun's Constant.

**************************************************************************/

#include <stdio.h> /* printf      */
#include <math.h>  /* sqrt        */
#include "sieve.h" /* TRUE, FALSE */

/**************************************************************************
      Function: sieve

   Description: Finds prime numbers through crossing out multiples.

        Inputs: array - given array of integers
                size - number of elements in the array

       Outputs: void
**************************************************************************/
void sieve(int array[], int size)
{
  int i; /* looping variable */
  int max = sqrt(size);
  for (i = 0; i <= size; i++) {
    array[i] = TRUE; /* set all elements to 1 */
  }

  array[0] = FALSE; /* 0 is not prime */
  array[1] = FALSE; /* 1 is not prime */

  /* starts at factor of 2 and goes until sqrt of size */
  for (i = 2; i <= max; i++) 
  {

    if (array[i] == TRUE)
    {
      /* checks all multiples of i */
      int j;
      for (j = i * 2; j <= size; j += i) 
      {
        array[j] = FALSE; /* set elements to 0 */
      }
    }
  }
}

/**************************************************************************
      Function: twin_primes

   Description: Finds prime numbers that have a difference of two.

        Inputs: primes - given array of integers
                size - number of elements in the array

       Outputs: total number of twin primes found
**************************************************************************/
int twin_primes(const int primes[], int size)
{
  int i; /* looping variable */
  int twinPrimes = 0; /* number of twin prime pairs found */

  /* goes through all numbers of the array starting from 3 */
  for(i = 3; i < size; i++) 
  {
    /* checks if the array has elements that have
    a difference of 2 and are prime */
    if (primes[i] && primes[i + 2]) 
    {
      twinPrimes++;
      printf("twin prime #%4i: %4i and %4i\n", twinPrimes, i, i + 2);
    }
  }
  return twinPrimes;  /* returns number of twin primes found */
}

/**************************************************************************
      Function: brun_constant

   Description: Finds Brun's Constant by summing prime twins.

        Inputs: primes - given array of integers
                size - number of elements in the array

       Outputs: sum - approximation of Brun's Constant
**************************************************************************/
double brun_constant(const int primes[], int size)
{
  int i; /* looping variable */
  double sum = 0.0; /* sum equal to Brun's Constant */

  /* goes through all numbers of the array starting from 3 */
  for (i = 3; i < size; i ++)
  {
    /* checks if the array has elements that have
    a difference of 2 and are prime */
    if(primes[i] && primes[i + 2])
    {
      double term = 1.0 / i + 1.0 / (i + 2);  /* each term of constant */
      sum += term;  /* add each term to sum */
    }
  }
  return sum; /* returns Brun's Constant */
}
