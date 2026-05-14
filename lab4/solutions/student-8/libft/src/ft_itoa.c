#include "libft.h"

char *ft_itoa(int n)
{
	char		*str;
	unsigned int	num;
	int		len;
	int		sign;

	sign = 0;
	if (n < 0)
		sign = 1;
	if (n == 0)
	{
		str = (char *)malloc(2);
		if (!str)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	num = (n < 0) ? -(unsigned int)n : (unsigned int)n;
	len = 0;
	while (num)
	{
		num /= 10;
		len++;
	}
	len += sign;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	num = (n < 0) ? -(unsigned int)n : (unsigned int)n;
	while (len-- > sign)
	{
		str[len] = (num % 10) + '0';
		num /= 10;
	}
	if (sign)
		str[0] = '-';
	return (str);
}