#include "matrix.h"

static int	allocate_rows(matrix_t *a)
{
	int	i;

	i = 0;
	while (i < a->rows)
	{
		a->matrix[i] = ft_calloc(a->columns, sizeof(int));
		if (!a->matrix[i])
		{
			while (i > 0)
			{
				i--;
				free(a->matrix[i]);
			}
			free(a->matrix);
			free(a);
			return (0);
		}
		i++;
	}
	return (1);
}

matrix_t	*create_matrix(int rows, int cols)
{
	matrix_t	*a;

	if (rows <= 0 || cols <= 0)
		return (NULL);
	a = malloc(sizeof(matrix_t));
	if (!a)
		return (NULL);
	a->rows = rows;
	a->columns = cols;
	a->matrix = ft_calloc(rows, sizeof(int *));
	if (!a->matrix)
	{
		free(a);
		return (NULL);
	}
	if (!allocate_rows(a))
		return (NULL);
	return (a);
}