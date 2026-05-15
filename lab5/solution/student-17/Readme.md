# Лабораторная работа №5: Библиотека для работы с матрицами

## Информация

- **Студент:** ИВТ, 17 вариант
- **Вариант:** 1 (сложение и вычитание матриц)
- **Язык:** C
- **Среда:** VS Code / Git Bash / MinGW

---

## Описание работы

Реализована библиотека `matrix` для выполнения операций над матрицами целых чисел.  
Вся работа с памятью и выводом выполняется через собственную библиотеку `libft` (без использования стандартных функций `stdio.h`, `stdlib.h`, `string.h`).

### Структура проекта

```
student-17/
├── libft/                 # Готовая библиотека libft
│   ├── inc/
│   │   └── libft.h
│   ├── src/
│   ├── obj/
│   └── libft.a
├── matrix/                # Библиотека для работы с матрицами
│   ├── matrix.h
│   ├── matrix_create.c
│   ├── matrix_remove.c
│   ├── matrix_print.c
│   ├── matrix_sum.c
│   └── matrix_sub.c
├── main.c                 # Демонстрационная программа
├── Makefile               # Сборка проекта
├── lab05.exe              # Исполняемый файл (после компиляции)
└── README.md              # Этот файл
```

---

## Сборка и запуск

### Требования

- Компилятор `gcc` (MinGW / MSYS2 / WSL / Linux)
- Утилита `make` (опционально)

### Команды

| Команда | Действие |
|---------|----------|
| `make` или `mingw32-make` | Сборка проекта |
| `make clean` | Удаление объектных файлов |
| `make fclean` | Полная очистка (объектные файлы + исполняемый) |
| `make re` | Пересборка проекта |
| `./lab05.exe` | Запуск программы |

### Пример сборки и запуска (Git Bash / MSYS2)

```bash
make (mingw32-make)
./lab05.exe
```

### Ручная сборка (без make)

```bash
gcc -Wall -Wextra -Werror -I./libft/inc -I./matrix -c main.c -o main.o
gcc -Wall -Wextra -Werror -I./libft/inc -I./matrix -c matrix/matrix_create.c -o matrix/matrix_create.o
gcc -Wall -Wextra -Werror -I./libft/inc -I./matrix -c matrix/matrix_remove.c -o matrix/matrix_remove.o
gcc -Wall -Wextra -Werror -I./libft/inc -I./matrix -c matrix/matrix_print.c -o matrix/matrix_print.o
gcc -Wall -Wextra -Werror -I./libft/inc -I./matrix -c matrix/matrix_sum.c -o matrix/matrix_sum.o
gcc -Wall -Wextra -Werror -I./libft/inc -I./matrix -c matrix/matrix_sub.c -o matrix/matrix_sub.o
gcc -o lab05.exe main.o matrix/*.o ./libft/libft.a
./lab05.exe
```

---

## Реализованные функции

### Библиотека `matrix`

| Функция | Описание |
|---------|----------|
| `matrix_t *create_matrix(int rows, int cols)` | Создание матрицы, выделение памяти |
| `void remove_matrix(matrix_t *A)` | Освобождение памяти матрицы |
| `void print_matrix(matrix_t *A)` | Вывод матрицы в `stdout` |
| `matrix_t *sum_matrix(matrix_t *A, matrix_t *B)` | Сложение двух матриц |
| `matrix_t *sub_matrix(matrix_t *A, matrix_t *B)` | Вычитание двух матриц |

### Структура

```c
typedef struct matrix_struct {
    int **matrix;
    int rows;
    int columns;
} matrix_t;
```

### Обработка ошибок

- При нулевых или отрицательных размерах → возвращается `NULL`
- При несовместимых размерах матриц → возвращается `NULL`
- При невозможности выделить память → возвращается `NULL`

---

## Демонстрация работы

Программа `main.c` демонстрирует:

1. Создание двух матриц `A` (3×3) и `B` (3×3)
2. Заполнение их целыми числами
3. Вывод исходных матриц
4. Вычисление суммы `A + B`
5. Вычисление разности `A - B`
6. Вывод результатов
7. Освобождение всей выделенной памяти

### Вывод программы

```
=== Lab05: Matrix library (variant 1: sum & sub) ===

Matrix A:
[1 2 3]
[4 5 6]
[7 8 9]

Matrix B:
[1 0 0]
[2 0 0]
[3 4 1]

A + B =
[2 2 3]
[6 5 6]
[10 12 10]

A - B =
[0 2 3]
[2 5 6]
[4 4 8]

Done. No memory leaks.
```

---

## Проверка утечек памяти

Для проверки используется `valgrind` (доступен в WSL / Linux / MSYS2):

```bash
valgrind --leak-check=full ./lab05.exe
```

Ожидаемый результат:
```
All heap blocks were freed -- no leaks are possible
```

---

## Соответствие чек-листу

- [x] Компиляция без ошибок с `-Wall -Wextra -Werror`
- [x] Makefile с целями `all`, `clean`, `fclean`, `re`
- [x] Реализована библиотека `matrix` (`.h` и `.c` файлы)
- [x] Базовые функции: `create_matrix`, `remove_matrix`, `print_matrix`
- [x] Функции по варианту: `sum_matrix`, `sub_matrix`
- [x] `main.c` демонстрирует работу библиотеки
- [x] Вывод через libft (`ft_putchar_fd`, `ft_putstr_fd`, `ft_putnbr_fd`, `ft_putendl_fd`)
- [x] Обработка ошибок (размеры, совместимость, выделение памяти)
- [x] Нет утечек памяти
- [x] Нет глобальных переменных

---

## Примечания

- Вместо `malloc` используется `ft_calloc` из libft (соблюдение запрета на `stdlib.h`)
- `free` разрешён как системный вызов (не из `stdlib.h`)
- Все операции ввода-вывода только через libft
- Проект готов к сдаче ✅

---

## Автор

Студент группы ИВТ, 17 вариант  
Дата выполнения: 15.05.2026
