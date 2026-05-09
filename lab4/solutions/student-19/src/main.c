#include "libft.h" // подключение своей библиотеки
#include <stdarg.h> // для variadic функций (va_list, va_start, va_arg, va_end)
#include <stdlib.h> // для malloc и free

int	compute(int metric, int count, ...) //Функция с переменным числом аргументов:

//metric — какая операция (min/max/sum/avg)
//count — сколько чисел
// ... — сами числа

{
	va_list	args; // переменная для перебора аргументов
	int		i; // счётчик
	int		val; // текущее значение
	int		res; // результат

	if (count <= 0) // если нет чисел возвращаем 0
		return (0);
	va_start(args, count); // инициализация списка аргументов
	res = va_arg(args, int); // берём первое число и делаем его базой:
// для min/max — начальное значение
// для sum — старт суммы

	i = 1; // начинаем со второго элемента 
	while (i < count) // проходим по оставльным числам
	{
		val = va_arg(args, int); // берем очередной аргумент
		if (metric == 0 && val < res) // если min, ищем минимальный 
			res = val;
		else if (metric == 1 && val > res) // если max, ищем максимальный
			res = val; 
		else if (metric == 2 || metric == 3) // если sum или avg - складываем
			res += val;
		i++;
	}
	va_end(args); // завершение работы с variadic аргументами
	if (metric == 3)
		return (res / count); // если avg - делим сумму на количество
	return (res);
}


int	ft_min_arr(int *arr, int count) // принимает массив чисел
{
	int	i;
	int	min;

	min = arr[0]; // начинаем с первого элемента
	i = 1;
	while (i < count) // перебираем массив
	{
		if (arr[i] < min)
			min = arr[i]; // обновляет минимум
		i++;
	}
	return (min);
}

int	ft_max_arr(int *arr, int count) // принимает массив чисел
{
	int	i;
	int	max;

	max = arr[0]; // начинаем с первого элемента
	i = 1;
	while (i < count)
	{
		if (arr[i] > max)
			max = arr[i]; // обновляет максимум
		i++;
	}
	return (max);
}

int	ft_sum_arr(int *arr, int count)
{
	int	i;
	int	sum;

	sum = 0;
	i = 0;
	while (i < count)
	{
		sum += arr[i]; //сумма
		i++;
	}
	return (sum);
}

int	ft_avg_arr(int *arr, int count)
{
	return (ft_sum_arr(arr, count) / count); 
}

typedef int	(*t_func)(int *, int); // указатель на функцию (принимает массив и размер)

typedef struct s_op
{
	char	*name;
	t_func	func;
}	t_op;

t_op	ops[] = {  // таблица соответствий
	{"min", ft_min_arr},
	{"max", ft_max_arr},
	{"sum", ft_sum_arr},
	{"avg", ft_avg_arr},
	{NULL, NULL}
};

t_func	get_func(char *name) // поиск функции
{
	int	i;

	i = 0;
	while (ops[i].name) // пока не дошли до конца таблицы, сравниваем строки
	{
		if (!ft_strncmp(name, ops[i].name, 4))
			return (ops[i].func); // возвращаем найденную функцию
		i++;
	}
	return (NULL); // если не нашли
}

int	main(int argc, char **argv)
{
	int		*nums;
	int		count;
	int		i;
	t_func	func;
	int		result;

	if (argc < 3)
		return (ft_putstr_fd("Error: not enough arguments\n", 2), 1);

	func = get_func(argv[1]);
	if (!func)
		return (ft_putstr_fd("Error: unknown metric\n", 2), 1);

	count = argc - 2;
	nums = (int *)malloc(sizeof(int) * count);
	if (!nums) // проверка malloc
		return (1);

	i = 0;
	while (i < count)
	{
		nums[i] = ft_atoi(argv[i + 2]); // преобразуем строки в числа
		i++;
	}

	result = func(nums, count); // вызываем нужную функцию через указатель

	ft_putnbr_fd(result, 1);
	ft_putchar_fd('\n', 1);

	free(nums); // освобождаем память
	return (0);
}    