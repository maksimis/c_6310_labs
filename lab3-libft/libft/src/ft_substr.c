#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *result;
    size_t s_len;
    size_t i;

    if (!s)
        return (NULL);
    s_len = ft_strlen(s);
    if (start >= s_len)
        return (ft_strdup(""));
    if (len > s_len - start)
        len = s_len - start;
    result = (char *)malloc(len + 1);
    if (!result)
        return (NULL);
    i = 0;
    while (i < len)
    {
        result[i] = s[start + i];
        i++;
    }
    result[i] = '\0';
    return (result);
}
