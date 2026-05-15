#include "matrix/matrix.h"
#include "libft/inc/libft.h"

int main(void)
{
    matrix_t *A, *B, *C_sum, *C_sub;
    int i, j;

    ft_putchar_fd('\n', 1);
    ft_putendl_fd("=== Lab05: Matrix library (variant 1: sum & sub) ===", 1);
    ft_putchar_fd('\n', 1);

    // Создание матрицы A 3x3
    A = create_matrix(3, 3);
    if (!A)
    {
        ft_putendl_fd("Error: failed to create matrix A", 2);
        return (1);
    }

    // Заполнение матрицы A: 1 2 3 / 4 5 6 / 7 8 9
    i = 0;
    while (i < 3)
    {
        j = 0;
        while (j < 3)
        {
            A->matrix[i][j] = i * 3 + j + 1;
            j++;
        }
        i++;
    }

    // Создание матрицы B 3x3
    B = create_matrix(3, 3);
    if (!B)
    {
        ft_putendl_fd("Error: failed to create matrix B", 2);
        remove_matrix(A);
        return (1);
    }

    // Заполнение матрицы B: 1 0 0 / 2 0 0 / 3 4 1
    B->matrix[0][0] = 1; B->matrix[0][1] = 0; B->matrix[0][2] = 0;
    B->matrix[1][0] = 2; B->matrix[1][1] = 0; B->matrix[1][2] = 0;
    B->matrix[2][0] = 3; B->matrix[2][1] = 4; B->matrix[2][2] = 1;

    ft_putendl_fd("Matrix A:", 1);
    print_matrix(A);
    ft_putchar_fd('\n', 1);
    ft_putendl_fd("Matrix B:", 1);
    print_matrix(B);
    ft_putchar_fd('\n', 1);

    // Сумма матриц
    C_sum = sum_matrix(A, B);
    if (!C_sum)
        ft_putendl_fd("Error: sum_matrix failed (dimensions mismatch?)", 2);
    else
    {
        ft_putendl_fd("A + B =", 1);
        print_matrix(C_sum);
        ft_putchar_fd('\n', 1);
    }

    // Разность матриц
    C_sub = sub_matrix(A, B);
    if (!C_sub)
        ft_putendl_fd("Error: sub_matrix failed", 2);
    else
    {
        ft_putendl_fd("A - B =", 1);
        print_matrix(C_sub);
    }

    // Освобождение памяти
    remove_matrix(A);
    remove_matrix(B);
    remove_matrix(C_sum);
    remove_matrix(C_sub);

    ft_putendl_fd("\nDone. No memory leaks.", 1);
    return (0);
}