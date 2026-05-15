#include "libft.h"

static int	count_digits(int n)
{
	int		count;
	long	nb;

	nb = n;
	if (nb == 0)
		return (1);
	count = 0;
	if (nb < 0)
	{
		count = 1;
		nb = -nb;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nb;

	// Специальная обработка INT_MIN
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));

	nb = n;
	len = count_digits(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nb == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		str[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}