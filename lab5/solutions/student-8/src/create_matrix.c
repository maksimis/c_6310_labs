#include "libft.h"
#include "matrix.h"

static void	free_rows(int **rows, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(rows[i]);
		i++;
	}
	free(rows);
}

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
	m->matrix = (int **)ft_calloc((size_t)rows, sizeof(int *));
	if (!m->matrix)
	{
		free(m);
		return (NULL);
	}
	i = 0;
	while (i < rows)
	{
		m->matrix[i] = (int *)ft_calloc((size_t)cols, sizeof(int));
		if (!m->matrix[i])
		{
			free_rows(m->matrix, i);
			free(m);
			return (NULL);
		}
		i++;
	}
	return (m);
}
