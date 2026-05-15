#include "libft.h"

static int count_words(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	*get_word(char const *s, char c, int *i)
{
	int	start;
	char *word;

	start = *i;
	while (s[*i] && s[*i] != c)
		(*i)++;
	word = (char *)malloc(*i - start + 1);
	if (!word)
		return (NULL);
	ft_strlcpy(word, &s[start], *i - start + 1);
	return (word);
}

char **ft_split(char const *s, char c)
{
	char **arr;
	int	words;
	int	i;
	int	j;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	arr = (char **)malloc((words + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	j = 0;
	while (j < words)
	{
		while (s[i] == c)
			i++;
		arr[j] = get_word(s, c, &i);
		if (!arr[j])
		{
			while (j > 0)
				free(arr[--j]);
			free(arr);
			return (NULL);
		}
		j++;
	}
	arr[j] = NULL;
	return (arr);
}