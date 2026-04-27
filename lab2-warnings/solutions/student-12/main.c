/*
 * Лабораторная работа №2
 * Студент: Загеева Ксения (номер: 12)
 * Вариант: 13
 * Задание: 13 (Сумма цифр числа)
 * Количество предупреждений: 10 типов -Wall, 5 типов -Wextra
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* -Wall 1, неиспользуемая функция, -Wunused-function */
static void unused_function() {
    int x = 5;
}

/* -Wall 10, отсутствие return в функции, -Wreturn-type */
int missing_return_function() {
    int a = 5;
}

int main(void) {

    int number;
    int sum = 0;
    char buffer[100];

    /* -Wall 2, неиспользуемая переменная, -Wunused-variable */
    int unused_variable = 10;

    /* -Wall 3, переменная объявлена но не инициализирована, -Wuninitialized */
    int maybe_uninitialized;
    int test = maybe_uninitialized;

    /* -Wall 4, сравнение signed и unsigned, -Wsign-compare*/
    int a = -1;
    unsigned int b = 1;
    if (a < b) {
    }

    /* -Wall 5, пустое тело if, -Wempty-body */
    if (sum > 100);

    /* -Wall 6, вводящий в заблуждение отступ, -Wmisleading-indentation */
    if (sum > 50)
        printf("Большая сумма\n");
        printf("Это сообщение всегда выводится\n");

    /* -Wall 7, деление на ноль, -Wdiv-by-zero */
    if (0) {
        int div_test = 10 / 0;
    }

    /* -Wall 8, char как индекс массива, -Wchar-subscripts */
    char index = 2;
    buffer[index] = 'a';

    /* -Wall 9,  присваивание в if, -Wparentheses*/
    if (a = 5) {
    }

    /* -Wextra 1,-Wtype-limits, сравнение всегда истинно/ложно */
    unsigned int u = 5;
    if (u >= 0) {   // всегда true
    }

    /* -Wextra 2, -Wmaybe-uninitialized, возможно использование неинициализированной переменной */
    int maybe;
    int result;
    if (number > 0) {
        result = maybe + 1; 
    }

    /* -Wextra 3, -Wunused-but-set-variable, присвоена, но не используется */
    int unused_var = 42;

    /* -Wextra 4, -Wunused-but-set-parameter, параметр присваивается, но не используется */
    void set_but_unused_param(int param) {
        param = 123; 
    }

    /* -Wextra 5, -Wshift-count-overflow, сдвиг больше размера типа */
    int shift_example = 1 << 32; 


    printf("Введите целое число: ");

    if (!fgets(buffer, sizeof(buffer), stdin)) {
        printf("Ошибка ввода: ввод не получен\n");
        return 1;
    }

    int only_spaces = 1;
    for (size_t i = 0; buffer[i] != '\n'; i++) {
        if (!isspace((unsigned char)buffer[i])) {
            only_spaces = 0;
            break;
        }
    }

    if (only_spaces) {
        printf("Ошибка: пустой ввод\n");
        return 1;
    }

    char extra;
    if (sscanf(buffer, " %d %c", &number, &extra) != 1) {
        printf("Ошибка: некорректный ввод, введите одно целое число\n");
        return 1;
    }

    if (number < 0) {
        printf("Ошибка: число должно быть неотрицательным\n");
        return 1;
    }

    if (number == 0) {
        printf("Сумма цифр числа 0 равна 0\n");
        return 0;
    }

    int temp = number;

    while (temp > 0) {
        sum += temp % 10;
        temp /= 10;
    }

    printf("Сумма цифр числа %d равна %d\n", number, sum);

    return 0;
}
