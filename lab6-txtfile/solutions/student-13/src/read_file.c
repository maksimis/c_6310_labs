#include "txtfile.h"

static int	count_lines(char *buffer)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			count++;
		i++;
	}
	if (i > 0 && buffer[i - 1] != '\n')
		count++;
	return (count);
}

static char	*copy_line(char *buffer, int start, int end)
{
	char	*line;
	int		i;

	line = malloc(sizeof(char) * (end - start + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (start < end)
	{
		line[i] = buffer[start];
		i++;
		start++;
	}
	line[i] = '\0';
	return (line);
}

static int	fill_lines(char **lines, char *buffer)
{
	int	i;
	int	start;
	int	line_index;

	i = 0;
	start = 0;
	line_index = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			lines[line_index] = copy_line(buffer, start, i);
			if (!lines[line_index])
				return (0);
			line_index++;
			start = i + 1;
		}
		i++;
	}
	if (start < i)
	{
		lines[line_index] = copy_line(buffer, start, i);
		if (!lines[line_index])
			return (0);
		line_index++;
	}
	lines[line_index] = NULL;
	return (1);
}

char	**read_file(const char *filename)
{
	int		fd;
	int		bytes;
	char	buffer[BUFFER_SIZE + 1];
	char	**lines;

	if (!filename)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	bytes = read(fd, buffer, BUFFER_SIZE);
	close(fd);
	if (bytes < 0)
		return (NULL);
	buffer[bytes] = '\0';
	lines = ft_calloc(count_lines(buffer) + 1, sizeof(char *));
	if (!lines)
		return (NULL);
	if (!fill_lines(lines, buffer))
	{
		free_lines(lines);
		return (NULL);
	}
	return (lines);
}