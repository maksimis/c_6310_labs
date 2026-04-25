#include "libft.h"

int ft_atoi(const char *nptr) {
    int i = 0;
    while (ft_isspace(nptr[i]))
        i++;
    
    int sign = 1;  
    if (nptr[i] == '+' || nptr[i] == '-')
    {
        if (nptr[i] == '-')
            sign = -1;  
        i++;  
    }

    int result = 0; 
    while (ft_isdigit(nptr[i]))
    {
        result = result * 10 + (nptr[i] - '0');
        i++;
    }
    return (result * sign);
}