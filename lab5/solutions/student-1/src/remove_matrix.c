#include "../inc/matrix.h"

void	remove_matrix(t_matrix *A)
{
	int	i;

	if (!A)
		return ;
	i = 0;
	while (i < A->rows)
	{
		free(A->matrix[i]);
		i++;
	}
	free(A->matrix);
	free(A);
}
