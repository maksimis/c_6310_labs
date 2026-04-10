#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ============ ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ ДЛЯ ТЕСТОВ ============

char	ft_toupper_char(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

void	ft_striteri_toupper(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
}

void	ft_lstiter_toupper(void *content)
{
	char *str = (char *)content;
	int i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		i++;
	}
}

void	*ft_lstmap_toupper(void *content)
{
	char *str;
	char *new_str;
	int i;

	str = (char *)content;
	new_str = ft_strdup(str);
	if (!new_str)
		return (NULL);
	i = 0;
	while (new_str[i])
	{
		if (new_str[i] >= 'a' && new_str[i] <= 'z')
			new_str[i] = new_str[i] - 32;
		i++;
	}
	return ((void *)new_str);
}

// ============ ТЕСТЫ ============

void	test_ft_isalpha(void)
{
	printf("\n=== Testing ft_isalpha ===\n");
	printf("ft_isalpha('A') = %d\n", ft_isalpha('A'));
	printf("ft_isalpha('z') = %d\n", ft_isalpha('z'));
	printf("ft_isalpha('5') = %d\n", ft_isalpha('5'));
	printf("ft_isalpha('@') = %d\n", ft_isalpha('@'));
}

void	test_ft_isdigit(void)
{
	printf("\n=== Testing ft_isdigit ===\n");
	printf("ft_isdigit('5') = %d\n", ft_isdigit('5'));
	printf("ft_isdigit('0') = %d\n", ft_isdigit('0'));
	printf("ft_isdigit('A') = %d\n", ft_isdigit('A'));
}

void	test_ft_isalnum(void)
{
	printf("\n=== Testing ft_isalnum ===\n");
	printf("ft_isalnum('A') = %d\n", ft_isalnum('A'));
	printf("ft_isalnum('5') = %d\n", ft_isalnum('5'));
	printf("ft_isalnum('@') = %d\n", ft_isalnum('@'));
}

void	test_ft_isascii(void)
{
	printf("\n=== Testing ft_isascii ===\n");
	printf("ft_isascii(65) = %d\n", ft_isascii(65));
	printf("ft_isascii(200) = %d\n", ft_isascii(200));
}

void	test_ft_isprint(void)
{
	printf("\n=== Testing ft_isprint ===\n");
	printf("ft_isprint('A') = %d\n", ft_isprint('A'));
	printf("ft_isprint(' ') = %d\n", ft_isprint(' '));
	printf("ft_isprint('\\n') = %d\n", ft_isprint('\n'));
}

void	test_ft_toupper_tolower(void)
{
	printf("\n=== Testing ft_toupper & ft_tolower ===\n");
	printf("ft_toupper('a') = '%c'\n", ft_toupper('a'));
	printf("ft_toupper('Z') = '%c'\n", ft_toupper('Z'));
	printf("ft_tolower('A') = '%c'\n", ft_tolower('A'));
	printf("ft_tolower('z') = '%c'\n", ft_tolower('z'));
}

void	test_ft_strlen(void)
{
	printf("\n=== Testing ft_strlen ===\n");
	printf("ft_strlen(\"Hello\") = %zu\n", ft_strlen("Hello"));
	printf("ft_strlen(\"\") = %zu\n", ft_strlen(""));
	printf("ft_strlen(\"42\") = %zu\n", ft_strlen("42"));
}

void	test_ft_strchr(void)
{
	printf("\n=== Testing ft_strchr ===\n");
	char *str = "Hello, World!";
	char *result = ft_strchr(str, 'o');
	printf("ft_strchr(\"%s\", 'o') = \"%s\"\n", str, result ? result : "NULL");
}

void	test_ft_strrchr(void)
{
	printf("\n=== Testing ft_strrchr ===\n");
	char *str = "Hello, World!";
	char *result = ft_strrchr(str, 'l');
	printf("ft_strrchr(\"%s\", 'l') = \"%s\"\n", str, result ? result : "NULL");
}

void	test_ft_strncmp(void)
{
	printf("\n=== Testing ft_strncmp ===\n");
	printf("ft_strncmp(\"abc\", \"abd\", 2) = %d\n", ft_strncmp("abc", "abd", 2));
	printf("ft_strncmp(\"abc\", \"abd\", 3) = %d\n", ft_strncmp("abc", "abd", 3));
}

void	test_ft_atoi(void)
{
	printf("\n=== Testing ft_atoi ===\n");
	printf("ft_atoi(\"42\") = %d\n", ft_atoi("42"));
	printf("ft_atoi(\"-42\") = %d\n", ft_atoi("-42"));
	printf("ft_atoi(\"   +123\") = %d\n", ft_atoi("   +123"));
	printf("ft_atoi(\"-2147483648\") = %d\n", ft_atoi("-2147483648"));
}

void	test_ft_calloc(void)
{
	printf("\n=== Testing ft_calloc ===\n");
	int *arr = (int *)ft_calloc(5, sizeof(int));
	if (arr)
	{
		printf("arr[0] = %d, arr[4] = %d\n", arr[0], arr[4]);
		free(arr);
	}
}

