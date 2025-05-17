// Выполнила: Мататова Эмилия 303ИС-22
// 301-302-303-313-314-315ИС-22. Гусятинер Л.Б., 16.05.2025
// МДК.01.04. Техника программирования на СИ (к зачету)
// ToDo-list (хотелки)
// 1. Меню
// 2. На оценку 4 и выше (4+). Запуск с аргументами командной строки
// 3. Чтение-запись в текстовый файл
// 4. Сортировка
// 5. Сортировка с выбором поля (4+)
// 6. Добавление, удаление, редактирование
// 7. Использование бинарного файла (4+)
// 8. Добавление, удаление, редактирование в файл (4+)
// 9. Сортировка файла (4+)
// 10. Использование индексного файла (4+)
/*
5 OGK Ivanov 80 25.02.2018 28.03.2024
2 OGT Petrov 100 26.02.2018 28.03.2025
3 OGBuh Dryahlova 150 12.03.2011 20.04.2025
4 OGK Vanyan 70 15.02.2013 11.03.2021
*/
/*
+Массив
+Структура
Функция
+Цикл
Строка
*/

#include <stdio.h>
#include <windows.h>
#include "person.h"
#include "sort.h"
#include "fileswork.h"

#define AR_SIZE 100

int main() {
    SetConsoleOutputCP(65001);
    person ar[AR_SIZE];
    int count = 0;

    count = loadfile("data.txt", ar);
    if (count == 0) {
        printf("Ошибка: не удалось прочитать файл или файл пуст.");
        return 1;
    }

    printf("Исходные данные:\n");
    ar_print(ar, count);

    person ar_bin[AR_SIZE];
    int count_bin = loadbinary("data.bin", ar_bin);

    if (count_bin > 0) {
        printf("--------------------\n");
        printf("Данные из бинарного файла:\n");
        ar_print(ar, count);
    } else {
        printf("--------------------\n");
        printf("Не удалось загрузить данные из бинарного файла.\n");
    }

    printf("--------------------\n");
    printf("Сортировка по id:\n");
    sortId(ar, count);
    ar_print(ar, count);

    printf("--------------------\n");
    printf("Сортировка по имени:\n");
    sortName(ar, count);
    ar_print(ar, count);

    printf("--------------------\n");
    printf("Сортировка по подразделению:\n");
    sortDept(ar, count);
    ar_print(ar, count);

    printf("--------------------\n");
    printf("Сортировка по зарплате (по модулю):\n");
    sortSalaryAbs(ar, count);
    ar_print(ar, count);

    savefile("output.txt", ar, count);

    savebinary("data.bin", ar, count);

    return 0;
}