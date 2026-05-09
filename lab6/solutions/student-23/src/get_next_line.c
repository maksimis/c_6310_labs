#include "../inc/txtfile.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	buffer = read_to_buffer(fd, buffer);
	if (!buffer || !buffer[0])
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}

	line = extract_line(buffer);
	buffer = update_buffer(buffer);

	return (line);
}