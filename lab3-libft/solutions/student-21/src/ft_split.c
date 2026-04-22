#include "libft.h"

static size_t count_words(char const *s, char c)
{
    size_t  count;
    int     in_word;

    count = 0;
    in_word = 0;
    while (*s)
    {
        if (*s != c && !in_word)
        {
            in_word = 1;
            count++;
        }
        else if (*s == c)
            in_word = 0;
        s++;
    }
    return (count);
}

static char *extract_word(char const *s, char c, size_t *pos)
{
    size_t  start;
    size_t  len;

    while (s[*pos] && s[*pos] == c)
        (*pos)++;
    start = *pos;
    len = 0;
    while (s[*pos] && s[*pos] != c)
    {
        len++;
        (*pos)++;
    }
    return (ft_substr(s, (unsigned int)start, len));
}

char **ft_split(char const *s, char c)
{
    char    **result;
    size_t  words;
    size_t  i;
    size_t  pos;

    if (!s)
        return (NULL);
    words = count_words(s, c);
    result = malloc((words + 1) * sizeof(char *));
    if (!result)
        return (NULL);
    i = 0;
    pos = 0;
    while (i < words)
    {
        result[i] = extract_word(s, c, &pos);
        if (!result[i])
        {
            while (i > 0)
                free(result[--i]);
            free(result);
            return (NULL);
        }
        i++;
    }
    result[words] = NULL;
    return (result);
}
