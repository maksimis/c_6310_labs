#include "matrix.h"

static void	fill_matrix_a(matrix_t *A)
{
	A->matrix[0][0] = 1;
	A->matrix[0][1] = 2;
	A->matrix[0][2] = 3;
	A->matrix[1][0] = 4;
	A->matrix[1][1] = 5;
	A->matrix[1][2] = 6;
}

static void	fill_matrix_b(matrix_t *B)
{
	B->matrix[0][0] = 7;
	B->matrix[0][1] = 8;
	B->matrix[1][0] = 9;
	B->matrix[1][1] = 10;
	B->matrix[2][0] = 11;
	B->matrix[2][1] = 12;
}

int	main(void)
{
	matrix_t	*A;
	matrix_t	*B;
	matrix_t	*C;

	A = create_matrix(2, 3);
	B = create_matrix(3, 2);
	if (!A || !B)
	{
		ft_putendl_fd("Error: matrix allocation failed", 1);
		remove_matrix(A);
		remove_matrix(B);
		return (1);
	}
	fill_matrix_a(A);
	fill_matrix_b(B);
	ft_putendl_fd("Matrix A:", 1);
	print_matrix(A);
	ft_putendl_fd("Matrix B:", 1);
	print_matrix(B);
	C = mult_matrix(A, B);
	if (!C)
		ft_putendl_fd("Error: matrices cannot be multiplied", 1);
	else
	{
		ft_putendl_fd("A * B:", 1);
		print_matrix(C);
	}
	remove_matrix(A);
	remove_matrix(B);
	remove_matrix(C);
	return (0);
}