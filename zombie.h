/**                                                                                        
 * @file zombie.h
 * @brief header file for lab6.c and zombie.c 
 * @author Benjamin Wilson
 * @date Fall 2021
 * @bug None yet
 * @todo Everything
 */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <stdio.h>
#include <stdlib.h>

#define SIZE 16
#define LOG 5

struct zombie_t {
    enum DAY {MON = 1, TUE, WED, THU, FRI, SAT, SUN} day;

    float blood;
    int toes;
    int hour;
    int min;
    int sec;
    char dead;
};

struct zombie_t get_zombie();
int input_toes();
float input_blood();
int input_day();
int input_time(char unit, char in_time[]);
void print_zombies(struct zombie_t zombie[], int count);

#endif