#include "txtfile.h"

static int	count_lines(char **lines)
{
	int	count;

	count = 0;
	while (lines[count])
		count++;
	return (count);
}

static char	**copy_lines(char **lines)
{
	char	**copy;
	int		count;
	int		i;

	count = count_lines(lines);
	copy = (char **)malloc(sizeof(char *) * (count + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < count)
	{
		copy[i] = ft_strdup(lines[i]);
		if (!copy[i])
		{
			copy[i] = NULL;
			free_lines(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static int	count_matches(const char *line, const char *old)
{
	int	count;
	int	old_len;

	count = 0;
	old_len = ft_strlen(old);
	while (*line)
	{
		if (ft_strnstr(line, old, ft_strlen(line)) == line)
		{
			count++;
			line += old_len;
		}
		else
			line++;
	}
	return (count);
}

static char	*replace_line(const char *line, const char *old, const char *new_str)
{
	char	*new_line;
	int		i;
	int		j;
	int		old_len;
	int		new_len;
	int		matches;

	old_len = ft_strlen(old);
	new_len = ft_strlen(new_str);
	matches = count_matches(line, old);
	new_line = (char *)malloc(sizeof(char) * (ft_strlen(line)
				+ matches * (new_len - old_len) + 1));
	if (!new_line)
		return (NULL);
	i = 0;
	j = 0;
	while (line[i])
	{
		if (ft_strnstr(line + i, old, ft_strlen(line + i)) == line + i)
		{
			ft_memcpy(new_line + j, new_str, new_len);
			j += new_len;
			i += old_len;
		}
		else
			new_line[j++] = line[i++];
	}
	new_line[j] = '\0';
	return (new_line);
}

char	**replace_substr(char **lines, const char *old, const char *new_str)
{
	char	**result;
	int		count;
	int		i;

	if (!lines || !old || !new_str)
		return (NULL);
	if (old[0] == '\0')
		return (copy_lines(lines));
	count = count_lines(lines);
	result = (char **)malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < count)
	{
		result[i] = replace_line(lines[i], old, new_str);
		if (!result[i])
		{
			result[i] = NULL;
			free_lines(result);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}