#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
    char    *result;
    size_t  start;
    size_t  end;
    size_t  i;
    
    if (!s1)
        return (NULL);
    if (!set || !*set)
        return (ft_strdup(s1));
    
    start = 0;
    while (s1[start] && ft_strchr(set, s1[start]))
        start++;
    
    end = ft_strlen(s1);
    while (end > start && ft_strchr(set, s1[end - 1]))
        end--;
    
    result = (char *)malloc(end - start + 1);
    if (!result)
        return (NULL);
    
    i = 0;
    while (start < end)
    {
        result[i] = s1[start];
        i++;
        start++;
    }
    result[i] = '\0';
    return (result);
}