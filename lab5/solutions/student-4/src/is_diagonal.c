#include "matrix.h"

// все элементы ВНЕ главной диагонали должны быть равны 0.
int	is_diagonal(matrix_t *A)
{
	// Не квадратная матрица не может быть диагональной
	if (!A || A->rows != A->columns)
		return (0);

	for(int i = 0; i < A->rows; i++)
	{
		for(int j = 0; j < A->columns; j++)
		{
			// i != j это всё кроме главной диагонали — там должен быть 0
			if (i != j && A->matrix[i][j] != 0)
				return (0);
		}
	}
	return (1);
}
