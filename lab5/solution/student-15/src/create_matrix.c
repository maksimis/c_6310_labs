#include "matrix.h"

static void	free_rows(int **arr, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

matrix_t	*create_matrix(int rows, int cols)
{
	matrix_t	*res;
	int			i;

	if (rows <= 0 || cols <= 0)
		return (NULL);
	res = (matrix_t *)malloc(sizeof(matrix_t));
	if (!res)
		return (NULL);
	res->rows = rows;
	res->columns = cols;
	res->matrix = (int **)malloc(sizeof(int *) * rows);
	if (!res->matrix)
	{
		free(res);
		return (NULL);
	}
	i = 0;
	while (i < rows)
	{
		res->matrix[i] = (int *)malloc(sizeof(int) * cols);
		if (!res->matrix[i])
		{
			free_rows(res->matrix, i);
			free(res);
			return (NULL);
		}
		i++;
	}
	return (res);
}