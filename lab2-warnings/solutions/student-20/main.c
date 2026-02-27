/*
 * Лабораторная работа №2
 * Студент: Мартынова Милена (номер: 20)
 * Вариант: 21
 * Задание: 21 (Площадь круга по радиусу)
 * Количество предупреждений: 18 (из них 7 только -Wextra)
 */

#include <stdio.h>

#define PI 3.14159265358979323846
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
 * Параметр units объявлен, но не используется в теле функции */
static void print_area(double radius, double area, int units) {
    printf("Площадь круга с радиусом %.4f: %.4f\n", radius, area);
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
 * Параметру precision присваивается значение внутри функции,
 * но новое значение нигде не читается */
static void log_output(double result, int precision) {
    precision = 4;
    printf("Результат: %.4f\n", result);
}

/* Wall-5: -Wpointer-sign
 * char* присваивается указателю unsigned char* без явного приведения типов */
static void demo_pointer_sign(void) {
    char char_buf[] = {1, 2, 3};
    unsigned char *uptr = char_buf;
    (void)uptr;
}

static double calculate_circle_area(double radius) {
    return PI * radius * radius;
}

int main(void) {
    double radius;

    /* Wall-1: -Wunused-variable
     * Переменная объявлена и инициализирована, но нигде не используется */
    int unused_counter = 0;

    /* Wall-2: -Wunused-variable
     * Массив объявлен, но нигде не используется */
    char status_buffer[32];

    /* Wextra-4: -Wmissing-field-initializers
     * Поле z явно не инициализировано (будет обнулено неявно) */
    struct point {
        int x;
        int y;
        int z;
    };
    struct point center = {0, 0};
    printf("Центр: (%d, %d)\n", center.x, center.y);

    /* Wall-9: -Wmissing-braces
     * Пропущены внутренние скобки вокруг инициализаторов строк матрицы */
    int matrix[2][2] = {1, 2, 3, 4};
    (void)matrix;

    printf("Введите радиус круга: ");
    if (scanf("%lf", &radius) != 1) {
        fprintf(stderr, "Ошибка: некорректный ввод\n");
        return 1;
    }

    if (radius < 0) {
        fprintf(stderr, "Ошибка: радиус не может быть отрицательным\n");
        return 1;
    }

    /* Wextra-5: -Wempty-body
     * Тело оператора if — пустой оператор (точка с запятой) */
    int debug_flag = 0;
    if (debug_flag);

    /* Wall-6: -Wparentheses
     * Оператор & имеет больший приоритет, чем |; скобки прояснили бы намерение */
    int radius_int = (int)radius;
    int combined = radius_int | radius_int & SIGN_MASK;
    (void)combined;

    /* Wall-7: -Wchar-subscripts
     * Переменная типа char используется как индекс массива */
    const char hex_digits[] = "0123456789abcdef";
    char hex_index = 5;
    char selected = hex_digits[hex_index];
    (void)selected;

    /* Wall-8: -Wunused-value
     * Результат арифметического выражения вычисляется, но нигде не используется */
    radius + 1.0;

    /* Wextra-7: -Wimplicit-fallthrough
     * Отсутствует break в case 0 — выполнение проваливается в case 1 */
    int category = radius_int % 3;
    switch (category) {
        case 0:
            printf("Радиус кратен 3.\n");
        case 1:
            printf("Остаток не более 1.\n");
            break;
        default:
            break;
    }

    /* Wextra-6: -Wtype-limits
     * Беззнаковое значение всегда >= 0; условие всегда истинно */
    unsigned int check_val = (unsigned int)radius_int;
    if (check_val >= 0) {
        printf("Радиус неотрицательный.\n");
    }

    /* Wall-10: -Woverflow
     * Константа 300 превышает максимальное значение unsigned char (255) */
    unsigned char byte_overflow = 300;
    (void)byte_overflow;

    /* Wall-11: -Wmisleading-indentation
     * log_output выглядит как продолжение if, но выполняется безусловно */
    double area = calculate_circle_area(radius);
    if (area > 0)
        printf("Площадь положительная.\n");
        log_output(area, 0);

    demo_pointer_sign();
    check_range(radius_int);
    print_area(radius, area, 0);

    (void)debug_flag;

    return 0;
}
