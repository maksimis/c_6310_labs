#include "matrix.h"

matrix_t *transpose(matrix_t *A)
{
	matrix_t	*T;
	int			i;
	int			j;

	if (!A || !A->matrix)
		return (NULL);

	T = create_matrix(A->cols, A->rows);

	if (!T)
		return (NULL);

	i = 0;
	while (i < A->rows)
	{
		j = 0;
		while (j < A->cols)
		{
			T->matrix[j][i] = A->matrix[i][j];
			j++;
		}
		i++;
	}

	return (T);
}