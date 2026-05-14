#include "matrix.h"

static void fill_matrix(matrix_t *a)
{
    if (!a || !a->matrix)
        return ;
    a->matrix[0][0] = 1;
    a->matrix[0][1] = 2;
    a->matrix[0][2] = 3;
    a->matrix[1][0] = 4;
    a->matrix[1][1] = 5;
    a->matrix[1][2] = 6;
}

static void print_test_result(char *name, int ok)
{
    ft_putstr_fd(name, 1);
    if (ok)
        ft_putendl_fd(": OK", 1);
    else
        ft_putendl_fd(": FAIL", 1);
}

static void test_errors(void)
{
    matrix_t *tmp;

    ft_putendl_fd("Error tests:", 1);
    tmp = create_matrix(0, 3);
    print_test_result("create_matrix(0, 3) returns NULL", tmp == NULL);
    tmp = create_matrix(-1, 2);
    print_test_result("create_matrix(-1, 2) returns NULL", tmp == NULL);
    tmp = mult_number(NULL, 2);
    print_test_result("mult_number(NULL, 2) returns NULL", tmp == NULL);
    tmp = transpose(NULL);
    print_test_result("transpose(NULL) returns NULL", tmp == NULL);
    ft_putchar_fd('\n', 1);
}

int main(void)
{
    matrix_t *a;
    matrix_t *b;
    matrix_t *t;

    test_errors();
    a = create_matrix(2, 3);
    if (!a)
        return (1);
    fill_matrix(a);
    ft_putendl_fd("Matrix A:", 1);
    print_matrix(a);
    ft_putchar_fd('\n', 1);
    b = mult_number(a, 2);
    if (!b)
    {
        remove_matrix(a);
        return (1);
    }
    ft_putendl_fd("A * 2:", 1);
    print_matrix(b);
    ft_putchar_fd('\n', 1);
    t = transpose(a);
    if (!t)
    {
        remove_matrix(a);
        remove_matrix(b);
        return (1);
    }
    ft_putendl_fd("Transpose A:", 1);
    print_matrix(t);
    remove_matrix(a);
    remove_matrix(b);
    remove_matrix(t);
    return (0);
}