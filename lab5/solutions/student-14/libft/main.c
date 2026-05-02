#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char	map_func(unsigned int i, char c)
{
	(void)i;
	return (c + 1);
}

void	iter_func(unsigned int i, char *c)
{
	(void)i;
	(*c)++;
}

void	*double_content(void *content)
{
	int	*new;

	new = malloc(sizeof(int));
	if (!new)
		return (NULL);
	*new = (*(int *)content) * 2;
	return (new);
}

void	free_content(void *content)
{
	free(content);
}

void test_ft_isalpha(void)
{
	printf("ft_isalpha('A') = %d\n", ft_isalpha('A'));
	printf("ft_isalpha('z') = %d\n", ft_isalpha('z'));
	printf("ft_isalpha('5') = %d\n", ft_isalpha('5'));
	printf("ft_isalpha(' ') = %d\n\n", ft_isalpha(' '));
}

void test_ft_isdigit(void)
{
	printf("ft_isdigit('5') = %d\n", ft_isdigit('5'));
	printf("ft_isdigit('0') = %d\n", ft_isdigit('0'));
	printf("ft_isdigit('A') = %d\n", ft_isdigit('A'));
	printf("ft_isdigit(' ') = %d\n\n", ft_isdigit(' '));
}

void test_ft_isalnum(void)
{
	printf("ft_isalnum('A') = %d\n", ft_isalnum('A'));
	printf("ft_isalnum('5') = %d\n", ft_isalnum('5'));
	printf("ft_isalnum(' ') = %d\n", ft_isalnum(' '));
	printf("ft_isalnum('.') = %d\n\n", ft_isalnum('.'));
}

void test_ft_isascii(void)
{
	printf("ft_isascii('A') = %d\n", ft_isascii('A'));
	printf("ft_isascii(127) = %d\n", ft_isascii(127));
	printf("ft_isascii(128) = %d\n", ft_isascii(128));
	printf("\n");
}

void test_ft_isprint(void)
{
	printf("ft_isprint(' ') = %d\n", ft_isprint(' '));
	printf("ft_isprint('~') = %d\n", ft_isprint('~'));
	printf("ft_isprint('\\n') = %d\n", ft_isprint('\n'));
	printf("\n");
}

void test_ft_isspace(void)
{
	printf("ft_isspace(' ') = %d\n", ft_isspace(' '));
	printf("ft_isspace('\\t') = %d\n", ft_isspace('\t'));
	printf("ft_isspace('\\n') = %d\n", ft_isspace('\n'));
	printf("ft_isspace('A') = %d\n\n", ft_isspace('A'));
}

void test_ft_toupper(void)
{
	printf("ft_toupper('a') = '%c'\n", ft_toupper('a'));
	printf("ft_toupper('z') = '%c'\n", ft_toupper('z'));
	printf("ft_toupper('A') = '%c'\n", ft_toupper('A'));
	printf("ft_toupper('5') = '%c'\n\n", ft_toupper('5'));
}

void test_ft_tolower(void)
{
	printf("ft_tolower('A') = '%c'\n", ft_tolower('A'));
	printf("ft_tolower('Z') = '%c'\n", ft_tolower('Z'));
	printf("ft_tolower('a') = '%c'\n", ft_tolower('a'));
	printf("ft_tolower('5') = '%c'\n\n", ft_tolower('5'));
}

void test_ft_strlen(void)
{
	printf("ft_strlen(\"Hello, world!\") = %zu\n", ft_strlen("Hello, world!"));
	printf("ft_strlen(\"\") = %zu\n", ft_strlen(""));
	printf("ft_strlen(\"42\") = %zu\n\n", ft_strlen("42"));
}

void test_ft_strchr(void)
{
	printf("ft_strchr(\"hello\", 'l') = %s\n", ft_strchr("hello", 'l'));
	printf("ft_strchr(\"hello\", 'z') = %s\n\n", ft_strchr("hello", 'z') ? ft_strchr("hello", 'z') : "(null)");
}

void test_ft_strrchr(void)
{
	printf("ft_strrchr(\"hello\", 'l') = %s\n", ft_strrchr("hello", 'l'));
	printf("ft_strrchr(\"hello\", 'z') = %s\n\n", ft_strrchr("hello", 'z') ? ft_strrchr("hello", 'z') : "(null)");
}

