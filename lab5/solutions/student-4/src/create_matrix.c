#include "matrix.h"
#include "libft.h"

matrix_t	*create_matrix(int rows, int cols)
{
	matrix_t *m;

	//проверка что размеры матрицы положительные числа 
	if (rows <= 0 || cols <= 0)
		return (NULL);

	m = (matrix_t *)ft_calloc(1, sizeof(matrix_t));
	if (!m)
		return (NULL);

	m->rows = rows;
	m->columns = cols;

	// массив указателей [ ptr0 | ptr1 | ptr2 ]
	m->matrix = (int **)ft_calloc(rows, sizeof(int *));
	if (!m->matrix)
	{
		remove_matrix(m);
		return (NULL);
	}

	// место для всех чисел матрицы [ 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 ]
	m->matrix[0] = (int *)ft_calloc(rows * cols, sizeof(int));
	if (!m->matrix[0])
	{
		remove_matrix(m);
		return (NULL);
	}

	// Строки i>0 указывают внутрь того же блока со сдвигом i*cols
	for(int i = 1;i < rows; i++)
	{
		m->matrix[i] = m->matrix[0] + i * cols;
	}
	return (m);
}
