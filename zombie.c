/**
 * @file zombie.c
 * @brief Holds functions for zombie.h
 * @author Benjamin Wilson
 * @date Fall 2021
 * @bug Probably
 * @todo none
 */

#include "zombie.h"

/** Takes user input for how many toes a zombie had
 * @result Integer value for user inputted number
 */
int input_toes()
{
    char in_toes[SIZE];
    int toes;
    
    printf("\nPlease enter the number of toes the zombie has:\n");
    printf(">> ");
    /* Takes user-input and converts it into return int data type */
    fgets(in_toes, SIZE, stdin);
    toes = atoi(in_toes);

    return toes;
}

/** Takes user input for how much blood a zombie oozed when killed
 * @result Floating point value for user inputted amount of blood.
 */
float input_blood()
{
    char in_blood[SIZE];
    float blood;

    printf("\nPlease enter the amount of blood that oozed from its body\n");
    printf("after you killed it (in mL):\n");
    printf(">> ");
    /* Takes user-input and converts it into return float data type */
    fgets(in_blood, SIZE, stdin);
    blood = atof(in_blood);

    return blood;
}

/** Takes user input for which day the zombie was encountered
 * @result Integer value corresponding to the constant that defines what day
 * was inputted by the user.
 */
int input_day()
{
    int day;

    char in_day[SIZE];
    int in_num_day;

    int loop = 1;

    /* Loops user input until a valid input is made */
    while(loop == 1)
    {
        printf("\nPlease choose the day this zombie was encountered:\n");
        printf("1) Monday\n");
        printf("2) Tuesday\n");
        printf("3) Wednesday\n");
        printf("4) Thursday\n");
        printf("5) Friday\n");
        printf("6) Saturday\n");
        printf("7) Sunday\n");
        printf(">> ");
        /* Takes user-input and converts it into return int data type */
        fgets(in_day, SIZE, stdin);
        in_num_day = atoi(in_day);

        /* Assigns return variable to day constant */
        switch(in_num_day)
        {
        case 1:
           day = MON;
           loop = 2;
           break;
                
        case 2:
            day = TUE;
            loop = 2;
            break;
                
        case 3:
            day = WED;
            loop = 2;
            break;
        
        case 4:
            day = THU;
            loop = 2;
            break;
                
        case 5:
            day = FRI;
            loop = 2;
            break;

        case 6:
            day = SAT;
            loop = 2;
            break;
                
        case 7:
            day = SUN;
            loop = 2;
            break;
        
        default:
            printf("\nInvalid input. Please try again.\n");
        }
    }    

    return day;
}

/** Takes user input for time of day zombie was encountered.
 * @param unit Which time unit (hours, minutes, or seconds) from console to return
 * @param in_time[] user-input of time that is converted to an integer and
 * eventually returned. Essentially source of time info/conversions of function.
 * @result Either the hour of the day, minutes of the hour, or seconds of the minute
 * that the zombie was encountered.
 */
int input_time(char unit, char in_time[])
{
    /* tmp[] holds 2 char values of user input corresponding to unit of time */
    char tmp[2];
    int num_time;

    /* Assigns return value based on unit desired */
    if(unit == 'h')
    {
        num_time = atoi(in_time);

    } else if(unit == 'm')
    {
        tmp[0] = in_time[3];
        tmp[1] = in_time[4];
        num_time = atoi(tmp);

    } else if(unit == 's')
    {
        tmp[0] = in_time[6];
        tmp[1] = in_time[7];
        num_time = atoi(tmp);
    }
    
    return num_time;
}

/** Calls all other functions to prompt user-input and store stats for a zombie
 * @result A struct containing zombie stats
 */
struct zombie_t get_zombie()
{
    struct zombie_t zombie;

    char in[SIZE];

    int loop = 1;

    /* Checks for valid input of whether zombie is dead or not and assigns dead stat */
    do
    {
        printf("\nWas the zombie found dead? Y or N\n");
        printf(">> ");
        fgets(in, SIZE, stdin);

        if((in[0] == 'Y' && in[1] == '\n') || (in[0] == 'y' && in[1] == '\n'))
        {
            zombie.dead = 'y';
            loop = 2;

        } else if((in[0] == 'N' && in[1] == '\n') || (in[0] == 'n' && in[1] == '\n'))
        {
            zombie.dead = 'n';
            loop = 2;

        } else
        {
            printf("\nInvalid user input, please try again!\n");
        }

    } while(loop == 1);

