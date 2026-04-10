#include "../inc/libft.h" // подключение заголовочного файла
#include <stdarg.h> // для вариативной функции (для va_list)
#include <unistd.h> // read (для чтения ввода) и _exit (для немедленного выхода из программы)

/* ------------- Блок объявлений и типов ------------- */

// t_search_fn - это создание псевдонима для типа «указатель на функцию»
// любая функция, которая принимает две строки и возвращает int, теперь может называться t_search_fn
// это нужно, чтобы мы могли передавать функции как обычные переменные.
typedef int (*t_search_fn)(const char *, const char *);

// Это структура-связка. Она соединяет текстовое название режима (например, "substr") с конкретной функцией, которая этот поиск выполняе
typedef struct s_mode
{
    char        *name;
    t_search_fn func;
}               t_mode;

/* ------------- Блок функций-предикатов (Callback-и) ------------- */

// Ищет, встречается ли шаблон где угодно внутри строки
int check_substr(const char *str, const char *pattern)
{
    if (ft_strnstr(str, pattern, ft_strlen(str)))
        return (1);
    return (0);
}

// Сравнивает начало строки с шаблоном
int check_prefix(const char *str, const char *pattern)
{
    size_t len = ft_strlen(pattern);
    if (ft_strncmp(str, pattern, len) == 0)
        return (1);
    return (0);
}

// Сравнивает хвост строки с шаблоном
int check_suffix(const char *str, const char *pattern)
{
    size_t s_len = ft_strlen(str);
    size_t p_len = ft_strlen(pattern);
    if (s_len < p_len)
        return (0);
    if (ft_strncmp(str + (s_len - p_len), pattern, p_len) == 0)
        return (1);
    return (0);
}

// превращает шаблон-строку в число и сравнивает его с длиной текущей строки
int check_len(const char *str, const char *pattern)
{
    int expected_len = ft_atoi(pattern);
    return ((int)ft_strlen(str) == expected_len);
}

/* ------------- Вариативная функция (Функция с ...) ------------- */

// Используется для вывода системных сообщений (заменяет printf для ошибок)
void    ft_error_log(int exit_code, int count, ...)
{
    va_list args;
    va_start(args, count);
    while (count--)
    {
        char *s = va_arg(args, char *);
        ft_putstr_fd(s, 2);
    }
    va_end(args);
    ft_putchar_fd('\n', 2);
    if (exit_code != 0)
        _exit(exit_code);
}

/* ------------- Логика выбора ------------- */

// Функция крутит цикл и сравнивает то, что ввел пользователь (mode_str), с названиями в массиве
// Если находит совпадение, возвращает адрес функции, чтобы программа понимала, какую логику применять
t_search_fn get_mode_func(char *mode_str)
{
    static t_mode modes[] = {
        {"substr", check_substr},
        {"prefix", check_prefix},
        {"suffix", check_suffix},
        {"len", check_len},
        {NULL, NULL}
    };
    int i = 0;
    while (modes[i].name)
    {
        if (ft_strncmp(modes[i].name, mode_str, ft_strlen(modes[i].name) + 1) == 0)
            return (modes[i].func);
        i++;
    }
    return (NULL);
}

/* ------------- База ------------- */

int main(int argc, char **argv)
{
    t_search_fn search;

    if (argc < 3)
        ft_error_log(1, 2, "Usage: ", "./search <mode> <pattern> [strings...]");

    search = get_mode_func(argv[1]);
    if (!search)
        ft_error_log(1, 3, "Error: ", "Unknown mode '", argv[1], "'");

    if (argc > 3)
    {
        /* Обработка строк из аргументов */
        for (int i = 3; i < argc; i++)
        {
            if (search(argv[i], argv[2]))
                ft_putendl_fd(argv[i], 1);
        }
    }
    else
    {
        char buf[1000];
        int ret;
        while ((ret = read(0, buf, 999)) > 0)
        {
            buf[ret] = '\0';
            char **lines = ft_split(buf, '\n');
            for (int i = 0; lines[i]; i++)
            {
                if (search(lines[i], argv[2]))
                    ft_putendl_fd(lines[i], 1);
                free(lines[i]);
            }
            free(lines);
        }
    }
    return (0);
}