/*
 * Лабораторная работа №1
 * Студент: Валеев Камил (номер: 5)
 * Вариант: 6
 * Задание: 21 (Площадь круга по радиусу)
 */

#include <stdio.h>

#define PI 3.141592653589793

int main(void) {
    double radius;
    double area;
    
    printf("Введите радиус круга (положительное число): ");
    
    if (scanf("%lf", &radius) != 1) {
        printf("Ошибка: необходимо ввести число.\n");
        return 1;
    }
    
    if (radius <= 0.0) {
        printf("Ошибка: радиус должен быть положительным числом.\n");
        return 1;
    }
    
    area = PI * radius * radius;
    
    printf("--- Результат ---\n");
    printf("Радиус: %.2f\n", radius);
    printf("Площадь круга: %.2f\n", area);
    
    return 0;
}