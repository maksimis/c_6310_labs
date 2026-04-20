/*
Лабораторная работа №1
Студент: Беляев Влад (номер: 4)
Вариант: 5
Задание: 20 (Перевод символа в ASCII-код и обратно) */

#include <stdio.h>

int main(void){
    char symbol;
    int code;

    printf("Введите символ: ");
    if (scanf( " %c", &symbol) != 1){
        printf("Ошибка - не удалось прочитать символ.\n");
        return 1;
    }
    printf("ASCII-код символа '%c' = %d\n", symbol, (int)symbol);


    printf("Введите ASCII-код (целое число от 0 до 255): ");
    if (scanf("%d", &code) != 1){
        printf("Ошибка: необходимо ввести целое число.\n");
        return 1;
    }
    if (code < 0 || code > 255) {
        printf("Ошибка: код должен быть в диапазоне 0...255.\n");
        return 1;
    }
    printf("Символ с кодом %d = '%c'\n", code, (char)code);

    return 0;
}
