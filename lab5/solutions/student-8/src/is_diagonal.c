#include "libft.h"
#include "matrix.h"

int	is_diagonal(matrix_t *A)
{
	int	i;
	int	j;

	if (!A || !A->matrix)
		return (0);
	if (A->rows != A->columns)
		return (0);
	i = 0;
	while (i < A->rows)
	{
		j = 0;
		while (j < A->columns)
		{
			if (i != j && A->matrix[i][j] != 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
