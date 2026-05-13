#include "matrix.h"

static void	print_title(char *title)
{
	ft_putendl_fd(title, 1);
}

static int	run_demo(void)
{
	matrix_t	*a;
	matrix_t	*b;
	matrix_t	*sum;
	matrix_t	*sub;

	a = create_matrix(2, 3);
	b = create_matrix(2, 3);
	if (!a || !b)
	{
		remove_matrix(a);
		remove_matrix(b);
		print_error("memory allocation failed");
		return (1);
	}
	fill_matrix(a, 1);
	fill_matrix(b, 10);
	print_title("Matrix A:");
	print_matrix(a);
	print_title("Matrix B:");
	print_matrix(b);
	sum = sum_matrix(a, b);
	sub = sub_matrix(b, a);
	if (!sum || !sub)
	{
		remove_matrix(a);
		remove_matrix(b);
		remove_matrix(sum);
		remove_matrix(sub);
		print_error("matrix operation failed");
		return (1);
	}
	print_title("A + B:");
	print_matrix(sum);
	print_title("B - A:");
	print_matrix(sub);
	remove_matrix(a);
	remove_matrix(b);
	remove_matrix(sum);
	remove_matrix(sub);
	return (0);
}

int	main(void)
{
	return (run_demo());
}