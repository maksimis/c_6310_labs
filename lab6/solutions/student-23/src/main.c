#include "../inc/txtfile.h"

int	main(int argc, char **argv)
{
	char	**lines;
	char	**result;

	if (argc != 4)
	{
		ft_putendl_fd(
			"Usage: ./replace_file <filename> <old> <new>",
			2);
		return (1);
	}
	lines = read_file(argv[1]);
	if (!lines)
	{
		ft_putendl_fd("Error: cannot read file", 2);
		return (1);
	}
	result = replace_substr(lines, argv[2], argv[3]);
	if (!result)
	{
		free_lines(lines);
		ft_putendl_fd("Error: replace failed", 2);
		return (1);
	}
	ft_putendl_fd("Original file:", 1);
	print_lines(lines);
	ft_putendl_fd("", 1);
	ft_putendl_fd("Result:", 1);
	print_lines(result);
	free_lines(lines);
	free_lines(result);
	return (0);
}