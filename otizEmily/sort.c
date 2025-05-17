#include "sort.h"
#include <string.h>
#include <stdlib.h> // для abs()

void sortName(person ar[], int len) {
    for (int i = 0; i < len - 1; ++i) {
        int imin = i;
        for (int j = i + 1; j < len; ++j) {
            if (strcmp(ar[j].name, ar[imin].name) < 0) {
                imin = j;
            }
        }
        if (i != imin) {
            swap(&ar[imin], &ar[i]);
        }
    }
}

void sortDept(person ar[], int len) {
    for (int i = 0; i < len - 1; ++i) {
        int imin = i;
        for (int j = i + 1; j < len; ++j) {
            if (strcmp(ar[j].dept, ar[imin].dept) < 0) {
                imin = j;
            }
        }
        if (i != imin) {
            swap(&ar[imin], &ar[i]);
        }
    }
}

int cmp_salary_abs(person a, person b) { // Сравниваю по абсолютной величине зарплаты
    return abs(a.salary) - abs(b.salary);
}

void sortSalaryAbs(person ar[], int len) {
    for (int i = 0; i < len - 1; ++i) {
        int imin = i;
        for (int j = i + 1; j < len; ++j) {
            if (cmp_salary_abs(ar[j], ar[imin]) < 0) {
                imin = j;
            }
        }
        if (i != imin) {
            swap(&ar[imin], &ar[i]);
        }
    }
}

void sortId(person ar[], int len) {
    for (int i = 0; i < len - 1; ++i) {
        int imin = i;
        for (int j = i + 1; j < len; ++j) {
            if (ar[j].id < ar[imin].id) {
                imin = j;
            }
        }
        if (i != imin) {
            swap(&ar[imin], &ar[i]);
        }
    }
}