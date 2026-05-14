#include "txtfile.h"

int	count_words(char **lines)
{
	int		total;
	int		i;
	int		in_word;
	char	*p;

	if (!lines)
		return (-1);
	total = 0;
	i = 0;
	while (lines[i])
	{
		in_word = 0;
		p = lines[i];
		while (*p)
		{
			if (!ft_isspace((unsigned char)*p) && !in_word)
			{
				in_word = 1;
				total++;
			}
			else if (ft_isspace((unsigned char)*p))
				in_word = 0;
			p++;
		}
		i++;
	}
	return (total);
}
