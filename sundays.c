/**
 * @file ssundays.c
 * @brief Determines number of Sundays on first day of a month in 20th century
 * @author Benjamin Wilson
 * @date Fall 2021
 * @bug none
 * @todo none (but could most likely be done more efficiently)
 */

#include <stdio.h>

/* Creates weekday constants for tracking the day as the century progresses */
enum days 
{
    MON = 1,
    TUE, WED, THUR, FRI, SAT, SUN
} start = TUE;

int main()
{
    /* Variables for tracking year, month of year, and number of sundays tallied */
    int year;
    int month;
    int sundays = 0;

    /* Runs through the years 1901 to 2000 */
    for(year = 1901; year < 2001; year++)
    {
        /* Determines if the year is a leap year or not */
        if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        {
            /* Leap year */
            /* Runs through every month in year */
            for(month = 1; month < 13; month++)
            {
                /* Runs through months with 31 days */
                if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
                {
                    /**
                     * Determines the first day of the month and calculates
                     * first day of the next month. Adds to sunday tally if
                     * first day is sunday
                     */
                    if(start < FRI)
                    {
                        start += 3;

                    } else if(start == FRI)
                    {
                        start = MON;

                    } else if(start == SAT)
                    {
                        start = TUE;

                    } else if(start == SUN)
                    {
                        sundays += 1;
                        start = WED;
                    }

                /* What to do for the month of february with 29 days */
                } else if (month == 2)
                {
                    /**
                     * Determines the first day of the month and calculates
                     * first day of the next month. Adds to sunday tally if
                     * first day is sunday
                     */
                    if(start != SUN)
                    {
                        start += 1;

                    } else if(start == SUN)
                    {
                        sundays += 1;
                        start = MON;
                    }
                
                /* Runs through months with 30 days */
                } else
                {
                    /**
                     * Determines the first day of the month and calculates
                     * first day of the next month. Adds to sunday tally if
                     * first day is sunday
                     */
                    if(start <= FRI)
                    {
                        start += 2;

                    } else if(start == SAT)
                    {
                        start = MON;

                    } else if(start == SUN)
                    {
                        sundays += 1;
                        start = TUE;
                    }
                }
            }

        } else
        {
            /* Runs through all the months for non-leap years */
            for(month = 1; month < 13; month++)
            {
                /* Runs through months with 31 days */
                if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
                {
                    /**
                     * Determines the first day of the month and calculates
                     * first day of the next month. Adds to sunday tally if
                     * first day is sunday
                     */
                    if(start < FRI)
                    {
                        start += 3;

                    } else if(start == FRI)
                    {
                        start = MON;

                    } else if(start == SAT)
                    {
                        start = TUE;

                    } else if(start == SUN)
                    {
                        sundays += 1;
                        start = WED;
                    }

                /* What to do with month of February with 28 days */
                } else if (month == 2)
                {
                    /* Adds to sunday tally if first day is sunday */
                    if(start == SUN)
                    {
                        sundays += 1;
                    }

                /* Runs through months with 30 days */
                } else
                {
                    /**
                     * Determines the first day of the month and calculates
                     * first day of the next month. Adds to sunday tally if
                     * first day is sunday
                     */
                    if(start <= FRI)
                    {
                        start += 2;

                    } else if(start == SAT)
                    {
                        start = MON;

                    } else if(start == SUN)
                    {
                        sundays += 1;
                        start = TUE;
                    }
                }
            }
        }
    }

    /* printf() split for display purposes */
    /* Prints out the number of sundays tallied as the first of a month */
    printf("\nThe number of sundays that fell on the first of the month ");
    printf("in the twentieth century (1 Jan, 1901 to 31 Dec, 2000): ");
    printf("%d\n\n", sundays);

    return 0;
}