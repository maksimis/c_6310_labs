# Вариант 2 — cut_file

Реализация библиотеки `txtfile` для вырезания диапазона строк из существующего текстового файла.

## Сборка

```bash
make
```

## Запуск

```bash
./cut_file <filename> <start> <end>
```

Пример:

```bash
./cut_file data/input.txt 2 4
```

## Файлы

- `inc/txtfile.h` — интерфейс библиотеки `txtfile`
- `src/read_file.c` — чтение текста из файла в массив строк
- `src/free_lines.c` — освобождение массива строк
- `src/print_lines.c` — вывод массива строк
- `src/cut_lines.c` — вырезание диапазона строк
- `src/main.c` — демонстрация работы
- `libft/` — собственная библиотека `libft`
