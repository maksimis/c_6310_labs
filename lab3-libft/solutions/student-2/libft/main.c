#include "libft.h"
#include <stdio.h>
#include <string.h>

static void test_is_functions(void)
{
    char chars[] = {'A', 'z', '0', ' ', '\n', 127};
    size_t i;

    printf("=== isalpha/isdigit/isalnum/isascii/isprint ===\n");
    for (i = 0; i < sizeof(chars); i++)
    {
        int c = (unsigned char)chars[i];
        printf("'%c' (%d): isalpha=%d, isdigit=%d, isalnum=%d, "
               "isascii=%d, isprint=%d\n",
               (c >= 32 && c <= 126) ? c : '.', c,
               ft_isalpha(c), ft_isdigit(c), ft_isalnum(c),
               ft_isascii(c), ft_isprint(c));
    }
}

static void	test_edge_cases(void)
{
    char **arr;
    char *str;
    size_t i;

    printf("\n=== edge cases ===\n");

    arr = ft_split("", ',');
    printf("ft_split(\"\", ','):\n");
    if (!arr)
        printf("returned NULL\n");
    else
    {
        if (!arr[0])
            printf("empty result\n");
        i = 0;
        while (arr[i])
        {
            printf("part[%zu] = \"%s\"\n", i, arr[i]);
            free(arr[i]);
            i++;
        }
        free(arr);
    }

    arr = ft_split(",,,,", ',');
    printf("ft_split(\",,,,\", ','):\n");
    if (!arr)
        printf("returned NULL\n");
    else
    {
        if (!arr[0])
            printf("empty result\n");
        i = 0;
        while (arr[i])
        {
            printf("part[%zu] = \"%s\"\n", i, arr[i]);
            free(arr[i]);
            i++;
        }
        free(arr);
    }

    str = ft_substr("", 0, 5);
    printf("ft_substr(\"\", 0, 5): \"%s\"\n", str);
    free(str);

    str = ft_strjoin("", "");
    printf("ft_strjoin(\"\", \"\"): \"%s\"\n", str);
    free(str);

    str = ft_strtrim("aaaa", "a");
    printf("ft_strtrim(\"aaaa\", \"a\"): \"%s\"\n", str);
    free(str);
}

static char	test_map(unsigned int i, char c)
{
    (void)i;
    return (c + 1);
}

static void	test_iter(unsigned int i, char *c)
{
    (void)i;
    if (c)
        *c = *c;
}

static void	test_del(void *ptr)
{
    free(ptr);
}

static void	*test_lstmap_f(void *ptr)
{
    return (ptr);
}

static void	test_iter_lst(void *ptr)
{
    (void)ptr;
}

static void	test_null_cases(void)
{
    char *str_result;
    char **split_result;
    t_list *lst;

    printf("\n=== NULL tests ===\n");

    str_result = ft_substr(NULL, 0, 5);
    printf("ft_substr(NULL, 0, 5): %p\n", (void *)str_result);

    str_result = ft_strtrim(NULL, " ");
    printf("ft_strtrim(NULL, \" \"): %p\n", (void *)str_result);

    str_result = ft_strtrim("abc", NULL);
    printf("ft_strtrim(\"abc\", NULL): %p\n", (void *)str_result);

    str_result = ft_strjoin(NULL, "abc");
    printf("ft_strjoin(NULL, \"abc\"): %p\n", (void *)str_result);

    str_result = ft_strjoin("abc", NULL);
    printf("ft_strjoin(\"abc\", NULL): %p\n", (void *)str_result);

    str_result = ft_strdup(NULL);
    printf("ft_strdup(NULL): %p\n", (void *)str_result);

    str_result = ft_strmapi(NULL, test_map);
    printf("ft_strmapi(NULL, test_map): %p\n", (void *)str_result);

    str_result = ft_strmapi("abc", NULL);
    printf("ft_strmapi(\"abc\", NULL): %p\n", (void *)str_result);

    split_result = ft_split(NULL, ',');
    printf("ft_split(NULL, ','): %p\n", (void *)split_result);

    printf("ft_putstr_fd(NULL, 1):\n");
    ft_putstr_fd(NULL, 1);

    printf("ft_putendl_fd(NULL, 1):\n");
    ft_putendl_fd(NULL, 1);

    printf("ft_striteri(NULL, test_iter):\n");
    ft_striteri(NULL, test_iter);

    printf("ft_striteri(\"abc\", NULL):\n");
    {
        char s[] = "abc";
        ft_striteri(s, NULL);
        printf("after ft_striteri(\"abc\", NULL): %s\n", s);
    }

    printf("ft_lstsize(NULL): %d\n", ft_lstsize(NULL));
    printf("ft_lstlast(NULL): %p\n", (void *)ft_lstlast(NULL));

    printf("ft_lstadd_front with NULL list pointer\n");
    ft_lstadd_front(NULL, NULL);

    printf("ft_lstadd_back with NULL list pointer\n");
    ft_lstadd_back(NULL, NULL);

    printf("ft_lstdelone(NULL, test_del)\n");
    ft_lstdelone(NULL, test_del);

    printf("ft_lstclear on NULL list pointer\n");
    ft_lstclear(NULL, test_del);

    lst = NULL;
    printf("ft_lstclear on empty list\n");
    ft_lstclear(&lst, test_del);

    printf("ft_lstiter(NULL, test_iter_lst)\n");
    ft_lstiter(NULL, test_iter_lst);

    printf("ft_lstmap(NULL, test_lstmap_f, test_del): %p\n",
        (void *)ft_lstmap(NULL, test_lstmap_f, test_del));
}

