//Ищет символ в строке (справа)
#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
    int i = ft_strlen(s);
    while (i >= 0)
    {
        if (s[i] == (char)c)
            return ((char *)&s[i]);
        i--;
    }
    return (NULL);
}