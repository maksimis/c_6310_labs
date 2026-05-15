#include "txtfile.h"

static void	print_error(char *message)
{
	ft_putendl_fd(message, 2);
}

int	main(int argc, char **argv)
{
	char	**lines;

	if (argc != 2)
	{
		print_error("Usage: ./analyze_file <filename>");
		return (1);
	}
	lines = read_file(argv[1]);
	if (!lines)
	{
		print_error("Error: cannot read file");
		return (1);
	}
    ft_putendl_fd("File content:", 1);
	print_lines(lines);
	ft_putendl_fd("Analysis:", 1);
	ft_putstr_fd("Lines: ", 1);
	ft_putnbr_fd(count_lines(lines), 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Words: ", 1);
	ft_putnbr_fd(count_words(lines), 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Characters(without |n and |0): ", 1);
	ft_putnbr_fd(count_chars(lines), 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Longest line length(without |n and |0): ", 1);
	ft_putnbr_fd(longest_line_length(lines), 1);
	ft_putchar_fd('\n', 1);
	free_lines(lines);
	return (0);
}