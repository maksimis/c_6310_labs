#include "libft.h"

char *ft_strnstr(const char *big, const char *little, size_t len)
{
    size_t i;
    size_t little_len;

    if (*little == '\0')
    {
        return (char *)big;
    }
    little_len = ft_strlen(little);
    for (i = 0; i + little_len <= len && big[i]; i++)
    {
        if (ft_strncmp(&big[i], little, little_len) == 0)
        {
            return (char *)&big[i];
        }
    }
    return NULL;
}