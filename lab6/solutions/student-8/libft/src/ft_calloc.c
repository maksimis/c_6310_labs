#include "libft.h"

void *ft_calloc(size_t nmemb, size_t size)
{
    void    *ptr;
    size_t  total_size;

    if (nmemb != 0 && size != 0 && nmemb > (size_t)-1 / size)
        return (NULL);

    total_size = nmemb * size;
    ptr = malloc(total_size);
    if (ptr == NULL)
        return (NULL);

    if (total_size > 0)
    {
        unsigned char *byte_ptr = (unsigned char *)ptr;
        size_t i = 0;
        while (i < total_size)
        {
            byte_ptr[i] = 0;
            i++;
        }
    }

    return (ptr);
}