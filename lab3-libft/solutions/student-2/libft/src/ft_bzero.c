#include "libft.h"

void ft_bzero(void *s, size_t n)
{
    size_t i;
    unsigned char *ptr;

    ptr = (unsigned char *)s;
    for (i = 0; i < n; i++)
    {
        ptr[i] = 0;
    }
}