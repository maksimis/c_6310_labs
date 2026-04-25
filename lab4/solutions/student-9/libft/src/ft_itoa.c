#include "libft.h"

static int count_digits(long long num)
{
    int digits;

    digits = 0;
    if (num == 0)
        return (1);
    while (num != 0)
    {
        num /= 10;
        digits++;
    }
    return (digits);
}

char *ft_itoa(int n)
{
    char *result;
    long long num;
    int digits;
    int is_negative;

    is_negative = (n < 0);
    num = n;
    if (is_negative)
        num = -num;
    digits = count_digits(num);
    if (is_negative)
        digits++;
    result = (char *)malloc(digits + 1);
    if (!result)
        return (NULL);
    result[digits] = '\0';
    if (n == 0)
        result[0] = '0';
    else
    {
        if (is_negative)
            result[0] = '-';
        while (num != 0)
        {
            digits--;
            result[digits] = (num % 10) + '0';
            num /= 10;
        }
    }
    return (result);
}