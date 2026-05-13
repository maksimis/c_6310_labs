#include "txtfile.h"

void	print_error(char *message)
{
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(message, 2);
}