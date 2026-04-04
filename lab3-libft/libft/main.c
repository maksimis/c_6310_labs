#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

// ===== ft_atoi =====
void test_ft_atoi(void)
{
    char *test1 = "123";
    char *test2 = "   -42";
    char *test3 = "+56abc";

    printf("ft_atoi(\"%s\") = %d (оригинал: %d)\n",
           test1, ft_atoi(test1), atoi(test1));
    printf("ft_atoi(\"%s\") = %d (оригинал: %d)\n",
           test2, ft_atoi(test2), atoi(test2));
    printf("ft_atoi(\"%s\") = %d (оригинал: %d)\n",
           test3, ft_atoi(test3), atoi(test3));
}

// ===== ft_bzero =====
void test_ft_bzero(void)
{
    char s1[10] = "abcdef";
    char s2[10] = "abcdef";

    ft_bzero(s1, 3);
    memset(s2, 0, 3);        // вместо bzero

    printf("ft_bzero: '%s' (первые 3 байта обнулены)\n", s1);
    printf("memset(0): '%s' (первые 3 байта обнулены)\n", s2);
}
// ===== ft_calloc =====
void test_ft_calloc(void)
{
    int *arr1 = ft_calloc(5, sizeof(int));
    int *arr2 = calloc(5, sizeof(int));

    printf("ft_calloc: ");
    for (int i = 0; i < 5; i++)
        printf("%d ", arr1[i]);

    printf("| оригинал: ");
    for (int i = 0; i < 5; i++)
        printf("%d ", arr2[i]);

    printf("\n");

    free(arr1);
    free(arr2);
}

// ===== ft_isalnum =====
void test_ft_isalnum(void)
{
    printf("ft_isalnum('A') = %d (оригинал: %d)\n",
           ft_isalnum('A') != 0, isalnum('A') != 0);
    printf("ft_isalnum('1') = %d (оригинал: %d)\n",
           ft_isalnum('1') != 0, isalnum('1') != 0);
    printf("ft_isalnum('#') = %d (оригинал: %d)\n",
           ft_isalnum('#') != 0, isalnum('#') != 0);
}

// ===== ft_isalpha =====
void test_ft_isalpha(void)
{
    printf("ft_isalpha('A') = %d (оригинал: %d)\n",
           ft_isalpha('A') != 0, isalpha('A') != 0);
    printf("ft_isalpha('z') = %d (оригинал: %d)\n",
           ft_isalpha('z') != 0, isalpha('z') != 0);
    printf("ft_isalpha('1') = %d (оригинал: %d)\n",
           ft_isalpha('1') != 0, isalpha('1') != 0);
}

// ===== ft_isascii =====
void test_ft_isascii(void)
{
    printf("ft_isascii(65) = %d (оригинал: %d)\n",
           ft_isascii(65), isascii(65));
    printf("ft_isascii(127) = %d (оригинал: %d)\n",
           ft_isascii(127), isascii(127));
    printf("ft_isascii(200) = %d (оригинал: %d)\n",
           ft_isascii(200), isascii(200));
}

// ===== ft_isdigit =====
void test_ft_isdigit(void)
{
    printf("ft_isdigit('5') = %d (оригинал: %d)\n",
           ft_isdigit('5'), isdigit('5'));
    printf("ft_isdigit('0') = %d (оригинал: %d)\n",
           ft_isdigit('0'), isdigit('0'));
    printf("ft_isdigit('a') = %d (оригинал: %d)\n",
           ft_isdigit('a'), isdigit('a'));
}

// ===== ft_isprint =====
void test_ft_isprint(void)
{
    printf("ft_isprint('A') = %d (оригинал: %d)\n",
           ft_isprint('A') != 0, isprint('A') != 0);
    printf("ft_isprint(' ') = %d (оригинал: %d)\n",
           ft_isprint(' ') != 0, isprint(' ') != 0);
    printf("ft_isprint('\\n') = %d (оригинал: %d)\n",
           ft_isprint('\n') != 0, isprint('\n') != 0);
}

// ===== ft_isspace =====
void test_ft_isspace(void)
{
    printf("ft_isspace(' ') = %d\n", ft_isspace(' '));
    printf("ft_isspace('\\n') = %d\n", ft_isspace('\n'));
    printf("ft_isspace('A') = %d\n", ft_isspace('A'));
}

