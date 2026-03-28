#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	nb;

	if (fd < 0)
		return ;
	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd);
	ft_putchar_fd('0' + (nb % 10), fd);
}