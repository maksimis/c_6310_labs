/*
 * Лабораторная работа №2
 * Студент: Карпов Родион (номер: 16)
 * Вариант: 17
 * Задание: 17 (Наименьшее общее кратное двух чисел)
 * Количество предупреждений: 18 (из них 7 только -Wextra)
 */

#include <stdio.h>

#define SIGN_MASK 0xFF

/* Wall-3: -Wunused-function
 * Статическая функция, которая нигде не вызывается */
static void debug_print(const char *message) {
    printf("DEBUG: %s\n", message);
}

/* Wall-4: -Wreturn-type
 * Функция с возвращаемым типом int не содержит оператора return */
int get_version(void) {
    /* Нет return */
}

/* Wextra-1: -Wunused-parameter
 * Параметр precision объявлен, но не используется в теле функции */
static void print_result(int first, int second, int result, int precision) {
    printf("НОК(%d, %d) = %d\n", first, second, result);
}

/* Wextra-2: -Wsign-compare
 * Параметр value (int) сравнивается с max_range (unsigned int) */
static void check_range(int value) {
    unsigned int max_range = 1000000;
    if (value < max_range) {
        printf("В допустимом диапазоне.\n");
    }
}

/* Wextra-3: -Wunused-but-set-parameter
 * Параметру base присваивается значение 10 внутри функции,
 * но новое значение нигде не читается */
static void log_output(int result, int base) {
    base = 10;
    printf("Результат: %d\n", result);
}

/* Wall-5: -Wpointer-sign
 * char* присваивается указателю unsigned char* без явного приведения типов */
static void demo_pointer_sign(void) {
    char char_buf[] = {1, 2, 3};
    unsigned char *uptr = char_buf;
    (void)uptr;
}

static int gcd(int first, int second) {
    while (second != 0) {
        int temp = second;
        second = first % second;
        first = temp;
    }
    return first;
}

static int lcm(int first, int second) {
    return first / gcd(first, second) * second;
}

int main(void) {
    int first, second;

    /* Wall-1: -Wunused-variable
     * Переменная объявлена и инициализирована, но нигде не используется */
    int unused_counter = 0;

    /* Wall-2: -Wunused-variable
     * Массив объявлен, но нигде не используется */
    char status_buffer[32];

    /* Wextra-4: -Wmissing-field-initializers
     * Поле z явно не инициализировано (будет обнулено неявно) */
    struct coord {
        int x;
        int y;
        int z;
    };
    struct coord origin = {0, 0};
    printf("Начало координат: (%d, %d)\n", origin.x, origin.y);

    /* Wall-9: -Wmissing-braces
     * Пропущены внутренние скобки вокруг инициализаторов строк матрицы */
    int matrix[2][2] = {1, 2, 3, 4};
    (void)matrix;

    printf("Введите два натуральных числа: ");
    if (scanf("%d %d", &first, &second) != 2) {
        fprintf(stderr, "Ошибка: некорректный ввод\n");
        return 1;
    }

    if (first <= 0 || second <= 0) {
        fprintf(stderr, "Ошибка: числа должны быть натуральными (больше 0)\n");
        return 1;
    }

    /* Wextra-5: -Wempty-body
     * Тело оператора if — пустой оператор (точка с запятой) */
    int debug_flag = 0;
    if (debug_flag);

    /* Wall-6: -Wparentheses
     * Оператор & имеет больший приоритет, чем |; скобки прояснили бы намерение */
    int combined = first | second & SIGN_MASK;
    (void)combined;

    /* Wall-7: -Wchar-subscripts
     * Переменная типа char используется как индекс массива */
    const char hex_digits[] = "0123456789abcdef";
    char hex_index = 5;
    char selected = hex_digits[hex_index];
    (void)selected;

    /* Wall-8: -Wunused-value
     * Результат арифметического выражения вычисляется, но нигде не используется */
    first + second;

    /* Wextra-7: -Wimplicit-fallthrough
     * Отсутствует break в case 0 — выполнение проваливается в case 1 */
    int category = first % 3;
    switch (category) {
        case 0:
            printf("Первое число кратно 3.\n");
        case 1:
            printf("Остаток не более 1.\n");
            break;
        default:
            break;
    }

    /* Wextra-6: -Wtype-limits
     * Беззнаковое значение всегда >= 0; условие всегда истинно */
    unsigned int check_val = (unsigned int)first;
    if (check_val >= 0) {
        printf("Первое число неотрицательное.\n");
    }

    /* Wall-10: -Woverflow
     * Константа 300 превышает максимальное значение unsigned char (255) */
    unsigned char byte_overflow = 300;
    (void)byte_overflow;

    /* Wall-11: -Wmisleading-indentation
     * log_output выглядит как продолжение if, но выполняется безусловно */
    int result = lcm(first, second);
    if (result > 0)
        printf("НОК положительный.\n");
        log_output(result, 0);

    demo_pointer_sign();
    check_range(result);
    print_result(first, second, result, 10);

    (void)debug_flag;

    return 0;
}
