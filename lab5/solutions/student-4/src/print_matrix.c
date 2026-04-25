#include "matrix.h"
#include "libft.h"

void print_matrix(matrix_t *A)
{
	if (!A)
		return ;
		
	for(int i = 0; i < A->rows; i++)
	{
		for(int j = 0; j < A->columns; j++)
		{
			ft_putnbr_fd(A->matrix[i][j], 1);
			if (j < A->columns - 1)
				ft_putchar_fd(' ', 1); // пробел между элементами, но не после последнего
		}
		ft_putchar_fd('\n', 1);
	}
}
