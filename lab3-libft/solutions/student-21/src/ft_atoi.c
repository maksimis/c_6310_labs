#include "libft.h"

int ft_atoi(const char *nptr)
{
    int sign;
    long result;

    if (!nptr)
        return (0);
    sign = 1;
    result = 0;
    while (ft_isspace((unsigned char)*nptr))
        nptr++;
    if (*nptr == '-' || *nptr == '+')
    {
        if (*nptr == '-')
            sign = -1;
        nptr++;
    }
    while (ft_isdigit((unsigned char)*nptr))
    {
        result = result * 10 + (*nptr - '0');
        nptr++;
    }
    return ((int)(result * sign));
}
