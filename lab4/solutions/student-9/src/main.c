#include "libft.h"
#include <stdarg.h>

typedef int (*t_op)(int count, ...);

typedef struct operation {
    char *name;
    t_op  func;
} operation;


int sum(int count, ...) {
    va_list args;
    va_start(args, count);

    int res = 0;
    for (int i = 0; i < count; i++) {
        res += va_arg(args, int);
    }
    
    va_end(args);
    return res;
}

int mul(int count, ...) {
    va_list args;
    va_start(args, count);

    int res = 1;
    for (int i = 0; i < count; i++) {
        res *= va_arg(args, int);
    }

    va_end(args);
    return res;
}

int avg(int count, ...) {
    va_list args;
    va_start(args, count);

    if (count == 0) {
        va_end(args);
        return 0;
    }

    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += va_arg(args, int);
    }

    va_end(args);
    return sum / count;
}


int call_op(t_op f, int count, int *v) {
    switch (count) {
        case 1:  return f(1, v[0]);
        case 2:  return f(2, v[0], v[1]);
        case 3:  return f(3, v[0], v[1], v[2]);
        case 4:  return f(4, v[0], v[1], v[2], v[3]);
        case 5:  return f(5, v[0], v[1], v[2], v[3], v[4]);
        default: return 0;
    }
}

int	is_valid_int(const char *s) {
	int	i;

	if (!s || !*s)
		return (0);
	i = 0;
	if (s[i] == '+' || s[i] == '-') {
		i++;
    }
	while (s[i])
	{
		if (!ft_isdigit(s[i++])) {
			return (0);
        }
	}
	return (i > (s[0] == '+' || s[0] == '-') ? 1 : 0);
}



int main(int argc, char **argv) {
    if (argc < 3) {
        ft_putstr_fd("Ошибка: недостаточно аргументов\n", 2);
        return 1;
    }

    operation ops[] = {
        {"sum", sum},
        {"mul", mul},
        {"avg", avg},
        {NULL, NULL}
    };


    t_op selected_op = NULL;
    for (int i = 0; ops[i].name != NULL; i++) {
        if (ft_strncmp(argv[1], ops[i].name, ft_strlen(ops[i].name) + 1) == 0) {
            selected_op = ops[i].func;
            break;
        }
    }

    if (!selected_op) {
        ft_putstr_fd("Ошибка: неизвестная операция\n", 2);
        return (1);
    }

    int count = argc - 2;

    if (count < 1 || count > 5) {
        ft_putstr_fd("Ошибка: разрешено только 1..5 чисел \n", 2);
        return 1;
    }

    int	v[5];

    for (int i = 0; i < count; i++) {
        if (!is_valid_int(argv[i + 2])){
            ft_putstr_fd("Ошибка: некорректное число\n", 2);
            return (1);
        }
        v[i] = ft_atoi(argv[i + 2]);
    }

    int result = call_op(selected_op, count, v);

    ft_putnbr_fd(result, 1);
    ft_putchar_fd('\n', 1);

    return 0;
}