/**
 * @file smallest.c
 * @brief Finds the smallest number divisible by all numbers 1-20
 * @author Benjamin Wilson
 * @date Fall 2021
 * @bug none
 * @todo none (but could most likely be done more efficiently)
 */

#include <stdio.h>

int main()
{
    int i, j, div, count;

    /* Check numbers 1-1000000000 for evenly divisible number */
    for(i = 1; i < 1000000000; i++)
    {
        /* Resets counts */
        div = 0;
        count = 0;

        /* Divides number by 1-20 */
        for(j = 1; j < 21; j++)
        {
            /* Counts remainder of all divisions */
            div = i % j;
            count += div;
        }

        /* If all j divisions returned 0 remainder, print and terminate */
        if(count == 0)
        {
            printf("\n The smallest number divisible by 1-20 is %d\n\n", i);
            return 0;
        }
    }

    return 0;
}