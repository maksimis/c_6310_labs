#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *sub;
    size_t  slen;
    size_t  copy_len;

    if (!s)
        return (NULL);
    slen = ft_strlen(s);
    if (start >= (unsigned int)slen)
        return (ft_strdup(""));
    copy_len = slen - start;
    if (copy_len > len)
        copy_len = len;
    sub = malloc(copy_len + 1);
    if (!sub)
        return (NULL);
    ft_memcpy(sub, s + start, copy_len);
    sub[copy_len] = '\0';
    return (sub);
}
