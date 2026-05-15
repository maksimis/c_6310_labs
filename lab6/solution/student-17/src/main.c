#include "../inc/txtfile.h"
#include "../libft/inc/libft.h"

int main(int argc, char **argv)
{
    char    **lines;
    char    **result;

    if (argc != 3)
    {
        ft_putendl_fd("Usage: ./txtfile <filename> <pattern>", 2);
        return (1);
    }
    lines = read_file(argv[1]);
    if (!lines)
    {
        ft_putendl_fd("Error: failed to read file or file is empty", 2);
        return (1);
    }
    ft_putchar_fd('\n', 1);
    ft_putendl_fd("=== Original file ===", 1);
    ft_putchar_fd('\n', 1);
    print_lines(lines);
    result = grep_lines(lines, argv[2]);
    if (!result)
    {
        ft_putendl_fd("Error: grep_lines failed", 2);
        free_lines(lines);
        return (1);
    }
    
    ft_putendl_fd("\n=== Matching lines ===", 1);
    ft_putchar_fd('\n', 1);
    print_lines(result);
    free_lines(lines);
    free_lines(result);
    ft_putchar_fd('\n', 1);
    return (0);
}