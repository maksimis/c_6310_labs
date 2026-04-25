#include "matrix.h"

matrix_t	*create_matrix(int rows, int cols)
{
	matrix_t	*m;
	int			i;

	if (rows <= 0 || cols <= 0)
		return (NULL);
	m = (matrix_t *)ft_calloc(1, sizeof(matrix_t));
	if (!m)
		return (NULL);
	m->rows = rows;
	m->columns = cols;
	m->matrix = (int **)ft_calloc(rows, sizeof(int *));
	if (!m->matrix)
	{
		free(m);
		return (NULL);
	}
	i = 0;
	while (i < rows)
	{
		m->matrix[i] = (int *)ft_calloc(cols, sizeof(int));
		if (!m->matrix[i])
		{
			while (--i >= 0)
				free(m->matrix[i]);
			free(m->matrix);
			free(m);
			return (NULL);
		}
		i++;
	}
	return (m);
}
