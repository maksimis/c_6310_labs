#include "matrix.h"

int	main(void)
{
	matrix_t	*A;
	matrix_t	*B;
	matrix_t	*T;

	A = create_matrix(2, 3);
	if (!A)
        ft_putendl_fd("Error: failed to create matrix A", 2);
		return (1);

	A->matrix[0][0] = 1;
	A->matrix[0][1] = 2;
	A->matrix[0][2] = 3;
	A->matrix[1][0] = 4;
	A->matrix[1][1] = 5;
	A->matrix[1][2] = 6;

	ft_putendl_fd("Matrix A:", 1);
	print_matrix(A);

	B = mult_number(A, 2);
	if (!B)
	{
		ft_putendl_fd("Error: failed to create matrix B", 2)
        remove_matrix(A);
		return (1);
	}

	ft_putendl_fd("\nMatrix B (A * 2):", 1);
	print_matrix(B);

	T = transpose(A);
	if (!T)
	{
        ft_putendl_fd("Error: failed to create matrix T", 2)
		remove_matrix(A);
		remove_matrix(B);
		return (1);
	}

	ft_putendl_fd("\nTranspose of A:", 1);
	print_matrix(T);

	remove_matrix(A);
	remove_matrix(B);
	remove_matrix(T);

    ft_putendl_fd("\nThe matrices are deleted", 1);

	return (0);
} 