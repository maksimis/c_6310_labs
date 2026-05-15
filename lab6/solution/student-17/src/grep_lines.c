#include "../inc/txtfile.h"
#include "../libft/inc/libft.h"
#include <stdlib.h>

static int count_matching_lines(char **lines, const char *pattern)
{
    int count;
    int i;

    if (!lines || !pattern)
        return (-1);
    count = 0;
    i = 0;
    while (lines[i])
    {
        // Используем ft_strnstr из libft
        if (ft_strnstr(lines[i], pattern, ft_strlen(lines[i])) != NULL)
            count++;
        i++;
    }
    return (count);
}

char **grep_lines(char **lines, const char *pattern)
{
    char    **result;
    int     match_count;
    int     i;
    int     j;

    if (!lines || !pattern)
        return (NULL);
    match_count = count_matching_lines(lines, pattern);
    if (match_count <= 0)
    {
        result = (char **)ft_calloc(1, sizeof(char *));
        if (!result)
            return (NULL);
        result[0] = NULL;
        return (result);
    }
    result = (char **)ft_calloc(match_count + 1, sizeof(char *));
    if (!result)
        return (NULL);
    i = 0;
    j = 0;
    while (lines[i])
    {
        if (ft_strnstr(lines[i], pattern, ft_strlen(lines[i])) != NULL)
        {
            result[j] = ft_strdup(lines[i]);  // ft_strdup уже есть в libft
            if (!result[j])
            {
                free_lines(result);
                return (NULL);
            }
            j++;
        }
        i++;
    }
    result[j] = NULL;
    return (result);
}