    /* Calculates for toe stat or blood stat based on whether zombie is dead or alive */
    if(zombie.dead == 'y')
    {
        zombie.toes = input_toes();

    } else
    {
        zombie.blood = input_blood();
    }

    /* Finds day stat of zombie */
    zombie.day = input_day();

    /* Checks for valid user input of time */
    int count = 0;
    do
    {   
        if(count > 0)
        {
            printf("\nInvalid user input, please try again!\n");
        }

        printf("\nEnter time when this zombie was encountered.\n");
        printf("Seperate hours, minutes, and seconds by colons.\n");
        printf("hh:mm:ss\n");
        printf(">> ");
        fgets(in, SIZE, stdin);

        count++;
    } while(in[0] < '0' || in[0] > '2' || in[1] < '0' || (in[0] == '0' && in[1] > '9') || (in[0] == '1' && in[1] > '9') || (in[0] == '2' && in[1] > '3') || in[2] != ':' || in[3] > '5' || in[3] < '0' || in[4] < '0' || in[4] > '9' || in[5] != ':' || in[6] > '5' || in[6] < '0' || in[7] < '0' || in[7] > '9');

    /* Finds time of day stats for zombie */
    zombie.hour = input_time('h', in);
    zombie.min = input_time('m', in);
    zombie.sec = input_time('s', in);

    return zombie;
}

/** Prints log of zombies (up-to-5)
 * @param zombie[] Log of zombies entered
 * @param total_count total amount of zombies in log (up-to-5)
 * to create circular buffer
 */
void print_zombies(struct zombie_t zombie[], int total_count)
{
    int i;

    /* Prints zombies in log, avoiding junk in array if zombie not inputted yet */
    for(i = 0; i < total_count; i++)
    {
        printf("\n%d.", i + 1);
        
        /* Prints if zombie was alive or dead */
        if(zombie[i].dead == 'y' || zombie[i].dead == 'Y')
        {
            printf("This zombie was found dead.\n");
            printf("This zombie had %d toes.\n", zombie[i].toes);
        } else
        {
            printf("This zombie was found alive.\n");
            printf("It was drained of %lf mL of blood once killed.\n", zombie[i].blood);
        }

        /* Prints day stat of zombie */
        switch(zombie[i].day)
        {
            case MON:
                printf("This zombie was sighted Monday at ");
                break;

            case TUE:
                printf("This zombie was sighted Tuesday at ");
                break;
                
            case WED:
                printf("This zombie was sighted Wednesday at ");
                break;

            case THU:
                printf("This zombie was sighted Thursday at ");
                break;

            case FRI:
                printf("This zombie was sighted Friday at ");
                break;

            case SAT:
                printf("This zombie was sighted Saturday at ");
                break;

            case SUN:
                printf("This zombie was sighted Sunday at ");
                break;
        }

        /* Prints time of day stats of zombie with appropriate formatting */
        if(zombie[i].hour < 10 && zombie[i].min < 10 && zombie[i].sec < 10)
        {
            printf("0%d:0%d:0%d\n", zombie[i].hour, zombie[i].min, zombie[i].sec);

        } else if(zombie[i].hour < 10 && zombie[i].min < 10 && zombie[i].sec > 9)
        {
            printf("0%d:0%d:%d\n", zombie[i].hour, zombie[i].min, zombie[i].sec);

        } else if(zombie[i].hour < 10 && zombie[i].min > 9 && zombie[i].sec > 9)
        {
            printf("0%d:%d:%d\n", zombie[i].hour, zombie[i].min, zombie[i].sec);

        } else if(zombie[i].hour > 9 && zombie[i].min < 10 && zombie[i].sec > 9)
        {
            printf("%d:0%d:%d\n", zombie[i].hour, zombie[i].min, zombie[i].sec);

        } else if(zombie[i].hour > 9 && zombie[i].min > 9 && zombie[i].sec < 10)
        {
            printf("%d:%d:0%d\n", zombie[i].hour, zombie[i].min, zombie[i].sec);

        } else if(zombie[i].hour > 9 && zombie[i].min < 10 && zombie[i].sec < 10)
        {
            printf("%d:0%d:0%d\n", zombie[i].hour, zombie[i].min, zombie[i].sec);

        } else if(zombie[i].hour < 10 && zombie[i].min > 9 && zombie[i].sec < 10)
        {
            printf("0%d:%d:0%d\n", zombie[i].hour, zombie[i].min, zombie[i].sec);

        } else
            printf("%d:%d:%d\n", zombie[i].hour, zombie[i].min, zombie[i].sec);
    }
}
