#include "txtfile.h"

int	longest_line_length(char **lines)
{
	int	max;
	int	len;
	int	i;

	if (!lines)
		return (-1);
	max = 0;
	i = 0;
	while (lines[i])
	{
		len = ft_strlen(lines[i]);
        // следующие две строки, чтобы \n не учитывался 
        if (lines[i][len - 1] == '\n')
			len--;
		if (len > max)
			max = len;
		i++;
	}
	return (max);
}