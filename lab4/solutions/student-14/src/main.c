#include "libft.h"
#include <stdarg.h>
#include <unistd.h>

#define CRIT_LEN   1
#define CRIT_START 2
#define CRIT_DIGIT 3

int	match(const char *str, int criterion, ...)
{
	va_list	args;
	int		res;
	size_t	i;

	va_start(args, criterion);
	res = 0;

	if (criterion == CRIT_LEN)
	{
		int n = va_arg(args, int);
		if ((int)ft_strlen(str) > n)
			res = 1;
	}
	else if (criterion == CRIT_START)
	{
		char *prefix = va_arg(args, char *);
		if (ft_strncmp(str, prefix, ft_strlen(prefix)) == 0)
			res = 1;
	}
	else if (criterion == CRIT_DIGIT)
	{
		if (str[0] != '\0')
		{
			res = 1;
			i = 0;
			while (str[i])
			{
				if (!ft_isdigit(str[i]))
				{
					res = 0;
					break;
				}
				i++;
			}
		}
	}

	va_end(args);
	return (res);
}

int	pred_len(const char *str, char *param)
{
	return (match(str, CRIT_LEN, ft_atoi(param)));
}

int	pred_start(const char *str, char *param)
{
	return (match(str, CRIT_START, param));
}

int	pred_digit(const char *str, char *param)
{
	(void)param;
	return (match(str, CRIT_DIGIT));
}


typedef struct s_filter
{
	char	*name;
	int		(*func)(const char *str, char *param);
	int		need_param;
}	t_filter;

static t_filter g_table[] = {
	{"len", pred_len, 1},
	{"start", pred_start, 1},
	{"digit", pred_digit, 0},
	{NULL, NULL, 0}
};


char	**read_stdin_lines(void)
{
	char	buf[1024];
	char	*raw;
	char	**lines;
	char	*tmp;
	ssize_t	bytes;

	raw = ft_strdup("");
	if (!raw)
		return (NULL);

	while ((bytes = read(0, buf, sizeof(buf) - 1)) > 0)
	{
		buf[bytes] = '\0';
		tmp = ft_strjoin(raw, buf);
		free(raw);
		if (!tmp)
			return (NULL);
		raw = tmp;
	}

	if (bytes < 0)
	{
		free(raw);
		return (NULL);
	}

	lines = ft_split(raw, '\n');
	free(raw);
	return (lines);
}

void free_lines(char **lines)
{
	int	i;

	if (!lines)
		return;
	i = 0;
	while (lines[i])
		free(lines[i++]);
	free(lines);
}


int	main(int argc, char **argv)
{
	t_filter	*f;
	char		**input;
	int			from_stdin;
	int			i;

	if (argc < 2)
	{
		ft_putendl_fd("Error: missing criterion", 2);
		return (1);
	}

	f = NULL;
	i = 0;
	while (g_table[i].name)
	{
		if (ft_strncmp(argv[1], g_table[i].name, ft_strlen(g_table[i].name)) == 0
			&& ft_strlen(argv[1]) == ft_strlen(g_table[i].name))
		{
			f = &g_table[i];
			break;
		}
		i++;
	}
	if (!f)
	{
		ft_putendl_fd("Error: invalid criterion", 2);
		return (1);
	}

	if (f->need_param && argc < 3)
	{
		ft_putendl_fd("Error: missing parameter", 2);
		return (1);
	}

	if (f->need_param && argc == 3)
	{
		input = read_stdin_lines();
		from_stdin = 1;
	}
	else if (!f->need_param && argc == 2)
	{
		input = read_stdin_lines();
		from_stdin = 1;
	}
	else
	{
		input = f->need_param ? &argv[3] : &argv[2];
		from_stdin = 0;
	}

	if (!input)
	{
		ft_putendl_fd("Error: input failed", 2);
		return (1);
	}


	i = 0;
    while (input[i])
    {
        if (f->func(input[i], f->need_param ? argv[2] : NULL))
            ft_putendl_fd(input[i], 1);
        i++;
    }

	if (from_stdin)
		free_lines(input);

	return (0);
}