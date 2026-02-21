// Лабораторная работа №1.
// Поликарпов Никита №22. 
// Вариант 23. 
// Задание 23: Факториал числа с использованием цикла while
#include <stdio.h>

unsigned long long factorial(int n) {
    unsigned long long result = 1;
    while (n > 1) {
        result *= n;
        n--;
    }
    return result;
}

int main() {
    int n;
    printf("Введите число для вычисления факториала: ");
    if (scanf("%d", &n) != 1 || n < 0 || n > 65) {
        printf("Ошибка ввода: введено число больше 65, введена строка или введено отрицательное число!\n");
        return 1;
    }
    printf("Факториал числа %d: %llu\n", n, factorial(n));
    return 0;
}