#include "../inc/libft.h"

typedef struct s_operation
{
	char	*name;
	int		(*func)(int, int *);
}t_operation;

int	calc_sum(int count, int *nums)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (i < count)
	{
		sum += nums[i];
		i++;
	}
	return (sum);
}

int	calc_mul(int count, int *nums)
{
	int	i;
	int	result;

	i = 0;
	result = 1;
	while (i < count)
	{
		result *= nums[i];
		i++;
	}
	return (result);
}

int	calc_avg(int count, int *nums)
{
	return (calc_sum(count, nums) / count);
}

int	variadic_sum(int count, ...)
{
	va_list	args;
	int		i;
	int		sum;

	va_start(args, count);
	i = 0;
	sum = 0;
	while (i < count)
	{
		sum += va_arg(args, int);
		i++;
	}
	va_end(args);
	return (sum);
}

int	find_operation(char *name, t_operation *ops, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (ft_strncmp(name, ops[i].name,
				ft_strlen(ops[i].name) + 1) == 0)
			return (i);
		i++;
	}
	return (-1);
}

int	parse_numbers(int argc, char **argv, int *numbers)
{
	int	i;

	i = 0;
	while (i < argc - 2)
	{
		numbers[i] = ft_atoi(argv[i + 2]);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_operation	ops[3];
	int			*numbers;
	int			op_index;
	int			result;

	if (argc < 4)
	{
		ft_putendl_fd("Error: invalid arguments", 2);
		return (1);
	}
	ops[0].name = "sum";
	ops[0].func = calc_sum;
	ops[1].name = "mul";
	ops[1].func = calc_mul;
	ops[2].name = "avg";
	ops[2].func = calc_avg;
	op_index = find_operation(argv[1], ops, 3);
	if (op_index == -1)
	{
		ft_putendl_fd("Error: unknown operation", 2);
		return (1);
	}
	numbers = (int *)malloc(sizeof(int) * (argc - 2));
	if (!numbers)
	{
		ft_putendl_fd("Error: malloc failed", 2);
		return (1);
	}
	parse_numbers(argc, argv, numbers);
	result = ops[op_index].func(argc - 2, numbers);
	ft_putnbr_fd(result, 1);
	ft_putchar_fd('\n', 1);
	free(numbers);
	variadic_sum(3, 1, 2, 3);
	return (0);
}
