/**************************************************************************
filename    main.c
author      Eric Lin
DP email    eric.lin@digipen.edu
course      CS120
section     B
lab         6
due date    10/23/2021

   Brief Description:
     This program contains the main.c to run primes1.c 
**************************************************************************/
#include <stdio.h> /* printf */

/* Prototypes implemented in primes1.c */
int is_prime(int n);
void conjecture(int low, int high);

void check_primes(int count)
{
  int primes = 0; /* number of primes found */
  int i;          /* loop counter           */

    /* Check all values from 1 to count */
  for (i = 1; i <= count; i++)
  {
      /* If it's prime, count it and print it */
    if (is_prime(i))
    {
      primes++;
      printf("#%3i: %3i is prime.\n", primes, i);
    }
  }
}

int main(void)
{
  
  check_primes(1000);
  conjecture(2, 2000);

  return 0;
}
