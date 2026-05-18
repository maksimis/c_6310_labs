//Преобразует число в строку
#include "libft.h"

static int count_digits(int n)
{
    int count = 0;
    
    if (n <= 0)
        count = 1;
    while (n != 0)
    {
        count++;
        n /= 10;
    }
    return (count);
}

static void fill_number(char *str, long n, int len)
{
    str[len] = '\0';
    len--;
    if (n == 0)
        str[0] = '0';
    if (n < 0)
    {
        str[0] = '-';
        n = -n;
    }
    while (n > 0)
    {
        str[len] = (n % 10) + '0';
        n /= 10;
        len--;
    }
}

char *ft_itoa(int n)
{
    char *result;
    int len;
    long num;
    
    num = n;
    len = count_digits(num);
    result = (char *)malloc(sizeof(char) * (len + 1));
    if (!result)
        return (NULL);
    fill_number(result, num, len);
    return (result);
}