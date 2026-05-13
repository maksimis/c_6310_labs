#include "txtfile.h"

int	main(int argc, char **argv)
{
	char	**lines;
	char	**result;
	int		start;
	int		end;

	if (argc != 4)
	{
		ft_putendl_fd("Usage: ./cut_file <filename> <start> <end>", 2);
		return (1);
	}
	lines = read_file(argv[1]);
	if (!lines)
	{
		ft_putendl_fd("Error: cannot read file or file is empty", 2);
		return (1);
	}
	start = ft_atoi(argv[2]);
	end = ft_atoi(argv[3]);
	result = cut_lines(lines, start, end);
	if (!result)
	{
		ft_putendl_fd("Error: invalid range", 2);
		free_lines(lines);
		return (1);
	}
	print_lines(result);
	free_lines(lines);
	free_lines(result);
	return (0);
}