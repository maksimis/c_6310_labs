#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static void	free_arr(char **arr, int n)
{
	while (n-- > 0)
		free(arr[n]);
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		n;
	int		i;
	int		start;

	if (!s)
		return (NULL);
	n = count_words(s, c);
	arr = (char **)ft_calloc(n + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	while (*s && i < n)
	{
		while (*s == c)
			s++;
		start = 0;
		while (s[start] && s[start] != c)
			start++;
		arr[i] = ft_substr(s, 0, start);
		if (!arr[i])
		{
			free_arr(arr, i);
			return (NULL);
		}
		i++;
		s += start;
	}
	arr[i] = NULL;
	return (arr);
}
