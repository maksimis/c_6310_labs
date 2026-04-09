/*
Лабораторная работа №1
Студент: Закиева Алина (номер: 13)
Вариант: 14
Задание: 14 (Среднее значение вещественного массива) 
*/

#include <stdio.h>
#define MAX_N 100000

int main(void) { 
    int n;
    printf("Задайте размерность вещественного массива: ");
    
    if (scanf("%d", &n) != 1) {
        printf("Ошибка: нужно ввести целое число.\n");
        return 1;
    }  
    if (n <= 0) {
        printf("Ошибка: n должно быть больше нуля.\n");
        return 1;
    }
    if (n > MAX_N) {
        printf("Ошибка: n слишком большое (максимум %d).\n", MAX_N);
        return 1;
    }

    double mas[n];
    printf("Заполните вещественный массив: ");
    for (int i = 0; i < n; i++) {
        if (scanf("%lf", &mas[i]) != 1) {
            printf("Ошибка: нужно ввести вещественные числа.\n");
            return 1;
        }
    }
    
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += mas[i];
    }
    double sr = sum / n;
    printf("Среднее значение вещественного массива: %.2f\n", sr);

    return 0;
}