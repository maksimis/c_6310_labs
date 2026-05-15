#include "../inc/matrix.h"

t_matrix	*create_matrix(int rows, int cols)
{
	t_matrix	*A;
	int		i;

	if (rows <= 0 || cols <= 0)
		return (NULL);
	A = (t_matrix *)malloc(sizeof(t_matrix));
	if (!A)
		return (NULL);
	A->rows = rows;
	A->cols = cols;
	A->matrix = (int **)malloc(sizeof(int *) * rows);
	if (!A->matrix)
	{
		free(A);
		return (NULL);
	}
	i = 0;
	while (i < rows)
	{
		A->matrix[i] = (int *)malloc(sizeof(int) * cols);
		if (!A->matrix[i])
		{
			while (i > 0)
				free(A->matrix[--i]);
			free(A->matrix);
			free(A);
			return (NULL);
		}
		i++;
	}
	return (A);
}
