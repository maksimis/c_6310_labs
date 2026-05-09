#include "../inc/txtfile.h"

char	*extract_line(char *buffer)
{
	int	i;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;

	line = ft_substr_gnl(buffer, 0, i);
	return (line);
}

char	*update_buffer(char *buffer)
{
	int	i;
	char	*new_buffer;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;

	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}

	new_buffer = ft_strdup_gnl(buffer + i + 1);
	free(buffer);
	return (new_buffer);
}

char	*read_to_buffer(int fd, char *buffer)
{
	char	*tmp;
	char	*read_buf;
	int	bytes;

	read_buf = malloc(BUFFER_SIZE + 1);
	if (!read_buf)
		return (NULL);

	bytes = 1;
	while (!find_newline(buffer) && bytes > 0)
	{
		bytes = read(fd, read_buf, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(read_buf);
			return (NULL);
		}
		read_buf[bytes] = '\0';
		tmp = ft_strjoin_gnl(buffer, read_buf);
		free(buffer);
		buffer = tmp;
	}

	free(read_buf);
	return (buffer);
}