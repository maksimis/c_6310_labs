#include "libft.h"

static int	ft_count(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	*ft_word(char const *s, char c)
{
	size_t	len;
	char	*res;
	size_t	i;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static void	ft_free(char **arr, int i)
{
	while (i--)
		free(arr[i]);
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;

	if (!s)
		return (NULL);
	res = malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			res[i] = ft_word(s, c);
			if (!res[i])
				return (ft_free(res, i), NULL);
			i++;
		}
		while (*s && *s != c)
			s++;
	}
	res[i] = NULL;
	return (res);
}