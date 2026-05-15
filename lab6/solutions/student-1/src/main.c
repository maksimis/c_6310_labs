#include "../inc/txtfile.h"

int	main(int argc, char **argv)
{
	char	**lines;
	char	**result;

	if (argc != 3)
	{
		ft_putendl_fd("Usage: ./txtfile <filename> <pattern>", 2);
		return (1);
	}

	lines = read_file(argv[1]);
	if (!lines)
	{
		ft_putendl_fd("Error: cannot read file", 2);
		return (1);
	}

	ft_putendl_fd("Original file:", 1);
	print_lines(lines);

	result = grep_lines(lines, argv[2]);
	if (!result)
	{
		free_lines(lines);
		ft_putendl_fd("Error: grep failed", 2);
		return (1);
	}

	ft_putendl_fd("Matched lines:", 1);
	print_lines(result);

	free_lines(lines);
	free_lines(result);

	return (0);
}
