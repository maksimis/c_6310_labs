// 3. Сортировка массива по возрастанию

#include <stdio.h>

int main() {
    double arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    double temp;
    
    printf("Исходный массив: ");
    for (int i = 0; i < size; i++) {
        printf("%0.f ", arr[i]);
    }

    // printf("\nПромежуточные массивы: \n");

    // Пузырьковая сортировка
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                /*
                for (int i = 0; i < size; i++) {
                    
                    printf("%0.f ", arr[i]);
                }
                printf("\n");
                */
            }
        }
    }
    
    printf("Отсортированный массив: ");
    for (int i = 0; i < size; i++) {
        printf("%0.f ", arr[i]);
    }
    
    return 0;
}