#include "../inc/txtfile.h"
#include "../libft/inc/libft.h"
#include <fcntl.h>
#include <unistd.h>

static int count_lines_in_file(const char *filename)
{
    int     fd;
    char    buf[1024];
    int     bytes;
    int     lines;
    int     i;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (-1);
    lines = 0;
    while ((bytes = read(fd, buf, 1024)) > 0)
    {
        i = 0;
        while (i < bytes)
        {
            if (buf[i] == '\n')
                lines++;
            i++;
        }
    }
    close(fd);
    return (lines);
}

static char *read_line(int fd)
{
    char    *line;
    char    c;
    int     bytes;
    int     i;

    line = (char *)ft_calloc(1024, sizeof(char));
    if (!line)
        return (NULL);
    i = 0;
    while ((bytes = read(fd, &c, 1)) > 0)
    {
        if (c == '\n')
            break;
        line[i++] = c;
        if (i >= 1023)
        {
            // В реальном GNL нужно расширение, для лабы хватит 1024
            break;
        }
    }
    if (bytes == 0 && i == 0)
    {
        free(line);
        return (NULL);
    }
    line[i] = '\0';
    return (line);
}

char **read_file(const char *filename)
{
    int     fd;
    int     line_count;
    char    **lines;
    char    *line;
    int     i;

    if (!filename)
        return (NULL);
    line_count = count_lines_in_file(filename);
    if (line_count < 0)
        return (NULL);
    lines = (char **)ft_calloc(line_count + 1, sizeof(char *));
    if (!lines)
        return (NULL);
    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        free(lines);
        return (NULL);
    }
    i = 0;
    while ((line = read_line(fd)) != NULL && i < line_count)
        lines[i++] = line;
    close(fd);
    lines[i] = NULL;
    return (lines);
}