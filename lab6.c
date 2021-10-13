/**
 * @file lab6.c
 * @brief Menu and calls for zombie program. Logs up-to 5 zombies
 * @author Benjamin Wilson
 * @date Fall 2021
 * @bug Probably
 * @todo none
 */

#include "zombie.h"

int main()
{
    /* Holds zombie stats in log */
    struct zombie_t zombie;
    struct zombie_t log[LOG];

    /* User-input arrays and integers */
    char in[SIZE];
    int in_num;

    /* Loop and log counting variables */
    int loop = 1;
    int log_loop = 1;
    int count = 0;
    int total_count = 0;

    printf("\n---Welcome to Benjamin Wilson's Zombie Log---\n");
    printf("---Serving the surviving members of humanity since 2021---\n");

    /* Checks that valid user-input of menu options */
    while(loop == 1)
    {
    
    printf("\n1) Enter new zombie information\n");
    printf("2) Display zombie information\n");
    printf("3) Return to fighting zombies (exit)\n");
    printf(">> ");
    /* Takes user-input and converts to integer for menu */
    fgets(in, SIZE, stdin);
    in_num = atoi(in);

    /* Menu option calls and printf() */
    switch(in_num)
    {
        /* Input zombie and place it in log */
        case 1:
            /* Tells user that max log number (5) is reached */
            if(count == LOG)
            {
                /* Checks for valid user-input */
                do
                {
                    /* printf() split for display purposes */
                    printf("\nWARNING! Maximum zombie log number reached!\n");
                    printf("Entering another zombie will begin deleting old");
                    printf("logs oldest to newest.\n");
                    printf("You will not be prompted again until 5 more logs");
                    printf("are overwritten.\n");
                    printf("Continue? Y or N\n");
                    printf(">> ");
                    /* User-input */
                    fgets(in, SIZE, stdin);

                    /* Take input, start count over, overwrite log one */
                    if((in[0] == 'Y' && in[1] == '\n') || (in[0] == 'y' && in[1] == '\n'))
                    {
                        zombie = get_zombie(zombie);
                        count = 0;
                        log[count] = zombie;
                        count++;
                        log_loop = 2;

                    /* Do nothing but exit user-input loop for yes or no */
                    } else if((in[0] == 'N' && in[1] == '\n') || (in[0] == 'n' && in[1] == '\n'))
                    {
                        log_loop = 2;

                    } else
                    {
                        printf("\nInvalid user input, please try again!\n");
                    }

                } while(log_loop == 1);

            /* get user-inputted zombie stats, and place in log based on count */
            } else if(count < LOG)
            {
                zombie = get_zombie(zombie);
                log[count] = zombie;
                count++;
                
                /**
                 * How many zombies are in log at any time. Does not start
                 * over if overwritting of previous logs begins. Creates
                 * circular buffer
                 */
                if(total_count != 5)
                {
                    total_count++;
                }
            }

            break;

        /* Print log of zombie stats */
        case 2:
            print_zombies(log, total_count);
            break;
        
        /* Terminate and quit program */
        case 3:
            /* printf() split for display purposes */
            printf("\nStay alert. Watch out for zombies! GOODBYE and ");
            printf("GOOD LUCK!\n\n");
            printf("Terminating program...\n\n");

            return 0;
        
        /* Invalid menu input */
        default:
            /* printf() split for display purposes */
            printf("\nInvalid user input. Time is of the essence, pay");
            printf(" attention and try again!\n\n");
    }

    }
}
