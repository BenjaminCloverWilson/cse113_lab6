/**
 * @file zombie.h
 * @brief header file for lab6.c and zombie.c
 * @author Benjamin Wilson
 * @date Fall 2021
 * @bug Probably
 * @todo none
 */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <stdio.h>
#include <stdlib.h>

/* Array sizes for user input and the zombie log itself */
#define SIZE 16
#define LOG 5

/* Holds stats about zombie */
struct zombie_t {
    enum DAY {MON = 1, TUE, WED, THU, FRI, SAT, SUN} day;

    float blood;
    int toes;
    int hour;
    int min;
    int sec;
    char dead;
};

/* Function prototypes that are defined in zombie.c */
struct zombie_t get_zombie();
int input_toes();
float input_blood();
int input_day();
int input_time(char unit, char in_time[]);
void print_zombies(struct zombie_t zombie[], int total_count);

#endif
