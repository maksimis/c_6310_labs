#include "libft.h"

int	ft_atoi(const char *nptr)
{
	long	result;
	int		sign;
	size_t	i;

	if (!nptr)
		return (0);
	result = 0;
	sign = 1;
	i = 0;
	while (ft_isspace((unsigned char)nptr[i]))
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
	return ((int)(result * sign));
}
