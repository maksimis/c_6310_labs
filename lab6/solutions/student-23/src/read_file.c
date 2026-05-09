#include "../inc/txtfile.h"
#include <fcntl.h>
#include <unistd.h>

char	**read_file(const char *filename)
{
	int		fd;
	char	**lines;
	char	buffer[1024];
	int		bytes;
	int		i;

	if (!filename)
		return (NULL);

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);

	lines = ft_calloc(10000, sizeof(char *));
	if (!lines)
		return (close(fd), NULL);

	i = 0;

	while ((bytes = read(fd, buffer, 1023)) > 0)
	{
		buffer[bytes] = '\0';
		lines[i] = ft_strdup(buffer);
		if (!lines[i])
			break ;
		i++;
	}

	lines[i] = NULL;
	close(fd);
	return (lines);
}