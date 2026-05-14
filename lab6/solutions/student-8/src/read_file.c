#include "txtfile.h"

#define READ_BUF 4096

static char	*read_all_content(int fd)
{
	char	buf[READ_BUF + 1];
	char	*content;
	char	*tmp;
	ssize_t	n;

	content = ft_strdup("");
	if (!content)
		return (NULL);
	n = read(fd, buf, READ_BUF);
	while (n > 0)
	{
		buf[n] = '\0';
		tmp = ft_strjoin(content, buf);
		free(content);
		if (!tmp)
			return (NULL);
		content = tmp;
		n = read(fd, buf, READ_BUF);
	}
	if (n < 0)
	{
		free(content);
		return (NULL);
	}
	return (content);
}

static int	count_nl(const char *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s == '\n')
			count++;
		s++;
	}
	return (count);
}

static void	free_partial(char **lines, int n)
{
	while (n-- > 0)
		free(lines[n]);
	free(lines);
}

static char	**split_into_lines(const char *content)
{
	char	**lines;
	int		total;
	int		i;
	int		start;
	int		len;

	total = count_nl(content);
	if (content[0] != '\0' && content[ft_strlen(content) - 1] != '\n')
		total++;
	lines = (char **)ft_calloc(total + 1, sizeof(char *));
	if (!lines)
		return (NULL);
	i = 0;
	start = 0;
	while (content[start] && i < total)
	{
		len = 0;
		while (content[start + len] && content[start + len] != '\n')
			len++;
		lines[i] = ft_substr(content, start, len);
		if (!lines[i])
		{
			free_partial(lines, i);
			return (NULL);
		}
		i++;
		start += len;
		if (content[start] == '\n')
			start++;
	}
	lines[i] = NULL;
	return (lines);
}

char	**read_file(const char *filename)
{
	int		fd;
	char	*content;
	char	**lines;

	if (!filename)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	content = read_all_content(fd);
	close(fd);
	if (!content)
		return (NULL);
	if (content[0] == '\0')
	{
		lines = (char **)ft_calloc(1, sizeof(char *));
		free(content);
		return (lines);
	}
	lines = split_into_lines(content);
	free(content);
	return (lines);
}
