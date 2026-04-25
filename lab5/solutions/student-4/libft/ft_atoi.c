#include "libft.h"

int ft_atoi(const char *nptr)
{
    int result;
    int sign;
    int i;

    result = 0;
    sign = 1;
    i = 0;
    while (ft_isspace(nptr[i]))
        i++;
    if (nptr[i] == '-' || nptr[i] == '+')
    {
        if (nptr[i] == '-')
            sign = -1;
        i++;
    }
    while (ft_isdigit(nptr[i]))
    {
        result = result * 10 + (nptr[i] - '0');
        i++;
    }
    return (result * sign);
}
