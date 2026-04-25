#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>

static void print_ok(const char *test_name)
{
    printf("[OK] %s\n", test_name);
}

static void print_fail(const char *test_name, const char *message)
{
    printf("[FAIL] %s: %s\n", test_name, message);
}

void test_ft_isalpha(void)
{
    int tests[] = {'A', 'Z', 'a', 'z', '0', '9', ' ', '\n', 128, EOF};
    int i;
    int ok = 1;

    for (i = 0; i < (int)(sizeof(tests)/sizeof(tests[0])); i++)
    {
        int c = tests[i];
        int ft = ft_isalpha(c);
        int orig = isalpha(c);
        if ((ft != 0) != (orig != 0))
        {
            ok = 0;
            printf("  ft_isalpha(%d) = %d, expected %s\n", c, ft,
                   orig ? "non-zero" : "zero");
        }
    }
    if (ok)
        print_ok("ft_isalpha");
    else
        print_fail("ft_isalpha", "mismatch for some values");
}

void test_ft_isdigit(void)
{
    int tests[] = {'0', '9', 'A', 'a', ' ', '\n', 128};
    int i, ok = 1;

    for (i = 0; i < (int)(sizeof(tests)/sizeof(tests[0])); i++)
    {
        int c = tests[i];
        int ft = ft_isdigit(c);
        int orig = isdigit(c);

        // ✅ правильное сравнение (логическое)
        if ((ft != 0) != (orig != 0))
        {
            ok = 0;
            printf("  ft_isdigit(%d) = %d, expected %d\n", c, ft, orig);
        }
    }

    if (ok)
        print_ok("ft_isdigit");
    else
        print_fail("ft_isdigit", "mismatch");
}

void test_ft_isalnum(void)
{
    int tests[] = {'A', 'Z', 'a', 'z', '0', '9', ' ', '\n', 128};
    int i, ok = 1;
    for (i = 0; i < (int)(sizeof(tests)/sizeof(tests[0])); i++)
    {
        int c = tests[i];
        int ft = ft_isalnum(c);
        int orig = isalnum(c);
        if ((ft != 0) != (orig != 0))
        {
            ok = 0;
            printf("  ft_isalnum(%d) = %d, expected %s\n", c, ft,
                   orig ? "non-zero" : "zero");
        }
    }
    if (ok)
        print_ok("ft_isalnum");
    else
        print_fail("ft_isalnum", "mismatch");
}

void test_ft_isascii(void)
{
    int tests[] = {0, 127, 128, -1, 'A', ' '};
    int i, ok = 1;
    for (i = 0; i < (int)(sizeof(tests)/sizeof(tests[0])); i++)
    {
        int c = tests[i];
        int ft = ft_isascii(c);
        int orig = (c >= 0 && c <= 127) ? 1 : 0;
        if (ft != orig)
        {
            ok = 0;
            printf("  ft_isascii(%d) = %d, expected %d\n", c, ft, orig);
        }
    }
    if (ok)
        print_ok("ft_isascii");
    else
        print_fail("ft_isascii", "mismatch");
}

void test_ft_isprint(void)
{
    int tests[] = {' ', '~', 31, 127, 128, 'A'};
    int i, ok = 1;
    for (i = 0; i < (int)(sizeof(tests)/sizeof(tests[0])); i++)
    {
        int c = tests[i];
        int ft = ft_isprint(c);
        int orig = isprint(c);
        if ((ft != 0) != (orig != 0))
        {
            ok = 0;
            printf("  ft_isprint(%d) = %d, expected %s\n", c, ft,
                   orig ? "non-zero" : "zero");
        }
    }
    if (ok)
        print_ok("ft_isprint");
    else
        print_fail("ft_isprint", "mismatch");
}

void test_ft_toupper(void)
{
    char tests[] = {'a', 'z', 'A', 'Z', '0', ' ', '\n'};
    int i, ok = 1;
    for (i = 0; i < (int)(sizeof(tests)/sizeof(tests[0])); i++)
    {
        int c = tests[i];
        int ft = ft_toupper(c);
        int orig = toupper(c);
        if (ft != orig)
        {
            ok = 0;
            printf("  ft_toupper('%c') = %c, expected %c\n", c, ft, orig);
        }
    }
    if (ok)
        print_ok("ft_toupper");
    else
        print_fail("ft_toupper", "mismatch");
}

