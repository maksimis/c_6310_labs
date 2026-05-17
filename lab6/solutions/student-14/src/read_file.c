#include "txtfile.h"

#define BUFFER_SIZE 1024

char    **read_file(const char *filename)
{
    int     fd;
    char    buffer[BUFFER_SIZE + 1];
    int     bytes_read;
    char    *content;
    char    *tmp;
    char    **result;

    if (!filename)
        return (NULL);

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (NULL);

    content = ft_strdup("");
    if (!content)
        return (NULL);

    bytes_read = 1;
    while (bytes_read > 0)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read < 0)
        {
            free(content);
            close(fd);
            return (NULL);
        }
        buffer[bytes_read] = '\0';

        tmp = ft_strjoin(content, buffer);
        free(content);
        content = tmp;
        if (!content)
        {
            close(fd);
            return (NULL);
        }
    }

    close(fd);

    if (content[0] == '\0')
    {
        free(content);
        return (NULL);
    }

    result = ft_split(content, '\n');
    free(content);

    return (result);
}