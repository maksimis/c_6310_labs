/*
* Лабораторная работа №1
 * Студент: Садырттинова Ильвина (номер: 23)
 * Вариант: 24
 * Задание: 24 (Проверка вхождения подстроки в строку)
 */

#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <windows.h>

#define MAX_STRING_LENGTH 100

/* Функция проверки: содержится ли substring в text */
int contains_substring(const wchar_t *text, const wchar_t *substring) {
    size_t text_length = wcslen(text);
    size_t substring_length = wcslen(substring);

    if (substring_length == 0) {
        return 1;
    }

    if (substring_length > text_length) {
        return 0;
    }

    for (size_t i = 0; i <= text_length - substring_length; i++) {
        size_t j = 0;

        while (j < substring_length && text[i + j] == substring[j]) {
            j++;
        }

        if (j == substring_length) {
            return 1;
        }
    }

    return 0;
}

int main(void) {
    // Устанавливаем кодировку для Windows
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");
    
    wchar_t main_string[MAX_STRING_LENGTH];
    wchar_t substring[MAX_STRING_LENGTH];

    wprintf(L"Введите основную строку: ");
    if (fgetws(main_string, MAX_STRING_LENGTH, stdin) == NULL) {
        wprintf(L"Ошибка ввода основной строки.\n");
        return 1;
    }
    // Удаляем символ новой строки
    size_t len = wcslen(main_string);
    if (len > 0 && main_string[len-1] == L'\n') {
        main_string[len-1] = L'\0';
    }

    wprintf(L"Введите подстроку: ");
    if (fgetws(substring, MAX_STRING_LENGTH, stdin) == NULL) {
        wprintf(L"Ошибка ввода подстроки.\n");
        return 1;
    }
    // Удаляем символ новой строки
    len = wcslen(substring);
    if (len > 0 && substring[len-1] == L'\n') {
        substring[len-1] = L'\0';
    }

    if (contains_substring(main_string, substring)) {
        wprintf(L"Подстрока \"%ls\" содержится в строке \"%ls\".\n", substring, main_string);
    } else {
        wprintf(L"Подстрока \"%ls\" НЕ содержится в строке \"%ls\".\n", substring, main_string);
    }

    return 0;
}