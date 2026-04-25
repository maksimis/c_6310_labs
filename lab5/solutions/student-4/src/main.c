#include "matrix.h"
#include "libft.h"

int	main(void)
{
	matrix_t	*A;
	matrix_t	*B;
	matrix_t	*C;
	matrix_t	*D;
	matrix_t	*E;

	A = create_matrix(2, 2);
	A->matrix[0][0] = 1; A->matrix[0][1] = 2;
	A->matrix[1][0] = 3; A->matrix[1][1] = 4;

	B = create_matrix(2, 2);
	B->matrix[0][0] = 1; B->matrix[0][1] = 2;
	B->matrix[1][0] = 3; B->matrix[1][1] = 4;

	ft_putstr_fd("Matrix A:\n", 1);
	print_matrix(A);
	ft_putstr_fd("Matrix B:\n", 1);
	print_matrix(B);
	ft_putstr_fd("eq_matrix(A, B): ", 1);
	ft_putnbr_fd(eq_matrix(A, B), 1);
	ft_putstr_fd("\n\n", 1);

	B->matrix[1][1] = 99;
	ft_putstr_fd("After B[1][1] = 99:\n", 1);
	ft_putstr_fd("eq_matrix(A, B): ", 1);
	ft_putnbr_fd(eq_matrix(A, B), 1);
	ft_putstr_fd("\n\n", 1);

	C = create_matrix(3, 3);
	C->matrix[0][0] = 1; C->matrix[0][1] = 2; C->matrix[0][2] = 3;
	C->matrix[1][0] = 2; C->matrix[1][1] = 5; C->matrix[1][2] = 6;
	C->matrix[2][0] = 3; C->matrix[2][1] = 6; C->matrix[2][2] = 9;

	ft_putstr_fd("Matrix C (symmetric):\n", 1);
	print_matrix(C);
	ft_putstr_fd("is_symmetric(C): ", 1);
	ft_putnbr_fd(is_symmetric(C), 1);
	ft_putstr_fd("\n\n", 1);

	D = create_matrix(3, 3);
	D->matrix[0][0] = 1; D->matrix[0][1] = 0; D->matrix[0][2] = 0;
	D->matrix[1][0] = 0; D->matrix[1][1] = 5; D->matrix[1][2] = 0;
	D->matrix[2][0] = 0; D->matrix[2][1] = 0; D->matrix[2][2] = 9;

	ft_putstr_fd("Matrix D (diagonal):\n", 1);
	print_matrix(D);
	ft_putstr_fd("is_diagonal(D): ", 1);
	ft_putnbr_fd(is_diagonal(D), 1);
	ft_putstr_fd("\n\n", 1);
	ft_putstr_fd("is_symmetric(D): ", 1);
	ft_putnbr_fd(is_symmetric(D), 1);
	ft_putstr_fd("\n\n", 1);

	E = create_matrix(3, 3);
	E->matrix[0][0] = 1; E->matrix[0][1] = 0; E->matrix[0][2] = 0;
	E->matrix[1][0] = 0; E->matrix[1][1] = 1; E->matrix[1][2] = 0;
	E->matrix[2][0] = 0; E->matrix[2][1] = 0; E->matrix[2][2] = 1;

	ft_putstr_fd("Matrix E (identity):\n", 1);
	print_matrix(E);
	ft_putstr_fd("is_identity(E): ", 1);
	ft_putnbr_fd(is_identity(E), 1);
	ft_putstr_fd("\n\n", 1);
	ft_putstr_fd("is_diagonal(E): ", 1);
	ft_putnbr_fd(is_diagonal(E), 1);
	ft_putstr_fd("\n\n", 1);

	remove_matrix(A);
	remove_matrix(B);
	remove_matrix(C);
	remove_matrix(D);
	remove_matrix(E);
	return (0);
}
