# Лабораторная работа №6: Библиотека для работы с текстовыми файлами

## Вариант 1: grep (поиск строк по подстроке)

## Сборка

make
Запуск

./txtfile data/input.txt <pattern>
Пример

./txtfile data/input.txt apple

Реализованные функции

read_file – чтение файла в массив строк

free_lines – освобождение памяти

print_lines – вывод строк

grep_lines – поиск строк, содержащих подстроку

Проверка утечек

valgrind --leak-check=full ./txtfile data/input.txt apple

---