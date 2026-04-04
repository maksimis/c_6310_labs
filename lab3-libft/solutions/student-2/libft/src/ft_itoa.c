#include "libft.h"

static int int_len(long nbr);
static char *pre_conv(int len);

char *ft_itoa(int n)
{
    int len;
    int i;
    char*result;
    long nbr;

    nbr = (long)n;
    len = int_len(nbr);
    result = pre_conv(len);
    if (!result)
        return (NULL);
    result[len] = '\0';
    i = len - 1;
    if (nbr < 0)
    {
        result[0] = '-';
        nbr = 0 - nbr;
    }
    while (nbr != 0)
    {
        result[i] = (char)((nbr % 10) + '0');
        nbr /= 10;
        i--;
    }
    return (result);
}

static char	*pre_conv(int len)
{
    char *tmp;

    tmp = (char *)malloc((len + 1) * sizeof(char));
    if (!tmp)
        return (NULL);
    tmp[0] = '0';
    return (tmp);
}

static int	int_len(long nbr)
{
    int	count;

    count = 0;
    if (nbr < 0)
    {
        count++;
        nbr = -nbr;
    }
    if (nbr == 0)
        count++;
    while (nbr != 0)
    {
        nbr /= 10;
        count++;
    }
    return (count);
}