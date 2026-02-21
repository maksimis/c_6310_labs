/*
 * Лабораторная работа №1
 * Студент: Валиев Марсель (номер: 6)
 * Вариант: 7
 * Задание: 7 (Проверка числа на простоту)
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>   // for memcpy (to generate -Wsizeof-pointer-memaccess)

// ---------------------------------------------------------------------
// Core functionality – no warnings here
// ---------------------------------------------------------------------

/**
 * Checks whether a given integer is prime.
 * @param n non‑negative integer
 * @return true if prime, false otherwise
 */
bool is_prime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main(void) {
    int num;
    printf("Enter an integer: ");
    if (scanf("%d", &num) != 1) {
        fprintf(stderr, "Invalid input.\n");
        return 1;
    }
    if (num < 0) {
        fprintf(stderr, "Negative number.\n");
        return 1;
    }
    if (is_prime(num))
        printf("%d is prime.\n", num);
    else
        printf("%d is not prime.\n", num);
    return 0;
}

// ---------------------------------------------------------------------
// Deliberately added warnings (all code below is never executed)
// ---------------------------------------------------------------------

// ---------- Warning 1: -Wunused-variable ----------
static void warn_unused_var(void) {
    int unused_local;               // never used
}

// ---------- Warning 2: -Wunused-parameter ----------
static void warn_unused_param(int x) {
    // parameter x is not used
}

// ---------- Warning 3: -Wunused-function ----------
static void never_called(void) {
    // this static function is never called
}

// ---------- Warning 4: -Wreturn-type ----------
static int missing_return(void) {
    // no return statement
}

// ---------- Warning 5: -Wsign-compare ----------
static void warn_sign_compare(void) {
    int signed_val = -1;
    unsigned int unsigned_val = 10;
    if (signed_val < unsigned_val) {   // comparison between signed and unsigned
        // do nothing
    }
}

// ---------- Warning 6: -Wuninitialized ----------
static void warn_uninitialized(void) {
    int a;                     // uninitialized
    int b = a + 1;             // reading uninitialized 'a'
    // b is never used – that's another warning, but we count only one
}

// ---------- Warning 7: -Wparentheses ----------
static void warn_parentheses(void) {
    int x;
    if (x = 5) {               // assignment inside if, missing parentheses
        // empty
    }
}

// ---------- Warning 8: -Wempty-body ----------
static void warn_empty_body(void) {
    int cond = 1;
    if (cond);                 // empty body (semicolon)
}

// ---------- Warning 9: -Wchar-subscripts ----------
static void warn_char_subscript(void) {
    char idx = 'a';
    int arr[256];
    int val = arr[idx];        // char used as array index
}

// ---------- Warning 10: -Wsizeof-pointer-memaccess ----------
static void warn_sizeof_pointer(void) {
    int *ptr = NULL;
    int dest[10];
    memcpy(dest, ptr, sizeof(ptr));   // suspicious: sizeof(ptr) instead of sizeof(*ptr)
}

// ---------- Bonus: -Wextra warnings ----------

// Warning 11: -Wtype-limits
static void warn_type_limits(void) {
    unsigned int u = 42;
    if (u >= 0) {              // always true
        // do nothing
    }
}

// Warning 12: -Wmissing-field-initializers
struct S {
    int a;
    int b;
    int c;
};
static struct S warn_missing_field = {1};   // missing initializers for b and c

// Warning 13: -Woverflow
static void warn_overflow(void) {
    int x = 2147483647 + 1;    // overflow in constant expression
}

// Warning 14: -Wshift-count-overflow
static void warn_shift_overflow(void) {
    int x = 1 << 40;           // shift exceeds width of type
}

// Warning 15: -Wcast-align
static void warn_cast_align(void) {
    char buffer[4];
    int *p = (int*)buffer;     // cast from char* to int* may break alignment
}