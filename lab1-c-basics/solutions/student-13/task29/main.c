/*
Лабораторная работа №1
Студент: Закиева Алина (номер: 13)
Вариант: 14
Задание: 29 (Сумма элементов главной и побочной диагоналей матрицы) 
*/

#include <stdio.h>
#include <stdlib.h> // для рандома
#include <time.h> // для разного рандома
#define MAX_N 500 

int main(void) { 
    int n, sum = 0;
    printf("Введите количество строк и столбцов для квадратной матрицы: ");

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

    int mas[n][n];
    srand(time(NULL)); // для разных чисел при разных запусках
    printf("\nМатрица: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mas[i][j] = rand() % 10; // рандомные числа от 0 до 9
            printf("%d ", mas[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        sum += mas[i][i] + mas[i][n - 1 - i];
    }
    if (n % 2 != 0) {
            sum -= mas[n / 2][n / 2];
        }
    printf("\nСумма элементов главной и побочной диагоналей равна: %d \n", sum);
    
    return 0;
}