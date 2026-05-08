#include "calc.h"

int	select_operation(char *name, t_operation *operation, int *initial)
{
	if (ft_strncmp(name, "sum", 4) == 0)
	{
		*operation = op_sum;
		*initial = 0;
		return (1);
	}
	if (ft_strncmp(name, "mul", 4) == 0)
	{
		*operation = op_mul;
		*initial = 1;
		return (1);
	}
	if (ft_strncmp(name, "avg", 4) == 0)
	{
		*operation = op_sum;
		*initial = 0;
		return (1);
	}
	return (0);
}