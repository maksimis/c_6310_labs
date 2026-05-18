#include "matrix.h"

void	remove_matrix(matrix_t *A)
{
	int	i;

	if (!A)
		return ;
	if (A->matrix)
	{
		i = 0;
		while (i < A->rows)
			free(A->matrix[i++]);
		free(A->matrix);
	}
	free(A);
}
