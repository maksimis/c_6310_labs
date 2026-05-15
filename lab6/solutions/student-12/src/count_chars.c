#include "txtfile.h"

int	count_chars(char **lines)
{
	int	count;
	int	i;

	if (!lines)
		return (-1);
	count = 0;
	i = 0;
	while (lines[i])
	{
		count += ft_strlen(lines[i]);
        // следующие две строки, чтобы \n не учитывался 
        if (lines[i][ft_strlen(lines[i]) - 1] == '\n')
			count--;
		i++;
	}
	return (count);
}