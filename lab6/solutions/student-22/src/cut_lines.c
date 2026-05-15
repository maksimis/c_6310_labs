#include "txtfile.h"

static int	count_arr_lines(char **lines)
{
	int	i;

	if (!lines)
		return (0);
	i = 0;
	while (lines[i])
		i++;
	return (i);
}

static char	**free_partial(char **arr, int filled)
{
	while (filled > 0)
	{
		filled--;
		free(arr[filled]);
	}
	free(arr);
	return (NULL);
}

char	**cut_lines(char **lines, int start, int end)
{
	char	**result;
	int		total;
	int		i;
	int		j;

	if (!lines || start <= 0 || end < start)
		return (NULL);
	total = count_arr_lines(lines);
	if (end > total)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (end - start + 2));
	if (!result)
		return (NULL);
	i = start - 1;
	j = 0;
	while (i < end)
	{
		result[j] = ft_strdup(lines[i]);
		if (!result[j])
			return (free_partial(result, j));
		i++;
		j++;
	}
	result[j] = NULL;
	return (result);
}