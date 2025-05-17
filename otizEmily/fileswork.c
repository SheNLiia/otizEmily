#include "fileswork.h"
#include "person.h"
#include <stdio.h>

int loadfile(const char *filename, person ar[]) {
    FILE *fin = fopen(filename, "r");
    if (!fin) {
        printf("Ошибка открытия файла для чтения\n");
        return 0;
    }

    int count = 0;
    while (fscanf(fin, "%d %s %s %d %d.%d.%d %d.%d.%d",
                  &ar[count].id, ar[count].dept,
                  ar[count].name, &ar[count].salary,
                  &ar[count].begin.year,
                  &ar[count].begin.month,
                  &ar[count].begin.day,
                  &ar[count].end.year,
                  &ar[count].end.month,
                  &ar[count].end.day) == 10) {
        count++;
    }

    fclose(fin);
    return count;
}

void savefile(const char *filename, person ar[], int count) {
    FILE *fout = fopen(filename, "w");
    if (!fout) {
        printf("Ошибка открытия файла для записи\n");
        return;
    }

    for (int i = 0; i < count; ++i) {
        fprintf(fout, "%d %s %s %d %d.%d.%d %d.%d.%d\n",
                ar[i].id, ar[i].dept, ar[i].name, ar[i].salary,
                ar[i].begin.year, ar[i].begin.month, ar[i].begin.day,
                ar[i].end.year, ar[i].end.month, ar[i].end.day);
    }

    fclose(fout);
}

void savebinary(const char *filename, person ar[], int count) {
    FILE *fb = fopen(filename, "wb");
    if (!fb) {
        printf("Ошибка открытия бинарного файла для записи\n");
        return;
    }
    fwrite(&count, sizeof(int), 1, fb); // Записываю количество записей
    fwrite(ar, sizeof(person), count, fb);  // Записываю массив
    fclose(fb);
}

int loadbinary(const char *filename, person ar[]) {
    FILE *fb = fopen(filename, "rb");
    if (!fb) {
        printf("Ошибка открытия бинарного файла для чтения\n");
        return 0;
    }

    int count;
    fread(&count, sizeof(int), 1, fb);
    fread(ar, sizeof(person), count, fb);
    fclose(fb);

    return count;
}