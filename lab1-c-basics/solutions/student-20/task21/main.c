/*
 * Лабораторная работа №1
 * Студент: Мартынова Милена (номер: 20)
 * Вариант: 21
 * Задание: 21 (Площадь круга по радиусу)
 */

#include <stdio.h>

#define PI 3.14159265358979323846
static double calculate_circle_area(double radius);

int main(void) {
    double radius;

    printf("Введите радиус круга: ");
    if (scanf("%lf", &radius) != 1) {
        fprintf(stderr, "Ошибка: некорректный ввод\n");
        return 1;
    }

    if (radius < 0) {
        fprintf(stderr, "Ошибка: радиус не может быть отрицательным\n");
        return 1;
    }

    printf("Площадь круга с радиусом %.4f: %.4f\n", radius, calculate_circle_area(radius));

    return 0;
}

static double calculate_circle_area(double radius) {
    return PI * radius * radius;
}
