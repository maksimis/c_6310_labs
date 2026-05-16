#include "txtfile.h"

char **cut_lines(char **lines, int start, int end)
{
    size_t total;
    size_t i;
    int index;
    char **result;

    if (!lines || start <= 0 || end < start)
        return (NULL);
    total = 0;
    while (lines[total])
        total++;
    if ((size_t)end > total)
        return (NULL);
    result = ft_calloc((end - start + 2), sizeof(char *));
    if (!result)
        return (NULL);
    index = 0;
    i = (size_t)(start - 1);
    while (i < (size_t)end)
    {
        result[index] = ft_strdup(lines[i]);
        if (!result[index])
        {
            free_lines(result);
            return (NULL);
        }
        index++;
        i++;
    }
    result[index] = NULL;
    return (result);
}
