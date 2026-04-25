#include "matrix.h"

int	eq_matrix(matrix_t *A, matrix_t *B)
{
	// NULL-матрицы считаем неравными
	if (!A || !B)
		return (0);

	// Матрицы разных размеров не могут быть равны
	if (A->rows != B->rows || A->columns != B->columns)
		return (0);

	for(int i = 0; i < A->rows; i++)
	{
		for(int j = 0; j < A->columns; j++)
		{
			// Если хоть один элемент отличается — матрицы не равны
			if (A->matrix[i][j] != B->matrix[i][j])
				return (0);
		}
	}
	return (1); // если все элементы совпали
}
