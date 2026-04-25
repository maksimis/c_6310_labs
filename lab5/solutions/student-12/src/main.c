#include "matrix.h"
#include "libft.h"

int main(void)
{
    // переменные для хранения адресов матриц
    matrix_t *A;
    matrix_t *B;
    matrix_t *C;

    // создание матриц, выделяется память,создаётся структура (двументрый массив)
    A = create_matrix(3, 3); 
    B = create_matrix(3, 3);
    C = create_matrix(3, 3);

    if (!A || !B || !C) // если create_matrix вернет null
    {
        ft_putendl_fd("Memory allocation error", 1);
        remove_matrix(A);
        remove_matrix(B);
        remove_matrix(C);
        return (1); // завершилась с ошибкой
    }

    /*
    A = create_matrix(2, 3);
    B = create_matrix(3, 2);
    C = create_matrix(2, 3);
    A->matrix[0][0] = 1; A->matrix[0][1] = 2; A->matrix[0][2] = 3;
    A->matrix[1][0] = 4; A->matrix[1][1] = 5; A->matrix[1][2] = 6;
    B->matrix[0][0] = 1; B->matrix[0][1] = 2;
    B->matrix[1][0] = 3; B->matrix[1][1] = 4;
    B->matrix[2][0] = 5; B->matrix[2][1] = 6;
    C->matrix[0][0] = 9; C->matrix[0][1] = 8; C->matrix[0][2] = 7;
    C->matrix[1][0] = 6; C->matrix[1][1] = 5; C->matrix[1][2] = 4; */

    A->matrix[0][0] = 1; A->matrix[0][1] = 0; A->matrix[0][2] = 0;
    A->matrix[1][0] = 0; A->matrix[1][1] = 1; A->matrix[1][2] = 0;
    A->matrix[2][0] = 0; A->matrix[2][1] = 0; A->matrix[2][2] = 1;
    
    B->matrix[0][0] = 1; B->matrix[0][1] = 0; B->matrix[0][2] = 0;
    B->matrix[1][0] = 0; B->matrix[1][1] = 1; B->matrix[1][2] = 0;
    B->matrix[2][0] = 0; B->matrix[2][1] = 0; B->matrix[2][2] = 1;

    C->matrix[0][0] = 1; C->matrix[0][1] = 0; C->matrix[0][2] = 0;
    C->matrix[1][0] = 0; C->matrix[1][1] = 1; C->matrix[1][2] = 0;
    C->matrix[2][0] = 0; C->matrix[2][1] = 0; C->matrix[2][2] = 1;

    // одинаковость 
    ft_putnbr_fd(eq_matrix(A, B), 1);
    ft_putchar_fd('\n', 1);

    // симметричность
    ft_putnbr_fd(is_symmetric(C), 1);
    ft_putchar_fd('\n', 1);

    // диагональность
    ft_putnbr_fd(is_diagonal(C), 1);
    ft_putchar_fd('\n', 1);

    // единичность
    ft_putnbr_fd(is_identity(C), 1);
    ft_putchar_fd('\n', 1);

    // принт 
    ft_putendl_fd("Matrix A:", 1); 
    print_matrix(A);
    ft_putendl_fd("Matrix B:", 1);
    print_matrix(B);
    ft_putendl_fd("Matrix C:", 1);
    print_matrix(C);

    remove_matrix(A);
    remove_matrix(B);
    remove_matrix(C);

    return (0);
}