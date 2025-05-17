#include "person.h"

void ar_print(person ar[], int len) {
    for (int i = 0; i < len; ++i) {
        printf("%d %s %s %d %d.%d.%d %d.%d.%d\n",
               ar[i].id, ar[i].dept,
               ar[i].name, ar[i].salary,
               ar[i].begin.year, ar[i].begin.month, ar[i].begin.day,
               ar[i].end.year, ar[i].end.month, ar[i].end.day);
    }
}

void swap(person *pa, person *pb) {
    person t = *pa;
    *pa = *pb;
    *pb = t;
}