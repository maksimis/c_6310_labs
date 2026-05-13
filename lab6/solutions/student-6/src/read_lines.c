#include "txtfile.h"

static char	*read_all(int fd)
{
	char	buf[BUFFER_SIZE];
	char	*result;
	char	*tmp;
	ssize_t	n;

	result = ft_strdup("");
	if (!result)
		return (NULL);
	while ((n = read(fd, buf, BUFFER_SIZE - 1)) > 0)
	{
		buf[n] = '\0';
		tmp = ft_strjoin(result, buf);
		free(result);
		if (!tmp)
			return (NULL);
		result = tmp;
	}
	if (n < 0)
	{
		free(result);
		return (NULL);
	}
	return (result);
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
	content = read_all(fd);
	close(fd);
	if (!content)
		return (NULL);
	if (content[0] == '\0')
	{
		free(content);
		return (NULL);
	}
	lines = ft_split(content, '\n');
	free(content);
	return (lines);
}