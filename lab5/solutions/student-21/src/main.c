#include "libft.h"
#include "matrix.h"

static void	show(char *title, matrix_t *M)
{
	ft_putendl_fd(title, 1);
	if (!M)
	{
		ft_putendl_fd("(NULL)", 1);
		return ;
	}
	print_matrix(M);
	ft_putchar_fd('\n', 1);
}

static void	fill_a(matrix_t *A)
{
	A->matrix[0][0] = 1;
	A->matrix[0][1] = 2;
	A->matrix[0][2] = 3;
	A->matrix[1][0] = 0;
	A->matrix[1][1] = 4;
	A->matrix[1][2] = 5;
	A->matrix[2][0] = 0;
	A->matrix[2][1] = 0;
	A->matrix[2][2] = 6;
}

static void	fill_b(matrix_t *B)
{
	B->matrix[0][0] = 1;
	B->matrix[0][1] = 0;
	B->matrix[0][2] = 0;
	B->matrix[1][0] = 2;
	B->matrix[1][1] = 0;
	B->matrix[1][2] = 0;
	B->matrix[2][0] = 3;
	B->matrix[2][1] = 4;
	B->matrix[2][2] = 1;
}

static int	demo_mismatch(void)
{
	matrix_t	*X;
	matrix_t	*Y;
	matrix_t	*R;

	X = create_matrix(2, 2);
	Y = create_matrix(2, 3);
	if (!X || !Y)
	{
		remove_matrix(X);
		remove_matrix(Y);
		ft_putstr_fd("Error: allocation failed\n", 2);
		return (1);
	}
	R = sum_matrix(X, Y);
	ft_putendl_fd("Mismatched sizes sum_matrix(2x2, 2x3) -> expected NULL:", 1);
	if (R == NULL)
		ft_putendl_fd("NULL (ok)", 1);
	else
		ft_putendl_fd("non-NULL (error)", 1);
	ft_putchar_fd('\n', 1);
	remove_matrix(X);
	remove_matrix(Y);
	remove_matrix(R);
	return (0);
}

int	main(void)
{
	matrix_t	*A;
	matrix_t	*B;
	matrix_t	*C;
	matrix_t	*D;

	A = create_matrix(3, 3);
	B = create_matrix(3, 3);
	if (!A || !B)
	{
		remove_matrix(A);
		remove_matrix(B);
		ft_putstr_fd("Error: allocation failed\n", 2);
		return (1);
	}
	fill_a(A);
	fill_b(B);
	show("Matrix A:", A);
	show("Matrix B:", B);
	C = sum_matrix(A, B);
	D = sub_matrix(A, B);
	show("C = A + B:", C);
	show("D = A - B:", D);
	remove_matrix(A);
	remove_matrix(B);
	remove_matrix(C);
	remove_matrix(D);
	return (demo_mismatch());
}
