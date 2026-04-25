#ifndef MATRIX_H
#define MATRIX_H

typedef struct matrix_struct { // структура с именем matrix_struct, typedef позволяет использовать короткое имя matrix_t вместо struct matrix_struct
    int **matrix; // указатель на указатель,  matrix → массив указателей, каждый указатель → строка
    int rows;
    int columns;
} matrix_t; // переименование

// Прототипы функций (декларации)
// Они показывают три вещи: как функция называется, что она принимает на вход и что возвращает
matrix_t *create_matrix(int rows, int cols); // matrix_t * → возвращает указатель на матрицу
void remove_matrix(matrix_t *A); // ссылка на аргемент с типом данных matrix_t
void print_matrix(matrix_t *A);

int eq_matrix(matrix_t *A, matrix_t *B);  // int - тип возвращаемого значения, название функции и её аргументы
int is_symmetric(matrix_t *A);
int is_diagonal(matrix_t *A);
int is_identity(matrix_t *A);

#endif