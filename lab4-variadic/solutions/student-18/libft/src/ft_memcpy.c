//Копирует память
#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;
    size_t i = 0;
    
    if (!dest && !src)
        return (NULL);
    while (i < n)
    {
        d[i] = s[i];
        i++;
    }
    return (dest);
}