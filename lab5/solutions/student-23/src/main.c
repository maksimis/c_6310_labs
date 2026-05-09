#include "../inc/matrix.h"

static void fill_matrix_a(matrix_t *A)
{
    A->matrix[0][0] = 1;
    A->matrix[0][1] = 2;
    A->matrix[0][2] = 3;
    A->matrix[1][0] = 4;
    A->matrix[1][1] = 5;
    A->matrix[1][2] = 6;
}

static void fill_matrix_b(matrix_t *B)
{
    B->matrix[0][0] = 7;
    B->matrix[0][1] = 8;
    B->matrix[1][0] = 9;
    B->matrix[1][1] = 10;
    B->matrix[2][0] = 11;
    B->matrix[2][1] = 12;
}

static void fill_square_a(matrix_t *A)
{
    A->matrix[0][0] = 1;
    A->matrix[0][1] = 2;
    A->matrix[1][0] = 3;
    A->matrix[1][1] = 4;
}

static void fill_square_b(matrix_t *B)
{
    B->matrix[0][0] = 5;
    B->matrix[0][1] = 6;
    B->matrix[1][0] = 7;
    B->matrix[1][1] = 8;
}

static void fill_row(matrix_t *A)
{
    A->matrix[0][0] = 1;
    A->matrix[0][1] = 2;
    A->matrix[0][2] = 3;
}

static void fill_column(matrix_t *B)
{
    B->matrix[0][0] = 4;
    B->matrix[1][0] = 5;
    B->matrix[2][0] = 6;
}

static void fill_zero(matrix_t *A)
{
    A->matrix[0][0] = 0;
    A->matrix[0][1] = 0;
    A->matrix[1][0] = 0;
    A->matrix[1][1] = 0;
}

static void fill_identity(matrix_t *A)
{
    A->matrix[0][0] = 1;
    A->matrix[0][1] = 0;
    A->matrix[1][0] = 0;
    A->matrix[1][1] = 1;
}

static void test_general(void)
{
    matrix_t *A = create_matrix(2, 3);
    matrix_t *B = create_matrix(3, 2);
    matrix_t *C;

    if (!A || !B)
        return;

    fill_matrix_a(A);
    fill_matrix_b(B);

    ft_putendl_fd("General multiplication:", 1);
    C = mult_matrix(A, B);
    print_matrix(C);

    remove_matrix(A);
    remove_matrix(B);
    remove_matrix(C);
}

static void test_square(void)
{
    matrix_t *A = create_matrix(2, 2);
    matrix_t *B = create_matrix(2, 2);
    matrix_t *C;

    if (!A || !B)
        return;

    fill_square_a(A);
    fill_square_b(B);

    ft_putendl_fd("Square matrices:", 1);
    C = mult_matrix(A, B);
    print_matrix(C);

    remove_matrix(A);
    remove_matrix(B);
    remove_matrix(C);
}

static void test_row_column(void)
{
    matrix_t *A = create_matrix(1, 3);
    matrix_t *B = create_matrix(3, 1);
    matrix_t *C;

    if (!A || !B)
        return;

    fill_row(A);
    fill_column(B);

    ft_putendl_fd("Row x Column:", 1);
    C = mult_matrix(A, B);
    print_matrix(C);

    remove_matrix(A);
    remove_matrix(B);
    remove_matrix(C);
}
static void test_invalid_sizes(void)
{
    matrix_t *A;

    ft_putendl_fd("Invalid sizes test:", 1);

    A = create_matrix(0, 5);
    if (!A)
        ft_putendl_fd("Correct: NULL returned", 1);

    A = create_matrix(-3, 4);
    if (!A)
        ft_putendl_fd("Correct: NULL returned", 1);

    A = create_matrix(0, 0);
    if (!A)
        ft_putendl_fd("Correct: NULL returned", 1);
}

static void test_zero(void)
{
    matrix_t *A = create_matrix(2, 2);
    matrix_t *B = create_matrix(2, 2);
    matrix_t *C;

    if (!A || !B)
        return;

    fill_zero(A);

    ft_putendl_fd("Zero matrix:", 1);
    C = mult_matrix(A, B);
    print_matrix(C);

    remove_matrix(A);
    remove_matrix(B);
    remove_matrix(C);
}

static void test_identity(void)
{
    matrix_t *A = create_matrix(2, 2);
    matrix_t *B = create_matrix(2, 2);
    matrix_t *C;

    if (!A || !B)
        return;

    fill_identity(A);
    fill_square_b(B);

    ft_putendl_fd("Identity test:", 1);
    C = mult_matrix(A, B);
    print_matrix(C);

    remove_matrix(A);
    remove_matrix(B);
    remove_matrix(C);
}

int main(void)
{
    test_general();
    ft_putchar_fd('\n', 1);

    test_square();
    ft_putchar_fd('\n', 1);

    test_row_column();
    ft_putchar_fd('\n', 1);

    test_zero();
    ft_putchar_fd('\n', 1);
    
    test_invalid_sizes();
    ft_putchar_fd('\n', 1);

    test_identity();

    return (0);
}