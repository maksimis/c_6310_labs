#include "matrix.h"

int main(void) {
    matrix_t *A;
    matrix_t *B;
    matrix_t *result;

    A = create_matrix(2, 2);
    A->matrix[0][0] = 1;
    A->matrix[0][1] = 2;
    A->matrix[1][0] = 3;
    A->matrix[1][1] = 4;

    B = create_matrix(2, 2);
    B->matrix[0][0] = 1;
    B->matrix[0][1] = 2;
    B->matrix[1][0] = 3;
    B->matrix[1][1] = 5;

    ft_putstr_fd("Matrix A:\n", 1);
    print_matrix(A);
    ft_putstr_fd("Matrix B:\n", 1);
    print_matrix(B);

    ft_putstr_fd("Result: A + B:\n", 1);
    result = sum_matrix(A, B);
    print_matrix(result);
    remove_matrix(result);

    ft_putstr_fd("Result: A - B:\n", 1);
    result = sub_matrix(A, B);
    print_matrix(result);
    remove_matrix(result);

    remove_matrix(A);
    remove_matrix(B);

    return 0;
}
