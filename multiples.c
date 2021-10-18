/**
 * @file multiples.c
 * @brief Finds sum of all multiples of 3 and 5 for 1-1000
 * @author Benjamin Wilson
 * @date Fall 2021
 * @bug none
 * @todo none (but could most likely could be done more efficiently)
 */

#include <stdio.h>

int main()
{
    int i;
    int sum = 0;

    /* Finds multiples and adds them to the total sum */
    for(i = 1; i < 1000; i++)
    {
        if(i % 3 == 0 || i % 5 == 0)
        {
            sum += i;
        }
    }

    /* Prints out sum of all multiples */
    printf("\nSum of all natural numbers below 1000 that are multiples of");
    printf(" 3 or 5 is: %d\n\n", sum);

    return 0;
}