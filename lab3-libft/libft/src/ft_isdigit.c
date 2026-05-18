//Проверяет, является ли символ цифрой
#include "libft.h"

int ft_isdigit(int c)
{
    return (c >= '0' && c <= '9');
}