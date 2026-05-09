#include "../inc/txtfile.h"

int	count_lines_array(char **lines)
{
	int	count;

	if (!lines)
		return (0);
	count = 0;
	while (lines[count])
		count++;
	return (count);
}

static int	match(const char *s, const char *old)
{
	int	i;

	i = 0;
	while (old[i])
	{
		if (s[i] != old[i])
			return (0);
		i++;
	}
	return (1);
}

static char	*append_char(char *str, char c)
{
	char	*new_str;
	int		len;

	len = ft_strlen(str);
	new_str = ft_calloc(len + 2, sizeof(char));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, str, len + 1);
	new_str[len] = c;
	free(str);
	return (new_str);
}

char	*replace_in_line(const char *line,
		const char *old,
		const char *new_str)
{
	char	*result;
	char	*tmp;
	int		i;

	result = ft_strdup("");
	if (!result)
		return (NULL);
	i = 0;
	while (line[i])
	{
		if (match(&line[i], old))
		{
			tmp = ft_strjoin(result, new_str);
			free(result);
			result = tmp;
			i += ft_strlen(old);
		}
		else
		{
			result = append_char(result, line[i]);
			i++;
		}
	}
	return (result);
}