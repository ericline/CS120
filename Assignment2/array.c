/**************************************************************************
filename    array.c
author      Eric Lin
DP email    eric.lin@digipen.edu
course      CS120
section     B
assignment  2
due date    10/21/2021

   Brief Description:
     This program contains the functions to reverse, add, multiply,
     find the dot product, and find the cross product of a given array.
**************************************************************************/

/**************************************************************************
    Function: reverse_array
Description: Reverses the elements in a given array.

        Inputs: a[] - A given array.
                size - A given size of the array.

       Outputs: Produces the reverse of the given array, but returns void.
**************************************************************************/

void reverse_array(int a[], int size)
{
    int i;  /* looping variable */
    for (i = 0; i < size / 2; i++) {
        /* Swaps lowest element with highest */
        int temp = a[i];
        a[i] = a[size - 1 - i];
        a[size - 1 - i] = temp;

    }
} 

/**************************************************************************
    Function: add_arrays
Description: Sums the elements of two given arrays.

        Inputs: a[] - A given array.
                b[] - A second given array.
                c[] - The sum of the two arrays: a and b.
                size - A given size of the array.

       Outputs: Stores the sum of the elements of array a[] and b[] into 
                array a[c], but returns void.
**************************************************************************/

void add_arrays(const int a[], const int b[], int c[], int size)
{
    int i;  /* looping variable */
    for (i = 0; i < size; i++) {
        /* Sum each element from a[] and b[] into c[] */
        c[i] = a[i] + b[i]; 

    }
}

/**************************************************************************
    Function: scalar_multiply
Description: Multiples the elements of a given array by a given multiplier.

        Inputs: a[] - A given array.
                size - A given size of the array.
                multiplier - The scale to multiple each array element by.

       Outputs: Produces the product of the given array multiplied by the
                given multiplier, but returns void.
**************************************************************************/

void scalar_multiply(int a[], int size, int multiplier)
{
    int i;  /* looping variable */
    for (i = 0; i < size; i++) {
        /* Multiple each element of a[] by the multiplier */
        a[i] *= multiplier; 

    }
}

/**************************************************************************
    Function: dot_product
Description: Sums the product of corresponding elements in two given 
             arrays.

        Inputs: a[] - A given array.
                b[] - Another given array.
                size - A given size of the array.

       Outputs: The sum (integer) of the products of the corresponding
                elements of the two arrays.
**************************************************************************/

int dot_product(const int a[], const int b[], int size)
{
    int i;  /* looping variable */
    int sum = 0;    /* sum of all products */    
    for (i = 0; i < size; i++) {
        /* Add the product of each element of a[] and b[] into sum */
        sum += a[i] * b[i];

    }

    return sum;

}

/**************************************************************************
    Function: cross_product
Description: Finds the cross product of two given arrays

        Inputs: a[] - A given array.
                b[] - Another given array.
                c[] - A third given array.

       Outputs: The cross product is stored in the array c[], but returns
       void.
**************************************************************************/

void cross_product(const int a[], const int b[], int c[])
{
    /* cross product formula */
    c[0] = a[1] * b[2] - a[2] * b[1];
    c[1] = -1 * (b[2] * a[0] - b[0] *a[2]);
    c[2] = a[0] * b[1] - a[1] * b[0];

}
