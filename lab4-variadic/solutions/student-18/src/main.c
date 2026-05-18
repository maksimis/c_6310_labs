#include "libft.h"
#include <stdarg.h>
#include <unistd.h>

int	match(const char *str, int criterion, ...)
{
	va_list	args;
	int		result;
	size_t	i;

	result = 0;
	va_start(args, criterion);
	
	if (criterion == 0)
	{
		int n = va_arg(args, int);
		if ((int)ft_strlen(str) > n)
			result = 1;
	}
	else if (criterion == 1)
	{
		char *substr = va_arg(args, char *);
		if (ft_strncmp(str, substr, ft_strlen(substr)) == 0)
			result = 1;
	}
	else if (criterion == 2)
	{
		i = 0;
		result = 1;
		if (ft_strlen(str) == 0)
			result = 0;
		else
		{
			while (str[i])
			{
				if (!ft_isdigit(str[i]))
				{
					result = 0;
					break;
				}
				i++;
			}
		}
	}
	va_end(args);
	return (result);
}

int	predicate_len(const char *param, char *str)
{
	(void)param;
	int n = ft_atoi(param);
	return (match(str, 0, n));
}

int	predicate_start(const char *param, char *str)
{
	return (match(str, 1, param));
}

int	predicate_digit(char *str)
{
	return (match(str, 2));
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return;
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

char	**read_from_stdin(void)
{
	char	buffer[4096];
	char	*all_data;
	char	**lines;
	ssize_t	bytes;
	char	*temp;

	all_data = ft_strdup("");
	if (!all_data)
		return (NULL);
	
	while ((bytes = read(0, buffer, sizeof(buffer) - 1)) > 0)
	{
		buffer[bytes] = '\0';
		temp = ft_strjoin(all_data, buffer);
		free(all_data);
		if (!temp)
			return (NULL);
		all_data = temp;
	}
	
	if (bytes == -1)
	{
		free(all_data);
		ft_putstr_fd("Error: Failed to read from stdin\n", 2);
		return (NULL);
	}
	
	if (ft_strlen(all_data) == 0)
	{
		free(all_data);
		return (NULL);
	}
	
	lines = ft_split(all_data, '\n');
	free(all_data);
	return (lines);
}

typedef struct s_criterion
{
	char	*name;
	int		(*pred_with_param)(const char*, char*);
	int		(*pred_no_param)(char*);
	int		has_param;
}	t_criterion;

int	main(int argc, char **argv)
{
	t_criterion	criteria[] = {
		{"len", predicate_len, NULL, 1},
		{"start", predicate_start, NULL, 1},
		{"digit", NULL, predicate_digit, 0},
		{NULL, NULL, NULL, 0}
	};
	
	int		i;
	char	**strings;
	
	if (argc < 2)
	{
		ft_putstr_fd("Error: Missing criterion\n", 2);
		return (1);
	}
	
	i = 0;
	while (criteria[i].name)
	{
		if (ft_strncmp(argv[1], criteria[i].name, ft_strlen(argv[1]) + 1) == 0)
			break;
		i++;
	}
	
	if (!criteria[i].name)
	{
		ft_putstr_fd("Error: Unknown criterion\n", 2);
		return (1);
	}
	
	if (criteria[i].has_param && argc < 3)
	{
		ft_putstr_fd("Error: Missing parameter for criterion\n", 2);
		return (1);
	}
	
	if (criteria[i].has_param)
	{
		if (argc > 3)
			strings = argv + 3;
		else
			strings = NULL;
	}
	else
	{
		if (argc > 2)
			strings = argv + 2;
		else
			strings = NULL;
	}
	
	if (!strings || !strings[0])
	{
		char	**stdin_lines = read_from_stdin();
		if (!stdin_lines)
			return (0);
		
		int j = 0;
		if (criteria[i].has_param)
		{
			while (stdin_lines[j])
			{
				if (criteria[i].pred_with_param(argv[2], stdin_lines[j]))
					ft_putendl_fd(stdin_lines[j], 1);
				j++;
			}
		}
		else
		{
			while (stdin_lines[j])
			{
				if (criteria[i].pred_no_param(stdin_lines[j]))
					ft_putendl_fd(stdin_lines[j], 1);
				j++;
			}
		}
		free_split(stdin_lines);
	}
	else
	{
		int j = 0;
		if (criteria[i].has_param)
		{
			while (strings[j])
			{
				if (criteria[i].pred_with_param(argv[2], strings[j]))
					ft_putendl_fd(strings[j], 1);
				j++;
			}
		}
		else
		{
			while (strings[j])
			{
				if (criteria[i].pred_no_param(strings[j]))
					ft_putendl_fd(strings[j], 1);
				j++;
			}
		}
	}
	
	return (0);
}