void test_ft_strnstr(void)
{
	printf("ft_strnstr(\"hello world\", \"world\", 11) = %s\n", ft_strnstr("hello world", "world", 11));
	printf("ft_strnstr(\"hello world\", \"world\", 5) = %s\n", ft_strnstr("hello world", "world", 5) ? ft_strnstr("hello world", "world", 5) : "(null)");
	printf("ft_strnstr(\"hello world\", \"\", 5) = %s\n\n", ft_strnstr("hello world", "", 5));
}

void test_ft_strncmp(void)
{
	printf("ft_strncmp(\"hello\", \"hello\", 5) = %d\n", ft_strncmp("hello", "hello", 5));
	printf("ft_strncmp(\"hello\", \"helly\", 5) = %d\n", ft_strncmp("hello", "helly", 5));
	printf("ft_strncmp(\"hello\", \"world\", 3) = %d\n", ft_strncmp("hello", "world", 3));
	printf("\n");
}

void test_ft_strlcpy(void)
{
	char dst[10];
	ft_strlcpy(dst, "hello", 10);
	printf("ft_strlcpy(dst, \"hello\", 10) = \"%s\"\n", dst);
	ft_strlcpy(dst, "hello", 3);
	printf("ft_strlcpy(dst, \"hello\", 3) = \"%s\"\n\n", dst);
}

void test_ft_strlcat(void)
{
	char dst1[20] = "Hello";
	char dst2[20] = "Hello";
	ft_strlcat(dst1, " World", 20);
	printf("ft_strlcat(dst, \" World\", 20) = \"%s\"\n", dst1);
	ft_strlcat(dst2, " World", 8);
	printf("ft_strlcat(dst, \" World\", 8) = \"%s\"\n\n", dst2);
}

void test_ft_memset(void)
{
	char buf[10] = "hello";
	ft_memset(buf, 'X', 3);
	printf("ft_memset(buf, 'X', 3) = \"%s\"\n\n", buf);
}

void test_ft_bzero(void)
{
	char buf[10] = "hello";
	ft_bzero(buf, 3);
	printf("ft_bzero(buf, 3) = первые 3 байта обнулены\n\n");
}

void test_ft_memcpy(void)
{
	char dst[10] = {0};
	ft_memcpy(dst, "hello", 5);
	printf("ft_memcpy(dst, \"hello\", 5) = \"%s\"\n\n", dst);
}

void test_ft_memmove(void)
{
	char buf[10] = "hello";
	ft_memmove(buf + 1, buf, 3);
	printf("ft_memmove(buf+1, buf, 3) = \"%s\"\n\n", buf);
}

void test_ft_calloc(void)
{
	int *arr = (int *)ft_calloc(5, sizeof(int));
	printf("ft_calloc(5, sizeof(int)) = %d %d %d %d %d\n", arr[0], arr[1], arr[2], arr[3], arr[4]);
	free(arr);
	printf("\n");
}

void test_ft_atoi(void)
{
	printf("ft_atoi(\"42\") = %d\n", ft_atoi("42"));
	printf("ft_atoi(\"   -42\") = %d\n", ft_atoi("   -42"));
	printf("ft_atoi(\"  +123\") = %d\n", ft_atoi("  +123"));
	printf("ft_atoi(\"42abc\") = %d\n", ft_atoi("42abc"));
	printf("\n");
}

void test_ft_itoa(void)
{
	char *s;
	s = ft_itoa(42);
	printf("ft_itoa(42) = \"%s\"\n", s);
	free(s);
	s = ft_itoa(-42);
	printf("ft_itoa(-42) = \"%s\"\n", s);
	free(s);
	s = ft_itoa(0);
	printf("ft_itoa(0) = \"%s\"\n", s);
	free(s);
	s = ft_itoa(INT_MAX);
	printf("ft_itoa(2147483647) = \"%s\"\n", s);
	free(s);
	s = ft_itoa(INT_MIN);
	printf("ft_itoa(-2147483648) = \"%s\"\n\n", s);
	free(s);
}

