#include "txtfile.h"
#include <fcntl.h>

#define READ_BUFFER 4096

static char	*load_file_content(int fd) {
	char buffer[READ_BUFFER + 1];
	char *file_content;
	char *joined;
	ssize_t	bytes_read;

	file_content = ft_strdup("");
	if (!file_content)
		return (NULL);

	bytes_read = read(fd, buffer, READ_BUFFER);
	while (bytes_read > 0) {
		buffer[bytes_read] = '\0';
		joined = ft_strjoin(file_content, buffer);
		free(file_content);
		if (!joined)
			return (NULL);
		file_content = joined;
		bytes_read = read(fd, buffer, READ_BUFFER);
	}

	if (bytes_read < 0)	{
		free(file_content);
		return (NULL);
	}

	return (file_content);
}

static int	count_newlines(const char *text) {
	int	count;

	count = 0;
	while (*text) {
		if (*text == '\n')
			count++;
		text++;
	}
	return (count);
}

static void	free_lines_partial(char **lines, int count) {
	while (count-- > 0)
		free(lines[count]);
	free(lines);
}

static char	**split_to_lines(const char *text) {
	char **lines;
	int	total;
	int	i;
	int	start;
	int	len;

	total = count_newlines(text);
	if (text[0] != '\0' && text[ft_strlen(text) - 1] != '\n')
		total++;

	lines = (char **)ft_calloc(total + 1, sizeof(char *));
	if (!lines)
		return (NULL);

	i = 0;
	start = 0;

	while (text[start] && i < total) {
		len = 0;
		while (text[start + len] && text[start + len] != '\n')
			len++;

		lines[i] = ft_substr(text, start, len);
		if (!lines[i]) {
			free_lines_partial(lines, i);
			return (NULL);
		}

		i++;
		start += len;
		if (text[start] == '\n')
			start++;
	}

	lines[i] = NULL;
	return (lines);
}

char	**read_file(const char *filename) {
	int	fd;
	char *file_content;
	char **lines;

	if (!filename)
		return (NULL);

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);

	file_content = load_file_content(fd);
	close(fd);

	if (!file_content)
		return (NULL);

	if (file_content[0] == '\0') {
		lines = (char **)ft_calloc(1, sizeof(char *));
		free(file_content);
		return (lines);
	}

	lines = split_to_lines(file_content);
	free(file_content);
	return (lines);
}