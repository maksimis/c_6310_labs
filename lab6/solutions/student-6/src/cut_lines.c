#include "txtfile.h"

char	**cut_lines(char **lines, int start, int end)
{
	int		total;
	int		i;
	char	**result;
	int		j;

	if (!lines)
		return (NULL);
	total = 0;
	while (lines[total])
		total++;
	if (start <= 0 || end < start || start > total || end > total)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (end - start + 2));
	if (!result)
		return (NULL);
	j = 0;
	i = start - 1;
	while (i <= end - 1 && lines[i])
	{
		result[j] = ft_strdup(lines[i]);
		if (!result[j])
		{
			free_lines(result);
			return (NULL);
		}
		j++;
		i++;
	}
	result[j] = NULL;
	return (result);
}