void test_ft_strdup(void)
{
	char *dup = ft_strdup("hello");
	printf("ft_strdup(\"hello\") = \"%s\"\n", dup);
	free(dup);
	printf("\n");
}

void test_ft_substr(void)
{
	char *sub;
	sub = ft_substr("hello world", 6, 5);
	printf("ft_substr(\"hello world\", 6, 5) = \"%s\"\n", sub);
	free(sub);
	sub = ft_substr("hello", 10, 5);
	printf("ft_substr(\"hello\", 10, 5) = \"%s\"\n", sub);
	free(sub);
	printf("\n");
}

void test_ft_strjoin(void)
{
	char *result = ft_strjoin("Hello, ", "World!");
	printf("ft_strjoin(\"Hello, \", \"World!\") = \"%s\"\n", result);
	free(result);
	printf("\n");
}

void test_ft_strtrim(void)
{
	char *result;
	result = ft_strtrim("   Hello, World!   ", " ");
	printf("ft_strtrim(\"   Hello, World!   \", \" \") = \"%s\"\n", result);
	free(result);
	result = ft_strtrim("xxxabcxxx", "x");
	printf("ft_strtrim(\"xxxabcxxx\", \"x\") = \"%s\"\n", result);
	free(result);
	printf("\n");
}

void test_ft_split(void)
{
	char **result = ft_split("hello world 42", ' ');
	int i;
	printf("ft_split(\"hello world 42\", ' ') = ");
	for (i = 0; result[i]; i++)
		printf("\"%s\" ", result[i]);
	printf("\n");
	for (i = 0; result[i]; i++)
		free(result[i]);
	free(result);
	printf("\n");
}

void test_ft_strmapi(void)
{
	char *result = ft_strmapi("abc", map_func);
	printf("ft_strmapi(\"abc\", increment) = \"%s\"\n", result);
	free(result);
	printf("\n");
}

void test_ft_striteri(void)
{
	char str[] = "abc";
	ft_striteri(str, iter_func);
	printf("ft_striteri(\"abc\", increment) = \"%s\"\n", str);
	printf("\n");
}

void test_ft_putchar_fd(void)
{
	printf("ft_putchar_fd('A', 1) = ");
	ft_putchar_fd('A', 1);
	printf("\n\n");
}

void test_ft_putstr_fd(void)
{
	printf("ft_putstr_fd(\"Hello\", 1) = ");
	ft_putstr_fd("Hello", 1);
	printf("\n\n");
}

void test_ft_putendl_fd(void)
{
	printf("ft_putendl_fd(\"Hello\", 1) =\n");
	ft_putendl_fd("Hello", 1);
	printf("\n");
}

void test_ft_putnbr_fd(void)
{
	printf("ft_putnbr_fd(42, 1) = ");
	ft_putnbr_fd(42, 1);
	printf("\n");
	printf("ft_putnbr_fd(-42, 1) = ");
	ft_putnbr_fd(-42, 1);
	printf("\n");
	printf("ft_putnbr_fd(0, 1) = ");
	ft_putnbr_fd(0, 1);
	printf("\n\n");
}

void test_ft_lstnew(void)
{
	int *content = malloc(sizeof(int));
	t_list *node;
	*content = 42;
	node = ft_lstnew(content);
	printf("ft_lstnew(42) = %d\n", *(int *)(node->content));
	free(node->content);
	free(node);
	printf("\n");
}

void test_ft_lstadd_front(void)
{
	t_list *list = NULL;
	int *a = malloc(sizeof(int));
	int *b = malloc(sizeof(int));
	*a = 10;
	*b = 20;
	ft_lstadd_front(&list, ft_lstnew(a));
	ft_lstadd_front(&list, ft_lstnew(b));
	printf("ft_lstadd_front: %d\n", *(int *)(list->content));
	ft_lstclear(&list, free);
	printf("\n");
}

void test_ft_lstsize(void)
{
	t_list *list = NULL;
	int *a = malloc(sizeof(int));
	int *b = malloc(sizeof(int));
	*a = 10;
	*b = 20;
	printf("ft_lstsize(NULL) = %d\n", ft_lstsize(list));
	ft_lstadd_back(&list, ft_lstnew(a));
	ft_lstadd_back(&list, ft_lstnew(b));
	printf("ft_lstsize(list) = %d\n", ft_lstsize(list));
	ft_lstclear(&list, free);
	printf("\n");
}

