#include "../inc/matrix.h"

int	main(void)
{
	t_matrix	*A;
	t_matrix	*B;
	t_matrix	*SUM;
	t_matrix	*SUB;

	A = create_matrix(2, 2);
	B = create_matrix(2, 2);
	if (!A || !B)
	{
		ft_putendl_fd("Error: matrix allocation failed", 2);
		return (1);
	}
	A->matrix[0][0] = 1;
	A->matrix[0][1] = 2;
	A->matrix[1][0] = 3;
	A->matrix[1][1] = 4;

	B->matrix[0][0] = 5;
	B->matrix[0][1] = 6;
	B->matrix[1][0] = 7;
	B->matrix[1][1] = 8;

	ft_putendl_fd("Matrix A:", 1);
	print_matrix(A);

	ft_putendl_fd("Matrix B:", 1);
	print_matrix(B);

	SUM = sum_matrix(A, B);
	SUB = sub_matrix(A, B);

	if (!SUM || !SUB)
	{
		ft_putendl_fd("Error: operation failed", 2);
		remove_matrix(A);
		remove_matrix(B);
		return (1);
	}

	ft_putendl_fd("A + B:", 1);
	print_matrix(SUM);

	ft_putendl_fd("A - B:", 1);
	print_matrix(SUB);

	remove_matrix(A);
	remove_matrix(B);
	remove_matrix(SUM);
	remove_matrix(SUB);

	return (0);
}
