#include "txtfile.h"

static int  count_lines(char **lines)
{
    int i;

    i = 0;
    while (lines[i])
        i++;
    return (i);
}

char    **cut_lines(char **lines, int start, int end)
{
    int     total;
    int     i;
    int     j;
    char    **result;

    if (!lines || start <= 0 || end < start)
        return (NULL);

    total = count_lines(lines);
    if (start > total || end > total)
        return (NULL);

    result = (char **)ft_calloc((end - start + 2), sizeof(char *));
    if (!result)
        return (NULL);

    i = start - 1;
    j = 0;
    while (i < end)
    {
        result[j] = ft_strdup(lines[i]);
        if (!result[j])
        {
            free_lines(result);
            return (NULL);
        }
        i++;
        j++;
    }
    result[j] = NULL;
    return (result);
}