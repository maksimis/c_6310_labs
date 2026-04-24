//Разбивает строку по разделителю
#include "libft.h"

static size_t count_words(char const *s, char c)
{
    size_t count = 0;
    int in_word = 0;
    
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

static char *get_word(char const *s, char c)
{
    size_t len = 0;
    char *word;
    
    while (s[len] && s[len] != c)
        len++;
    word = (char *)malloc(sizeof(char) * (len + 1));
    if (!word)
        return (NULL);
    ft_strlcpy(word, s, len + 1);
    return (word);
}

static void free_all(char **result, size_t i)
{
    while (i > 0)
    {
        i--;
        free(result[i]);
    }
    free(result);
}

char **ft_split(char const *s, char c)
{
    char **result;
    size_t words;
    size_t i;
    
    if (!s)
        return (NULL);
    words = count_words(s, c);
    result = (char **)malloc(sizeof(char *) * (words + 1));
    if (!result)
        return (NULL);
    i = 0;
    while (*s)
    {
        if (*s != c)
        {
            result[i] = get_word(s, c);
            if (!result[i])
            {
                free_all(result, i);
                return (NULL);
            }
            i++;
            while (*s && *s != c)
                s++;
        }
        else
            s++;
    }
    result[i] = NULL;
    return (result);
}