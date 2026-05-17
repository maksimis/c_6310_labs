#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *substr;
    size_t  s_len;
    size_t  sub_len;
    
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
    
    if (len > ft_strlen(s + start))
        sub_len = ft_strlen(s + start);
    else
        sub_len = len;
    
    substr = (char *)malloc(sub_len + 1);
    if (!substr)
        return (NULL);
    
    ft_strlcpy(substr, s + start, sub_len + 1);
    return (substr);
}