void	test_ft_strdup(void)
{
	printf("\n=== Testing ft_strdup ===\n");
	char *original = "Hello!";
	char *copy = ft_strdup(original);
	printf("Original: %s, Copy: %s\n", original, copy);
	free(copy);
}

void	test_ft_substr(void)
{
	printf("\n=== Testing ft_substr ===\n");
	char *str = "Hello, World!";
	char *sub = ft_substr(str, 7, 5);
	printf("ft_substr(\"%s\", 7, 5) = \"%s\"\n", str, sub ? sub : "NULL");
	free(sub);
}

void	test_ft_strjoin(void)
{
	printf("\n=== Testing ft_strjoin ===\n");
	char *joined = ft_strjoin("Hello, ", "World!");
	printf("ft_strjoin(\"Hello, \", \"World!\") = \"%s\"\n", joined);
	free(joined);
}

void	test_ft_strtrim(void)
{
	printf("\n=== Testing ft_strtrim ===\n");
	char *trimmed = ft_strtrim("   Hello   ", " ");
	printf("ft_strtrim(\"   Hello   \", \" \") = \"%s\"\n", trimmed);
	free(trimmed);
}

void	test_ft_split(void)
{
	printf("\n=== Testing ft_split ===\n");
	char *str = "Hello World from 42";
	char **result = ft_split(str, ' ');
	if (result)
	{
		for (int i = 0; result[i]; i++)
			printf("result[%d] = \"%s\"\n", i, result[i]);
		for (int i = 0; result[i]; i++)
			free(result[i]);
		free(result);
	}
}

void	test_ft_itoa(void)
{
	printf("\n=== Testing ft_itoa ===\n");
	int tests[] = {0, 42, -42, 2147483647, -2147483648};
	for (int i = 0; i < 5; i++)
	{
		char *str = ft_itoa(tests[i]);
		printf("ft_itoa(%d) = \"%s\"\n", tests[i], str);
		free(str);
	}
}

void	test_ft_strmapi(void)
{
	printf("\n=== Testing ft_strmapi ===\n");
	char *result = ft_strmapi("abc", ft_toupper_char);
	printf("ft_strmapi(\"abc\", toupper) = \"%s\"\n", result);
	free(result);
}

void	test_ft_striteri(void)
{
	printf("\n=== Testing ft_striteri ===\n");
	char str[] = "abc";
	ft_striteri(str, ft_striteri_toupper);
	printf("ft_striteri(\"abc\") = \"%s\"\n", str);
}

void	test_ft_put_functions(void)
{
	printf("\n=== Testing ft_put functions ===\n");
	printf("ft_putchar_fd('A', 1): ");
	ft_putchar_fd('A', 1);
	printf("\n");
	
	printf("ft_putstr_fd(\"Hello\", 1): ");
	ft_putstr_fd("Hello", 1);
	printf("\n");
	
	printf("ft_putendl_fd(\"Hello\", 1): ");
	ft_putendl_fd("Hello", 1);
	
	printf("ft_putnbr_fd(42, 1): ");
	ft_putnbr_fd(42, 1);
	printf("\n");
}

void	test_ft_memset_bzero(void)
{
	printf("\n=== Testing ft_memset & ft_bzero ===\n");
	char buf[10];
	ft_memset(buf, 'A', 5);
	printf("ft_memset: первые 5 байтов = %c%c%c%c%c\n", buf[0], buf[1], buf[2], buf[3], buf[4]);
	ft_bzero(buf, 3);
	printf("ft_bzero: первые 3 байта = %d,%d,%d\n", buf[0], buf[1], buf[2]);
}

void	test_linked_list(void)
{
	printf("\n=== Testing Linked List ===\n");
	t_list *list = NULL;
	
	char *data1 = ft_strdup("First");
	char *data2 = ft_strdup("Second");
	char *data3 = ft_strdup("Third");
	
	ft_lstadd_back(&list, ft_lstnew(data1));
	ft_lstadd_back(&list, ft_lstnew(data2));
	ft_lstadd_front(&list, ft_lstnew(data3));
	
	printf("List size: %d\n", ft_lstsize(list));
	printf("Last element: %s\n", (char *)ft_lstlast(list)->content);
	
	t_list *current = list;
	int i = 0;
	while (current)
	{
		printf("Element %d: %s\n", i++, (char *)current->content);
		current = current->next;
	}
	
	ft_lstclear(&list, free);
}

void	test_ft_lstiter(void)
{
	printf("\n=== Testing ft_lstiter ===\n");
	t_list *list = NULL;
	char *s1 = ft_strdup("a");
	char *s2 = ft_strdup("b");
	char *s3 = ft_strdup("c");
	
	ft_lstadd_back(&list, ft_lstnew(s1));
	ft_lstadd_back(&list, ft_lstnew(s2));
	ft_lstadd_back(&list, ft_lstnew(s3));
	
	ft_lstiter(list, ft_lstiter_toupper);
	
	printf("ft_lstiter result: ");
	t_list *cur = list;
	while (cur)
	{
		printf("%s ", (char *)cur->content);
		cur = cur->next;
	}
	printf("\n");
	
	ft_lstclear(&list, free);
}

