#include <stdarg.h>
#include "libft.h"

/* Тип указателя на функцию-обработчик */
typedef int (*t_op_func_va)(int count, va_list args);

/* Структура для таблицы операций */
typedef struct s_op
{
    char        *name;
    t_op_func_va func;
} t_op;

/* Обработчики операций */
static int op_sum(int count, va_list args)
{
    int result = 0;
    for (int i = 0; i < count; i++)
        result += va_arg(args, int);
    return result;
}

static int op_mul(int count, va_list args)
{
    int result = 1;
    for (int i = 0; i < count; i++)
        result *= va_arg(args, int);
    return result;
}

static int op_avg(int count, va_list args)
{
    if (count == 0)
        return 0;
    int sum = 0;
    for (int i = 0; i < count; i++)
        sum += va_arg(args, int);
    return sum / count;
}

/* Таблица переходов */
static const t_op g_ops[] = {
    {"sum", op_sum},
    {"mul", op_mul},
    {"avg", op_avg},
    {NULL, NULL}
};

/* Диспетчер операций */
static int dispatch_op(const char *op_name, int count, ...)
{
    va_list args;
    int result = 0;
    const t_op *op = g_ops;

    /* Поиск операции */
    while (op->name)
    {
        if (ft_strncmp(op->name, op_name, ft_strlen(op_name) + 1) == 0)
            break;
        op++;
    }
    if (!op->name)
    {
        ft_putstr_fd("Error: unknown operation\n", 2);
        return 0;
    }

    va_start(args, count);
    result = op->func(count, args);
    va_end(args);
    return result;
}

int main(int argc, char **argv)
{
    int count = argc - 2;
    int result;

    if (argc < 3)
    {
        ft_putstr_fd("Usage: ./calc <operation> <num1> [num2 ...]\n", 2);
        return 1;
    }

    /* Преобразование аргументов в массив */
    int *nums = (int *)malloc(sizeof(int) * count);
    if (!nums)
    {
        ft_putstr_fd("Error: memory allocation failed\n", 2);
        return 1;
    }

    for (int i = 0; i < count; i++)
        nums[i] = ft_atoi(argv[i + 2]);

    /* Вызов диспетчера в зависимости от количества аргументов */
    switch (count)
    {
        case 1:  result = dispatch_op(argv[1], 1, nums[0]); break;
        case 2:  result = dispatch_op(argv[1], 2, nums[0], nums[1]); break;
        case 3:  result = dispatch_op(argv[1], 3, nums[0], nums[1], nums[2]); break;
        case 4:  result = dispatch_op(argv[1], 4, nums[0], nums[1], nums[2], nums[3]); break;
        case 5:  result = dispatch_op(argv[1], 5, nums[0], nums[1], nums[2], nums[3], nums[4]); break;
        case 6:  result = dispatch_op(argv[1], 6, nums[0], nums[1], nums[2], nums[3], nums[4], nums[5]); break;
        case 7:  result = dispatch_op(argv[1], 7, nums[0], nums[1], nums[2], nums[3], nums[4], nums[5], nums[6]); break;
        case 8:  result = dispatch_op(argv[1], 8, nums[0], nums[1], nums[2], nums[3], nums[4], nums[5], nums[6], nums[7]); break;
        case 9:  result = dispatch_op(argv[1], 9, nums[0], nums[1], nums[2], nums[3], nums[4], nums[5], nums[6], nums[7], nums[8]); break;
        case 10: result = dispatch_op(argv[1], 10, nums[0], nums[1], nums[2], nums[3], nums[4], nums[5], nums[6], nums[7], nums[8], nums[9]); break;
        default:
            ft_putstr_fd("Error: too many arguments (max 10 supported)\n", 2);
            free(nums);
            return 1;
    }

    ft_putnbr_fd(result, 1);
    ft_putchar_fd('\n', 1);
    
    free(nums);
    return 0;
}