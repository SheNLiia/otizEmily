#ifndef PERSON_H
#define PERSON_H

#include <stdio.h>

typedef struct {
    int year, month, day;
} date;

typedef struct {
    int id;
    char dept[20];
    char name[20];
    int salary;
    date begin;
    date end;
} person;

void ar_print(person[], int);
void swap(person *, person *);

#endif