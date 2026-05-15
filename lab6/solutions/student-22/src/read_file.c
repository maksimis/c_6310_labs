#include "txtfile.h"

static char	*join_and_free(char *s1, char *s2)
{
	char	*res;

	res = ft_strjoin(s1, s2);
	free(s1);
	return (res);
}

static char	*read_all(int fd)
{
	char	buffer[1025];
	char	*content;
	char	*tmp;
	ssize_t	bytes;

	content = ft_strdup("");
	if (!content)
		return (NULL);
	bytes = read(fd, buffer, 1024);
	while (bytes > 0)
	{
		buffer[bytes] = '\0';
		tmp = join_and_free(content, buffer);
		if (!tmp)
			return (NULL);
		content = tmp;
		bytes = read(fd, buffer, 1024);
	}
	if (bytes < 0)
	{
		free(content);
		return (NULL);
	}
	return (content);
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
	lines = ft_split(content, '\n');
	free(content);
	return (lines);
}