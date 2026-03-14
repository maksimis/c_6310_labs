/*
Лабораторная работа №2
Студент: Асфандияров Камиль (номер: 1)
Вариант: 2
Задание: 2
Количество предупреждений: 10 (из них 5 -Wextra)
*/

#include <stdio.h>

// Предупреждение 1: функция определена, но не используется
void old_function() {
    int a = 5;
}

int mistakes() {

    // Предупреждение 2: неиспользуемая переменная
    int unused = 100;

    // Предупреждение 3: неинициализированная переменная
    int x;
    if (x > 10) {
        printf("%d", x);
    }

    int array[] = {1, -3, 4, 9, 5, 4};
    int leng = sizeof(array) / sizeof(array[0]);
    int maxn = array[0];

    // Предупреждение 4: лишний аргумент printf
    printf("Поиск максимума\n", 123);

    // Предупреждение 5: выход за границы массива
    int temp = array[10];

    for (int i = 1; i < leng; i++) {

        // Предупреждение 6: присваивание в условии (но массив не портим)
        int t;
        if (t = maxn) {
            ; // пусто
        }

        
        if (array[i] > maxn) {
            maxn = array[i];
        }
    }

    // Предупреждение 7: неправильный формат
    printf("Максимум: %f\n", maxn);

    // Предупреждение 8: пустое тело цикла
    for (int i = 0; i < 5; i++);

    // Предупреждение 9: сравнение signed и unsigned
    unsigned int u = 5;
    if (leng > u) {
        printf("leng > u\n");
    }

    // Предупреждение 10: переменная объявлена, но не используется
    int another_unused = 42;

    return 0;
}

int main() {

    int array[] = {1, -3, 4, 9, 5, 4};
    int leng = sizeof(array) / sizeof(array[0]);

    int maxn = array[0];

    for (int i = 1; i < leng; i++) {
        if (array[i] > maxn) {
            maxn = array[i];
        }
    }

    printf("%d\n", maxn);

    return 0;
}