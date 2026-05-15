#include "../inc/txtfile.h"
#include "../libft/inc/libft.h"

void print_lines(char **lines)
{
    int i;

    if (!lines)
    {
        ft_putendl_fd("NULL lines", 1);
        return;
    }
    i = 0;
    while (lines[i])
    {
        ft_putendl_fd(lines[i], 1);
        i++;
    }
}