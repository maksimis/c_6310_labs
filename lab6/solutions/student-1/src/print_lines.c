#include "../inc/txtfile.h"

void	print_lines(char **lines)
{
	int	i;

	if (!lines)
		return ;
	i = 0;
	while (lines[i])
	{
		ft_putstr_fd(lines[i], 1);
		if (lines[i][ft_strlen(lines[i]) - 1] != '\n')
			ft_putchar_fd('\n', 1);
		i++;
	}
}
