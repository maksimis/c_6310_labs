/*
    * Лабораторная работа №1
    * Студент: Асфандияров Камиль (номер: 1)
    * Вариант: 2
    * Задание: 2 (Нахождение наибольшего числа в массиве)
    */



#include <stdio.h>

int main() {
    
    int array[] = {1, -3, 4, 9, 5, 4};

    int leng = sizeof(array) / sizeof(array[0]);
    int maxn = array[0];

    for (int i = 1; i < leng; i++) {
        if (array[i] > maxn) {
            maxn = array[i];
        }
    }

    printf("Наибольшее число в массиве: %d\n", maxn);

    return 0;
}