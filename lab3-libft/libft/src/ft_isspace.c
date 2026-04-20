#include "libft.h"

int ft_isspace(int c)
{
    if (c == ' ' || c == '\t' || c == '\n')
        return (1);
    if (c == '\v' || c == '\f' || c == '\r')
        return (1);
    return (0);
}
