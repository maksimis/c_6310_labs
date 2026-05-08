#include "txtfile.h"

static int	count_matches(char **lines, const char *pattern)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (lines[i])
	{
		if (ft_strnstr(lines[i], pattern, ft_strlen(lines[i])))
			count++;
		i++;
	}
	return (count);
}

char	**grep_lines(char **lines, const char *pattern)
{
	char	**result;
	int		i;
	int		j;
	int		count;

	if (!lines || !pattern)
		return (NULL);
	count = count_matches(lines, pattern);
	result = ft_calloc(count + 1, sizeof(char *));
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