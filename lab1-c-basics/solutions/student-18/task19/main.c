/*
 * Лабораторная работа №1
 * Студент: Королева Диана Дмитриевна (номер: 18)
 * Вариант: 19
 * Задание: 19 (Вычисление значения функции y = x² + 2x + 1)
 */

#include <stdio.h>

double calculate_function(double argument) {
    return argument * argument + 2.0 * argument + 1.0;
}

int main(void) {
    double input_value;
    int scanf_result;
    
    printf("Вычисление значения функции y = x² + 2x + 1\n");
    printf("Введи значение аргумента x: ");
    
    scanf_result = scanf("%lf", &input_value);
    
    if (scanf_result != 1) {
        printf("Ошибка ввода числа\n");
        return 1;
    }
    
    double function_result = calculate_function(input_value);
    printf("При аргументе x = %.2f, значение функции y = %.2f\n", input_value, function_result);
    
    return 0;
}