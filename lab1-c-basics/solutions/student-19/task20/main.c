   /*
    * Лабораторная работа №1
    * Студент: Котова Алиса (номер: 19)
    * Вариант: 20
    * Задание: 20 (Перевод символа в ASCII-код и обратно)
    */

#include <stdio.h>
#include <stdlib.h>


#define ASCII_MIN 0
#define ASCII_MAX 127

/* 
 * Функция перевода символа в его ASCII-код.
 * Принимает символ и возвращает его числовое представление.
 */
int get_ascii_code(char input_symbol) {
    return (int) input_symbol;
}

/*
 * Функция перевода ASCII-кода в символ.
 * Проверяет, что код находится в допустимом диапазоне.
 */
char get_symbol_from_ascii(int ascii_code) {
    return (char) ascii_code;
}


int main(void) {
    int user_choice = 0;

    printf("Выберите режим работы:\n");
    printf("1 — Перевести символ в ASCII-код\n");
    printf("2 — Перевести ASCII-код в символ\n");
    printf("Ваш выбор: ");

    if (scanf("%d", &user_choice) != 1) {
        printf("Ошибка: некорректный ввод режима.\n");
        return 1;
    }

    if (user_choice == 1) {
        char input_symbol;

        printf("Введите символ: ");

        /* Пробел перед %c нужен для пропуска символа новой строки */
        if (scanf(" %c", &input_symbol) != 1) {
            printf("Ошибка: не удалось прочитать символ.\n");
            return 1;
        }

        int ascii_code = get_ascii_code(input_symbol);

        printf("Символ '%c' имеет ASCII-код: %d\n", input_symbol, ascii_code);

    } else if (user_choice == 2) {
        int ascii_code;

        printf("Введите ASCII-код (от %d до %d): ", ASCII_MIN, ASCII_MAX);

        if (scanf("%d", &ascii_code) != 1) {
            printf("Ошибка: введите число.\n");
            return 1;
        }

        if (ascii_code < ASCII_MIN || ascii_code > ASCII_MAX) {
            printf("Ошибка: ASCII-код должен быть в диапазоне от %d до %d.\n",
                   ASCII_MIN, ASCII_MAX);
            return 1;
        }

        char result_symbol = get_symbol_from_ascii(ascii_code);

        printf("ASCII-код %d соответствует символу: '%c'\n",
               ascii_code, result_symbol);

    } else {
        printf("Ошибка: выбран некорректный режим.\n");
        return 1;
    }

    return 0;
}