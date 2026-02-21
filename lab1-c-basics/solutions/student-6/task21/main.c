/*
 * Лабораторная работа №1
 * Студент: Валиев Марсель (номер: 6)
 * Вариант: 6
 * Задание: 21 (Площадь круга по радиусу)
 */

#include <stdio.h>

#define PI 3.141592653589793

int main(void) {
    double radius;

    printf("Calculate the area of a circle.\n");
    printf("Enter the radius of the circle (positive number): ");
    if (scanf("%lf", &radius) != 1) {
        fprintf(stderr, "Error: please enter a number.\n");
        return 1;
    }

    if (radius < 0.0) {
        fprintf(stderr, "Error: radius cannot be negative.\n");
        return 1;
    }

    double area = PI * radius * radius;
    printf("Area of circle with radius %.6f = %.6f\n", radius, area);

    return 0;
}