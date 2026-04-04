#include "libft.h"

// переводит символ в верхний регистр
int ft_toupper(int c)
{
    if (c >= 'a' && c <= 'z')
        return (c - ('a' - 'A'));

    return c; 
}