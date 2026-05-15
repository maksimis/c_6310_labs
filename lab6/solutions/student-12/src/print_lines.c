#include "txtfile.h"

void	print_lines(char **lines)
{
	int	i;

	if (!lines)
		return ;
	i = 0;
	while (lines[i])
	{
		ft_putstr_fd(lines[i], 1); // печать lines[i] в стандартный вывод терминала
		if (lines[i][ft_strlen(lines[i]) - 1] != '\n') // ft_strlen(lines[i]) - 1 это индекс последнего элемента. надо чтобы после послденей строки был переход, так как в последней строке по умолчанию этого перехода нет
			ft_putchar_fd('\n', 1); // печать \n
		i++;
	}
}