void test_ft_tolower(void)
{
    char tests[] = {'A', 'Z', 'a', 'z', '0', ' ', '\n'};
    int i, ok = 1;
    for (i = 0; i < (int)(sizeof(tests)/sizeof(tests[0])); i++)
    {
        int c = tests[i];
        int ft = ft_tolower(c);
        int orig = tolower(c);
        if (ft != orig)
        {
            ok = 0;
            printf("  ft_tolower('%c') = %c, expected %c\n", c, ft, orig);
        }
    }
    if (ok)
        print_ok("ft_tolower");
    else
        print_fail("ft_tolower", "mismatch");
}

void test_ft_strlen(void)
{
    const char *tests[] = {"Hello", "", "42", "A long string with spaces"};
    int i, ok = 1;
    for (i = 0; i < (int)(sizeof(tests)/sizeof(tests[0])); i++)
    {
        size_t ft = ft_strlen(tests[i]);
        size_t orig = strlen(tests[i]);
        if (ft != orig)
        {
            ok = 0;
            printf("  ft_strlen(\"%s\") = %zu, expected %zu\n", tests[i], ft, orig);
        }
    }
    if (ok)
        print_ok("ft_strlen");
    else
        print_fail("ft_strlen", "mismatch");
}

void test_ft_strchr(void)
{
    const char *s = "test string";
    int ch = 's';
    char *ft = ft_strchr(s, ch);
    char *orig = strchr(s, ch);
    if (ft == orig)
        print_ok("ft_strchr");
    else
        print_fail("ft_strchr", "wrong pointer");
    ft = ft_strchr(s, 'x');
    orig = strchr(s, 'x');
    if (ft == orig)
        print_ok("ft_strchr");
    else
        print_fail("ft_strchr (not found)", "should be NULL");
}

void test_ft_strrchr(void)
{
    const char *s = "test string";
    int ch = 't';
    char *ft = ft_strrchr(s, ch);
    char *orig = strrchr(s, ch);
    if (ft == orig)
        print_ok("ft_strrchr");
    else
        print_fail("ft_strrchr", "wrong pointer");
}

void test_ft_strnstr(void)
{
    const char *big = "Hello world";
    const char *little = "world";
    char *ft = ft_strnstr(big, little, 12);
    char *expected = (strlen(little) <= 12) ? (char *)(big + 6) : NULL;
    if (ft == expected)
        print_ok("ft_strnstr");
    else
        print_fail("ft_strnstr", "mismatch");

    ft = ft_strnstr(big, little, 5);
    if (ft == NULL)
        print_ok("ft_strnstr");
    else
        print_fail("ft_strnstr limited", "should be NULL");
}

void test_ft_strncmp(void)
{
    const char *s1 = "Hello";
    const char *s2 = "Helxo";
    int n = 4;
    int ft = ft_strncmp(s1, s2, n);
    int orig = strncmp(s1, s2, n);
    if ((ft < 0) == (orig < 0) && (ft > 0) == (orig > 0) && (ft == 0) == (orig == 0))
        print_ok("ft_strncmp");
    else
        print_fail("ft_strncmp", "mismatch in comparison sign");
}

void test_ft_atoi(void)
{
    const char *tests[] = {"42", "-42", "   +123", "2147483647", "-2147483648", "0", "abc"};
    int i, ok = 1;
    for (i = 0; i < (int)(sizeof(tests)/sizeof(tests[0])); i++)
    {
        int ft = ft_atoi(tests[i]);
        int orig = atoi(tests[i]);
        if (ft != orig)
        {
            ok = 0;
            printf("  ft_atoi(\"%s\") = %d, expected %d\n", tests[i], ft, orig);
        }
    }
    if (ok)
        print_ok("ft_atoi");
    else
        print_fail("ft_atoi", "mismatch");
}

void test_ft_calloc(void)
{
    size_t nmemb = 5;
    size_t size = sizeof(int);
    int *ft = (int *)ft_calloc(nmemb, size);
    if (!ft)
    {
        print_fail("ft_calloc", "allocation failed");
        return;
    }
    int i, ok = 1;
    for (i = 0; i < (int)nmemb; i++)
        if (ft[i] != 0)
            ok = 0;
    if (ok)
        print_ok("ft_calloc");
    else
        print_fail("ft_calloc", "memory not zeroed");
    free(ft);
}

