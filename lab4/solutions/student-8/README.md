# Лабораторная работа №4 — Решение студента №8

## Вариант
Номер варианта = `8 % 4 = 0` → **Вариант 4: поиск строк по шаблону**.

## Используемая libft
Библиотека `libft` взята из лабораторной работы №3 того же студента
(PR `maksimis/c_6310_labs#60`,
ветка `rrrenata/c_6310_labs:student-8-lab3`) — папка `lab3-libft/libft`
скопирована в `student-8/libft` без изменений (удалён только встроенный
`main.c` и артефакты сборки).

## Описание
Программа `search` ищет в наборе строк (аргументы или `stdin`) строки,
удовлетворяющие шаблону.

```
./search <режим> <шаблон> [строки...]
```

Режимы:

- `substr` — строки, содержащие подстроку `<шаблон>`;
- `prefix` — строки, начинающиеся с `<шаблон>`;
- `suffix` — строки, заканчивающиеся на `<шаблон>`;
- `len` — строки, длина которых равна числу из `<шаблон>` (через `ft_atoi`).

Если строки не переданы в аргументах, они построчно читаются из `stdin`
до `EOF`.

## Соответствие требованиям

- **Указатели на функции** — массив `t_mode { name, fn, pattern_is_int }`
  связывает имя режима с предикатом. Выбор обработчика — `find_mode`.
- **Вариативные функции** — каждый предикат объявлен как
  `int p_*(const char *str, ...)` и читает шаблон через
  `va_start`/`va_arg`/`va_end`. Для `substr/prefix/suffix` извлекается
  `const char *`, для `len` — `int`.
- **libft** — использованы `ft_strnstr`, `ft_strncmp`, `ft_strlen`,
  `ft_atoi`, `ft_strdup`, `ft_strjoin`, `ft_split`, `ft_putstr_fd`,
  `ft_putendl_fd`, `ft_putchar_fd`. Из системных вызовов — только `read`
  для чтения `stdin` (разрешён лабой) и `malloc`/`free` для буферов.
  Стандартные `stdio.h`, `stdlib.h` (кроме `malloc`/`free`), `string.h`
  не используются.
- **Аргументы командной строки** — `main` разбирает `argc`/`argv`,
  проверяет наличие режима и шаблона, поддерживает строки и из argv,
  и из stdin.
- **Обработка ошибок** — неизвестный режим/нехватка аргументов выводят
  сообщение в `stderr` через `ft_putstr_fd(..., 2)` и возвращают `1`.

## Структура

```
student-8/
├── libft/                # libft студента 8 (lab3)
│   ├── inc/libft.h
│   ├── src/ft_*.c
│   └── Makefile
├── src/
│   └── main.c
├── Makefile
└── README.md
```

## Сборка и запуск

```
make           # собирает libft (объекты в libft/obj/) и ./search
make clean
make fclean
make re
```

Флаги: `-Wall -Wextra -Werror`.

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

$ printf 'hello\nhi\nworld\n' | ./search prefix h
hello
hi

$ ./search foo abc xyz
Error: unknown mode: foo

$ ./search len
Usage: ./search <substr|prefix|suffix|len> <pattern> [strings...]
```

## Утечки памяти

```
valgrind --leak-check=full --show-leak-kinds=all ./search substr abc abc xy
```
Ожидается `All heap blocks were freed -- no leaks are possible` на всех путях
(аргументы, `stdin`, ошибки).
