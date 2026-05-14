 #include "libft.h"

char *ft_strrchr(const char *s, int c)
{
    char *last;
    char ch;

    if (!s)
        return (NULL);
    ch = (char)c;
    last = NULL;
    while (*s)
    {
        if (*s == ch)
            last = (char *)s;
        s++;
    }
    if (ch == '\0')
        last = (char *)s;
    return (last);
}