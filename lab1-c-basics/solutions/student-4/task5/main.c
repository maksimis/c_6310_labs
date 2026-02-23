/*
Лабораторная работа №1
Студент: Беляев Влад (номер: 4)
Вариант: 5
Задание: 5 (N-е число Фибоначчи) */

#include <stdio.h>

int fib(int n){
    if(n == 0){
        return 0;
    }
    else if(n == 1){
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

int main(void){
    int n;
    printf("Введите номер числа Фибоначчи (n >= 0): ");
    if (scanf("%d", &n) != 1){
        printf("Ошибка: вы ввели не целое число.\n");
        return 1;
    }
    if(n < 0) {
        printf("Ошибка: номер не может быть отрицательным.\n");
        return 1;
    }

    int result = fib(n);
    printf("fib(%d) = %d\n", n, result);

    return 0;
}