void test_ft_strdup(void)
{
    const char *s = "duplicate me";
    char *ft = ft_strdup(s);
    if (ft && strcmp(ft, s) == 0)
        print_ok("ft_strdup");
    else
        print_fail("ft_strdup", "mismatch");
    free(ft);
}

void test_ft_substr(void)
{
    const char *s = "Hello, world!";
    char *sub = ft_substr(s, 7, 5);
    if (sub && strcmp(sub, "world") == 0)
        print_ok("ft_substr");
    else
        print_fail("ft_substr", "wrong result");
    free(sub);
}

void test_ft_strjoin(void)
{
    const char *s1 = "Hello";
    const char *s2 = "World";
    char *joined = ft_strjoin(s1, s2);
    if (joined && strcmp(joined, "HelloWorld") == 0)
        print_ok("ft_strjoin");
    else
        print_fail("ft_strjoin", "wrong result");
    free(joined);
}

void test_ft_strtrim(void)
{
    const char *s = "   xxx   ";
    const char *set = " ";          
    char *trimmed = ft_strtrim(s, set);
    if (trimmed && strcmp(trimmed, "xxx") == 0)
        print_ok("ft_strtrim");
    else
        print_fail("ft_strtrim", "wrong result");
    free(trimmed);
}

void test_ft_split(void)
{
    const char *s = "hello world 42";
    char c = ' ';
    char **result = ft_split(s, c);
    if (result && strcmp(result[0], "hello") == 0 && strcmp(result[1], "world") == 0 && strcmp(result[2], "42") == 0 && result[3] == NULL)
        print_ok("ft_split");
    else
        print_fail("ft_split", "wrong result");
    // free
    for (int i = 0; result[i]; i++)
        free(result[i]);
    free(result);
}

void test_ft_itoa(void)
{
    int tests[] = {0, 42, -42, 2147483647, -2147483648};
    int i, ok = 1;
    for (i = 0; i < (int)(sizeof(tests)/sizeof(tests[0])); i++)
    {
        char *str = ft_itoa(tests[i]);
        if (!str)
        {
            ok = 0;
            continue;
        }
        int val = atoi(str);
        if (val != tests[i])
            ok = 0;
        free(str);
    }
    if (ok)
        print_ok("ft_itoa");
    else
        print_fail("ft_itoa", "wrong conversion");
}

static char char_wrapper(unsigned int idx, char c)
{
    (void)idx;
    return (char)toupper((unsigned char)c);
}

void test_ft_strmapi(void)
{
    char *s = "abc";
    char *result = ft_strmapi(s, char_wrapper);
    if (result && strcmp(result, "ABC") == 0)
        print_ok("ft_strmapi");
    else
        print_fail("ft_strmapi", "wrong result");
    free(result);
}

static void stub_iter(unsigned int idx, char *c)
{
    (void)idx;
    (void)c;
}

void test_ft_striteri(void)
{
    char s[] = "abc";
    ft_striteri(s, stub_iter);
    print_ok("ft_striteri");
}

void test_ft_putchar_fd(void)
{
    ft_putchar_fd('A', 1);
    print_ok("ft_putchar_fd");
}

void test_ft_putstr_fd(void)
{
    ft_putstr_fd("Hello", 1);
    print_ok("ft_putstr_fd");
}

void test_ft_putendl_fd(void)
{
    ft_putendl_fd("end line", 1);
    print_ok("ft_putendl_fd");
}

void test_ft_putnbr_fd(void)
{
    ft_putnbr_fd(42, 1);
    ft_putnbr_fd(-2147483648, 1);
    print_ok("ft_putnbr_fd");
}

void test_ft_isspace(void)
{
    int tests[] = {' ', '\t', '\n', '\v', '\f', '\r', 'A', '0'};
    int i, ok = 1;
    for (i = 0; i < (int)(sizeof(tests)/sizeof(tests[0])); i++)
    {
        int c = tests[i];
        int ft = ft_isspace(c);
        int orig = isspace(c);
        if ((ft != 0) != (orig != 0))
        {
            ok = 0;
            printf("  ft_isspace(%d) = %d, expected %s\n", c, ft,
                   orig ? "non-zero" : "zero");
        }
    }
    if (ok)
        print_ok("ft_isspace");
    else
        print_fail("ft_isspace", "mismatch");
}

