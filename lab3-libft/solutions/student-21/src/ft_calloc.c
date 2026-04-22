#include "libft.h"

void *ft_calloc(size_t nmemb, size_t size)
{
    void    *ptr;
    size_t  total;

    if (size != 0 && nmemb > (size_t)-1 / size)
        return (NULL);
    total = nmemb * size;
    ptr = malloc(total);
    if (!ptr)
        return (NULL);
    ft_bzero(ptr, total);
    return (ptr);
}
