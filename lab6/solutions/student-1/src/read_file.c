#include "../inc/txtfile.h"

static int	count_lines_fd(int fd)
{
	char	buf;
	int		count;

	count = 1;
	while (read(fd, &buf, 1) > 0)
	{
		if (buf == '\n')
			count++;
	}
	return (count);
}

static char	*read_line(int fd)
{
	char	buf;
	char	*line;
	char	*new_line;
	int		len;

	line = (char *)malloc(1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	len = 0;
	while (read(fd, &buf, 1) > 0)
	{
		new_line = (char *)malloc(len + 2);
		if (!new_line)
			return (NULL);
		for (int i = 0; i < len; i++)
			new_line[i] = line[i];
		new_line[len] = buf;
		new_line[len + 1] = '\0';
		free(line);
		line = new_line;
		len++;
		if (buf == '\n')
			break ;
	}
	return (line);
}

char	**read_file(const char *filename)
{
	int		fd;
	int		lines_count;
	char	**lines;
	int		i;

	if (!filename)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	lines_count = count_lines_fd(fd);
	close(fd);

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);

	lines = (char **)malloc(sizeof(char *) * (lines_count + 1));
	if (!lines)
		return (NULL);

	i = 0;
	while (i < lines_count)
	{
		lines[i] = read_line(fd);
		i++;
	}
	lines[i] = NULL;
	close(fd);
	return (lines);
}