void test_ft_strlcpy(void)
{
    char dst[10];
    const char *src = "Hello";
    size_t ft = ft_strlcpy(dst, src, sizeof(dst));
    size_t expected_len = strlen(src);
    if (ft == expected_len && strcmp(dst, src) == 0)
        print_ok("ft_strlcpy ");
    else
        print_fail("ft_strlcpy", "mismatch");

    char dst2[5];
    ft = ft_strlcpy(dst2, src, sizeof(dst2));
    if (ft == expected_len && strcmp(dst2, "Hell") == 0)
        print_ok("ft_strlcpy");
    else
        print_fail("ft_strlcpy", "truncation mismatch");
}

void test_ft_strlcat(void)
{
    char dst[20] = "Hello";
    const char *src = "World";
    size_t ft = ft_strlcat(dst, src, sizeof(dst));
    size_t expected_len = strlen("Hello") + strlen(src);
    if (ft == expected_len && strcmp(dst, "HelloWorld") == 0)
        print_ok("ft_strlcat (full)");
    else
        print_fail("ft_strlcat", "mismatch");

    char dst2[10] = "Hello";
    ft = ft_strlcat(dst2, src, sizeof(dst2));
    if (ft == expected_len && strcmp(dst2, "HelloWorl") == 0)
        print_ok("ft_strlcat");
    else
        print_fail("ft_strlcat", "truncation mismatch");
}

void test_ft_memset(void)
{
    char buf[10];
    ft_memset(buf, 'A', 5);
    int i, ok = 1;
    for (i = 0; i < 5; i++)
        if (buf[i] != 'A')
            ok = 0;
    if (ok)
        print_ok("ft_memset");
    else
        print_fail("ft_memset", "wrong fill");
}

void test_ft_bzero(void)
{
    char buf[10] = "abcdefgh";
    ft_bzero(buf, 5);
    int i, ok = 1;
    for (i = 0; i < 5; i++)
        if (buf[i] != 0)
            ok = 0;
    if (ok)
        print_ok("ft_bzero");
    else
        print_fail("ft_bzero", "not zeroed");
}

void test_ft_memcpy(void)
{
    char src[] = "hello";
    char dst[10];
    ft_memcpy(dst, src, 5);
    if (memcmp(dst, src, 5) == 0)
        print_ok("ft_memcpy");
    else
        print_fail("ft_memcpy", "mismatch");
}

void test_ft_memmove(void)
{
    char str[] = "abcdef";
    ft_memmove(str + 2, str, 3);
    if (memcmp(str, "ababc", 5) == 0)
        print_ok("ft_memmove");
    else
        print_fail("ft_memmove", "overlap handling wrong");
}


void test_ft_lstnew(void)
{
    int val = 42;
    t_list *node = ft_lstnew(&val);
    if (node && node->content == &val && node->next == NULL)
        print_ok("ft_lstnew");
    else
        print_fail("ft_lstnew", "wrong node");
    free(node);
}

void test_ft_lstadd_front(void)
{
    t_list *head = NULL;
    int a = 1, b = 2;
    t_list *node1 = ft_lstnew(&a);
    t_list *node2 = ft_lstnew(&b);
    ft_lstadd_front(&head, node2);
    ft_lstadd_front(&head, node1);
    if (head == node1 && head->next == node2 && head->next->next == NULL)
        print_ok("ft_lstadd_front");
    else
        print_fail("ft_lstadd_front", "wrong order");
    free(node1);
    free(node2);
}

void test_ft_lstsize(void)
{
    t_list *head = NULL;
    int a, b, c;
    t_list *node1 = ft_lstnew(&a);
    t_list *node2 = ft_lstnew(&b);
    t_list *node3 = ft_lstnew(&c);
    ft_lstadd_back(&head, node1);
    ft_lstadd_back(&head, node2);
    ft_lstadd_back(&head, node3);
    int size = ft_lstsize(head);
    if (size == 3)
        print_ok("ft_lstsize");
    else
        print_fail("ft_lstsize", "wrong size");
    free(node1); free(node2); free(node3);
}

