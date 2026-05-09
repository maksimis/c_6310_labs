# Лабораторная работа №6 — Студент 21, Вариант 1 (grep)

## Сборка

```bash
make
```

## Запуск

```bash
./grep_file <filename> <pattern>
```

## Пример

```bash
./grep_file data/input.txt apple
```

Выведет все строки файла, содержащие подстроку `apple`.

## Цели Makefile

- `make` / `make all` — сборка
- `make clean` — удаление объектных файлов
- `make fclean` — полная очистка
- `make re` — пересборка
