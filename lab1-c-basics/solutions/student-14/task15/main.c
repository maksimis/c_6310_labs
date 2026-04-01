/*
 * Лабораторная работа №1
 * Студент: Зиатдинова Дина (номер: 14)
 * Вариант: 15
 * Задание: 15 (Проверка вхождения числа в заданный диапазон)
 */

#include <stdio.h>

void clear() {
    int reset = getchar();
    while (reset != '\n' && reset != EOF) {
        reset = getchar();
    };
}

int check(const char *print, int *value) {
    printf("%s", print);

    int result = scanf("%d", value);
    clear();

    if (result != 1) {
        printf("Ошибка! Введено не целое число.\n");
        return 1;
    }
    return 0;
}

int main(void) {
    int num;
    if (check("Введите ЧИСЛО для его проверки вхождения в диапазон: ", &num)) {
        return 1;
    }  

    int range1;
    int range2;
    if (check("\nВведите МИНИМАЛЬНОЕ число диапазона: ", &range1)) {
        return 1;
    }
    if (check("Введите МАКСИМАЛЬНОЕ число диапазона: ", &range2)) {
        return 1;
    }

    if (range1 >= range2) {
        printf("Ошибка! Минимальная граница должна быть меньше максимальной.\n");
        return 1;
    }

    if (num >= range1 && num <= range2) {
        printf("\nЧисло %d ВХОДИТ в заданный диапазон [%d, %d]", num, range1, range2);
    } else {
        printf("\nЧисло %d НЕ ВХОДИТ в заданный диапазон [%d, %d]", num, range1, range2);
    }

    return 0;
};