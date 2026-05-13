#include "txtfile.h"

int	main(int argc, char **argv)
{
	char	**lines;
	char	**matches;

	if (argc != 3)
	{
		print_error("usage: ./grep_file <file> <pattern>");
		return (1);
	}
	lines = read_file(argv[1]);
	if (!lines)
	{
		print_error("cannot read file");
		return (1);
	}
	matches = grep_lines(lines, argv[2]);
	if (!matches)
	{
		free_lines(lines);
		print_error("grep failed");
		return (1);
	}
	print_lines(matches);
	free_lines(lines);
	free_lines(matches);
	return (0);
}