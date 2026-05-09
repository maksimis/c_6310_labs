#include "matrix.h"

matrix_t	*mult_matrix(matrix_t *A, matrix_t *B)  // функция умножения двух матриц
{
	matrix_t	*C;
	int			i;
	int			j;
	int			k;

	if (!A || !B) // проверка, что матрицы существуют
		return (NULL);
    // проверка совместимости матриц
	// количество столбцов A должно быть равно количеству строк B
	if (A->columns != B->rows)
		return (NULL);
	C = create_matrix(A->rows, B->columns); // создаём матрицу для результата

	if (!C) // проверка успешного выделения памяти
		return (NULL);
	i = 0;
	while (i < A->rows)  // проходим по строкам матрицы A
	{
		j = 0;
		while (j < B->columns)  // проходим по столбцам матрицы B

        	// сначала обнуляем элемент результирующей матрицы
		{
			C->matrix[i][j] = 0;
			k = 0;
			while (k < A->columns) // считаем сумму произведений элементов A на столбец B
			{
				C->matrix[i][j] +=
					A->matrix[i][k] * B->matrix[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	return (C); //возвращаем результирующую матрицу
}