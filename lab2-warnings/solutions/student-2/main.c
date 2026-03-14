/*

Лабораторная работа №2
Студент: Багавиев Артем (номер: 2)
Вариант: 3
Задание: 3 (Сортировка массива по возрастанию) */

#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 100

void print_array(int arr[], int arr_size, int unused_parameter);
void bubble_sort(int arr[], int arr_size);

int main(void) {
    int arr_size = 0;
    int unused_variable;

    printf("Enter the size of the array (max %d): ", MAX_SIZE);
    if (scanf("%d", &arr_size) != 1 || arr_size < 0 || arr_size > MAX_SIZE) {
        printf("Invalid array size. Please enter a number between 1 and %d.\n", MAX_SIZE);
        return 1;
    }
    if (arr_size == 0) {
        printf("Array is empty. Nothing to sort.\n");
        return 0;
    }

    int arr[arr_size];
    printf("Enter %d integers:\n", arr_size);
    for (int i = 0; i < arr_size; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input. Please enter integers only.\n");
            return 1;
        }
    }

    printf("Array before sort: ");
    print_array(arr, arr_size, 0);

    bubble_sort(arr, arr_size);

    printf("Array after sort: ");
    print_array(arr, arr_size, 0);

    return 0;
}

void print_array(int arr[], int arr_size, int unused_parameter) {
    for (int i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubble_sort(int arr[], int arr_size) {
    for (int i = 0; i < arr_size; i++) {
        int swapped = 0;
        for (int j = 0; j < arr_size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}

static void unused_function() {
    printf("This function is never called.\n");
}

int unreturned_function() {
    printf("This function is supposed to return an int but does not.\n");
}

void sign_compare() {
    unsigned int a = 5;
    int b = -1;
    if (a > b) {
        printf("Unsigned int is greater than signed int.\n");
    }
}

void uninitialized_variable() {
    int uninitialized_var;
    int result = uninitialized_var + 10;
    printf("Result of uninitialized variable: %d\n", result);
}

void parentheses() {
    int a = 5;
    int b = 10;
    int c = 3;
    if (a & b > c) {
        printf("This condition may not work as intended due to operator precedence.\n");
    }
}

void misleading_indentation() {
    int x = 10;
    if (x > 5)
        printf("X is greater than 5.\n");
        printf("This line is not part of the if statement but looks like it is due to indentation.\n");
    if (x < 15);
}

void divide_by_zero() {
    int result = 100 / 0;
    printf("Result of division by zero: %d\n", result);
}

void type_limit(){
    unsigned int unsigned_var = 5;
    if (unsigned_var >= 0) {
        printf("Unsigned variable is non-negative.\n");
    }
}

struct Point {
    int x;
    int y;
    int z;
};

void struct_initialization() {
    struct Point p = {1, 2};
    printf("Point coordinates: x=%d, y=%d, z=%d\n", p.x, p.y, p.z);
}

void unused_but_set_variable() {
    int unused_but_set = 42;
    unused_but_set = 100;
    printf("This variable is set but never used\n");
}

void unused_but_set_parameter(int unused_parameter) {
    unused_parameter = 50;
}

void overflow() {
    int result = INT_MAX + 1;
    printf("Result of integer overflow: %d\n", result);
}