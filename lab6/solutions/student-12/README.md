# Лабораторная работа №6 —  Анализ текстового файла (Вариант 4)
## Описание:   
Текстовый файл можно анализировать по различным характеристикам:

- **количество строк** — число строк в файле;
- **количество символов** — общее число символов во всех строках;
- **количество слов** — число последовательностей символов, разделённых пробелами, табуляцией или переводами строки;
- **самая длинная строка** — строка с максимальной длиной.

## Реализованные функции
### Обязательные функции библиотеки `txtfile`
```c
char    **read_file(const char *filename);
void    free_lines(char **lines);
void    print_lines(char **lines);
```
### Функции анализа текста
```c
int count_lines(char **lines);
int count_words(char **lines);
int count_chars(char **lines);
int longest_line_length(char **lines);
```

## Структура итогового проекта:
```
lab6/solutions/student-12
├── libft/
├── inc/
│   ├── libft.h
│   └── txtfile.h
├── src/
│   ├── main.c
│   ├── read_file.c
│   ├── free_lines.c
│   ├── print_lines.c
│   ├── count_lines.c
│   ├── count_words.c
│   ├── count_chars.c
│   └── longest_line_length.c
├── data/
│   └── input.txt
├── Makefile
└── README.md
```

## Сборка и запуск:
```bash
cd /d/Projects/c_6310_labs/lab6/solutions/student-12
make
./analyze_file data/input.txt
```

## Проверка:
1. Входные данные файла:
```
Hello world
This is text
abc
```
Результат:
```
Lines: 3
Words: 6
Characters(without |n and |0): 26
Longest line length(without |n and |0): 12
```
2. Входные данные файла:
```
One two three
Hello
42
```
Результат:
```
Lines: 3
Words: 5
Characters(without |n and |0): 20
Longest line length(without |n and |0): 13
```
3. Входные данные файла:
```
apple

banana orange

kiwi
```
Результат:
```
Lines: 5
Words: 4
Characters(without |n and |0): 22
Longest line length(without |n and |0): 13
```
4. Входные данные файла:один пробел
Результат:
```
Lines: 1
Words: 0
Characters(without |n and |0): 1
Longest line length(without |n and |0): 1
```

5. Входные данные: enter и пустота
Результат:
```
Error: cannot read file
```

## Чек-лист
- [+] Программа компилируется без ошибок и предупреждений с флагами `-Wall -Wextra -Werror`.
- [+] В `Makefile` реализованы цели `all`, `clean`, `fclean`, `re`.
- [+] Реализована библиотека `txtfile`: заголовочный файл `txtfile.h` и `.c`-файлы с реализациями.
- [+] Реализованы базовые функции: `read_file`, `free_lines`, `print_lines`.
- [+] Функции по варианту (`grep`, `cut`, `replace`, `анализ`) работают корректно.
- [+] `main.c` использует `argc/argv` для получения файла и параметров.
- [+] В `main.c` нет захардкоженных значений.
- [+] Реализована проверка количества аргументов (`argc`).
- [+] При ошибке аргументов выводится сообщение `Usage`.
- [+] Все операции вывода выполняются через функции `libft`.
- [+] Функции библиотеки корректно обрабатывают ошибки.
- [+] Нет утечек памяти (`valgrind` показывает "All heap blocks were freed").
- [+] Код отформатирован, нет лишних заголовков, нет глобальных переменных.

## Критерии оценивания (максимум 5 баллов)
- [+] Реализована библиотека `txtfile`
- [+] Реализованы базовые функции
- [+] Операции по варианту работают корректно
- [+] `main.c` использует `argv` и корректно демонстрирует работу
- [+] Нет утечек памяти

### Штрафы:
- [-] Использование запрещённых функций 
- [-] Утечки памяти
- [-] Отсутствие обработки ошибок 
- [-] Жёстко заданные параметры (без `argv`) 
- [-] Программа не компилируется с нужными флагами 