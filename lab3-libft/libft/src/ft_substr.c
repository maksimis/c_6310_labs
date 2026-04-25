#include "libft.h"

size_t ft_strlen(const char *s);

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *substr;
    size_t s_len;
    size_t actual_len;
    size_t i;

    if (!s)
        return (NULL);
    s_len = ft_strlen(s);
    if (start >= s_len)
    {
        substr = (char *)malloc(1);
        if (!substr)
            return (NULL);
        substr[0] = '\0';
        return (substr);
    }
    if (start + len > s_len)
        actual_len = s_len - start;
    else
        actual_len = len;
    substr = (char *)malloc(actual_len + 1);
    if (!substr)
        return (NULL);
    i = 0;
    while (i < actual_len)
    {
        substr[i] = s[start + i];
        i++;
    }
    substr[actual_len] = '\0';
    return (substr);
}