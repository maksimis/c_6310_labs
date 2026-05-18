/*
 * Лабораторная работа №1
 * Студент: Валиев Марсель (номер: 6)
 * Вариант: 7
 * Задание: 7 (Проверка числа на простоту)
 */

#include <stdio.h>
#include <stdbool.h>

/**
 * Checks whether a given integer is prime.
 * @param n non‑negative integer
 * @return true if prime, false otherwise
 */
bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    if (n == 2) {
        return true;
    }
    if (n % 2 == 0) {
        return false;
    }
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main(void) {
    int number;

    printf("Prime number check.\n");
    printf("Enter an integer: ");
    if (scanf("%d", &number) != 1) {
        fprintf(stderr, "Error: invalid input (integer expected).\n");
        return 1;
    }

    if (number < 0) {
        fprintf(stderr, "Error: primality is defined only for natural numbers (>=2).\n");
        return 1;
    }

    if (is_prime(number)) {
        printf("%d is prime.\n", number);
    } else {
        printf("%d is not prime.\n", number);
    }

    return 0;
}