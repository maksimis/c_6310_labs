#include "libft.h"

static size_t count_words(const char *s, char c)
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

static char *get_word(const char *s, char c)
{
    char    *word;
    size_t  len;
    
    len = 0;
    while (s[len] && s[len] != c)
        len++;
    word = (char *)malloc(len + 1);
    if (!word)
        return (NULL);
    ft_strlcpy(word, s, len + 1);  
    return (word);
}

static void free_array(char **arr, size_t index)
{
    while (index > 0)
    {
        index--;
        free(arr[index]);
    }
    free(arr);
}

char **ft_split(char const *s, char c)
{
    char    **result;
    size_t  word_count;
    size_t  i;
    size_t  k;
    int     in_word;
    
    if (!s)
        return (NULL);
    
    word_count = count_words(s, c);
    result = (char **)malloc((word_count + 1) * sizeof(char *));
    if (!result)
        return (NULL);
    
    i = 0;
    k = 0;
    in_word = 0;
    while (s[i])
    {
        if (s[i] != c && !in_word)
        {
            in_word = 1;
            result[k] = get_word(&s[i], c);
            if (!result[k])
            {
                free_array(result, k);
                return (NULL);
            }
            k++;
        }
        else if (s[i] == c)
            in_word = 0;
        i++;
    }
    result[k] = NULL;
    return (result);
}