// ===== ft_itoa =====
void test_ft_itoa(void)
{
    int n1 = 123;
    int n2 = -456;
    int n3 = 0;

    char *s1 = ft_itoa(n1);
    char *s2 = ft_itoa(n2);
    char *s3 = ft_itoa(n3);

    printf("ft_itoa(%d) = %s\n", n1, s1);
    printf("ft_itoa(%d) = %s\n", n2, s2);
    printf("ft_itoa(%d) = %s\n", n3, s3);

    free(s1);
    free(s2);
    free(s3);
}

// ===== ft_lstadd_back =====
void test_ft_lstadd_back(void)
{
    t_list *lst = NULL;

    t_list *n1 = ft_lstnew("one");
    t_list *n2 = ft_lstnew("two");

    ft_lstadd_back(&lst, n1);
    ft_lstadd_back(&lst, n2);

    t_list *tmp = lst;
    while (tmp)
    {
        printf("%s -> ", (char *)tmp->content);
        tmp = tmp->next;
    }
    printf("NULL\n");
}

// ===== ft_lstadd_front =====
void test_ft_lstadd_front(void)
{
    t_list *lst = NULL;

    t_list *n1 = ft_lstnew("one");
    t_list *n2 = ft_lstnew("two");

    ft_lstadd_front(&lst, n1);
    ft_lstadd_front(&lst, n2);

    t_list *tmp = lst;
    while (tmp)
    {
        printf("%s -> ", (char *)tmp->content);
        tmp = tmp->next;
    }
    printf("NULL\n");
}

// вспомогательная функция для удаления
void del_content(void *content)
{
    (void)content;
}

// вспомогательная функция для вывода
void print_content(void *content)
{
    printf("%s ", (char *)content);
}

// ===== ft_lstdelone =====
void test_ft_lstdelone(void)
{
    t_list *node = ft_lstnew("hello");

    ft_lstdelone(node, del_content);
    printf("ft_lstdelone выполнена\n");
}

// ===== ft_lstclear =====
void test_ft_lstclear(void)
{
    t_list *lst = NULL;

    ft_lstadd_back(&lst, ft_lstnew("one"));
    ft_lstadd_back(&lst, ft_lstnew("two"));

    ft_lstclear(&lst, del_content);

    if (lst == NULL)
        printf("ft_lstclear: список очищен\n");
}

// ===== ft_lstiter =====
void test_ft_lstiter(void)
{
    t_list *lst = NULL;

    ft_lstadd_back(&lst, ft_lstnew("one"));
    ft_lstadd_back(&lst, ft_lstnew("two"));

    printf("ft_lstiter: ");
    ft_lstiter(lst, print_content);
    printf("\n");
}

// ===== ft_lstlast =====
void test_ft_lstlast(void)
{
    t_list *lst = NULL;

    ft_lstadd_back(&lst, ft_lstnew("one"));
    ft_lstadd_back(&lst, ft_lstnew("two"));

    t_list *last = ft_lstlast(lst);

    if (last)
        printf("ft_lstlast: %s\n", (char *)last->content);
}

// вспомогательная для lstmap (делает копию строки)
void *dup_content(void *content)
{
    return (ft_strdup((char *)content));
}

// ===== ft_lstnew =====
void test_ft_lstnew(void)
{
    t_list *node = ft_lstnew("hello");

    if (node)
        printf("ft_lstnew: %s\n", (char *)node->content);
}

// ===== ft_lstsize =====
void test_ft_lstsize(void)
{
    t_list *lst = NULL;

    ft_lstadd_back(&lst, ft_lstnew("one"));
    ft_lstadd_back(&lst, ft_lstnew("two"));
    ft_lstadd_back(&lst, ft_lstnew("three"));

    printf("ft_lstsize: %d\n", ft_lstsize(lst));
}

// ===== ft_lstmap =====
void test_ft_lstmap(void)
{
    t_list *lst = NULL;

    ft_lstadd_back(&lst, ft_lstnew("one"));
    ft_lstadd_back(&lst, ft_lstnew("two"));

    t_list *new_lst = ft_lstmap(lst, dup_content, del_content);

    printf("ft_lstmap: ");
    t_list *tmp = new_lst;
    while (tmp)
    {
        printf("%s ", (char *)tmp->content);
        tmp = tmp->next;
    }
    printf("\n");
}

// ===== ft_memcpy =====
void test_ft_memcpy(void)
{
    char src[] = "Hello";
    char dst1[10];
    char dst2[10];

    ft_memcpy(dst1, src, 6);
    memcpy(dst2, src, 6);

    printf("ft_memcpy: %s | оригинал: %s\n", dst1, dst2);
}

