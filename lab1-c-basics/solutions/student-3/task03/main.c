/*
 * Лабораторная работа №1
 * Студент: Багаутдинова Диана (номер: 3)
 * Вариант: 3
 * Задание: 3 (Сортировка массива по возрастанию)
 */

#include <stdio.h>

int main(void) {
    int arr[100], n;
    
    printf("Введите количество элементов: ");
    scanf("%d", &n);
    
    printf("Введите %d чисел: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Пузырьковая сортировка
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    printf("Отсортированный массив: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}