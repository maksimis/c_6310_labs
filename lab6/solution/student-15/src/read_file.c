#include "txtfile.h"

static void	free_partial_lines(char **lines, int count)
{
	int	i;

	if (!lines)
		return ;
	i = 0;
	while (i < count)
	{
		free(lines[i]);
		i++;
	}
	free(lines);
}

static int	count_lines_in_file(const char *filename)
{
	int		fd;
	char	buf[1024];
	int		bytes;
	int		i;
	int		count;
	char	last_char;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	count = 0;
	last_char = '\0';
	bytes = read(fd, buf, 1024);
	while (bytes > 0)
	{
		i = 0;
		while (i < bytes)
		{
			if (buf[i] == '\n')
				count++;
			last_char = buf[i];
			i++;
		}
		bytes = read(fd, buf, 1024);
	}
	close(fd);
	if (bytes < 0)
		return (-1);
	if (count == 0 || last_char != '\n')
		count++;
	return (count);
}

static int	append_text(char **current, const char *part)
{
	char	*tmp;

	tmp = ft_strjoin(*current, part);
	if (!tmp)
		return (0);
	free(*current);
	*current = tmp;
	return (1);
}

static int	store_line(char **lines, int *index, char *current)
{
	lines[*index] = ft_strdup(current);
	if (!lines[*index])
		return (0);
	(*index)++;
	return (1);
}

static int	process_buffer(char *buffer, char **current, char **lines, int *index)
{
	int		start;
	int		i;
	char	*part;

	start = 0;
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			part = ft_substr(buffer, start, i - start);
			if (!part)
				return (0);
			if (!append_text(current, part) || !store_line(lines, index, *current))
				return (free(part), 0);
			free(part);
			free(*current);
			*current = ft_strdup("");
			if (!*current)
				return (0);
			start = i + 1;
		}
		i++;
	}
	part = ft_substr(buffer, start, i - start);
	if (!part)
		return (0);
	if (!append_text(current, part))
		return (free(part), 0);
	free(part);
	return (1);
}

char	**read_file(const char *filename)
{
	int		fd;
	int		count;
	int		index;
	int		bytes;
	char	buffer[1025];
	char	**lines;
	char	*current;

	if (!filename)
		return (NULL);
	count = count_lines_in_file(filename);
	if (count < 0)
		return (NULL);
	lines = (char **)malloc(sizeof(char *) * (count + 1));
	if (!lines)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (free(lines), NULL);
	current = ft_strdup("");
	if (!current)
		return (close(fd), free(lines), NULL);
	index = 0;
	bytes = read(fd, buffer, 1024);
	while (bytes > 0)
	{
		buffer[bytes] = '\0';
		if (!process_buffer(buffer, &current, lines, &index))
			return (close(fd), free(current), free_partial_lines(lines, index), NULL);
		bytes = read(fd, buffer, 1024);
	}
	if (bytes < 0)
		return (close(fd), free(current), free_partial_lines(lines, index), NULL);
	if ((count == 1 && index == 0) || ft_strlen(current) > 0)
		if (!store_line(lines, &index, current))
			return (close(fd), free(current), free_partial_lines(lines, index), NULL);
	lines[index] = NULL;
	free(current);
	close(fd);
	return (lines);
}