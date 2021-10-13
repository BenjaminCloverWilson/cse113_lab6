#include "zombie.h"

int main()
{
    struct zombie_t zombie;
    struct zombie_t log[LOG];

    char in[SIZE];
    int in_num;

    int loop = 1;
    int log_loop = 1;
    int count = 0;

    printf("\n---Welcome to Benjamin Wilson's Zombie Log---\n");
    printf("---Serving the surviving members of humanity since 2021---\n");

    while(loop == 1)
    {
    
    printf("\n1) Enter new zombie information\n");
    printf("2) Display zombie information\n");
    printf("3) Return to fighting zombies (exit)\n");
    printf(">> ");
    fgets(in, SIZE, stdin);
    in_num = atoi(in);

    switch(in_num)
    {
        case 1:
            if(count == LOG)
            {
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
                    fgets(in, SIZE, stdin);

                    if((in[0] == 'Y' && in[1] == '\n') || (in[0] == 'y' && in[1] == '\n'))
                    {
                        zombie = get_zombie(zombie);
                        count = 0;
                        log[count] = zombie;
                        count++;
                        log_loop = 2;

                    } else if((in[0] == 'N' && in[1] == '\n') || (in[0] == 'n' && in[1] == '\n'))
                    {
                        log_loop = 2;
                        break;

                } else
                {
                    printf("\nInvalid user input, please try again!\n");
                }

                } while(log_loop == 1);

            } else if(count < LOG)
            {
                zombie = get_zombie(zombie);
                log[count] = zombie;
                count++;
                break;
            }

        case 2:
            print_zombies(log, count);
            break;
        
        case 3:
            /* printf() split for display purposes */
            printf("\nStay alert. Watch out for zombies! GOODBYE and ");
            printf("GOOD LUCK!\n\n");
            printf("Terminating program...\n\n");

            return 0;
        
        default:
            /* printf() split for display purposes */
            printf("\nInvalid user input. Time is of the essence, pay");
            printf(" attention and try again!\n\n");
    }

    }
}