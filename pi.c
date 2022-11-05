/******************************************************************************
   Function: circle_pi
             leibniz.pi

Description: Given number of rectangles, approximate the value of pi using the 
             Circle Method. Returns the approximation of pi.
             Given number of iterations, approximate the value of pi using the
             Leibniz Method. Returns the approximation of pi.

     Inputs: rectangles - number of rectangles to split up a quarter circle
             iterations - number of times to run the Leibniz Method.

    Outputs: The approximation of pi (double) base on the number of given 
             iterations/rectangles. 
******************************************************************************/
#include <math.h>
#include <stdio.h>

double circle_pi(int rectangles)
{   
  int i; /* loop counter */
  double sum = 0.0; /* Sum of rectangle areas */
  double pi;  /* Stores the approximation of pi */

  for (i = 0; i < rectangles; ++i) 
  {
    double width = 1.0 / rectangles;  /* Dividing radius by rectangles to find width */
    double midpoint = (width / 2.0) + (i * width);    /* Dividing width by 2 to find midpoint */
    double height = sqrt(1.0 - midpoint * midpoint);  /* Pythagorean Theorem to find height*/

    /* Multiplying to find area of rectangle */
    double area = width * height;

    /* Add each rectangle to get pi */
    sum += area;
  }
  
  pi = sum * 4;

    /* Return an approximation of pi */
  return pi;
}

double leibniz_pi(int iterations )
{
  int i = 0; /* loop counter */
  double sum = 0.0; /* sum of terms */
  double pi = 0.0; /* Stores the approximation of pi */

  while (i < iterations)
  {
      /* Calculate denominator of each term */
    double denom = 2 * i + 1;

      /* Check if i is odd */
      if (i % 2 == 0 || i == 0) 
      {
        sum += (1 / denom);
      }    
      else
      {
        sum -= (1 / denom); 
      }
    ++i;
  }

    /* Multiply approximation of pi/4 by 4 */
  pi = sum * 4;

    /* Return an approximation of pi */
  return pi;
}
