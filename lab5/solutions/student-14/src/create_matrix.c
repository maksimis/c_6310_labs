#include "matrix.h"

matrix_t *create_matrix(int rows, int cols)
{
	matrix_t	*new_matrix;
	int			i;

	if (rows <= 0 || cols <= 0)
		return (NULL);

	new_matrix = (matrix_t *)ft_calloc(1, sizeof(matrix_t));

	if (!new_matrix)
		return (NULL);

	new_matrix->rows = rows;
	new_matrix->cols = cols;
	new_matrix->matrix = (int **)ft_calloc(rows, sizeof(int *));

	if (!new_matrix->matrix)
	{
		free(new_matrix);
		return (NULL);
	}

	i = 0;
	while (i < rows)
	{
		new_matrix->matrix[i] = (int *)ft_calloc(cols, sizeof(int));
		if (!new_matrix->matrix[i])
		{
			while (i > 0)
			{
				i--;
				free(new_matrix->matrix[i]);
			}
			free(new_matrix->matrix);
			free(new_matrix);
			return (NULL);
		}
		i++;
	}
    
	return (new_matrix);
}