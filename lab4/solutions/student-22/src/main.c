#include "libft.h"
#include <stdarg.h>
#include <unistd.h>

enum e_criterion
{
	CRIT_LEN,
	CRIT_START,
	CRIT_DIGIT
};

typedef int	(*t_predicate)(const char *str, const char *param);

typedef struct s_filter
{
	char		*name;
	int			need_param;
	t_predicate	pred;
}	t_filter;

static int match_len(const char *str, ...)
{
    va_list args;
    int     n;

    if (!str)
        return (0);
    va_start(args, str);
    n = va_arg(args, int);
    va_end(args);
    return ((int)ft_strlen(str) > n);
}

static int match_start(const char *str, ...)
{
    va_list args;
    const char *prefix;

    if (!str)
        return (0);
    va_start(args, str);
    prefix = va_arg(args, const char *);
    va_end(args);
    if (!prefix)
        return (0);
    return (ft_strncmp(str, prefix, ft_strlen(prefix)) == 0);
}

static int match_digit(const char *str)
{
    size_t i;

    if (!str || str[0] == '\0')
        return (0);
    i = 0;
    while (str[i])
    {
        if (!ft_isdigit((unsigned char)str[i]))
            return (0);
        i++;
    }
    return (1);
}

static int pred_len(const char *str, const char *param)
{
    if (!param)
        return (0);
    return (match_len(str, ft_atoi(param)));
}

static int pred_start(const char *str, const char *param)
{
    return (match_start(str, param));
}

static int pred_digit(const char *str, const char *param)
{
    (void)param;
    return (match_digit(str));
}

static void	free_split(char **arr)
{
	size_t	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static char	*read_all_stdin(void)
{
	char	buffer[1024];
	char	*all;
	char	*tmp;
	ssize_t	bytes;

	all = ft_strdup("");
	if (!all)
		return (NULL);
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(0, buffer, sizeof(buffer) - 1);
		if (bytes > 0)
		{
			buffer[bytes] = '\0';
			tmp = ft_strjoin(all, buffer);
			free(all);
			if (!tmp)
				return (NULL);
			all = tmp;
		}
	}
	if (bytes < 0)
	{
		free(all);
		ft_putendl_fd("Error: failed to read from stdin", 2);
		return (NULL);
	}
	return (all);
}

static char	**read_lines_from_stdin(void)
{
	char	*all;
	char	**lines;

	all = read_all_stdin();
	if (!all)
		return (NULL);
	if (all[0] == '\0')
	{
		free(all);
		return (NULL);
	}
	lines = ft_split(all, '\n');
	free(all);
	return (lines);
}

static int	print_error(char *msg)
{
	ft_putendl_fd(msg, 2);
	return (1);
}

static t_filter	*find_filter(t_filter *filters, char *name)
{
	size_t	i;

	i = 0;
	while (filters[i].name)
	{
		if (ft_strncmp(filters[i].name, name, ft_strlen(name) + 1) == 0)
			return (&filters[i]);
		i++;
	}
	return (NULL);
}

static void	process_lines(char **lines, t_filter *filter, const char *param)
{
	size_t	i;

	i = 0;
	while (lines[i])
	{
		if (filter->pred(lines[i], param))
			ft_putendl_fd(lines[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_filter filters[] = {
		{"len",   1, pred_len},
		{"start", 1, pred_start},
		{"digit", 0, pred_digit},
		{NULL,    0, NULL}
	};
	t_filter	*filter;
	char		**lines;
	char		**input_lines;
	char		*param;

	if (argc < 2)
		return (print_error("Error: missing criterion"));
	filter = find_filter(filters, argv[1]);
	if (!filter)
		return (print_error("Error: unknown criterion"));
	if (filter->need_param && argc < 3)
		return (print_error("Error: missing parameter"));
	param = NULL;
	if (filter->need_param)
		param = argv[2];
	if (filter->need_param)
		lines = argv + 3;
	else
		lines = argv + 2;
	if (lines[0])
	{
		process_lines(lines, filter, param);
		return (0);
	}
	input_lines = read_lines_from_stdin();
	if (!input_lines)
		return (0);
	process_lines(input_lines, filter, param);
	free_split(input_lines);
	return (0);
}