#include "calc.h"

int	calculate(int count, t_operation operation, int initial, ...)
{
	va_list	args;
	int		result;
	int		i;

	result = initial;
	i = 0;
	va_start(args, initial);
	while (i < count)
	{
		result = operation(result, va_arg(args, int));
		i++;
	}
	va_end(args);
	return (result);
}