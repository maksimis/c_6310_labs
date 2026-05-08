#include "matrix.h"

matrix_t	*sum_matrix(matrix_t *a, matrix_t *b)
{
	matrix_t	*result;
	int			i;
	int			j;

	if (!a || !b || !a->matrix || !b->matrix)
		return (NULL);
	if (a->rows != b->rows || a->columns != b->columns)
		return (NULL);
	result = create_matrix(a->rows, a->columns);
	if (!result)
		return (NULL);
	i = 0;
	while (i < a->rows)
	{
		j = 0;
		while (j < a->columns)
		{
			result->matrix[i][j] = a->matrix[i][j] + b->matrix[i][j];
			j++;
		}
		i++;
	}
	return (result);
}