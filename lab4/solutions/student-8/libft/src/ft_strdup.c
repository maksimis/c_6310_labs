#include "libft.h"

size_t ft_strlen(const char *s);

char *ft_strdup(const char *s)
{
    char *dup;
    size_t len;
    size_t i;

    if (s == NULL)
        return (NULL);
    len = ft_strlen(s);
    dup = (char *)malloc(sizeof(char) * (len + 1));
    if (dup == NULL)
        return (NULL);
    i = 0;
    while (i < len)
    {
        dup[i] = s[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}