static void test_toupper_tolower(void)
{
    char s[] = "AbZ0?";
    size_t i;

    printf("\n=== toupper/tolower ===\n");
    for (i = 0; i < sizeof(s) - 1; i++)
    {
        int c = (unsigned char)s[i];
        printf("'%c': toupper=%c, tolower=%c\n",
               c, ft_toupper(c), ft_tolower(c));
    }
}

static void test_strlen(void)
{
    const char *tests[] = {"", "Hello", "42", "longer string here"};
    size_t i;

    printf("\n=== strlen ===\n");
    for (i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        printf("\"%s\": ft=%zu, std=%zu\n",
               tests[i], ft_strlen(tests[i]), strlen(tests[i]));
    }
}

static void test_strchr_strrchr(void)
{
    const char *s = "hello world";
    int c = 'l';

    printf("\n=== strchr/strrchr ===\n");
    printf("strchr:   %s\n", ft_strchr(s, c));
    printf("strrchr:  %s\n", ft_strrchr(s, c));
    printf("strchr '\\0': %s\n", ft_strchr(s, '\0'));
    printf("strrchr '\\0': %s\n", ft_strrchr(s, '\0'));
}

static void test_strnstr(void)
{
    const char *big = "Foo bar baz";
    const char *little = "bar";

    printf("\n=== strnstr ===\n");
    printf("len 3:  %s\n", ft_strnstr(big, little, 3));
    printf("len 10: %s\n", ft_strnstr(big, little, 10));
    printf("empty needle: %s\n", ft_strnstr(big, "", 5));
}

static void test_strncmp(void)
{
    const char *a = "abc";
    const char *b = "abd";

    printf("\n=== strncmp ===\n");
    printf("n=2: ft=%d, std=%d\n", ft_strncmp(a, b, 2), strncmp(a, b, 2));
    printf("n=3: ft=%d, std=%d\n", ft_strncmp(a, b, 3), strncmp(a, b, 3));
}

