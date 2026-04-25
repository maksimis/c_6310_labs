#include "matrix.h"

static void	fill_matrix(t_matrix *A, int values[], int size)
{
	int	i;
	int	j;
	int	idx;

	i = 0;
	idx = 0;
	while (i < A->rows)
	{
		j = 0;
		while (j < A->cols)
		{
			if (idx < size)
				A->data[i][j] = values[idx];
			j++;
			idx++;
		}
		i++;
	}
}

int	main(void)
{
	t_matrix	*A;
	t_matrix	*B;
	t_matrix	*T;
	int			values[6];

	ft_putendl_fd("\n1. Создание матрицы A (2x3):", 1);
	A = create_matrix(2, 3);
	if (!A)
	{
		ft_putendl_fd("Ошибка: не удалось создать матрицу A", 2);
		return (1);
	}
	values[0] = 1;
	values[1] = 2;
	values[2] = 3;
	values[3] = 4;
	values[4] = 5;
	values[5] = 6;

	fill_matrix(A, values, 6);
	ft_putendl_fd("Матрица A:", 1);
	print_matrix(A);

	ft_putendl_fd("\n2. Умножение матрицы A на число 2:", 1);
	B = mult_number(A, 2);
	if (!B)
	{
		ft_putendl_fd("Ошибка: не удалось создать матрицу B", 2);
		remove_matrix(A);
		return (1);
	}
	ft_putendl_fd("Матрица B = A × 2:", 1);
	print_matrix(B);

	ft_putendl_fd("\n3. Транспонирование матрицы A:", 1);
	T = transpose(A);
	if (!T)
	{
		ft_putendl_fd("Ошибка: не удалось создать матрицу T", 2);
		remove_matrix(A);
		remove_matrix(B);
		return (1);
	}
	ft_putendl_fd("Матрица T = A^T (3x2):", 1);
	print_matrix(T);

	ft_putendl_fd("\n4. Освобождение памяти:", 1);
	remove_matrix(A);
	remove_matrix(B);
	remove_matrix(T);
	ft_putendl_fd("Все матрицы удалены\n", 1);
	return (0);
}