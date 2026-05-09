#include "txtfile.h"

static int	count_matches(char **lines, const char *pattern)
{
	int		count;
	int		i;
	size_t	line_len;

	count = 0;
	i = 0;
	while (lines[i])
	{
		line_len = ft_strlen(lines[i]);
		if (ft_strnstr(lines[i], pattern, line_len))
			count++;
		i++;
	}
	return (count);
}

char	**grep_lines(char **lines, const char *pattern)
{
	char	**result;
	int		total;
	int		i;
	int		j;

	if (!lines || !pattern)
		return (NULL);
	total = count_matches(lines, pattern);
	result = (char **)ft_calloc(total + 1, sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (lines[i])
	{
		if (ft_strnstr(lines[i], pattern, ft_strlen(lines[i])))
		{
			result[j] = ft_strdup(lines[i]);
			if (!result[j])
			{
				free_lines(result);
				return (NULL);
			}
			j++;
		}
		i++;
	}
	result[j] = NULL;
	return (result);
}
