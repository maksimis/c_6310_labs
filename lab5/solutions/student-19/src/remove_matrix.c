#include "matrix.h"

void	remove_matrix(matrix_t *A) // функция освобождения памяти матрицы
{
	int	i;

	if (!A) // проверка, что указатель на матрицу существует
		return ;
	i = 0;
	while (i < A->rows) // освобождаем память каждой строки матрицы
	{
		free(A->matrix[i]); 
		i++;
	}
	free(A->matrix); // освобождаем массив указателей на строки
	free(A); // освобождаем саму структуру matrix_t
}