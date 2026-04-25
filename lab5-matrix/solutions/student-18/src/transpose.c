#include "matrix.h"

t_matrix	*transpose(t_matrix *A)
{
	t_matrix	*result;
	int			i;
	int			j;

	if (!A)
		return (NULL);
	result = create_matrix(A->cols, A->rows);
	if (!result)
		return (NULL);
	i = 0;
	while (i < A->rows)
	{
		j = 0;
		while (j < A->cols)
		{
			result->data[j][i] = A->data[i][j];
			j++;
		}
		i++;
	}
	return (result);
}
