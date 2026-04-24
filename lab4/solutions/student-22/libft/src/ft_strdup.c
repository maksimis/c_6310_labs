#include "libft.h"

char *ft_strdup(const char *s)
{
    char *dup;
    size_t len;

    if (!s)
        return NULL;

    len = ft_strlen(s);
    dup = (char *)malloc(len + 1);
    if (!dup)
    {
        return NULL;
    }
    ft_strlcpy(dup, s, len + 1);
    return dup;
}