//Применяет функцию к каждому символу (in-place)
#include "libft.h"

void ft_striteri(char *s, void (*f)(unsigned int, char*))
{
    size_t i = 0;
    
    if (!s || !f)
        return;
    while (s[i])
    {
        f(i, &s[i]);
        i++;
    }
}