#include "../inc/matrix.h"

t_matrix	*sub_matrix(t_matrix *A, t_matrix *B)
{
	t_matrix	*C;
	int		i;
	int		j;

	if (!A || !B)
		return (NULL);
	if (A->rows != B->rows || A->cols != B->cols)
		return (NULL);
	C = create_matrix(A->rows, A->cols);
	if (!C)
		return (NULL);
	i = 0;
	while (i < A->rows)
	{
		j = 0;
		while (j < A->cols)
		{
			C->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
			j++;
		}
		i++;
	}
	return (C);
}