void test_ft_lstlast(void)
{
    t_list *head = NULL;
    int a, b;
    t_list *node1 = ft_lstnew(&a);
    t_list *node2 = ft_lstnew(&b);
    ft_lstadd_back(&head, node1);
    ft_lstadd_back(&head, node2);
    t_list *last = ft_lstlast(head);
    if (last == node2)
        print_ok("ft_lstlast");
    else
        print_fail("ft_lstlast", "wrong last");
    free(node1); free(node2);
}

void test_ft_lstadd_back(void)
{
    t_list *head = NULL;
    int a, b;
    t_list *node1 = ft_lstnew(&a);
    t_list *node2 = ft_lstnew(&b);
    ft_lstadd_back(&head, node1);
    ft_lstadd_back(&head, node2);
    if (head == node1 && head->next == node2 && head->next->next == NULL)
        print_ok("ft_lstadd_back");
    else
        print_fail("ft_lstadd_back", "wrong order");
    free(node1); free(node2);
}

void test_ft_lstdelone(void)
{
    int *val = malloc(sizeof(int));
    *val = 42;
    t_list *node = ft_lstnew(val);
    ft_lstdelone(node, free);
    print_ok("ft_lstdelone");
}

void test_ft_lstclear(void)
{
    t_list *head = NULL;
    int *a = malloc(sizeof(int)); *a = 1;
    int *b = malloc(sizeof(int)); *b = 2;
    t_list *node1 = ft_lstnew(a);
    t_list *node2 = ft_lstnew(b);
    ft_lstadd_back(&head, node1);
    ft_lstadd_back(&head, node2);
    ft_lstclear(&head, free);
    if (head == NULL)
        print_ok("ft_lstclear");
    else
        print_fail("ft_lstclear", "head not NULL");
}

static void stub_lst_iter(void *content)
{
    (void)content;
}

void test_ft_lstiter(void)
{
    t_list *head = NULL;
    int a = 1, b = 2;
    t_list *node1 = ft_lstnew(&a);
    t_list *node2 = ft_lstnew(&b);
    ft_lstadd_back(&head, node1);
    ft_lstadd_back(&head, node2);
    ft_lstiter(head, stub_lst_iter);
    print_ok("ft_lstiter");
    free(node1); free(node2);
}

static void *identity(void *content)
{
    return content;
}

void test_ft_lstmap(void)
{
    t_list *head = NULL;
    int a = 1, b = 2;
    t_list *node1 = ft_lstnew(&a);
    t_list *node2 = ft_lstnew(&b);
    ft_lstadd_back(&head, node1);
    ft_lstadd_back(&head, node2);
    t_list *new = ft_lstmap(head, identity, NULL);
    if (new != NULL && ft_lstsize(new) == 2)
        print_ok("ft_lstmap");
    else
        print_fail("ft_lstmap", "something wrong");
    ft_lstclear(&head, NULL);
    ft_lstclear(&new, NULL);
}

int main(void)
{
    printf("\n=== Тестирование libft ===\n\n");

    test_ft_isalpha();
    test_ft_isdigit();
    test_ft_isalnum();
    test_ft_isascii();
    test_ft_isprint();
    test_ft_toupper();
    test_ft_tolower();
    test_ft_strlen();
    test_ft_strchr();
    test_ft_strrchr();
    test_ft_strnstr();
    test_ft_strncmp();
    test_ft_atoi();
    test_ft_calloc();
    test_ft_strdup();
    test_ft_substr();
    test_ft_strjoin();
    test_ft_strtrim();
    test_ft_split();
    test_ft_itoa();
    test_ft_strmapi();
    test_ft_striteri();
    test_ft_putchar_fd();
    test_ft_putstr_fd();
    test_ft_putendl_fd();
    test_ft_putnbr_fd();
    test_ft_isspace();
    test_ft_strlcpy();
    test_ft_strlcat();
    test_ft_memset();
    test_ft_bzero();
    test_ft_memcpy();
    test_ft_memmove();
    test_ft_lstnew();
    test_ft_lstadd_front();
    test_ft_lstsize();
    test_ft_lstlast();
    test_ft_lstadd_back();
    test_ft_lstdelone();
    test_ft_lstclear();
    test_ft_lstiter();
    test_ft_lstmap();

    printf("\n=== Тестирование завершено ===\n");
    return 0;
}