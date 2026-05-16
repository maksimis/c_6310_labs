#include "libft.h"

size_t ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t len_dst;
    size_t len_src;
    size_t i;

    if (!dst || !src)
        return (0);
    len_dst = ft_strlen(dst);
    len_src = ft_strlen(src);
    if (size <= len_dst)
        return (size + len_src);
    i = 0;
    while (src[i] && (len_dst + i) < size - 1)
    {
        dst[len_dst + i] = src[i];
        i++;
    }
    dst[len_dst + i] = '\0';
    return (len_dst + len_src);
}