#include "libft.h"
#include "matrix.h"

matrix_t	*sub_matrix(matrix_t *A, matrix_t *B)
{
	matrix_t	*C;
	int			i;
	int			j;

	if (!A || !B || !A->matrix || !B->matrix)
		return (NULL);
	if (A->rows != B->rows || A->columns != B->columns)
		return (NULL);
	C = create_matrix(A->rows, A->columns);
	if (!C)
		return (NULL);
	i = 0;
	while (i < A->rows)
	{
		j = 0;
		while (j < A->columns)
		{
			C->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
			j++;
		}
		i++;
	}
	return (C);
}
