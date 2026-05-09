 #include "matrix.h"

int	main(void)
{
	matrix_t	*A;
	matrix_t	*B;
	matrix_t	*C;

	A = create_matrix(2, 3); // создаем матрицу размером 2x3
	if (!A) // проверка, что память успешно выделилась
		return (1);
	A->matrix[0][0] = 1;  // заполняем матрицу A значениями
	A->matrix[0][1] = 2;
	A->matrix[0][2] = 3;
	A->matrix[1][0] = 4;
	A->matrix[1][1] = 5;
	A->matrix[1][2] = 6;

	B = create_matrix(3, 2); // создаем матрицу размером 3x2
    // если память не выделилась,
	// освобождаем первую матрицу
	if (!B)
	{
		remove_matrix(A);
		return (1);
	}
	B->matrix[0][0] = 7; // заполняем матрицу B значениями
	B->matrix[0][1] = 8;
	B->matrix[1][0] = 9;
	B->matrix[1][1] = 10;
	B->matrix[2][0] = 11;
	B->matrix[2][1] = 12;

	ft_putendl_fd("Matrix A:", 1); // вывод первой матрицы
	print_matrix(A);

	ft_putendl_fd("\nMatrix B:", 1); // вывод второй матрицы
	print_matrix(B);

	C = mult_matrix(A, B); // умножение матриц A и B
	if (!C)  // проверка, что умножение прошло успешно
	{ 
		ft_putendl_fd("Multiplication error", 1); 
		remove_matrix(A);
		remove_matrix(B);
		return (1);
	}

	ft_putendl_fd("\nResult matrix C:", 1); // вывод результирующей матрицы
	print_matrix(C);

    //освобождаем память
	remove_matrix(A);
	remove_matrix(B);
	remove_matrix(C);

	return (0);
}