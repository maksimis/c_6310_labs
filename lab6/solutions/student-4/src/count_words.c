#include "txtfile.h"

static int count_words_in_line(const char *line)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*line)
	{
		if (ft_isspace((unsigned char)*line))
			in_word = 0;
		else if (!in_word)
		{
			in_word = 1;
			count++;
		}
		line++;
	}
	return (count);
}

int	count_words(char **lines)
{
	int	total;
	int	i;

	if (!lines)
		return (-1);
	total = 0;
	i = 0;
	while (lines[i])
	{
		total += count_words_in_line(lines[i]);
		i++;
	}
	return (total);
}