void	test_ft_strnstr(void)
{
	printf("\n=== Testing ft_strnstr ===\n");
	char *big = "Hello, World!";
	char *result = ft_strnstr(big, "World", 20);
	printf("ft_strnstr(\"%s\", \"World\", 20) = \"%s\"\n", big, result ? result : "NULL");
	
	result = ft_strnstr(big, "xyz", 20);
	printf("ft_strnstr(\"%s\", \"xyz\", 20) = %s\n", big, result ? result : "NULL");
	
	result = ft_strnstr(big, "Hello", 3);
	printf("ft_strnstr(\"%s\", \"Hello\", 3) = %s (должно: NULL)\n", big, result ? result : "NULL");
}

void	test_ft_strlcpy(void)
{
	printf("\n=== Testing ft_strlcpy ===\n");
	char dst[10];
	size_t len = ft_strlcpy(dst, "Hello", 10);
	printf("ft_strlcpy(dst, \"Hello\", 10) = %zu, dst = \"%s\"\n", len, dst);
	
	len = ft_strlcpy(dst, "Hello, World!", 6);
	printf("ft_strlcpy(dst, \"Hello, World!\", 6) = %zu, dst = \"%s\"\n", len, dst);
}

void	test_ft_strlcat(void)
{
	printf("\n=== Testing ft_strlcat ===\n");
	char dst[20] = "Hello";
	size_t len = ft_strlcat(dst, " World", 20);
	printf("ft_strlcat(dst, \" World\", 20) = %zu, dst = \"%s\"\n", len, dst);
	
	char dst2[10] = "Hello";
	len = ft_strlcat(dst2, " World!", 10);
	printf("ft_strlcat(dst2, \" World!\", 10) = %zu, dst2 = \"%s\"\n", len, dst2);
}

void	test_ft_memcpy(void)
{
	printf("\n=== Testing ft_memcpy ===\n");
	char src[] = "Hello";
	char dst[10];
	ft_memcpy(dst, src, 5);
	dst[5] = '\0';
	printf("ft_memcpy(dst, \"Hello\", 5) = \"%s\"\n", dst);
}

void	test_ft_memmove(void)
{
	printf("\n=== Testing ft_memmove ===\n");
	char str[] = "123456";
	ft_memmove(str + 2, str, 3);
	printf("ft_memmove (перекрытие): \"%s\"\n", str);
}

void	test_ft_isspace(void)
{
	printf("\n=== Testing ft_isspace ===\n");
	printf("ft_isspace(' ') = %d\n", ft_isspace(' '));
	printf("ft_isspace('\\t') = %d\n", ft_isspace('\t'));
	printf("ft_isspace('\\n') = %d\n", ft_isspace('\n'));
	printf("ft_isspace('A') = %d\n", ft_isspace('A'));
}

void	test_ft_lstdelone(void)
{
	printf("\n=== Testing ft_lstdelone ===\n");
	char *data = ft_strdup("test");
	t_list *node = ft_lstnew(data);
	printf("До удаления: content = %s\n", (char *)node->content);
	ft_lstdelone(node, free);
	printf("После ft_lstdelone: элемент удалён (память освобождена)\n");
}

void	test_ft_lstmap(void)
{
	printf("\n=== Testing ft_lstmap ===\n");
	t_list *list = NULL;
	char *s1 = ft_strdup("a");
	char *s2 = ft_strdup("b");
	char *s3 = ft_strdup("c");
	
	ft_lstadd_back(&list, ft_lstnew(s1));
	ft_lstadd_back(&list, ft_lstnew(s2));
	ft_lstadd_back(&list, ft_lstnew(s3));
	
	t_list *new_list = ft_lstmap(list, ft_lstmap_toupper, free);
	
	printf("Оригинальный список: ");
	t_list *cur = list;
	while (cur)
	{
		printf("%s ", (char *)cur->content);
		cur = cur->next;
	}
	
	printf("\nНовый список (после ft_lstmap): ");
	cur = new_list;
	while (cur)
	{
		printf("%s ", (char *)cur->content);
		cur = cur->next;
	}
	printf("\n");
	
	ft_lstclear(&list, free);
	ft_lstclear(&new_list, free);
}

// ============ MAIN ============

int	main(void)
{
	printf("\n========== LIBFT TEST SUITE ==========\n");
	
	test_ft_isalpha();
	test_ft_isdigit();
	test_ft_isalnum();
	test_ft_isascii();
	test_ft_isprint();
	test_ft_toupper_tolower();
	
	test_ft_strlen();
	test_ft_strchr();
	test_ft_strrchr();
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
	
	test_ft_put_functions();
	test_ft_memset_bzero();
	
	test_linked_list();
	test_ft_lstiter();
	
	test_ft_strnstr();
	test_ft_strlcpy();
	test_ft_strlcat();
	test_ft_memcpy();
	test_ft_memmove();
	test_ft_isspace();
	test_ft_lstdelone();
	test_ft_lstmap();
	
	printf("\n========== ALL TESTS COMPLETED ==========\n");
	return (0);
}