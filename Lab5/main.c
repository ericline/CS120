/******************************************************************************
filename    main.c
author      Eric Lin
DP email    eric.lin@digipen.edu
course      CS120
section     B
lab week    2
due date    10/15/2021

Brief Description:
  This program is the driver that prints all integers with the cube property
  up to 1000 and all possible Pythagorean triples up to 100.
  
******************************************************************************/

/* Function declarations */
void print_cubes(void);
void print_pythagorean_triples(int low, int high);

int main(void)
{
    /* Print all of the integers with the cube property */
  print_cubes();

    /* Print all of the triples from 1 up to 100        */
    /* but not including 100  [1, 100)                  */
  print_pythagorean_triples(1, 100);

  return 0;
}