// ===== ft_memmove =====
void test_ft_memmove(void)
{
    char s1[20] = "HelloWorld";
    char s2[20] = "HelloWorld";

    ft_memmove(s1 + 5, s1, 5);
    memmove(s2 + 5, s2, 5);

    printf("ft_memmove: %s | оригинал: %s\n", s1, s2);
}

// ===== ft_memset =====
void test_ft_memset(void)
{
    char s1[10] = "abcdef";
    char s2[10] = "abcdef";

    ft_memset(s1, 'X', 3);
    memset(s2, 'X', 3);

    printf("ft_memset: %s | оригинал: %s\n", s1, s2);
}

// ===== ft_putchar_fd =====
void test_ft_putchar_fd(void)
{
    printf("ft_putchar_fd: ");
    ft_putchar_fd('A', 1);
    printf("\n");
}

// ===== ft_putstr_fd =====
void test_ft_putstr_fd(void)
{
    printf("ft_putstr_fd: ");
    ft_putstr_fd("Hello", 1);
    printf("\n");
}

// ===== ft_putendl_fd =====
void test_ft_putendl_fd(void)
{
    printf("ft_putendl_fd: ");
    ft_putendl_fd("Hello", 1);
}

// ===== ft_putnbr_fd =====
void test_ft_putnbr_fd(void)
{
    printf("ft_putnbr_fd:\n");

    ft_putnbr_fd(123, 1);
    write(1, "\n", 1);

    ft_putnbr_fd(-456, 1);
    write(1, "\n", 1);

    ft_putnbr_fd(0, 1);
    write(1, "\n", 1);
}

// ===== ft_split =====
void test_ft_split(void)
{
    char **res = ft_split("one,two,three", ',');

    int i = 0;
    printf("ft_split:\n");
    while (res && res[i])
    {
        printf("%s\n", res[i]);
        free(res[i]);
        i++;
    }
    free(res);
}

// ===== ft_strchr =====
void test_ft_strchr(void)
{
    char *s = "Hello";

    printf("ft_strchr: %s\n", ft_strchr(s, 'l'));
    printf("ft_strchr: %s\n", ft_strchr(s, 'H'));
    printf("ft_strchr: %s\n", ft_strchr(s, 'z'));
}

// ===== ft_strdup =====
void test_ft_strdup(void)
{
    char *s = "Hello";
    char *dup = ft_strdup(s);

    printf("ft_strdup: %s\n", dup);

    free(dup);
}

// ===== ft_striteri =====
void to_upper_index(unsigned int i, char *c)
{
    if (i % 2 == 0 && *c >= 'a' && *c <= 'z')
        *c -= 32;
}

void test_ft_striteri(void)
{
    char s[] = "hello";

    ft_striteri(s, to_upper_index);
    printf("ft_striteri: %s\n", s);
}

// ===== ft_strjoin =====
void test_ft_strjoin(void)
{
    char *s1 = "Hello ";
    char *s2 = "World";

    char *res = ft_strjoin(s1, s2);

    printf("ft_strjoin: %s\n", res);

    free(res);
}

// ===== ft_strlcat =====

void test_ft_strlcat(void)
{
    char dst1[20] = "Hello";
    char *src = "World";

    size_t r1 = ft_strlcat(dst1, src, 20);

    printf("ft_strlcat result: %zu | dst: %s\n", r1, dst1);
    printf("original strlcat: (недоступен в MinGW)\n");
}

// ===== ft_strlcpy =====

void test_ft_strlcpy(void)
{
    char dst1[20] = "";
    char *src = "HelloWorld";

    size_t r1 = ft_strlcpy(dst1, src, 20);

    printf("ft_strlcpy result: %zu | dst: %s\n", r1, dst1);
    printf("original strlcpy: (недоступен в MinGW)\n");
}

// ===== ft_strlen =====
void test_ft_strlen(void)
{
    char *s1 = "Hello";
    char *s2 = "";

    printf("ft_strlen(\"%s\") = %zu (original: %zu)\n",
           s1, ft_strlen(s1), strlen(s1));
    printf("ft_strlen(\"%s\") = %zu (original: %zu)\n",
           s2, ft_strlen(s2), strlen(s2));
}

// ===== ft_strmapi =====
char to_upper_even(unsigned int i, char c)
{
    if (i % 2 == 0 && c >= 'a' && c <= 'z')
        return c - 32;
    return c;
}

void test_ft_strmapi(void)
{
    char *s = "hello";
    char *res = ft_strmapi(s, to_upper_even);

    printf("ft_strmapi: %s\n", res);

    free(res);
}

