#include "matrix.h"

void print_matrix(matrix_t *a)
{
    int i;
    int j;

    if (!a || !a->matrix)
        return ;
    i = 0;
    while (i < a->rows)
    {
        j = 0;
        while (j < a->columns)
        {
            ft_putnbr_fd(a->matrix[i][j], 1);
            if (j < a->columns - 1)
                ft_putchar_fd(' ', 1);
            j++;
        }
        ft_putchar_fd('\n', 1);
        i++;
    }
}