#ifndef MATRIX_H
#define MATRIX_H

typedef struct matrix_struct {
    int **matrix;
    int rows;
    int columns;
} matrix_t;

matrix_t *create_matrix(int rows, int cols);
void remove_matrix(matrix_t *A);
void print_matrix(matrix_t *A);

int eq_matrix(matrix_t *A, matrix_t *B);
int is_symmetric(matrix_t *A);
int is_diagonal(matrix_t *A);
int is_identity(matrix_t *A);

#endif