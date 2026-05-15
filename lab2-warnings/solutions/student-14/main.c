/*
Лабораторная работа №2
Студент: Зиатдинова Дина (номер: 14)
Количество предупреждений: 10 (из них 0 -Wextra)
*/

#include <stdio.h>

static void unused_function(void) {}

void warning_block(int param) { 
    int unUsed_var;

    int a = 1, b = 2;
    int c = a & b == 0;
    (void)c;

    int div = 10 / 0;
    (void)div;

    unsigned int u = 10;
    int *p = &u;
    (void)p;

    char index = 1;
    int arr[5] = {0};
    arr[index];

    if (a)
        printf("F");
        printf("");

    int uninit;
    printf("%d\n", uninit);
}


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