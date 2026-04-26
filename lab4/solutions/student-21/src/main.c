#include "libft.h"
#include <stdarg.h>

#define MAX_NUMS 32

typedef int	(*t_op_fn)(int count, ...);

typedef struct s_op
{
	const char	*name;
	t_op_fn		fn;
}	t_op;

static int	op_sum(int count, ...)
{
	va_list	ap;
	int		total;
	int		i;

	va_start(ap, count);
	total = 0;
	i = 0;
	while (i < count)
	{
		total += va_arg(ap, int);
		i++;
	}
	va_end(ap);
	return (total);
}

static int	op_mul(int count, ...)
{
	va_list	ap;
	int		total;
	int		i;

	va_start(ap, count);
	total = 1;
	i = 0;
	while (i < count)
	{
		total *= va_arg(ap, int);
		i++;
	}
	va_end(ap);
	return (total);
}

static int	op_avg(int count, ...)
{
	va_list	ap;
	long	total;
	int		i;

	va_start(ap, count);
	total = 0;
	i = 0;
	while (i < count)
	{
		total += va_arg(ap, int);
		i++;
	}
	va_end(ap);
	if (count == 0)
		return (0);
	if (total < 0 && total % count != 0)
		return ((int)(total / count - 1));
	return ((int)(total / count));
}

static const t_op	*find_op(const char *name)
{
	static const t_op	ops[] = {
	{"sum", op_sum},
	{"mul", op_mul},
	{"avg", op_avg},
	{NULL, NULL}
	};
	int					i;
	size_t				len;

	i = 0;
	while (ops[i].name)
	{
		len = ft_strlen(ops[i].name);
		if (ft_strlen(name) == len
			&& ft_strncmp(ops[i].name, name, len + 1) == 0)
			return (&ops[i]);
		i++;
	}
	return (NULL);
}

static int	is_valid_int(const char *s)
{
	int	i;

	i = 0;
	if (!s || !s[0])
		return (0);
	if (s[0] == '+' || s[0] == '-')
		i = 1;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (!ft_isdigit((unsigned char)s[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	parse_numbers(int count, char **argv, int *out)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (!is_valid_int(argv[i]))
		{
			ft_putstr_fd("Error: invalid number: ", 2);
			ft_putstr_fd(argv[i], 2);
			ft_putchar_fd('\n', 2);
			return (0);
		}
		out[i] = ft_atoi(argv[i]);
		i++;
	}
	return (1);
}

static int	dispatch(const t_op *op, int n, int *v)
{
	switch (n)
	{
		case 1: return (op->fn(1, v[0]));
		case 2: return (op->fn(2, v[0], v[1]));
		case 3: return (op->fn(3, v[0], v[1], v[2]));
		case 4: return (op->fn(4, v[0], v[1], v[2], v[3]));
		case 5: return (op->fn(5, v[0], v[1], v[2], v[3], v[4]));
		case 6: return (op->fn(6, v[0], v[1], v[2], v[3], v[4], v[5]));
		case 7: return (op->fn(7, v[0], v[1], v[2], v[3], v[4], v[5], v[6]));
		case 8: return (op->fn(8, v[0], v[1], v[2], v[3], v[4], v[5], v[6],
							v[7]));
		case 9: return (op->fn(9, v[0], v[1], v[2], v[3], v[4], v[5], v[6],
							v[7], v[8]));
		case 10: return (op->fn(10, v[0], v[1], v[2], v[3], v[4], v[5], v[6],
							v[7], v[8], v[9]));
		case 11: return (op->fn(11, v[0], v[1], v[2], v[3], v[4], v[5], v[6],
							v[7], v[8], v[9], v[10]));
		case 12: return (op->fn(12, v[0], v[1], v[2], v[3], v[4], v[5], v[6],
							v[7], v[8], v[9], v[10], v[11]));
		case 13: return (op->fn(13, v[0], v[1], v[2], v[3], v[4], v[5], v[6],
							v[7], v[8], v[9], v[10], v[11], v[12]));
		case 14: return (op->fn(14, v[0], v[1], v[2], v[3], v[4], v[5], v[6],
							v[7], v[8], v[9], v[10], v[11], v[12], v[13]));
		case 15: return (op->fn(15, v[0], v[1], v[2], v[3], v[4], v[5], v[6],
							v[7], v[8], v[9], v[10], v[11], v[12], v[13],
							v[14]));
		case 16: return (op->fn(16, v[0], v[1], v[2], v[3], v[4], v[5], v[6],
							v[7], v[8], v[9], v[10], v[11], v[12], v[13],
							v[14], v[15]));
	}
	return (op->fn(n, v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7],
			v[8], v[9], v[10], v[11], v[12], v[13], v[14], v[15],
			v[16], v[17], v[18], v[19], v[20], v[21], v[22], v[23],
			v[24], v[25], v[26], v[27], v[28], v[29], v[30], v[31]));
}

static int	run(const t_op *op, int count, char **nums_argv)
{
	int	*nums;
	int	result;

	if (count < 1)
	{
		ft_putstr_fd("Error: at least one number required\n", 2);
		return (1);
	}
	if (count > MAX_NUMS)
	{
		ft_putstr_fd("Error: too many numbers (max ", 2);
		ft_putnbr_fd(MAX_NUMS, 2);
		ft_putstr_fd(")\n", 2);
		return (1);
	}
	nums = (int *)malloc(sizeof(int) * (size_t)count);
	if (!nums)
	{
		ft_putstr_fd("Error: allocation failed\n", 2);
		return (1);
	}
	if (!parse_numbers(count, nums_argv, nums))
	{
		free(nums);
		return (1);
	}
	result = dispatch(op, count, nums);
	ft_putnbr_fd(result, 1);
	ft_putchar_fd('\n', 1);
	free(nums);
	return (0);
}

int	main(int argc, char **argv)
{
	const t_op	*op;

	if (argc < 3)
	{
		ft_putstr_fd("Usage: ", 2);
		if (argc >= 1)
			ft_putstr_fd(argv[0], 2);
		else
			ft_putstr_fd("calc", 2);
		ft_putstr_fd(" <sum|mul|avg> <num> [num...]\n", 2);
		return (1);
	}
	op = find_op(argv[1]);
	if (!op)
	{
		ft_putstr_fd("Error: unknown operation: ", 2);
		ft_putstr_fd(argv[1], 2);
		ft_putchar_fd('\n', 2);
		return (1);
	}
	return (run(op, argc - 2, &argv[2]));
}
