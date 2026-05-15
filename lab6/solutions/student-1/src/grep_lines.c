#include "../inc/txtfile.h"

static int	count_matches(char **lines, const char *pattern)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
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
	int		matches;
	int		i;
	int		j;

	if (!lines || !pattern)
		return (NULL);
	matches = count_matches(lines, pattern);
	result = (char **)malloc(sizeof(char *) * (matches + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (lines[i])
	{
		if (ft_strnstr(lines[i], pattern, ft_strlen(lines[i])))
		{
			result[j] = ft_strdup(lines[i]);
			j++;
		}
		i++;
	}
	result[j] = NULL;
	return (result);
}
