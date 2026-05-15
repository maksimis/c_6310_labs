#include "stats.h"

int	get_metric_code(char *name)
{
	int	code;

	code = -1;
	if (ft_strncmp(name, "min", 4) == 0)
		code = METRIC_MIN;
	else if (ft_strncmp(name, "max", 4) == 0)
		code = METRIC_MAX;
	else if (ft_strncmp(name, "sum", 4) == 0)
		code = METRIC_SUM;
	else if (ft_strncmp(name, "avg", 4) == 0)
		code = METRIC_AVG;
	return (code);
}

t_metric_fn	get_metric_function(char *name)
{
	t_metric_fn	func;

	func = 0;
	if (ft_strncmp(name, "min", 4) == 0)
		func = metric_min;
	else if (ft_strncmp(name, "max", 4) == 0)
		func = metric_max;
	else if (ft_strncmp(name, "sum", 4) == 0)
		func = metric_sum;
	else if (ft_strncmp(name, "avg", 4) == 0)
		func = metric_avg;
	return (func);
}

static int	parse_numbers(int count, char **argv, int *nums)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	while (i < count && status == 0)
	{
		if (!parse_int(argv[i + 2], &nums[i]))
			status = print_error("Error: invalid number");
		i++;
	}
	return (status);
}

static int	call_metric(t_metric_fn func, int count, int *nums)
{
	int	result;

	result = 0;
	if (count == 1)
		result = func(count, nums[0]);
	else if (count == 2)
		result = func(count, nums[0], nums[1]);
	else if (count == 3)
		result = func(count, nums[0], nums[1], nums[2]);
	else if (count == 4)
		result = func(count, nums[0], nums[1], nums[2], nums[3]);
	else if (count == 5)
		result = func(count, nums[0], nums[1], nums[2], nums[3], nums[4]);
	else if (count == 6)
		result = func(count, nums[0], nums[1], nums[2], nums[3],
				nums[4], nums[5]);
	else if (count == 7)
		result = func(count, nums[0], nums[1], nums[2], nums[3],
				nums[4], nums[5], nums[6]);
	else if (count == 8)
		result = func(count, nums[0], nums[1], nums[2], nums[3],
				nums[4], nums[5], nums[6], nums[7]);
	else if (count == 9)
		result = func(count, nums[0], nums[1], nums[2], nums[3],
				nums[4], nums[5], nums[6], nums[7], nums[8]);
	else if (count == 10)
		result = func(count, nums[0], nums[1], nums[2], nums[3],
				nums[4], nums[5], nums[6], nums[7], nums[8], nums[9]);
	return (result);
}

static int	run_metric(char *metric_name, int count, char **argv)
{
	t_metric_fn	func;
	int			nums[10];
	int			result;
	int			status;

	func = get_metric_function(metric_name);
	result = 0;
	status = 0;
	if (!func)
		status = print_error("Error: unknown metric");
	else
	{
		status = parse_numbers(count, argv, nums);
		if (status == 0)
		{
			result = call_metric(func, count, nums);
			ft_putnbr_fd(result, 1);
			ft_putchar_fd('\n', 1);
		}
	}
	return (status);
}

int	main(int argc, char **argv)
{
	int	count;
	int	status;

	count = 0;
	status = 0;
	if (argc < 3)
		status = print_error("Error: not enough arguments");
	else
	{
		count = argc - 2;
		if (count <= 0)
			status = print_error("Error: empty number list");
		else if (count > 10)
			status = print_error("Error: too many numbers (max 10)");
		else
			status = run_metric(argv[1], count, argv);
	}
	return (status);
}