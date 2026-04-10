//Преобразует строку в целое число
#include "libft.h"

int ft_atoi(const char *nptr)
{
    int i = 0;
    int sign = 1;
    int result = 0;
    
    while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
        || nptr[i] == '\r' || nptr[i] == '\v' || nptr[i] == '\f')
        i++;
    if (nptr[i] == '+' || nptr[i] == '-')
    {
        if (nptr[i] == '-')
            sign = -1;
        i++;
    }
    while (nptr[i] >= '0' && nptr[i] <= '9')
    {
        result = result * 10 + (nptr[i] - '0');
        i++;
    }
    return (result * sign);
}