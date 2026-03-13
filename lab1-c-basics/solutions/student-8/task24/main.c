/*
* Лабораторная работа №1
* Студент: Галиуллина Рената (номер: 8)
* Вариант: 9
* Задание: 24 (Проверка вхождения подстроки в строку)
*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>          

#define MAX_STR_LEN 500

bool is_substring_present(const char *str, const char *sub) {
    if (sub[0] == '\0') {
        return true;
    }

    size_t str_len = strlen(str);
    size_t sub_len = strlen(sub);

    if (sub_len > str_len) {
        return false;
    }

    for (size_t i = 0; i <= str_len - sub_len; ++i) {
        size_t j;
        for (j = 0; j < sub_len; ++j) {
            if (str[i + j] != sub[j]) {
                break;
            }
        }
        if (j == sub_len) {
            return true;
        }
    }
    return false;
}

bool read_line(const char *prompt, char *buffer, size_t buffer_size) {
    printf("%s", prompt);
    fflush(stdout);

    if (fgets(buffer, buffer_size, stdin) == NULL) {
        return false;
    }

    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    } else {
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }
        return false;
    }
    return true;
}

int main(void) {
    setlocale(LC_ALL, "C");

    char str[MAX_STR_LEN];
    char sub[MAX_STR_LEN];

    printf("Программа проверяет, содержит ли строка заданную подстроку.\n");

    if (!read_line("Введите исходную строку: ", str, sizeof(str))) {
        if (feof(stdin)) {
            fprintf(stderr, "Ошибка: достигнут конец файла.\n");
        } else {
            fprintf(stderr, "Ошибка: строка слишком длинная");
        }
        return 1;
    }

    if (!read_line("Введите подстроку для поиска: ", sub, sizeof(sub))) {
        if (feof(stdin)) {
            fprintf(stderr, "Ошибка: достигнут конец файла");
        } else {
            fprintf(stderr, "Ошибка: подстрока слишком длинная");
        }
        return 1;
    }

    bool found = is_substring_present(str, sub);
    if (found) {
        printf("Результат: подстрока найдена в строке");
    } else {
        printf("Результат: подстрока  не найдена в строке");
    }

    return 0;
}