void test_ft_lstlast(void)
{
	t_list *list = NULL;
	int *a = malloc(sizeof(int));
	int *b = malloc(sizeof(int));
	*a = 10;
	*b = 20;
	ft_lstadd_back(&list, ft_lstnew(a));
	ft_lstadd_back(&list, ft_lstnew(b));
	printf("ft_lstlast(list) = %d\n", *(int *)(ft_lstlast(list)->content));
	ft_lstclear(&list, free);
	printf("\n");
}

void test_ft_lstadd_back(void)
{
	t_list *list = NULL;
	int *a = malloc(sizeof(int));
	int *b = malloc(sizeof(int));
	*a = 10;
	*b = 20;
	ft_lstadd_back(&list, ft_lstnew(a));
	ft_lstadd_back(&list, ft_lstnew(b));
	printf("ft_lstadd_back: %d\n", *(int *)(ft_lstlast(list)->content));
	ft_lstclear(&list, free);
	printf("\n");
}

void test_ft_lstdelone(void)
{
	int *content = malloc(sizeof(int));
	t_list *node;
	*content = 42;
	node = ft_lstnew(content);
	ft_lstdelone(node, free);
	printf("ft_lstdelone: done\n\n");
}

void test_ft_lstclear(void)
{
	t_list *list = NULL;
	int *a = malloc(sizeof(int));
	int *b = malloc(sizeof(int));
	*a = 10;
	*b = 20;
	ft_lstadd_back(&list, ft_lstnew(a));
	ft_lstadd_back(&list, ft_lstnew(b));
	ft_lstclear(&list, free);
	printf("ft_lstclear: %p\n\n", list);
}

void test_ft_lstiter(void)
{
	t_list *list = NULL;
	int *a = malloc(sizeof(int));
	int *b = malloc(sizeof(int));
	*a = 10;
	*b = 20;
	ft_lstadd_back(&list, ft_lstnew(a));
	ft_lstadd_back(&list, ft_lstnew(b));
	ft_lstiter(list, free_content);
	printf("ft_lstiter: done\n");
	free(list);
	printf("\n");
}

void test_ft_lstmap(void)
{
	t_list *list = NULL;
	t_list *new_list = NULL;
	int *a = malloc(sizeof(int));
	int *b = malloc(sizeof(int));
	*a = 10;
	*b = 20;
	ft_lstadd_back(&list, ft_lstnew(a));
	ft_lstadd_back(&list, ft_lstnew(b));
	new_list = ft_lstmap(list, double_content, free);
	if (new_list)
	{
		printf("ft_lstmap: %d %d\n", *(int *)(new_list->content), *(int *)(new_list->next->content));
		ft_lstclear(&new_list, free);
	}
	ft_lstclear(&list, free);
	printf("\n");
}

int main(void)
{
	test_ft_isalpha();
	test_ft_isdigit();
	test_ft_isalnum();
	test_ft_isascii();
	test_ft_isprint();
	test_ft_isspace();
	test_ft_toupper();
	test_ft_tolower();
	test_ft_strlen();
	test_ft_strchr();
	test_ft_strrchr();
	test_ft_strnstr();
	test_ft_strncmp();
	test_ft_strlcpy();
	test_ft_strlcat();
	test_ft_memset();
	test_ft_bzero();
	test_ft_memcpy();
	test_ft_memmove();
	test_ft_calloc();
	test_ft_atoi();
	test_ft_itoa();
	test_ft_strdup();
	test_ft_substr();
	test_ft_strjoin();
	test_ft_strtrim();
	test_ft_split();
	test_ft_strmapi();
	test_ft_striteri();
	test_ft_putchar_fd();
	test_ft_putstr_fd();
	test_ft_putendl_fd();
	test_ft_putnbr_fd();
	test_ft_lstnew();
	test_ft_lstadd_front();
	test_ft_lstsize();
	test_ft_lstlast();
	test_ft_lstadd_back();
	test_ft_lstdelone();
	test_ft_lstclear();
	test_ft_lstiter();
	test_ft_lstmap();
	return (0);
}