static void test_atoi(void)
{
    const char *tests[] = {"0", "42", "-42", "   +123", "  -0010", "2147483647",
                           "-2147483648", "42abc", "abc42"};
    size_t i;

    printf("\n=== atoi ===\n");
    for (i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
        printf("\"%s\": %d\n", tests[i], ft_atoi(tests[i]));
}

static void test_calloc(void)
{
    int *arr;
    size_t i;

    printf("\n=== calloc ===\n");
    arr = (int *)ft_calloc(5, sizeof(int));
    if (!arr)
    {
        printf("calloc returned NULL\n");
        return;
    }
    for (i = 0; i < 5; i++)
        printf("arr[%zu] = %d\n", i, arr[i]);
    free(arr);
}

static void test_strdup(void)
{
    const char *s = "Hello dup";
    char *copy = ft_strdup(s);

    printf("\n=== strdup ===\n");
    printf("src:  \"%s\"\n", s);
    printf("copy: \"%s\"\n", copy);
    free(copy);
}

static void test_substr(void)
{
    char *sub;

    printf("\n=== substr ===\n");
    sub = ft_substr("Hello world", 6, 5);
    printf("[6,5]: %s\n", sub);
    free(sub);
    sub = ft_substr("Hello", 10, 3);
    printf("start>=len: \"%s\"\n", sub);
    free(sub);
}

static void test_strjoin(void)
{
    char *res = ft_strjoin("Hello", "World");

    printf("\n=== strjoin ===\n");
    printf("%s\n", res);
    free(res);
}

static void test_strtrim(void)
{
    char *res = ft_strtrim("  \tHello  \n", " \n\t");

    printf("\n=== strtrim ===\n");
    printf("\"%s\"\n", res);
    free(res);
}

static void test_split(void)
{
    char **arr;
    size_t i;

    printf("\n=== split ===\n");
    arr = ft_split("one,two,,three", ',');
    if (!arr)
    {
        printf("split returned NULL\n");
        return;
    }
    for (i = 0; arr[i]; i++)
        printf("part[%zu] = \"%s\"\n", i, arr[i]);
    i = 0;
    while (arr[i])
        free(arr[i++]);
    free(arr);
}

static void test_itoa(void)
{
    long nums[] = {0, 42, -42, 2147483647, -2147483647};
    size_t i;

    printf("\n=== itoa ===\n");
    for (i = 0; i < sizeof(nums) / sizeof(nums[0]); i++)
    {
        char *s = ft_itoa(nums[i]);
        printf("%ld -> \"%s\"\n", nums[i], s);
        free(s);
    }
}

static char plus_one(unsigned int i, char c)
{
    (void)i;
    if (c >= 'a' && c <= 'z')
        return (char)(c + 1);
    return c;
}

static void iter_upper(unsigned int i, char *c)
{
    (void)i;
    if (*c >= 'a' && *c <= 'z')
        *c = (char)(*c - 32);
}

static void test_strmapi_striteri(void)
{
    char s1[] = "abc";
    char *mapped;

    printf("\n=== strmapi/striteri ===\n");
    mapped = ft_strmapi(s1, plus_one);
    printf("strmapi: %s -> %s\n", s1, mapped);
    free(mapped);
    ft_striteri(s1, iter_upper);
    printf("striteri: %s\n", s1);
}

static void test_put_fd(void)
{
    printf("\n=== put*_fd (output to stdout) ===\n");
    ft_putchar_fd('A', 1);
    ft_putstr_fd(" BC", 1);
    ft_putendl_fd(" DEF", 1);
    ft_putnbr_fd(12345, 1);
    ft_putchar_fd('\n', 1);
}

static void test_isspace(void)
{
    char chars[] = {' ', '\t', '\n', 'A'};
    size_t i;

    printf("\n=== isspace ===\n");
    for (i = 0; i < sizeof(chars); i++)
        printf("'%c' (%d): %d\n",
               (chars[i] >= 32 && chars[i] <= 126) ? chars[i] : '.',
               (int)chars[i], ft_isspace((unsigned char)chars[i]));
}

static void test_strlcpy_strlcat(void)
{
    char dst[20];
    size_t r;

    printf("\n=== strlcpy ===\n");
    r = ft_strlcpy(dst, "Hello", sizeof(dst));
    printf("dst=\"%s\", ret=%zu\n", dst, r);

    printf("\n=== strlcat ===\n");
    r = ft_strlcat(dst, " World", sizeof(dst));
    printf("dst=\"%s\", ret=%zu\n", dst, r);
}

static void test_memory(void)
{
    char buf[20];
    char src[20] = "1234567890";

    printf("\n=== memset ===\n");
    ft_memset(buf, 'A', 5);
    buf[5] = '\0';
    printf("%s\n", buf);

    printf("\n=== bzero ===\n");
    ft_bzero(buf, sizeof(buf));
    printf("first byte after bzero: %d\n", (unsigned char)buf[0]);

    printf("\n=== memcpy ===\n");
    ft_memcpy(buf, src, 11);
    printf("%s\n", buf);

    printf("\n=== memmove (overlap) ===\n");
    ft_memmove(src + 2, src, 5);
    src[7] = '\0';
    printf("%s\n", src);
}

static void del_int(void *p)
{
    free(p);
}

static void *dup_int(void *p)
{
    int *n = (int *)malloc(sizeof(int));
    if (!n)
        return NULL;
    *n = *(int *)p;
    return n;
}

static void print_int(void *p)
{
    printf("%d ", *(int *)p);
}

static void test_list(void)
{
    t_list *lst = NULL;
    t_list *tmp;
    int *a, *b, *c;
    t_list *mapped;

    printf("\n=== list functions ===\n");

    a = (int *)malloc(sizeof(int));
    b = (int *)malloc(sizeof(int));
    c = (int *)malloc(sizeof(int));
    if (!a || !b || !c)
        return;
    *a = 1; *b = 2; *c = 3;

    lst = ft_lstnew(a);
    tmp = ft_lstnew(b);
    ft_lstadd_front(&lst, tmp);
    tmp = ft_lstnew(c);
    ft_lstadd_back(&lst, tmp);

    printf("size=%d\n", ft_lstsize(lst));
    printf("last=%d\n", *(int *)ft_lstlast(lst)->content);

    ft_lstiter(lst, print_int);
    printf("\n");

    mapped = ft_lstmap(lst, dup_int, del_int);
    printf("mapped: ");
    ft_lstiter(mapped, print_int);
    printf("\n");

    ft_lstclear(&lst, del_int);
    ft_lstclear(&mapped, del_int);
}

int main(void)
{
    test_is_functions();
    test_null_cases();
    test_edge_cases();
    test_toupper_tolower();
    test_strlen();
    test_strchr_strrchr();
    test_strnstr();
    test_strncmp();
    test_atoi();
    test_calloc();
    test_strdup();
    test_substr();
    test_strjoin();
    test_strtrim();
    test_split();
    test_itoa();
    test_strmapi_striteri();
    test_put_fd();
    test_isspace();
    test_strlcpy_strlcat();
    test_memory();
    test_list();
    return 0;
}