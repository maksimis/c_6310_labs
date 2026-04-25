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

static void	check(char *label, int value)
{
	ft_putstr_fd(label, 1);
	ft_putstr_fd(": ", 1);
	ft_putnbr_fd(value, 1);
	ft_putchar_fd('\n', 1);
}

static void	fill_a(matrix_t *A)
{
	A->matrix[0][0] = 1;
	A->matrix[0][1] = 2;
	A->matrix[1][0] = 3;
	A->matrix[1][1] = 4;
}

static void	fill_b_eq_a(matrix_t *B)
{
	B->matrix[0][0] = 1;
	B->matrix[0][1] = 2;
	B->matrix[1][0] = 3;
	B->matrix[1][1] = 4;
}

static void	fill_sym(matrix_t *S)
{
	S->matrix[0][0] = 1;
	S->matrix[0][1] = 2;
	S->matrix[0][2] = 3;
	S->matrix[1][0] = 2;
	S->matrix[1][1] = 5;
	S->matrix[1][2] = 6;
	S->matrix[2][0] = 3;
	S->matrix[2][1] = 6;
	S->matrix[2][2] = 9;
}

static void	fill_diag(matrix_t *D)
{
	D->matrix[0][0] = 1;
	D->matrix[1][1] = 5;
	D->matrix[2][2] = 9;
}

static void	fill_id(matrix_t *E)
{
	E->matrix[0][0] = 1;
	E->matrix[1][1] = 1;
	E->matrix[2][2] = 1;
}

int	main(void)
{
	matrix_t	*A;
	matrix_t	*B;
	matrix_t	*S;
	matrix_t	*D;
	matrix_t	*E;

	A = create_matrix(2, 2);
	B = create_matrix(2, 2);
	S = create_matrix(3, 3);
	D = create_matrix(3, 3);
	E = create_matrix(3, 3);
	if (!A || !B || !S || !D || !E)
	{
		remove_matrix(A);
		remove_matrix(B);
		remove_matrix(S);
		remove_matrix(D);
		remove_matrix(E);
		ft_putstr_fd("Error: allocation failed\n", 2);
		return (1);
	}
	fill_a(A);
	fill_b_eq_a(B);
	fill_sym(S);
	fill_diag(D);
	fill_id(E);
	show("Matrix A:", A);
	show("Matrix B (== A):", B);
	check("eq_matrix(A, B)", eq_matrix(A, B));
	check("is_symmetric(A)", is_symmetric(A));
	ft_putchar_fd('\n', 1);
	show("Matrix S (symmetric):", S);
	check("is_symmetric(S)", is_symmetric(S));
	check("is_diagonal(S)", is_diagonal(S));
	check("is_identity(S)", is_identity(S));
	ft_putchar_fd('\n', 1);
	show("Matrix D (diagonal):", D);
	check("is_symmetric(D)", is_symmetric(D));
	check("is_diagonal(D)", is_diagonal(D));
	check("is_identity(D)", is_identity(D));
	ft_putchar_fd('\n', 1);
	show("Matrix E (identity):", E);
	check("is_symmetric(E)", is_symmetric(E));
	check("is_diagonal(E)", is_diagonal(E));
	check("is_identity(E)", is_identity(E));
	remove_matrix(A);
	remove_matrix(B);
	remove_matrix(S);
	remove_matrix(D);
	remove_matrix(E);
	return (0);
}
