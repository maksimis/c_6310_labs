#include "libft.h"
#include <stdarg.h>
#include <unistd.h>

/*
** Лабораторная работа №4, вариант 4: поиск строк по шаблону.
** Студент: 16.
**
** Демонстрация:
**   - указателей на функции (таблица режимов g_modes);
**   - вариативной функции (ft_report);
**   - работы с argc/argv и чтения строк из stdin;
**   - использования libft вместо stdio/stdlib/string.
*/

typedef int	(*t_match)(const char *str, const char *pat, int num);

typedef struct s_mode
{
	const char	*name;
	t_match		fn;
}	t_mode;

/* ------------- Предикаты ------------- */

static int	match_substr(const char *s, const char *p, int n)
{
	(void)n;
	return (ft_strnstr(s, p, ft_strlen(s)) != NULL);
}

static int	match_prefix(const char *s, const char *p, int n)
{
	size_t	lp;

	(void)n;
	lp = ft_strlen(p);
	if (ft_strlen(s) < lp)
		return (0);
	return (ft_strncmp(s, p, lp) == 0);
}

static int	match_suffix(const char *s, const char *p, int n)
{
	size_t	ls;
	size_t	lp;

	(void)n;
	ls = ft_strlen(s);
	lp = ft_strlen(p);
	if (ls < lp)
		return (0);
	return (ft_strncmp(s + (ls - lp), p, lp) == 0);
}

static int	match_len(const char *s, const char *p, int n)
{
	(void)p;
	return ((int)ft_strlen(s) == n);
}

/* ------------- Таблица режимов (указатели на функции) ------------- */

static const t_mode	g_modes[] = {
	{"substr", match_substr},
	{"prefix", match_prefix},
	{"suffix", match_suffix},
	{"len",    match_len},
	{NULL,     NULL}
};

static t_match	find_mode(const char *name)
{
	int	i;

	i = 0;
	while (g_modes[i].name)
	{
		if (ft_strncmp(g_modes[i].name, name, ft_strlen(g_modes[i].name) + 1) == 0)
			return (g_modes[i].fn);
		i++;
	}
	return (NULL);
}

/* ------------- Вариативная функция ------------- */

/*
** ft_report — печатает произвольное число строк в заданный fd,
** завершая вывод переводом строки. Используется для сообщений об ошибках
** и справки. Демонстрирует работу с va_list / va_start / va_arg / va_end.
*/
static void	ft_report(int fd, int count, ...)
{
	va_list	ap;
	int		i;
	char	*s;

	va_start(ap, count);
	i = 0;
	while (i < count)
	{
		s = va_arg(ap, char *);
		ft_putstr_fd(s, fd);
		i++;
	}
	va_end(ap);
	ft_putchar_fd('\n', fd);
}

/* ------------- Работа со строками ------------- */

static void	check_and_print(t_match fn, const char *pat, int n, char *s)
{
	if (fn(s, pat, n))
		ft_putendl_fd(s, 1);
}

static void	free_split(char **arr)
{
	int	i;

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

static int	read_all_stdin(char **out)
{
	char	buf[1024];
	char	*tmp;
	ssize_t	r;

	*out = ft_strdup("");
	if (!*out)
		return (-1);
	while (1)
	{
		r = read(0, buf, sizeof(buf) - 1);
		if (r < 0)
		{
			free(*out);
			return (-1);
		}
		if (r == 0)
			break ;
		buf[r] = '\0';
		tmp = ft_strjoin(*out, buf);
		free(*out);
		if (!tmp)
			return (-1);
		*out = tmp;
	}
	return (0);
}

static int	process_stdin(t_match fn, const char *pat, int n)
{
	char	*all;
	char	**lines;
	int		i;

	if (read_all_stdin(&all) != 0)
		return (1);
	lines = ft_split(all, '\n');
	free(all);
	if (!lines)
		return (1);
	i = 0;
	while (lines[i])
	{
		check_and_print(fn, pat, n, lines[i]);
		i++;
	}
	free_split(lines);
	return (0);
}

/* ------------- main ------------- */

int	main(int argc, char **argv)
{
	t_match	fn;
	int		n;
	int		i;

	if (argc < 3)
	{
		ft_report(2, 2, "Usage: ",
			"./search <substr|prefix|suffix|len> <pattern> [strings...]");
		return (1);
	}
	fn = find_mode(argv[1]);
	if (!fn)
	{
		ft_report(2, 3, "Error: unknown mode '", argv[1], "'");
		return (1);
	}
	n = 0;
	if (ft_strncmp(argv[1], "len", 4) == 0)
		n = ft_atoi(argv[2]);
	if (argc > 3)
	{
		i = 3;
		while (i < argc)
		{
			check_and_print(fn, argv[2], n, argv[i]);
			i++;
		}
		return (0);
	}
	return (process_stdin(fn, argv[2], n));
}
