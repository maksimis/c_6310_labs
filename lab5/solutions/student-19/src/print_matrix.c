#include "matrix.h"

void	print_matrix(matrix_t *A) // функция вывода матрицы на экран
{
	int	i;
	int	j;

	if (!A) // проверка, что матрица существуют
		return ;
	i = 0;
	while (i < A->rows) // проходим по всем строкам матрицы
	{
		j = 0;
		while (j < A->columns) // проходим по всем элементам строки
		{
			ft_putnbr_fd(A->matrix[i][j], 1); // выводим число
			if (j < A->columns - 1) // ставим пробел между числами
				ft_putchar_fd(' ', 1);
			j++;
		}
		ft_putchar_fd('\n', 1); // переход на новую строку после вывода строки матрицы  
		i++;
	}
}