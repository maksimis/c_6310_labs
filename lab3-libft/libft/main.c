#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void test_char_functions(void)
{
    printf("=== Тестирование функций проверки символов ===\n\n");

    printf("ft_isalpha('A') = %d (оригинал: %d)\n", ft_isalpha('A'), isalpha('A'));
    printf("ft_isalpha('1') = %d (оригинал: %d)\n", ft_isalpha('1'), isalpha('1'));
    printf("ft_isdigit('5') = %d (оригинал: %d) [оба ненулевые = true]\n", ft_isdigit('5'), isdigit('5'));
    printf("ft_isdigit('a') = %d (оригинал: %d)\n", ft_isdigit('a'), isdigit('a'));
    printf("ft_isalnum('Z') = %d (оригинал: %d)\n", ft_isalnum('Z'), isalnum('Z'));
    printf("ft_isalnum('@') = %d (оригинал: %d)\n", ft_isalnum('@'), isalnum('@'));
    printf("ft_isascii(65) = %d (оригинал: %d)\n", ft_isascii(65), isascii(65));
    printf("ft_isascii(200) = %d (оригинал: %d)\n", ft_isascii(200), isascii(200));
    printf("ft_isprint(' ') = %d (оригинал: %d) [оба ненулевые = true]\n", ft_isprint(' '), isprint(' '));
    printf("ft_isprint('\\n') = %d (оригинал: %d)\n", ft_isprint('\n'), isprint('\n'));
    printf("ft_toupper('a') = %c (оригинал: %c)\n", ft_toupper('a'), toupper('a'));
    printf("ft_tolower('Z') = %c (оригинал: %c)\n", ft_tolower('Z'), tolower('Z'));
    printf("ft_isspace(' ') = %d (оригинал: %d) [оба ненулевые = true]\n", ft_isspace(' '), isspace(' '));
    printf("ft_isspace('a') = %d (оригинал: %d)\n", ft_isspace('a'), isspace('a'));
    printf("\n");
}

void test_string_functions(void)
{
    printf("=== Тестирование функций работы со строками ===\n\n");

    char *test1 = "Hello, world!";
    char *test2 = "";
    char *test3 = "42";

    printf("ft_strlen(\"%s\") = %zu (оригинал: %zu)\n", test1, ft_strlen(test1), strlen(test1));
    printf("ft_strlen(\"%s\") = %zu (оригинал: %zu)\n", test2, ft_strlen(test2), strlen(test2));
    printf("ft_strlen(\"%s\") = %zu (оригинал: %zu)\n", test3, ft_strlen(test3), strlen(test3));

    printf("ft_strchr(\"Hello\", 'e') = %s\n", ft_strchr("Hello", 'e'));
    printf("ft_strchr(\"Hello\", 'z') = %s\n", ft_strchr("Hello", 'z'));
    printf("ft_strrchr(\"Hello\", 'l') = %s\n", ft_strrchr("Hello", 'l'));

    printf("ft_strnstr(\"Hello, world!\", \"world\", 13) = %s\n", ft_strnstr("Hello, world!", "world", 13));
    printf("ft_strnstr(\"Hello, world!\", \"world\", 5) = %s\n", ft_strnstr("Hello, world!", "world", 5));

    printf("ft_strncmp(\"abc\", \"abd\", 3) = %d\n", ft_strncmp("abc", "abd", 3));
    printf("ft_strncmp(\"abc\", \"abc\", 3) = %d\n", ft_strncmp("abc", "abc", 3));

    char buf[20];
    ft_strlcpy(buf, "Hello", sizeof(buf));
    printf("ft_strlcpy(buf, \"Hello\", sizeof(buf)) -> buf = \"%s\"\n", buf);

    char buf2[30] = "Hello ";
    ft_strlcat(buf2, "world", sizeof(buf2));
    printf("ft_strlcat(buf2, \"world\", sizeof(buf2)) -> buf2 = \"%s\"\n", buf2);
    printf("\n");
}

void test_memory_functions(void)
{
    printf("=== Тестирование функций работы с памятью ===\n\n");

    char buf[10];
    ft_memset(buf, 'A', 5);
    buf[5] = '\0';
    printf("ft_memset(buf, 'A', 5) -> buf = \"%s\"\n", buf);

    char buf2[10];
    ft_bzero(buf2, 10);
    printf("ft_bzero(buf2, 10) -> buf2[0] = %d\n", buf2[0]);

    char src[] = "Hello";
    char dest[10];
    ft_memcpy(dest, src, 6);
    printf("ft_memcpy(dest, \"Hello\", 6) -> dest = \"%s\"\n", dest);

    char overlap[20] = "Hello, world!";
    ft_memmove(overlap + 7, overlap, 5);
    printf("ft_memmove(overlap+7, overlap, 5) -> overlap = \"%s\"\n", overlap);
    printf("\n");
}

