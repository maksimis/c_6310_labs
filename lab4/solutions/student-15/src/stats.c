#include "stats.h"

int	metric_min(int count, ...)
{
	va_list	args;
	int		i;
	int		value;
	int		min;

	min = 0;
	if (count > 0)
	{
		va_start(args, count);
		min = va_arg(args, int);
		i = 1;
		while (i < count)
		{
			value = va_arg(args, int);
			if (value < min)
				min = value;
			i++;
		}
		va_end(args);
	}
	return (min);
}

int	metric_max(int count, ...)
{
	va_list	args;
	int		i;
	int		value;
	int		max;

	max = 0;
	if (count > 0)
	{
		va_start(args, count);
		max = va_arg(args, int);
		i = 1;
		while (i < count)
		{
			value = va_arg(args, int);
			if (value > max)
				max = value;
			i++;
		}
		va_end(args);
	}
	return (max);
}

int	metric_sum(int count, ...)
{
	va_list	args;
	int		i;
	int		sum;

	sum = 0;
	va_start(args, count);
	i = 0;
	while (i < count)
	{
		sum += va_arg(args, int);
		i++;
	}
	va_end(args);
	return (sum);
}

int	metric_avg(int count, ...)
{
	va_list	args;
	int		i;
	int		sum;
	int		result;

	sum = 0;
	result = 0;
	if (count > 0)
	{
		va_start(args, count);
		i = 0;
		while (i < count)
		{
			sum += va_arg(args, int);
			i++;
		}
		va_end(args);
		result = sum / count;
	}
	return (result);
}

int	compute(int metric, int count, ...)
{
	va_list	args;
	int		i;
	int		value;
	int		result;

	i = 0;
	value = 0;
	result = 0;
	if (count > 0)
	{
		va_start(args, count);
		if (metric == METRIC_MIN || metric == METRIC_MAX)
		{
			result = va_arg(args, int);
			i = 1;
		}
		while (i < count)
		{
			value = va_arg(args, int);
			if (metric == METRIC_MIN && value < result)
				result = value;
			else if (metric == METRIC_MAX && value > result)
				result = value;
			else if (metric == METRIC_SUM || metric == METRIC_AVG)
				result += value;
			i++;
		}
		va_end(args);
		if (metric == METRIC_AVG)
			result = result / count;
	}
	return (result);
}