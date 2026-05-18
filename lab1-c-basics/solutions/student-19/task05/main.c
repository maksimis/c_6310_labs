   /*
    * Лабораторная работа №1
    * Студент: Котова Алиса (номер: 19)
    * Вариант: 20
    * Задание: 5 (N-е число Фибоначчи)
    */

#include <stdio.h> //Подключение стандартной библиотеки ввода/вывода 
#include <stdlib.h> // Подключение стандартной библиотеки (для корректного использования return 1 и др.)
#include <windows.h> // Нужна для настройки кодировки консоли в Windows

#define MAX_FIB_INDEX 93 
#define INPUT_BUFFER_SIZE 100 // Для буффера

unsigned long long calculate_fibonacci(unsigned int index) {
    if (index == 0) {
        return 0;
    }
    if (index == 1) {
        return 1;
    }

    unsigned long long previous = 0;
    unsigned long long current = 1;

    for (unsigned int i = 2; i <= index; i++) {
        unsigned long long next = previous + current;
        previous = current;
        current = next;
    }

    return current;
}

int main(void) {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    char input_buffer[INPUT_BUFFER_SIZE];
    int input_index;
    char extra_char;

    printf("Введите номер числа Фибоначчи (от 0 до %d): ",
           MAX_FIB_INDEX);

    if (fgets(input_buffer, sizeof(input_buffer), stdin) == NULL) {
        fprintf(stderr, "Ошибка: не удалось прочитать ввод.\n");
        return 1;
    }

    /*
       Формат "%d %c":
       - %d считывает целое число
       - пробел перед %c заставляет sscanf пропустить
         все пробельные символы
       - %c пытается считать ЛЮБОЙ следующий символ

       Если после числа есть:
       - буквы
       - знаки (!, @, # и т.д.)
       - второе число
       — sscanf считает второй аргумент,
         и возвращаемое значение будет 2.
    */
    if (sscanf(input_buffer, "%d %c",
               &input_index, &extra_char) != 1) {
        fprintf(stderr,
                "Ошибка: необходимо ввести только одно целое число без букв и символов.\n");
        return 1;
    }

    if (input_index < 0) {
        fprintf(stderr,
                "Ошибка: номер числа Фибоначчи не может быть отрицательным.\n");
        return 1;
    }

    if (input_index > MAX_FIB_INDEX) {
        fprintf(stderr,
                "Ошибка: слишком большое значение. Максимально допустимое — %d.\n",
                MAX_FIB_INDEX);
        return 1;
    }

    unsigned long long result =
        calculate_fibonacci((unsigned int)input_index);

    printf("Число Фибоначчи с номером %d равно %llu.\n",
           input_index, result);

    return 0;
}