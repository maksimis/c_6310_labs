#include "matrix.h"
#include "../libft/inc/libft.h"

void print_matrix(matrix_t *A)
{
    int i, j;
    
    if (!A || !A->matrix)
    {
        ft_putendl_fd("NULL matrix", 1);
        return;
    }
    i = 0;
    while (i < A->rows)
    {
        j = 0;
        ft_putchar_fd('[', 1);
        while (j < A->columns)
        {
            ft_putnbr_fd(A->matrix[i][j], 1);
            if (j < A->columns - 1)
                ft_putchar_fd(' ', 1);
            j++;
        }
        ft_putchar_fd(']', 1);
        if (i < A->rows - 1)
            ft_putchar_fd('\n', 1);
        i++;
    }
    ft_putchar_fd('\n', 1);
}