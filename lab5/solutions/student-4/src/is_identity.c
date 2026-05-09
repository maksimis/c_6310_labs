#include "matrix.h"

// на главной диагонали — единицы, везде остальное — нули.

int	is_identity(matrix_t *A)
{
	// Не квадратная матрица не может быть диагональной
	if (!A || A->rows != A->columns)
		return (0);
	
	for(int i = 0; i < A->rows; i++)
	{
		for(int j = 0; j < A->columns; j++)
		{
			// На диагонали (i == j) должна стоять 1
			if (i == j && A->matrix[i][j] != 1)
				return (0);
			// Вне диагонали (i != j) должен стоять 0
			if (i != j && A->matrix[i][j] != 0)
				return (0);
		}
	}
	return (1);
}
