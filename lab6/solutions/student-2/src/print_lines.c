#include "txtfile.h"

void print_lines(char **lines)
{
    size_t i;

    if (!lines)
        return;
    i = 0;
    while (lines[i])
    {
        ft_putendl_fd(lines[i], 1);
        i++;
    }
}
