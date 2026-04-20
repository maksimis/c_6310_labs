#include "libft.h"

char *ft_strdup(const char *s)
{
    char *result;
    size_t len;

    if (!s)
        return (NULL);
    len = ft_strlen(s);
    result = (char *)malloc(len + 1);
    if (!result)
        return (NULL);
    ft_memcpy(result, s, len + 1);
    return (result);
}
