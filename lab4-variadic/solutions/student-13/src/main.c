#include "calc.h"

static int	parse_numbers(int argc, char **argv, int *numbers)
{
	int	i;

	i = 2;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
			return (0);
		numbers[i - 2] = ft_atoi(argv[i]);
		i++;
	}
	return (1);
}

static int	run_operation(char *name, int count, int *numbers)
{
	t_operation	operation;
	int			initial;
	int			result;
	int			i;

	if (!select_operation(name, &operation, &initial))
	{
		print_error("unknown operation");
		return (1);
	}
	result = initial;
	i = 0;
	while (i < count)
	{
		result = calculate(1, operation, result, numbers[i]);
		i++;
	}
	if (ft_strncmp(name, "avg", 4) == 0 && count > 0)
		result = result / count;
	ft_putnbr_fd(result, 1);
	ft_putchar_fd('\n', 1);
	return (0);
}

int	main(int argc, char **argv)
{
	int	numbers[1024];
	int	count;

	if (argc < 3)
	{
		print_error("usage: ./calc <sum|mul|avg> [numbers...]");
		return (1);
	}
	count = argc - 2;
	if (count > 1024)
	{
		print_error("too many numbers");
		return (1);
	}
	if (!parse_numbers(argc, argv, numbers))
	{
		print_error("invalid number");
		return (1);
	}
	return (run_operation(argv[1], count, numbers));
}