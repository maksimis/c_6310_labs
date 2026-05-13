#include "matrix.h"

t_matrix	*create_matrix(int rows, int cols)
{
	t_matrix	*mat;
	int			i;

	if (rows <= 0 || cols <= 0)
		return (NULL);
	mat = (t_matrix *)malloc(sizeof(t_matrix));
	if (!mat)
		return (NULL);
	mat->rows = rows;
	mat->cols = cols;
	mat->data = (int **)malloc(sizeof(int *) * rows);
	if (!mat->data)
	{
		free(mat);
		return (NULL);
	}
	i = 0;
	while (i < rows)
	{
		mat->data[i] = (int *)malloc(sizeof(int) * cols);
		if (!mat->data[i])
		{
			while (--i >= 0)
				free(mat->data[i]);
			free(mat->data);
			free(mat);
			return (NULL);
		}
		i++;
	}
	return (mat);
}