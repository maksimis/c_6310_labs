/*
 * Лабораторная работа №1
 * Студент: Студент (номер: 21)
 * Вариант: 22
 * Задание: 22 (Корни квадратного уравнения)
 */

#include <stdio.h>
#include <math.h>

#define EPSILON 1e-9

static void solve_quadratic(double coeff_a, double coeff_b, double coeff_c)
{
    double discriminant = coeff_b * coeff_b - 4.0 * coeff_a * coeff_c;

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

    return 0;
}
