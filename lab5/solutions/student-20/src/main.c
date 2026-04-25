#include "matrix.h"

static void	print_result(char *label, int value)
{
	ft_putstr_fd(label, 1);
	ft_putnbr_fd(value, 1);
	ft_putchar_fd('\n', 1);
}

int	main(void)
{
	matrix_t	*A;
	matrix_t	*B;
	matrix_t	*C;
	matrix_t	*E;

	ft_putendl_fd("=== eq_matrix ===", 1);
	A = create_matrix(2, 2);
	A->matrix[0][0] = 1; A->matrix[0][1] = 2;
	A->matrix[1][0] = 3; A->matrix[1][1] = 4;
	B = create_matrix(2, 2);
	B->matrix[0][0] = 1; B->matrix[0][1] = 2;
	B->matrix[1][0] = 3; B->matrix[1][1] = 4;
	ft_putstr_fd("A:\n", 1);
	print_matrix(A);
	ft_putstr_fd("B:\n", 1);
	print_matrix(B);
	print_result("eq_matrix(A, B) = ", eq_matrix(A, B));

	ft_putendl_fd("=== is_symmetric ===", 1);
	C = create_matrix(3, 3);
	C->matrix[0][0] = 1; C->matrix[0][1] = 2; C->matrix[0][2] = 3;
	C->matrix[1][0] = 2; C->matrix[1][1] = 5; C->matrix[1][2] = 6;
	C->matrix[2][0] = 3; C->matrix[2][1] = 6; C->matrix[2][2] = 9;
	ft_putstr_fd("C:\n", 1);
	print_matrix(C);
	print_result("is_symmetric(C) = ", is_symmetric(C));

	ft_putendl_fd("=== is_diagonal ===", 1);
	print_result("is_diagonal(C) = ", is_diagonal(C));

	ft_putendl_fd("=== is_identity ===", 1);
	E = create_matrix(3, 3);
	E->matrix[0][0] = 1; E->matrix[1][1] = 1; E->matrix[2][2] = 1;
	ft_putstr_fd("E:\n", 1);
	print_matrix(E);
	print_result("is_identity(E) = ", is_identity(E));
	print_result("is_diagonal(E) = ", is_diagonal(E));

	remove_matrix(A);
	remove_matrix(B);
	remove_matrix(C);
	remove_matrix(E);
	return (0);
}
