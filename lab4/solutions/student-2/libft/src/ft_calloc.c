#include "libft.h"

void *ft_calloc(size_t nmemb, size_t size)
{
    void *ptr;

    if (nmemb == 0 || size == 0)
    {
        nmemb = 1;
        size = 1;
    }
    ptr = malloc(nmemb * size);
    if (!ptr)
    {
        return NULL;
    }
    ft_bzero(ptr, nmemb * size);
    return ptr;
}