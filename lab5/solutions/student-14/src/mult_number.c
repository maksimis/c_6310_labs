#include "matrix.h"

matrix_t	*mult_number(matrix_t *A, int num)
{
	matrix_t	*B;
	int			i;
	int			j;

	if (!A || !A->matrix)
		return (NULL);

	B = create_matrix(A->rows, A->cols);

	if (!B)
		return (NULL);

	i = 0;
	while (i < A->rows)
	{
		j = 0;
		while (j < A->cols)
		{
			B->matrix[i][j] = A->matrix[i][j] * num;
			j++;
		}
		i++;
	}

	return (B);
}