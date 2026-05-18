/*
 * Лабораторная работа №1
 * Студент: Галиуллина Рената (номер: 8)
 * Вариант: 9
 * Задание: 9 (Проверка строки на палиндром)
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>

#define MIN_LEN 1
#define MAX_LEN 500
#define BUFFER_SIZE (MAX_LEN + 2U)

static bool is_palindrome(const wchar_t *str) {
    size_t len = wcslen(str);
    for (size_t i = 0; i < len / 2; ++i) {
        if (str[i] != str[len - 1 - i])
            return false;
    }
    return true;
}

int main(void) {
    setlocale(LC_ALL, "en_US.UTF-8"); 

    char input[BUFFER_SIZE];

    printf("Введите строку, чтобы проверить, является ли она палиндромом (от 1 до 500 символов): ");

    if (fgets(input, sizeof(input), stdin) == NULL) {
        fprintf(stderr, "Ошибка чтения");
        return 1;
    }

    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
        --len;
    }

    if (len < MIN_LEN) {
        fprintf(stderr, "Ошибка: введите хотя бы 1 символ");
        return 1;
    }

    wchar_t *wide_str = malloc((len + 1) * sizeof(wchar_t));
    if (!wide_str) {
        fprintf(stderr, "Ошибка памяти");
        return 1;
    }

    size_t converted = mbstowcs(wide_str, input, len + 1);
    if (converted == (size_t)-1) {
        fprintf(stderr, "Ошибка преобразования строки");
        free(wide_str);
        return 1;
    }

    if (converted > MAX_LEN) {
        fprintf(stderr, "Ошибка: введите не более 500 символов");
        free(wide_str);
        return 1;
    }

    if (is_palindrome(wide_str)) {
        printf("Строка \"%s\" палиндром.\n", input);
    } else {
        printf("Строка \"%s\" не палиндром.\n", input);
    }

    free(wide_str);
    return 0;
}