#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    size_t len;
    size_t i;
    char *result;

    if (!s)
        return (NULL);
    len = 0;
    while (s[len])
        len++;
    result = (char *)malloc(sizeof(char) * (len + 1));
    if (!result)
        return (NULL);
    i = 0;
    while (i < len)
    {
        result[i] = f(i, s[i]);
        i++;
    }
    result[len] = '\0';
    return (result);
}