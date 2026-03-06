// Лабораторная работа №1.
// Поликарпов Никита №22. 
// Вариант 23. 
// Задание 23: Факториал числа с использованием цикла while
// Количество предупреждений - 15 (10 WALL и 5 WEXTRA)
#include <stdio.h>

unsigned long long factorial(int n, int err0) { // -Wunused-parameter (WEXTRA)
    unsigned long long result = 1;

    // WALL
    int err1 = 42; // 1 -Wunused-variable
    if (n > 9); // 2 -Wempty-body
    if (n = 0) {} // 3 -Wparentheses
    // WALL

    while (n > 1) {
        result *= n;
        n--;
    }
    return result;
}

int main() {
    int n;
    unsigned int limit = 65;
    10 + 20; // 4 -Wunused-value
    printf("Vvedite chislo dl'a vychicleniya faktoriala: ");
    if (scanf("%d", &n) != 1 || n < 0 || n > limit) { // -Wsign-compare (WEXTRA)
        printf("Oshibka vvoda: chislo bolshe 65/vvedena stroka/vvedeno otricatel'noe chislo!\n");
        return 1;
    }

    // WALL & WEXTRA
    if (0) printf("%d", 3.14); // 5 -Wformat=
    if (printf == NULL) {} // 6 -Waddress
    int i = 0;
    if (0) i = i++ + ++i; // 7 -Wsequence-point
    empty_label: // 8 -Wunused-label
    int a[5]; // 9 -Wunused-but-set-variable
    char idx = 1;
    if (0) a[idx] = 0; // 10 -Wchar-subscripts
    if (0) { int m; m = m; }
    unsigned int u_val = 10;
    if (u_val >= 0) { /* Always true */ } // -Wtype-limits (WEXTRA)
    struct { int x; int y; } op = {1}; // -Wmissing-field-initializers (WEXTRA)
    int garbage;
    if (n < 0) {
        printf("%d", garbage); // -Wmaybe-uninitialized (WEXTRA)
    }
    // WALL & WEXTRA

    printf("Faktorial chisla %d: %llu\n", n, factorial(n, 0));
    return 0;
}