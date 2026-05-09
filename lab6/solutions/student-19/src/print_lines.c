#include "../inc/txtfile.h"

void	print_lines(char **lines)
{
	int	i;

	if (!lines) // если массив пустой, просто ничего не выводим
		return ;
	i = 0;
	while (lines[i]) // проходим по всему массиву строк до NULL
	{
		ft_putendl_fd(lines[i], 1); // выводим текущую строку + '\n'
		i++;
	}
}