// ===== ft_strncmp =====
void test_ft_strncmp(void)
{
    char *s1 = "Hello";
    char *s2 = "Hello";
    char *s3 = "Hellp";

    printf("ft_strncmp(\"%s\",\"%s\",5) = %d (original: %d)\n",
           s1, s2, ft_strncmp(s1, s2, 5), strncmp(s1, s2, 5));

    printf("ft_strncmp(\"%s\",\"%s\",5) = %d (original: %d)\n",
           s1, s3, ft_strncmp(s1, s3, 5), strncmp(s1, s3, 5));
}

// ===== ft_strnstr =====
void test_ft_strnstr(void)
{
    char *big = "HelloWorld";
    char *little = "World";

    char *res = ft_strnstr(big, little, 10);

    printf("ft_strnstr: %s\n", res ? res : "(NULL)");
    printf("original strnstr: (недоступен в MinGW)\n");
}

// ===== ft_strrchr =====
void test_ft_strrchr(void)
{
    char *s = "Hello";

    printf("ft_strrchr: %s (original: %s)\n",
           ft_strrchr(s, 'l'),
           strrchr(s, 'l'));

    printf("ft_strrchr (last char): %s (original: %s)\n",
           ft_strrchr(s, '\0'),
           strrchr(s, '\0'));
}

// ===== ft_strtrim =====
void test_ft_strtrim(void)
{
    char *s = "   hello   ";
    char *set = " ";

    char *res = ft_strtrim(s, set);

    printf("ft_strtrim: '%s'\n", res);

    free(res);
}

// ===== ft_substr =====
void test_ft_substr(void)
{
    char *s = "HelloWorld";

    char *res = ft_substr(s, 5, 5);

    printf("ft_substr: %s\n", res);

    free(res);
}

// ===== ft_tolower =====
void test_ft_tolower(void)
{
    printf("ft_tolower('A') = %c (original: %c)\n",
           ft_tolower('A'), tolower('A'));
    printf("ft_tolower('z') = %c (original: %c)\n",
           ft_tolower('z'), tolower('z'));
}

// ===== ft_toupper =====
void test_ft_toupper(void)
{
    printf("ft_toupper('a') = %c (original: %c)\n",
           ft_toupper('a'), toupper('a'));
    printf("ft_toupper('Z') = %c (original: %c)\n",
           ft_toupper('Z'), toupper('Z'));
}

// ===== MAIN =====
int main(void)
{
    setlocale(LC_ALL, "C.UTF-8");

    printf("=== Тестирование libft ===\n\n");

    test_ft_atoi();
    printf("\n");

    test_ft_bzero();
    printf("\n");

    test_ft_calloc();
    printf("\n");

    test_ft_isalnum();
    printf("\n");
    
    test_ft_isalpha();
    printf("\n");

    test_ft_isascii();
    printf("\n");

    test_ft_isdigit();
    printf("\n");

    test_ft_isprint();
    printf("\n");

    test_ft_isspace();
    printf("\n");

    test_ft_itoa();
    printf("\n");

    test_ft_lstadd_back();
    printf("\n");

    test_ft_lstadd_front();
    printf("\n");

    test_ft_lstdelone();
    printf("\n");

    test_ft_lstclear();
    printf("\n");
 
    test_ft_lstiter();
    printf("\n");

    test_ft_lstlast();
    printf("\n");

    test_ft_lstnew();
    printf("\n");

    test_ft_lstsize();
    printf("\n");

    test_ft_lstmap();
    printf("\n");

    test_ft_memcpy();
    printf("\n");
 
    test_ft_memmove();
    printf("\n");

    test_ft_memset();
    printf("\n");

    test_ft_putchar_fd();
    printf("\n");

    test_ft_putstr_fd();
    printf("\n");

    test_ft_putendl_fd();
    printf("\n");
 
    test_ft_putnbr_fd();
    printf("\n");

    test_ft_split();
    printf("\n");

    test_ft_strchr();
    printf("\n");

    test_ft_strdup();

    test_ft_striteri();
    printf("\n");

    test_ft_strjoin();
    printf("\n");

    test_ft_strlcat();
    printf("\n");

    test_ft_strlcpy();
    printf("\n");

    test_ft_strlen();
    printf("\n");

    test_ft_strmapi();
    printf("\n");

    test_ft_strncmp();
    printf("\n");

    test_ft_strnstr();
    printf("\n");
 
    test_ft_strrchr();
    printf("\n");

    test_ft_strtrim();
    printf("\n");

    test_ft_substr();
    printf("\n");

    test_ft_tolower();
    printf("\n");

    test_ft_toupper();
    printf("\n");

printf("\n");

    return 0;
}