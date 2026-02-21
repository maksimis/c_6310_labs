// Лабораторная работа №1. 
// Поликарпов Никита №22 
// Вариант 23. 
// Задание 8: Наибольший общий делитель двух чисел


#include <stdio.h>
#include <stdlib.h>  // Для функции abs()

int NOD(int a, int b) {
    a = abs(a);
    b = abs(b);
    
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int x, y;
    printf("Введите первое число: ");
    if (scanf("%d", &x) != 1) {
        printf("Ошибка ввода!\n");
        return 1;
    }
    
    printf("Введите второе число: ");
    if (scanf("%d", &y) != 1) {
        printf("Ошибка ввода!\n");
        return 1;
    }
    
    printf("Наибольший общий делитель: %d\n", NOD(x, y));
    return 0;
}