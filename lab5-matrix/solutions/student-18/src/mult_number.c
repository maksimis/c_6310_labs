#include "matrix.h"

t_matrix	*mult_number(t_matrix *A, int num)
{
	t_matrix	*result;
	int			i;
	int			j;

	if (!A)
		return (NULL);
	result = create_matrix(A->rows, A->cols);
	if (!result)
		return (NULL);
	i = 0;
	while (i < A->rows)
	{
		j = 0;
		while (j < A->cols)
		{
			result->data[i][j] = A->data[i][j] * num;
			j++;
		}
		i++;
	}
	return (result);
}