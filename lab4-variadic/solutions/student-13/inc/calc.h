#ifndef CALC_H
# define CALC_H

# include <stdarg.h>
# include "../libft/inc/libft.h"

typedef int	(*t_operation)(int, int);

int		op_sum(int a, int b);
int		op_mul(int a, int b);
int		calculate(int count, t_operation operation, int initial, ...);
int		select_operation(char *name, t_operation *operation, int *initial);
int		is_valid_number(char *str);
void	print_error(char *message);

#endif