void test_conversion_functions(void)
{
    printf("=== Тестирование функций преобразования ===\n\n");

    printf("ft_atoi(\"42\") = %d\n", ft_atoi("42"));
    printf("ft_atoi(\"  -42abc\") = %d\n", ft_atoi("  -42abc"));
    printf("ft_atoi(\"+123\") = %d\n", ft_atoi("+123"));

    int *arr = (int *)ft_calloc(5, sizeof(int));
    printf("ft_calloc(5, sizeof(int)) -> arr[0]=%d, arr[4]=%d\n", arr[0], arr[4]);
    free(arr);

    char *dup = ft_strdup("Hello");
    printf("ft_strdup(\"Hello\") = \"%s\"\n", dup);
    free(dup);

    char *substr = ft_substr("Hello, world!", 7, 5);
    printf("ft_substr(\"Hello, world!\", 7, 5) = \"%s\"\n", substr);
    free(substr);

    char *join = ft_strjoin("Hello, ", "world!");
    printf("ft_strjoin(\"Hello, \", \"world!\") = \"%s\"\n", join);
    free(join);

    char *trim = ft_strtrim("   Hello   ", " ");
    printf("ft_strtrim(\"   Hello   \", \" \") = \"%s\"\n", trim);
    free(trim);

    char **split = ft_split("Hello,world,42", ',');
    int i;

    i = 0;
    printf("ft_split(\"Hello,world,42\", ',') = [");
    while (split[i])
    {
        if (i > 0)
            printf(", ");
        printf("\"%s\"", split[i]);
        i++;
    }
    printf("]\n");
    i = 0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);

    char *itoa = ft_itoa(-42);
    printf("ft_itoa(-42) = \"%s\"\n", itoa);
    free(itoa);

    char *itoa_min = ft_itoa(-2147483648);
    printf("ft_itoa(INT_MIN) = \"%s\"\n", itoa_min);
    free(itoa_min);
    printf("\n");
}

void test_output_functions(void)
{
    printf("=== Тестирование функций вывода ===\n\n");

    printf("ft_putchar_fd('X', 1): ");
    ft_putchar_fd('X', 1);
    printf("\n");

    printf("ft_putstr_fd(\"Hello\", 1): ");
    ft_putstr_fd("Hello", 1);
    printf("\n");

    printf("ft_putendl_fd(\"Hello\", 1):\n");
    ft_putendl_fd("Hello", 1);

    printf("ft_putnbr_fd(-42, 1): ");
    ft_putnbr_fd(-42, 1);
    printf("\n");

    printf("ft_putnbr_fd(INT_MIN, 1): ");
    ft_putnbr_fd(-2147483648, 1);
    printf("\n\n");
}

void test_list_functions(void)
{
    printf("=== Тестирование функций списков ===\n\n");

    t_list *list = NULL;
    t_list *node1 = ft_lstnew("Hello");
    t_list *node2 = ft_lstnew("world");
    t_list *node3 = ft_lstnew("42");

    ft_lstadd_front(&list, node1);
    ft_lstadd_front(&list, node2);
    ft_lstadd_front(&list, node3);

    printf("ft_lstsize(list) = %d\n", ft_lstsize(list));
    printf("ft_lstlast(list)->content = \"%s\"\n", (char *)ft_lstlast(list)->content);

    t_list *node4 = ft_lstnew("end");
    ft_lstadd_back(&list, node4);
    printf("После ft_lstadd_back: размер = %d\n", ft_lstsize(list));

    ft_lstclear(&list, NULL);
    printf("После ft_lstclear: list = %p\n", (void *)list);

    list = ft_lstnew("test1");
    list->next = ft_lstnew("test2");
    ft_lstiter(list, NULL);
    printf("ft_lstiter: OK\n");

    t_list *mapped = ft_lstmap(list, NULL, NULL);
    printf("ft_lstmap с NULL: %p\n", (void *)mapped);

    ft_lstclear(&list, NULL);
    printf("\n");
}

int main(void)
{
    printf("=== Тестирование libft ===\n\n");

    test_char_functions();
    test_string_functions();
    test_memory_functions();
    test_conversion_functions();
    test_output_functions();
    test_list_functions();

    printf("=== Все тесты завершены ===\n");
    return 0;
}
