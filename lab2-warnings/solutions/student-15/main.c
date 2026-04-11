/*
Лабораторная работа №2
Студент: Иванов Артем (номер: 15)
Вариант: 16
Задание: 1 (Сумма элементов массива)
Количество предупреждений: 20 (4 дубликата из -Wall; 5 -Wextra; 1 дубликат -Wextra) */

#include <stdio.h>

#define MAX_ARRAY_SIZE 10


double sumArray(double arr[], int size, int extra) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}


int getNumber() {

}


static void unusedHelper() {
    printf("This function is never called\n");
}


static int implicitFunc(int x) {  
    return x * 2;
}


struct Point {
    int x;
    int y;
    int z;
};

int main() {

    int unusedVar = 42;
    

    int uninitVar;
    if (uninitVar > 0) {
        printf("uninitVar is positive\n");
    }
    

    unsigned int unsignedVal = 10;
    int signedVal = -5;
    if (signedVal < unsignedVal) {
        printf("signed < unsigned\n");
    }
    

    int a = 5, b = 3, c = 2;
    if (a > b > c) {
        printf("a > b > c\n");
    }
    

    if (a == 5);  
        printf("This always runs\n");
    

    char ch = 'A';
    int intArr[10];
    intArr[ch] = 100;
    

    struct Point p = {10};  
    

    unsigned int always = 10;
    if (always >= 0) {
        printf("Always true\n");
    }
    

    int x = 5;
    x = 10;  
    

    int overflow = 1000000 * 1000000;
    

    int shift = 1;
    int bigShift = shift << 100;
    

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
    
    double sum = sumArray(arr, size, 0);
    
    printf("Sum of array elements: %.2f\n", sum);
    
    return 0;
}