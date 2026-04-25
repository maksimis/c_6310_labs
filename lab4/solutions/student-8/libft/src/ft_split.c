#include "libft.h"

static void	free_array(char **arr, size_t i)
{
	while (i--)
		free(arr[i]);
	free(arr);
}

char **ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	word_count;

	if (!s)
		return (NULL);
	i = 0;
	word_count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			word_count++;
		i++;
	}
	result = (char **)ft_calloc(word_count + 1, sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	k = 0;
	while (s[i] && k < word_count)
	{
		if (s[i] != c)
		{
			j = i;
			while (s[i] && s[i] != c)
				i++;
			result[k] = (char *)malloc(i - j + 1);
			if (!result[k])
			{
				free_array(result, k);
				return (NULL);
			}
			ft_strlcpy(result[k], &s[j], i - j + 1);
			k++;
		}
		else
			i++;
	}
	return (result);
}