#include "libft.h"

void *ft_memset(void *s, int c, size_t n)
{
    unsigned char *ptr;

    if (!s)
        return (NULL);
    ptr = (unsigned char *)s;
    while (n--)
        *ptr++ = (unsigned char)c;
    return (s);
}