/*
 * Лабораторная работа №2
 * Студент: Садырттинова Ильвина (номер: 23)
 * Вариант: 24
 * Задание: 24 (Проверка вхождения подстроки в строку)
 * Количество предупреждений: 15 (из них 5(8) -Wextra  и 10 -Wall)
 */

#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <windows.h>

#define MAX_STRING_LENGTH 100

// Пред 1: -Wunused-function — неиспользуемая статическая функция
static void func() {
}

// Пред 2: -Wreturn-type — функция без return
int get_number() {
    int value = 42;
    printf("%d\n", value);
}

 // Пред 3: -Wunused-parameter — неиспользуемый параметр функции
int contains_substring(const wchar_t *text, const wchar_t *substring, int flag) {

    size_t substring_length = wcslen(substring);
    size_t text_length = wcslen(text);

    // Пред 4: -Wunused-variable — переменная не используется
    int unused_global = 42;

    // Пред 5: -Wsign-compare — сравнение знакового и беззнакового типов
    int a = -1;
    unsigned int b = 5;
    if (a < b) { }

    // Пред 6: -Wuninitialized — использование неинициализированной переменной
    int x;
    printf("%d", x);

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

// Пред 7: -Wparentheses — присваивание в условии
void parentheses_warning(int a, int b) {
    if (a = b) {
        printf("проверка \n");
    }
}

// Пред 8: -Wchar-subscripts — char используется как индекс массива
void char_index_warning() {
    char c = 2;
    int arr[5] = {1,2,3,4,5};
    int value = arr[c];
    printf("%d", value);
}

// Пред 9: -Wempty-body — пустое тело if
void empty_body_warning(int x) {
    if (x > 5);

}

// Пред 10 : -Wdiv-by-zero — деление на ноль 
void division_warning() {
    int div_by_zero = 100 / 0;
    printf("%d", div_by_zero);

}

// Бонус 1: -Wtype-limits — сравнение всегда истинно
void type_limits_warning() {
    unsigned int u = 5;
    if (u >= 0) {
    }

}

// Бонус 2: -Wunused-but-set-variable — значение присвоено, но не используется
void unused_but_set_warning() {
    int y = 10;
    y = 20;

}

// Бонус 3: -Woverflow — переполнение int
int overflow_warning = 2147483647 + 1;


// Бонус 4: -Wmissing-field-initializers — пропущено поле структуры
struct Point {
    int x;
    int y;
    int z;

};

void missing_fields_warning() {
    struct Point p = {1, 2};
    printf("%d %d", p.x, p.y);
}

// Бонус 5: -Wshift-count-overflow — слишком большой сдвиг
int shift_overflow_warning() {
    int x = 1;
    return x << 100;
}


int main(void) {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "ru_RU.UTF-8");
    // Вызовы функций с бонусными предупреждениями
    type_limits_warning();
    unused_but_set_warning();
    shift_overflow_warning();

    wchar_t main_string[MAX_STRING_LENGTH];
    wchar_t substring[MAX_STRING_LENGTH];

    wprintf(L"Введите основную строку: ");

    if (fgetws(main_string, MAX_STRING_LENGTH, stdin) == NULL) {

        wprintf(L"Ошибка ввода основной строки.\n");
        return 1;

    }

    size_t len = wcslen(main_string);

    if (len > 0 && main_string[len-1] == L'\n') {
        main_string[len-1] = L'\0';
    }

    wprintf(L"Введите подстроку: ");

    if (fgetws(substring, MAX_STRING_LENGTH, stdin) == NULL) {

        wprintf(L"Ошибка ввода подстроки.\n");
        return 1;

    }

    len = wcslen(substring);
    if (len > 0 && substring[len-1] == L'\n') {
        substring[len-1] = L'\0';
    }

    if (contains_substring(main_string, substring, 0)) {

        wprintf(L"Подстрока \"%ls\" содержится в строке \"%ls\".\n", substring, main_string);

    } else {

        wprintf(L"Подстрока \"%ls\" НЕ содержится в строке \"%ls\".\n", substring, main_string);

    }

    return 0;

}