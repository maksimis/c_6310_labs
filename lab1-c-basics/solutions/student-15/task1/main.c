/*
Лабораторная работа №1
Студент: Иванов Артем (номер: 15)
Вариант: 16
Задание: 1 (Сумма элементов массива) */
#include <stdio.h>

#define MAX_ARRAY_SIZE 10

double sumArray(double arr[], int size) {
    double sum = 0;  
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int size;
    
    printf("Enter array size (max %d): ", MAX_ARRAY_SIZE);
    if (scanf("%d", &size) != 1 || size <= 0 || size > MAX_ARRAY_SIZE) {
        printf("Invalid array size!\n");
        return 1;
    }
    
    double arr[size];
    
    printf("Enter %d numbers:\n", size);
    for (int i = 0; i < size; i++) {
        printf("arr[%d] = ", i);
        if (scanf("%lf", &arr[i]) != 1) {  
            printf("Input error!\n");
            return 1;
        }
    }
    
    double sum = sumArray(arr, size);
    
    printf("Sum of array elements: %.2f\n", sum);  
    
    return 0;
}