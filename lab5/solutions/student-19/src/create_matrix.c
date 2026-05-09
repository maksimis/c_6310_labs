#include "matrix.h"


// функция для освобождения уже выделенных строк
// если во время malloc произошла ошибка
static void	free_rows(int **matrix, int count) 
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

matrix_t	*create_matrix(int rows, int cols)  // создание матрицы размером rows x cols
{
	matrix_t	*A;
	int			i;

	if (rows <= 0 || cols <= 0)  // проверка на некорректные размеры
		return (NULL);
	A = (matrix_t *)malloc(sizeof(matrix_t)); // выделяем память под структуру matrix_t
	if (!A)
		return (NULL);
         
	A->rows = rows; // сохраняем размеры матрицы
	A->columns = cols;
	A->matrix = (int **)malloc(sizeof(int *) * rows);  // выделяем память под массив указателей на строки
	if (!A->matrix)
	{
		free(A);
		return (NULL);
	}
	i = 0;
	while (i < rows) // выделяем память под каждую строку матрицы
	{
		A->matrix[i] = (int *)malloc(sizeof(int) * cols);
        // если malloc не сработал
		// очищаем уже выделенную память
		if (!A->matrix[i])  
		{
			free_rows(A->matrix, i);
			free(A);
			return (NULL);
		}
		i++;
	}
	return (A); //возвращаем матрицу
}