#include "stats.h"

static int	is_digit(char c)
{
	int	result;

	result = 0;
	if (c >= '0' && c <= '9')
		result = 1;
	return (result);
}

int	is_valid_number(char *str)
{
	int	i;
	int	valid;

	i = 0;
	valid = 1;
	if (!str || !str[0])
		valid = 0;
	else
	{
		if (str[i] == '+' || str[i] == '-')
			i++;
		if (!str[i])
			valid = 0;
		while (str[i] && valid == 1)
		{
			if (!is_digit(str[i]))
				valid = 0;
			i++;
		}
	}
	return (valid);
}

int	parse_int(char *str, int *out)
{
	int	status;

	status = 1;
	if (!is_valid_number(str))
		status = 0;
	else
		*out = ft_atoi(str);
	return (status);
}