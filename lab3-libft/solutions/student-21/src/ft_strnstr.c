#include "libft.h"

char *ft_strnstr(const char *big, const char *little, size_t len)
{
    size_t  little_len;
    size_t  i;

    if (!big || !little)
        return (NULL);
    little_len = ft_strlen(little);
    if (little_len == 0)
        return ((char *)big);
    i = 0;
    while (i + little_len <= len && big[i])
    {
        if (ft_strncmp(big + i, little, little_len) == 0)
            return ((char *)(big + i));
        i++;
    }
    return (NULL);
}
