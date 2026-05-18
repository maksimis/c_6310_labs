#include "libft.h"

static size_t count_words(char const *s, char c)
{
    size_t count;
    size_t i;

    count = 0;
    i = 0;
    while (s[i])
    {
        while (s[i] == c)
            i++;
        if (s[i])
            count++;
        while (s[i] && s[i] != c)
            i++;
    }
    return (count);
}

static void free_array(char **array, size_t size)
{
    size_t i;

    i = 0;
    while (i < size)
    {
        free(array[i]);
        i++;
    }
    free(array);
}

char **ft_split(char const *s, char c)
{
    char **result;
    size_t word_count;
    size_t i;
    size_t j;
    size_t word_len;
    size_t word_index;

    if (!s)
        return (NULL);
    word_count = count_words(s, c);
    result = (char **)malloc((word_count + 1) * sizeof(char *));
    if (!result)
        return (NULL);
    i = 0;
    word_index = 0;
    while (s[i])
    {
        while (s[i] == c)
            i++;
        if (s[i])
        {
            j = i;
            while (s[j] && s[j] != c)
                j++;
            word_len = j - i;
            result[word_index] = ft_substr(s, i, word_len);
            if (!result[word_index])
            {
                free_array(result, word_index);
                return (NULL);
            }
            word_index++;
            i = j;
        }
    }
    result[word_index] = NULL;
    return (result);
}
