#include "matrix.h"
#include "libft.h"

void remove_matrix(matrix_t *A)
{
	if (!A)
		return ;

	if (A->matrix)
	{
		free(A->matrix[0]); // сначала чистим все числа(данные матрицы)
		free(A->matrix);    // чистим массив указателей на строки
	}
	free(A);                //чистим саму структуру matrix_t
}
