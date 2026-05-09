#include "txtfile.h"

static int	is_match(char *line, const char *pattern) {
	if (!line || !pattern)
		return (0);
	return (ft_strnstr(line, pattern, ft_strlen(line)) != NULL);
}

char	**grep_lines(char **lines, const char *pattern) {
	int	i;
	int	count;
	char **result;

	i = 0;
	count = 0;
	if (!lines || !pattern)
		return (NULL);
	while (lines[i]) {
		if (is_match(lines[i], pattern)) {
			count++;
		}
		i++;
	}
	result = ft_calloc(count + 1, sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	count = 0;
	while (lines[i]) {
		if (is_match(lines[i], pattern)) {
			result[count] = ft_strdup(lines[i]);
			if (!result[count])	{
				free_lines(result);
				return (NULL);
			}
			count++;
		}
		i++;
	}
	result[count] = NULL;
	return (result);
}