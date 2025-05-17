#ifndef FILESWORK_H
#define FILESWORK_H

#include "person.h"

int loadfile(const char *filename, person ar[]);
void savefile(const char *filename, person ar[], int count);
int loadbinary(const char *filename, person ar[]);
void savebinary(const char *filename, person ar[], int count);

#endif