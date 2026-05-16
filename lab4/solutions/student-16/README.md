# Лабораторная работа №4 — Студент 16

**Вариант:** 4 (16 % 4 = 0 → вариант 4). Поиск строк по шаблону.

## Формат вызова

```
./search <substr|prefix|suffix|len> <шаблон> [строки...]
```

Если строки не переданы в аргументах — читаются построчно из `stdin`.

Режимы:
- `substr` — строки, содержащие подстроку `<шаблон>`;
- `prefix` — строки, начинающиеся с `<шаблон>`;
- `suffix` — строки, заканчивающиеся на `<шаблон>`;
- `len`    — строки, длина которых равна числу `<шаблон>`.

## Что использовано

- **Указатели на функции:** таблица `g_modes[]` связывает имя режима с предикатом типа `int (*)(const char *, const char *, int)`; `find_mode` возвращает нужный указатель.
- **Вариативная функция:** `ft_report(int fd, int count, ...)` печатает произвольное число строк через `va_list`/`va_start`/`va_arg`/`va_end` — используется для сообщений об ошибках и справки.
- **argc/argv:** `main` разбирает аргументы, при ошибках пишет в `stderr` (fd 2) и возвращает ненулевой код.
- **libft:** `ft_strnstr`, `ft_strncmp`, `ft_strlen`, `ft_atoi`, `ft_strdup`, `ft_strjoin`, `ft_split`, `ft_putstr_fd`, `ft_putchar_fd`, `ft_putendl_fd`.
- **stdio.h/stdlib.h/string.h не подключаются**, используются только `libft.h`, `stdarg.h`, `unistd.h` (для `read`).

## Сборка

```
make
./search substr abc abcde xyz abc123
```

Цели Makefile: `all`, `clean`, `fclean`, `re`. Флаги компиляции: `-Wall -Wextra -Werror`.

## Примеры

```
$ ./search substr abc abcde xyz abc123
abcde
abc123

$ ./search prefix pre prefix pred prelude
prefix
pred
prelude

$ ./search suffix ing running swim jump
running

$ ./search len 3 cat dog bird
cat
dog

$ printf "abcde\nxyz\nabc123\n" | ./search substr abc
abcde
abc123
```

## Структура

```
student-16/
├── inc/libft.h
├── src/main.c
├── libft/libft.a      (собранная библиотека из lab3)
├── Makefile
└── README.md
```
