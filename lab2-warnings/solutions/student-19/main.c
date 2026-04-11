/*
 * Лабораторная работа №2
 * Студент: Котова Алиса (номер: 19)
 * Вариант: 20
 * Задание: 20 (Перевод символа в ASCII-код и обратно)
 */

#include <stdio.h>
#include <stdlib.h>

#define ASCII_MIN 0
#define ASCII_MAX 127

/* --- ПРЕДУПРЕЖДЕНИЯ --- */

/* -Wunused-function */
/* Функция объявлена, но нигде не используется */
static void unused_function() {
    printf("Эта функция никогда не вызывается\n");
}

/* -Wreturn-type */
/*Функция объявлена как возвращающая int,
   но не содержит оператора return */
int missing_return_function() {
}

/* -Wunused-parameter */
/*Параметр x передаётся в функцию,
но внутри функции не используется*/
int unused_parameter_function(int x) {
    return 0;
}

/* -Wunused-but-set-variable (-Wextra) */
/*   Переменной присваивается значение,
   но далее она нигде не используется*/
void set_but_not_used() {
    int x = 0;
    x = 10;
}

/* -Wmissing-field-initializers (-Wextra) */
/*Не все поля структуры инициализированы*/
struct Example {
    int a;
    int b;
    int c;
};

struct Example example_struct = {1};

/* -Wtype-limits (-Wextra) */
/*Для unsigned условие x >= 0 всегда истинно*/
void always_true_condition() {
    unsigned int x = 5;
    if (x >= 0) {
        printf("");
    }
}

/* -Wshift-count-overflow (-Wextra) */
/*Сдвиг на количество бит больше размера типа int*/
void shift_overflow() {
    int x = 1 << 40;
}

/*
 * Функция перевода символа в его ASCII-код.
 */
int get_ascii_code(char input_symbol) {
    return (int) input_symbol;
}

/*
 * Функция перевода ASCII-кода в символ.
 */
char get_symbol_from_ascii(int ascii_code) {
    return (char) ascii_code;
}

int main(void) {

    /* -Wunused-variable */
    /*Переменная объявлена, но не используется*/
    int unused_variable = 10;

    /* -Wsign-compare */
    /*Сравнение signed и unsigned типов*/
    unsigned int unsigned_number = 10;
    int signed_number = -1;

    if (signed_number < unsigned_number) {
        printf("");
    }

    /* -Wparentheses */
    /*Компилятор предлагает добавить скобки
       для ясности логического выражения*/
    int a = 5, b = 10, c = 15;
    if (a < b && b < c || a == c) {
        printf("");
    }

    /* -Wchar-subscripts */
    /* Использование типа char как индекса массива */
    int array[10];
    char index = 2;
    array[index] = 5;

    /* -Wpointer-sign */
    /* Несоответствие знаковости указателей */
    char text[] = "hello";
    unsigned char *ptr = text;

    /* -Wsizeof-pointer-memaccess */
    /* Используется memset без подключения string.h */
    char buffer[10];
    memset(buffer, 0, sizeof(buffer));

    /* -Wdiv-by-zero */
    /* Возможное деление на ноль */
    int zero = 0;
    int division = 10 / zero;

    /* -Wmisleading-indentation */
    /* Отступ создаёт впечатление,
       что второй printf внутри if */
    if (a > 0)
        printf("");
        printf("");

    /* -Wempty-body */
    /* Условие if с пустым телом */
    if (a == b);

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