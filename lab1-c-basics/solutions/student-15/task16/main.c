/*
Лабораторная работа №1
Студент: Иванов Артем (номер: 15)
Вариант: 16
Задание: Сумма диагональных элементов матрицы
*/

#include <stdio.h>

#define MAX_SIZE 10
#define MIN_SIZE 1

void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    printf("=== Your matrix ===\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%6d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int calculateDiagonalSum(int rows, int cols, int matrix[rows][cols]){
    int sum = 0;
    int diagonal_length = (rows < cols) ? rows : cols;

    for (int i = 0; i < diagonal_length; i++){
        sum += matrix[i][i];
    }
    return sum;
}

int main(){
    int rows, cols;

    printf("Enter number of rows %d-%d: ", MIN_SIZE, MAX_SIZE);
    if (scanf("%d", &rows) != 1){
        printf("Error: must be a number!\n");
        return 1;
    }

    if (rows < MIN_SIZE || rows > MAX_SIZE){
        printf("Error: rows must be from %d to %d\n", MIN_SIZE, MAX_SIZE);
        return 1;
    }

    printf("Enter number of columns %d-%d: ", MIN_SIZE, MAX_SIZE);
    if (scanf("%d", &cols) != 1) {
        printf("Error: Must be a number!\n");
        return 1;
    }
    
    if (cols < MIN_SIZE || cols > MAX_SIZE) {
        printf("Error: Columns must be from %d to %d!\n", MIN_SIZE, MAX_SIZE);
        return 1;
    }
    
    int matrix[rows][cols];

    printf("Enter matrix elements %dx%d\n", rows, cols);
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            printf("matrix[%d][%d] = ", i, j);
            if (scanf("%d", &matrix[i][j]) != 1){
                printf("Error: invalid input!\n");
                return 1;
            }
        }
    }

    printMatrix(rows, cols, matrix);

    int sum = calculateDiagonalSum(rows, cols, matrix);
    
     printf("=== RESULT ===\n");
     printf("Sum of diagonal elements: %d\n", sum);

    return 0;
}