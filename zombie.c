#include "zombie.h"


int input_toes()
{
    char in_toes[SIZE];
    int toes;
    
    printf("\nPlease enter the number of toes the zombie has:\n");
    printf(">> ");
    fgets(in_toes, SIZE, stdin);
    toes = atoi(in_toes);

    return toes;
}


float input_blood()
{
    char in_blood[SIZE];
    float blood;

    printf("\nPlease enter the amount of blood that oozed from its body\n");
    printf("after you killed it (in mL):\n");
    printf(">> ");
    fgets(in_blood, SIZE, stdin);
    blood = atof(in_blood);

    return blood;
}


int input_day()
{
    int day;

    char in_day[SIZE];
    int in_num_day;

    int loop = 1;

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
        fgets(in_day, SIZE, stdin);
        in_num_day = atoi(in_day);

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


int input_time(char unit, char in_time[])
{
    char tmp[2];
    int num_time;

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


struct zombie_t get_zombie()
{
    struct zombie_t zombie;

    char in[SIZE];

    int loop = 1;

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

    if(zombie.dead == 'y')
    {
        zombie.toes = input_toes();

    } else
    {
        zombie.blood = input_blood();
    }

    zombie.day = input_day();


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
    } while(in[0] < '0' || in[0] > '2' || in[1] < '0' || in[1] > '3' || in[2] != ':' || in[3] > '5' || in[3] < '0' || in[4] < '0' || in[4] > '9' || in[5] != ':' || in[6] > '5' || in[6] < '0' || in[7] < '0' || in[7] > '9');

    zombie.hour = input_time('h', in);
    zombie.min = input_time('m', in);
    zombie.sec = input_time('s', in);

    return zombie;
}


void print_zombies(struct zombie_t zombie[], int count)
{
    int i;

    for(i = 0; i < count; i++)
    {
        printf("%d.", i + 1);
        
        if(zombie[i].dead == 'y' || zombie[i].dead == 'Y')
        {
            printf("This zombie was found dead.\n");
            printf("This zombie had %d toes.\n", zombie[i].toes);
        } else
        {
            printf("This zombie was found alive.\n");
            printf("It was drained of %lf mL of blood once killed.\n", zombie[i].blood);
        }

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