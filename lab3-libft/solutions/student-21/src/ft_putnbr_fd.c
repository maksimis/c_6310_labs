#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
    long num;
    char c;

    num = (long)n;
    if (num < 0)
    {
        write(fd, "-", 1);
        num = -num;
    }
    if (num >= 10)
        ft_putnbr_fd((int)(num / 10), fd);
    c = (char)('0' + (num % 10));
    write(fd, &c, 1);
}
