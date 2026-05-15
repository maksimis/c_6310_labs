/*
 * Лабораторная работа №1
 * Студент: Королева Диана Дмитриевна (номер: 18)
 * Вариант: 19
 * Задание: 4 (Факториал числа)
 */

#include <stdio.h>

#define MAX_FACTORIAL 12

int main(void) {
    int input_value;
    int factorial_result = 1;
    
    printf("Программа вычисления факториала числа\n");
    printf("Введи целое число от 0 до %d: ", MAX_FACTORIAL);
    
    if (scanf("%d", &input_value) != 1) {
        printf("Ошибка ввода! Введи целое число.\n");
        return 1;
    }
    
    if (input_value < 0) {
        printf("Ошибка ввода! факториал отрицательного числа не определяется.\n");
        return 1;
    }
    
    if (input_value > MAX_FACTORIAL) {
        printf("Ошибка: число слишком большое (максимум %d). Переполнение памяти.\n", MAX_FACTORIAL);
        return 1;
    }
    
    for (int current = 2; current <= input_value; current++) {
        factorial_result *= current;
    }
    
    printf("%d! = %d\n", input_value, factorial_result);
    
    return 0;
}