/*
Лабораторная работа №1
Студент: Беляев Влад (номер: 4)
Вариант: 5
Задание: 5 (N-е число Фибоначчи) */

#include <stdio.h>

long long fib(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    long long a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}


int main(void){
    int n;
    printf("Введите номер числа Фибоначчи (n >= 0): ");
    if (scanf("%d", &n) != 1){
        printf("Ошибка: вы ввели не целое число.\n");
        return 1;
    }
    if (n < 0) {
        printf("Ошибка: номер не может быть отрицательным.\n");
        return 1;
    }

    if (n > 93) {
        printf("Предупреждение: число слишком велико, результат может быть неверным из‑за переполнения.\n");
    }

    long long result = fib(n);
    printf("fib(%d) = %lld\n", n, result);

    return 0;
}