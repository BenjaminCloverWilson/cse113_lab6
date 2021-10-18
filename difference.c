/**
 * @file difference.c
 * @brief Finds difference of sum of squares and square of sum for 1-100
 * @author Benjamin Wilson
 * @date Fall 2021
 * @bug none
 * @todo none (but could most likely be done more efficiently)
 */

#include <stdio.h>

int main()
{
    int i, squared, dif;
    int sum_squares = 0;
    int sum = 0;

    /* Finds sum of the squares (first) then the sum of the raw numbers */
    for(i = 1; i < 101; i++)
    {
        sum_squares += i * i;
        sum += i;
    }

    /* Finds the squared sum of the numbers */
    squared = sum * sum;

    /* Finds difference */
    dif = squared - sum_squares;

    /* printf() split for display purposes */
    printf("\nThe difference between the sum of the squares and square of the sum");
    printf(" is: %d\n\n", dif);

    return 0;
}