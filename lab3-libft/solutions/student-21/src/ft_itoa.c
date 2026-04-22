#include "libft.h"

static int num_len(long n)
{
    int len;

    len = 0;
    if (n <= 0)
        len = 1;
    while (n != 0)
    {
        n /= 10;
        len++;
    }
    return (len);
}

char *ft_itoa(int n)
{
    long    num;
    int     len;
    char    *str;

    num = (long)n;
    len = num_len(num);
    str = malloc(len + 1);
    if (!str)
        return (NULL);
    str[len] = '\0';
    if (num < 0)
    {
        str[0] = '-';
        num = -num;
    }
    if (num == 0)
        str[0] = '0';
    while (num > 0)
    {
        str[--len] = (char)('0' + (num % 10));
        num /= 10;
    }
    return (str);
}
