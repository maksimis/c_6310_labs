#include "libft.h"

static int	ft_len(int n)
{
	int	len;

	len = (n <= 0);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*res;
	long	num;
	int		len;

	num = n;
	len = ft_len(n);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (num < 0)
	{
		res[0] = '-';
		num = -num;
	}
	while (len-- && res[len] != '-')
	{
		res[len] = (num % 10) + '0';
		num /= 10;
	}
	return (res);
}