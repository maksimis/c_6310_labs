//Ищет подстроку в строке с ограничением
#include "libft.h"

char *ft_strnstr(const char *big, const char *little, size_t len)
{
    size_t i, j;
    
    if (*little == '\0')
        return ((char *)big);
    i = 0;
    while (big[i] && i < len)
    {
        j = 0;
        while (little[j] && big[i + j] == little[j] && i + j < len)
            j++;
        if (little[j] == '\0')
            return ((char *)&big[i]);
        i++;
    }
    return (NULL);
}