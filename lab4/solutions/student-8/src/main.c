#include "libft.h"
#include <stdarg.h>

typedef int	(*t_pred)(const char *str, ...);

typedef struct s_mode
{
	const char	*name;
	t_pred		fn;
	int			pattern_is_int;
}	t_mode;

static int	p_substr(const char *str, ...)
{
	va_list		ap;
	const char	*pat;

	va_start(ap, str);
	pat = va_arg(ap, const char *);
	va_end(ap);
	if (!str || !pat)
		return (0);
	return (ft_strnstr(str, pat, ft_strlen(str)) != NULL);
}

static int	p_prefix(const char *str, ...)
{
	va_list		ap;
	const char	*pat;
	size_t		n;

	va_start(ap, str);
	pat = va_arg(ap, const char *);
	va_end(ap);
	if (!str || !pat)
		return (0);
	n = ft_strlen(pat);
	if (ft_strlen(str) < n)
		return (0);
	return (ft_strncmp(str, pat, n) == 0);
}

static int	p_suffix(const char *str, ...)
{
	va_list		ap;
	const char	*pat;
	size_t		ls;
	size_t		lp;

	va_start(ap, str);
	pat = va_arg(ap, const char *);
	va_end(ap);
	if (!str || !pat)
		return (0);
	ls = ft_strlen(str);
	lp = ft_strlen(pat);
	if (ls < lp)
		return (0);
	return (ft_strncmp(str + ls - lp, pat, lp) == 0);
}

static int	p_len(const char *str, ...)
{
	va_list	ap;
	int		target;

	va_start(ap, str);
	target = va_arg(ap, int);
	va_end(ap);
	if (!str)
		return (0);
	return ((int)ft_strlen(str) == target);
}

static const t_mode	*find_mode(const char *name)
{
	static const t_mode	modes[] = {
	{"substr", p_substr, 0},
	{"prefix", p_prefix, 0},
	{"suffix", p_suffix, 0},
	{"len", p_len, 1},
	{NULL, NULL, 0}
	};
	int					i;
	size_t				n;

	i = 0;
	while (modes[i].name)
	{
		n = ft_strlen(modes[i].name);
		if (ft_strlen(name) == n
			&& ft_strncmp(modes[i].name, name, n + 1) == 0)
			return (&modes[i]);
		i++;
	}
	return (NULL);
}

static int	apply(const t_mode *m, const char *str,
		const char *pat_str, int pat_int)
{
	if (m->pattern_is_int)
		return (m->fn(str, pat_int));
	return (m->fn(str, pat_str));
}

static char	*read_all_stdin(void)
{
	char	buf[1024];
	char	*acc;
	char	*tmp;
	ssize_t	n;

	acc = ft_strdup("");
	if (!acc)
		return (NULL);
	while (1)
	{
		n = read(0, buf, sizeof(buf) - 1);
		if (n <= 0)
			break ;
		buf[n] = '\0';
		tmp = ft_strjoin(acc, buf);
		free(acc);
		if (!tmp)
			return (NULL);
		acc = tmp;
	}
	return (acc);
}

static int	process_stdin(const t_mode *m, const char *pat_str, int pat_int)
{
	char	*data;
	char	**lines;
	int		i;

	data = read_all_stdin();
	if (!data)
		return (1);
	lines = ft_split(data, '\n');
	free(data);
	if (!lines)
		return (1);
	i = 0;
	while (lines[i])
	{
		if (apply(m, lines[i], pat_str, pat_int))
			ft_putendl_fd(lines[i], 1);
		free(lines[i]);
		i++;
	}
	free(lines);
	return (0);
}

static void	process_argv(const t_mode *m, int argc, char **argv,
		const char *pat_str, int pat_int)
{
	int	i;

	i = 3;
	while (i < argc)
	{
		if (apply(m, argv[i], pat_str, pat_int))
			ft_putendl_fd(argv[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	const t_mode	*m;
	const char		*pat_str;
	int				pat_int;

	if (argc < 3)
	{
		ft_putstr_fd("Usage: ", 2);
		if (argc >= 1)
			ft_putstr_fd(argv[0], 2);
		else
			ft_putstr_fd("search", 2);
		ft_putstr_fd(" <substr|prefix|suffix|len> <pattern> [strings...]\n",
			2);
		return (1);
	}
	m = find_mode(argv[1]);
	if (!m)
	{
		ft_putstr_fd("Error: unknown mode: ", 2);
		ft_putstr_fd(argv[1], 2);
		ft_putchar_fd('\n', 2);
		return (1);
	}
	pat_str = argv[2];
	pat_int = ft_atoi(argv[2]);
	if (argc > 3)
	{
		process_argv(m, argc, argv, pat_str, pat_int);
		return (0);
	}
	return (process_stdin(m, pat_str, pat_int));
}
