
#include "txtfile.h"

static int	count_matching_lines(char **lines, const char *pattern)
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
	int		match_count;
	int		i;
	int		j;

	if (!lines || !pattern)
		return (NULL);
	match_count = count_matching_lines(lines, pattern);
	result = (char **)malloc(sizeof(char *) * (match_count + 1));
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
				while (j > 0)
					free(result[--j]);
				free(result);
				return (NULL);
			}
			j++;
		}
		i++;
	}
	result[match_count] = NULL;
	return (result);
}
