#include "libft.h"
#include <stdarg.h>

typedef int	(*t_func)(int *, int);

typedef struct s_op
{
	char	*name;
	t_func	func;
	int		metric;
}	t_op;

/*
** Variadic function
*/
int	compute(int metric, int count, ...)
{
	va_list	args;
	int		i;
	int		val;
	int		res;

	if (count <= 0)
		return (0);
	va_start(args, count);
	res = va_arg(args, int);
	i = 1;
	while (i < count)
	{
		val = va_arg(args, int);
		if (metric == 0 && val < res)
			res = val;
		else if (metric == 1 && val > res)
			res = val;
		else if (metric == 2 || metric == 3)
			res += val;
		i++;
	}
	va_end(args);
	if (metric == 3)
		return (res / count);
	return (res);
}

int	ft_min_arr(int *arr, int count)
{
	int	i;
	int	min;

	min = arr[0];
	i = 1;
	while (i < count)
	{
		if (arr[i] < min)
			min = arr[i];
		i++;
	}
	return (min);
}

int	ft_max_arr(int *arr, int count)
{
	int	i;
	int	max;

	max = arr[0];
	i = 1;
	while (i < count)
	{
		if (arr[i] > max)
			max = arr[i];
		i++;
	}
	return (max);
}

int	ft_sum_arr(int *arr, int count)
{
	int	i;
	int	sum;

	sum = 0;
	i = 0;
	while (i < count)
	{
		sum += arr[i];
		i++;
	}
	return (sum);
}

int	ft_avg_arr(int *arr, int count)
{
	return (ft_sum_arr(arr, count) / count);
}

t_func	get_func(char *name)
{
	t_op	ops[5];
	int		i;

	ops[0] = (t_op){"min", ft_min_arr, 0};
	ops[1] = (t_op){"max", ft_max_arr, 1};
	ops[2] = (t_op){"sum", ft_sum_arr, 2};
	ops[3] = (t_op){"avg", ft_avg_arr, 3};
	ops[4] = (t_op){NULL, NULL, -1};

	i = 0;
	while (ops[i].name)
	{
		if (ft_strncmp(name, ops[i].name, 4) == 0)
			return (ops[i].func);
		i++;
	}
	return (NULL);
}

int	get_metric(char *name)
{
	t_op	ops[5];
	int		i;

	ops[0] = (t_op){"min", ft_min_arr, 0};
	ops[1] = (t_op){"max", ft_max_arr, 1};
	ops[2] = (t_op){"sum", ft_sum_arr, 2};
	ops[3] = (t_op){"avg", ft_avg_arr, 3};
	ops[4] = (t_op){NULL, NULL, -1};

	i = 0;
	while (ops[i].name)
	{
		if (ft_strncmp(name, ops[i].name, 4) == 0)
			return (ops[i].metric);
		i++;
	}
	return (-1);
}

int	main(int argc, char **argv)
{
	int		*nums;
	int		count;
	int		i;
	t_func	func;
	int		result;
	int		metric;

	if (argc < 3)
		return (ft_putstr_fd("Error: not enough arguments\n", 2), 1);

	func = get_func(argv[1]);
	metric = get_metric(argv[1]);

	if (!func || metric == -1)
		return (ft_putstr_fd("Error: unknown metric\n", 2), 1);

	count = argc - 2;

	nums = (int *)malloc(sizeof(int) * count);
	if (!nums)
		return (ft_putstr_fd("Error: malloc failed\n", 2), 1);

	i = 0;
	while (i < count)
	{
		nums[i] = ft_atoi(argv[i + 2]);
		i++;
	}

	/*
	** Использование указателя на функцию
	*/
	func(nums, count);

	/*
	** Использование variadic function
	*/
	if (count == 1)
		result = compute(metric, 1,
				nums[0]);
	else if (count == 2)
		result = compute(metric, 2,
				nums[0], nums[1]);
	else if (count == 3)
		result = compute(metric, 3,
				nums[0], nums[1], nums[2]);
	else if (count == 4)
		result = compute(metric, 4,
				nums[0], nums[1], nums[2], nums[3]);
	else
		result = compute(metric, 5,
				nums[0], nums[1], nums[2], nums[3], nums[4]);

	ft_putnbr_fd(result, 1);
	ft_putchar_fd('\n', 1);

	free(nums);
	return (0);
}