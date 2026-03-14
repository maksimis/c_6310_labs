/*
 * Лабораторная работа №2
 * Студент: Студент (номер: 21)
 * Вариант: 22
 * Задание: 22 (Корни квадратного уравнения)
 * Количество предупреждений: 15 (из них 5 -Wextra)
 */

#include <stdio.h>
#include <math.h>

#define EPSILON 1e-9

/* ================================================================
 * РАЗДЕЛ НАМЕРЕННЫХ ПРЕДУПРЕЖДЕНИЙ
 * ================================================================ */

/* Предупреждение 2: -Wunused-function [-Wall]
 * Статическая функция определена, но никогда не вызывается */
static void debug_log(void)
{
    printf("debug\n");
}

/* Предупреждение 3: -Wreturn-type [-Wall]
 * Функция объявлена как возвращающая int, но оператор return отсутствует
 * Также вызывает -Wunused-function, поскольку функция нигде не вызывается */
static int get_version(void)
{
    printf("v1.0");
    /* намеренно нет return */
}

/* Предупреждение 11 (-Wunused-parameter, -Wextra): параметр extra не используется.
 * Предупреждение 12 (-Wunused-but-set-parameter, -Wextra): mode присваивается, но значение не читается.
 * Функция вызывается из main, поэтому -Wunused-function не возникает. */
static void process_data(int value, int extra, int mode)
{
    mode = 1;  /* mode присваивается, но новое значение нигде не читается */
    printf("process: %d\n", value);
    /* параметр extra намеренно не используется */
}

/* Структура для предупреждения -Wmissing-field-initializers */
struct CoeffInfo {
    int count;
    int degree;
    int is_monic;
};

/* ================================================================
 * ОСНОВНАЯ ЛОГИКА РЕШЕНИЯ КВАДРАТНОГО УРАВНЕНИЯ
 * ================================================================ */

static void solve_quadratic(double coeff_a, double coeff_b, double coeff_c)
{
    double discriminant = coeff_b * coeff_b - 4.0 * coeff_a * coeff_c;

    /* Предупреждение 6: -Wempty-body [-Wall]
     * Пустое тело оператора if (точка с запятой вместо блока) */
    if (coeff_a > 0) ;

    /* Предупреждение 7: -Wparentheses [-Wall]
     * Смешение || и && без явных скобок */
    int mixed_check = discriminant > 0 || discriminant < 0 && coeff_a != 0;
    (void)mixed_check;

    /* Предупреждение 8: -Wsign-compare [-Wall]
     * Сравнение знакового int с беззнаковым unsigned int в условии цикла */
    unsigned int max_iter = 2;
    for (int iter = 0; iter < max_iter; iter++) {
        (void)iter;
        break;
    }

    /* Предупреждение 9: -Wchar-subscripts [-Wall]
     * Использование переменной типа char в качестве индекса массива */
    char char_idx = 1;
    int lookup_table[3] = {0, 1, 2};
    int lookup_val = lookup_table[char_idx];
    (void)lookup_val;

    /* Предупреждение 10: -Wpointer-sign [-Wall]
     * Инициализация unsigned char * из char * — несоответствие знаковости */
    char *equation_str = "ax^2+bx+c=0";
    unsigned char *ustr = equation_str;
    (void)ustr;

    /* Предупреждение 4: -Wimplicit-fallthrough [-Wall]
     * Неявный проваливающийся case в switch (нет break перед case 2) */
    int fall_demo = 1;
    switch (fall_demo) {
        case 1:
            fall_demo = 2;
            /* намеренно нет break — неявный проваливающийся переход */
        case 2:
            fall_demo = 3;
            break;
        default:
            break;
    }
    (void)fall_demo;

    /* Предупреждение 13: -Wtype-limits [-Wextra]
     * Сравнение беззнакового числа >= 0 всегда истинно */
    unsigned int pos_check = 5;
    if (pos_check >= 0) {
        (void)pos_check;
    }

    /* Предупреждение 14: -Wmissing-field-initializers [-Wextra]
     * Поля degree и is_monic не указаны — инициализируются нулём неявно */
    struct CoeffInfo info = {3};
    (void)info;

    /* Основная логика — корректное решение квадратного уравнения */
    if (discriminant > EPSILON) {
        double root1 = (-coeff_b + sqrt(discriminant)) / (2.0 * coeff_a);
        double root2 = (-coeff_b - sqrt(discriminant)) / (2.0 * coeff_a);
        printf("Два вещественных корня:\n");
        printf("x1 = %.6f\n", root1);
        printf("x2 = %.6f\n", root2);
    } else if (discriminant > -EPSILON) {
        double root = -coeff_b / (2.0 * coeff_a);
        printf("Один вещественный корень:\n");
        printf("x = %.6f\n", root);
    } else {
        printf("Вещественных корней нет (дискриминант < 0)\n");
    }
}

int main(void)
{
    /* Предупреждение 1: -Wunused-variable [-Wall]
     * Переменная объявлена и инициализирована, но никогда не используется */
    int debug_counter = 0;

    /* Предупреждение 5: -Wformat-extra-args (часть -Wformat, -Wall)
     * printf вызывается с лишним аргументом, которого нет в строке формата */
    printf("Лабораторная работа №2\n", 0);

    /* Предупреждение 15: -Wunused-but-set-variable [-Wextra]
     * Переменной присваивается значение, которое никогда не используется */
    int temp_storage;
    temp_storage = 42;

    double coeff_a = 0.0;
    double coeff_b = 0.0;
    double coeff_c = 0.0;

    printf("Решение квадратного уравнения ax^2 + bx + c = 0\n");
    printf("Введите коэффициент a: ");
    if (scanf("%lf", &coeff_a) != 1) {
        fprintf(stderr, "Ошибка: некорректный ввод коэффициента a\n");
        return 1;
    }

    if (coeff_a > -EPSILON && coeff_a < EPSILON) {
        fprintf(stderr, "Ошибка: коэффициент a не может быть равен нулю\n");
        return 1;
    }

    printf("Введите коэффициент b: ");
    if (scanf("%lf", &coeff_b) != 1) {
        fprintf(stderr, "Ошибка: некорректный ввод коэффициента b\n");
        return 1;
    }

    printf("Введите коэффициент c: ");
    if (scanf("%lf", &coeff_c) != 1) {
        fprintf(stderr, "Ошибка: некорректный ввод коэффициента c\n");
        return 1;
    }

    printf("Уравнение: %.6fx^2 + %.6fx + %.6f = 0\n",
           coeff_a, coeff_b, coeff_c);

    solve_quadratic(coeff_a, coeff_b, coeff_c);

    /* Вызов process_data — функция используется, -Wunused-function не возникает */
    process_data(1, 2, 3);

    return 0;
}
