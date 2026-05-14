/*
 * Лабораторная работа №1
 * Студент: Садырттинова Ильвина (номер: 23)
 * Вариант: 24
 * Задание: 9 (Проверка строки на палиндром)
 */

#include <stdio.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>

#define MAX_STRING_LENGTH 100

int is_palindrome(const wchar_t *text) {
    size_t left = 0;
    size_t right = wcslen(text) - 1;
    
    if (right == 0) return 1;
    
    while (left < right) {
        // Пропускаем не-буквенные символы слева
        while (left < right && !iswalpha(text[left])) {
            left++;
        }
        // Пропускаем не-буквенные символы справа
        while (left < right && !iswalpha(text[right])) {
            right--;
        }
        
        // Сравниваем символы в нижнем регистре
        if (towlower(text[left]) != towlower(text[right])) {
            return 0;
        }
        
        left++;
        right--;
    }
    
    return 1;
}

int main(void) {
    setlocale(LC_ALL, "");
    wchar_t input_string[MAX_STRING_LENGTH];
    
    wprintf(L"Введите строку: ");
    if (fgetws(input_string, MAX_STRING_LENGTH, stdin) == NULL) {
        wprintf(L"Ошибка ввода.\n");
        return 1;
    }
    
    size_t len = wcslen(input_string);
    if (len > 0 && input_string[len-1] == L'\n') {
        input_string[len-1] = L'\0';
    }
    
    if (is_palindrome(input_string)) {
        wprintf(L"Строка является палиндромом.\n");
    } else {
        wprintf(L"Строка НЕ является палиндромом.\n");
    }
    
    return 0;
}