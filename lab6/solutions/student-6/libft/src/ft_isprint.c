//Проверяет, является ли символ печатным
#include "libft.h"

int ft_isprint(int c)
{
    return (c >= 32 && c <= 126);
}