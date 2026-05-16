#include "txtfile.h"
#include <fcntl.h>
#include <unistd.h>

static char *append_content(char *content, char *buf, ssize_t bytes)
{
    char *new_content;
    size_t old_len;

    old_len = content ? ft_strlen(content) : 0;
    new_content = ft_calloc(old_len + bytes + 1, sizeof(char));
    if (!new_content)
    {
        free(content);
        return (NULL);
    }
    if (content)
    {
        ft_memcpy(new_content, content, old_len);
        free(content);
    }
    ft_memcpy(new_content + old_len, buf, bytes);
    return (new_content);
}

static void free_line_array(char **lines)
{
    size_t i;

    if (!lines)
        return;
    i = 0;
    while (lines[i])
    {
        free(lines[i]);
        i++;
    }
    free(lines);
}

static char **build_lines(char *content)
{
    size_t len;
    size_t count;
    char **lines;
    size_t i;
    size_t start;
    size_t index;
    char *line;

    if (!content)
        return (NULL);
    len = ft_strlen(content);
    if (len == 0)
    {
        lines = ft_calloc(1, sizeof(char *));
        return (lines);
    }
    count = 0;
    i = 0;
    while (i < len)
    {
        if (content[i] == '\n')
            count++;
        i++;
    }
    if (len > 0 && content[len - 1] != '\n')
        count++;
    lines = ft_calloc(count + 1, sizeof(char *));
    if (!lines)
        return (NULL);
    start = 0;
    index = 0;
    i = 0;
    while (i < len)
    {
        if (content[i] == '\n')
        {
            line = ft_substr(content, start, i - start);
            if (!line)
            {
                free_line_array(lines);
                return (NULL);
            }
            lines[index++] = line;
            start = i + 1;
        }
        i++;
    }
    if (start < len)
    {
        line = ft_substr(content, start, len - start);
        if (!line)
        {
            free_line_array(lines);
            return (NULL);
        }
        lines[index++] = line;
    }
    lines[index] = NULL;
    return (lines);
}

char **read_file(const char *filename)
{
    int fd;
    ssize_t bytes;
    char buffer[1024];
    char *content;
    char **lines;

    if (!filename)
        return (NULL);
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (NULL);
    content = NULL;
    while ((bytes = read(fd, buffer, sizeof(buffer))) > 0)
    {
        content = append_content(content, buffer, bytes);
        if (!content)
        {
            close(fd);
            return (NULL);
        }
    }
    if (bytes < 0)
    {
        free(content);
        close(fd);
        return (NULL);
    }
    close(fd);
    if (!content)
        content = ft_calloc(1, 1);
    if (!content)
        return (NULL);
    lines = build_lines(content);
    free(content);
    return (lines);
}
