/*
 * Лабораторная работа №3
 * Студент: Студент (номер: 21)
 * Тестовая программа для библиотеки libft
 */

#include "inc/libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

static void to_upper_iter(unsigned int i, char *c)
{
    (void)i;
    *c = (char)ft_toupper((unsigned char)*c);
}

static char to_upper_map(unsigned int i, char c)
{
    (void)i;
    return ((char)ft_toupper((unsigned char)c));
}

static void del_content(void *content)
{
    free(content);
}

static void *dup_content(void *content)
{
    return ft_strdup((char *)content);
}

static void print_content(void *content)
{
    printf("  -> %s\n", (char *)content);
}

static void test_char_functions(void)
{
    printf("=== Character functions ===\n");
    printf("ft_isalpha('a') = %d\n", ft_isalpha('a'));
    printf("ft_isalpha('1') = %d\n", ft_isalpha('1'));
    printf("ft_isdigit('5') = %d\n", ft_isdigit('5'));
    printf("ft_isalnum('z') = %d\n", ft_isalnum('z'));
    printf("ft_isascii(127) = %d\n", ft_isascii(127));
    printf("ft_isprint(' ') = %d\n", ft_isprint(' '));
    printf("ft_toupper('a') = %c\n", ft_toupper('a'));
    printf("ft_tolower('Z') = %c\n", ft_tolower('Z'));
    printf("ft_isspace(' ') = %d\n", ft_isspace(' '));
    printf("\n");
}

static void test_string_functions(void)
{
    char buf[64];
    char cat_buf[64];

    printf("=== String functions ===\n");
    printf("ft_strlen(\"hello\") = %zu\n", ft_strlen("hello"));
    printf("ft_strchr(\"hello\", 'l') = %s\n", ft_strchr("hello", 'l'));
    printf("ft_strrchr(\"hello\", 'l') = %s\n", ft_strrchr("hello", 'l'));
    printf("ft_strncmp(\"abc\", \"abd\", 3) = %d\n", ft_strncmp("abc", "abd", 3));
    printf("ft_strnstr(\"hello world\", \"world\", 11) = %s\n",
        ft_strnstr("hello world", "world", 11));

    ft_strlcpy(buf, "hello", sizeof(buf));
    printf("ft_strlcpy -> \"%s\"\n", buf);

    ft_strlcpy(cat_buf, "hello", sizeof(cat_buf));
    ft_strlcat(cat_buf, " world", sizeof(cat_buf));
    printf("ft_strlcat -> \"%s\"\n", cat_buf);
    printf("\n");
}

static void test_memory_functions(void)
{
    char buf[16];
    char src[] = "overlap test";
    char dst[32];

    printf("=== Memory functions ===\n");
    ft_memset(buf, 'X', 5);
    buf[5] = '\0';
    printf("ft_memset -> \"%s\"\n", buf);

    ft_bzero(buf, 5);
    printf("ft_bzero applied\n");

    ft_memcpy(dst, src, sizeof(src));
    printf("ft_memcpy -> \"%s\"\n", dst);

    ft_memmove(dst + 2, dst, 6);
    printf("ft_memmove (overlap) -> \"%s\"\n", dst);
    printf("\n");
}

static void test_conversion_functions(void)
{
    char *str;

    printf("=== Conversion functions ===\n");
    printf("ft_atoi(\"  -42\") = %d\n", ft_atoi("  -42"));
    printf("ft_atoi(\"+100\") = %d\n", ft_atoi("+100"));

    str = ft_itoa(42);
    printf("ft_itoa(42) = \"%s\"\n", str);
    free(str);

    str = ft_itoa(-2147483648);
    printf("ft_itoa(INT_MIN) = \"%s\"\n", str);
    free(str);
    printf("\n");
}

static void test_alloc_functions(void)
{
    char    *sub;
    char    *joined;
    char    *trimmed;
    char    **parts;
    char    *mapped;
    char    buf[32];
    void    *mem;
    int     i;

    printf("=== Allocation & string functions ===\n");

    mem = ft_calloc(4, sizeof(int));
    printf("ft_calloc(4, 4): %s\n", mem ? "OK" : "FAIL");
    free(mem);

    sub = ft_substr("Hello, World!", 7, 5);
    printf("ft_substr -> \"%s\"\n", sub);
    free(sub);

    joined = ft_strjoin("Hello, ", "World!");
    printf("ft_strjoin -> \"%s\"\n", joined);
    free(joined);

    trimmed = ft_strtrim("   hello   ", " ");
    printf("ft_strtrim -> \"%s\"\n", trimmed);
    free(trimmed);

    parts = ft_split("one two three", ' ');
    printf("ft_split:\n");
    i = 0;
    while (parts && parts[i])
    {
        printf("  [%d] = \"%s\"\n", i, parts[i]);
        free(parts[i]);
        i++;
    }
    free(parts);

    ft_strlcpy(buf, "hello", sizeof(buf));
    ft_striteri(buf, to_upper_iter);
    printf("ft_striteri (toupper) -> \"%s\"\n", buf);

    mapped = ft_strmapi("hello", to_upper_map);
    printf("ft_strmapi (toupper) -> \"%s\"\n", mapped);
    free(mapped);
    printf("\n");
}

static void test_output_functions(void)
{
    printf("=== Output functions (stdout) ===\n");
    ft_putchar_fd('A', 1);
    ft_putchar_fd('\n', 1);
    ft_putstr_fd("Hello from ft_putstr_fd\n", 1);
    ft_putendl_fd("Hello from ft_putendl_fd", 1);
    ft_putchar_fd('>', 1);
    ft_putnbr_fd(-2147483648, 1);
    ft_putchar_fd('\n', 1);
    printf("\n");
}

static void test_list_functions(void)
{
    t_list *lst;
    t_list *copy;
    t_list *node;

    printf("=== Linked list functions ===\n");

    lst = NULL;
    ft_lstadd_back(&lst, ft_lstnew(ft_strdup("first")));
    ft_lstadd_back(&lst, ft_lstnew(ft_strdup("second")));
    ft_lstadd_front(&lst, ft_lstnew(ft_strdup("zeroth")));

    printf("List size: %d\n", ft_lstsize(lst));
    printf("Last element: %s\n", (char *)ft_lstlast(lst)->content);
    printf("Elements:\n");
    ft_lstiter(lst, print_content);

    copy = ft_lstmap(lst, dup_content, del_content);
    printf("Mapped copy elements:\n");
    node = copy;
    while (node)
    {
        printf("  -> %s\n", (char *)node->content);
        node = node->next;
    }

    ft_lstclear(&lst, del_content);
    ft_lstclear(&copy, del_content);
    printf("Lists cleared.\n");
    printf("\n");
}

int main(void)
{
    printf("=== Тестирование libft (Student 21) ===\n\n");

    test_char_functions();
    test_string_functions();
    test_memory_functions();
    test_conversion_functions();
    test_alloc_functions();
    test_output_functions();
    test_list_functions();

    printf("All tests completed.\n");
    return (0);
}
