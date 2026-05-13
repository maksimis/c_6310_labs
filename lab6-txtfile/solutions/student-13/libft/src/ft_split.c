#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			count++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (count);
}

static void	free_result(char **result, size_t i)
{
	while (i > 0)
	{
		i--;
		free(result[i]);
	}
	free(result);
}

static char	*get_word(char const *s, char c, size_t *i)
{
	size_t	start;
	size_t	len;

	while (s[*i] == c)
		(*i)++;
	start = *i;
	while (s[*i] != '\0' && s[*i] != c)
		(*i)++;
	len = *i - start;
	return (ft_substr(s, start, len));
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;
	size_t	j;

	result = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			result[j] = get_word(s, c, &i);
			if (result[j] == NULL)
				return (free_result(result, j), NULL);
			j++;
		}
	}
	result[j] = NULL;
	return (result);
}