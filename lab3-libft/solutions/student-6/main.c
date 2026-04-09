#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	test_character_functions(void)
{
	printf("=== Character functions ===\n");
	printf("ft_isalpha('a') = %d (expected: 1)\n", ft_isalpha('a'));
	printf("ft_isdigit('5') = %d (expected: 1)\n", ft_isdigit('5'));
	printf("ft_isalnum('a') = %d (expected: 1)\n", ft_isalnum('a'));
	printf("ft_isascii('A') = %d (expected: 1)\n", ft_isascii('A'));
	printf("ft_isprint(' ') = %d (expected: 1)\n", ft_isprint(' '));
	printf("ft_toupper('a') = %c (expected: A)\n", ft_toupper('a'));
	printf("ft_tolower('A') = %c (expected: a)\n", ft_tolower('A'));
	printf("\n");
}

void	test_string_functions(void)
{
	printf("=== String functions ===\n");
	printf("ft_strlen(\"hello\") = %zu (expected: 5)\n", ft_strlen("hello"));
	printf("ft_strchr(\"hello\", 'l') = %s (expected: llo)\n", ft_strchr("hello", 'l'));
	printf("ft_strrchr(\"hello\", 'l') = %s (expected: lo)\n", ft_strrchr("hello", 'l'));
	printf("ft_strncmp(\"hello\", \"hello\", 5) = %d (expected: 0)\n", ft_strncmp("hello", "hello", 5));
	printf("\n");
}

void	test_memory_functions(void)
{
	printf("=== Memory functions ===\n");
	char	buffer[20];
	ft_memset(buffer, 'A', 5);
	buffer[5] = '\0';
	printf("ft_memset(buffer, 'A', 5) = %s (expected: AAAAA)\n", buffer);
	printf("\n");
}

void	test_conversion_functions(void)
{
	printf("=== Conversion functions ===\n");
	printf("ft_atoi(\"42\") = %d (expected: 42)\n", ft_atoi("42"));
	printf("ft_atoi(\"-123\") = %d (expected: -123)\n", ft_atoi("-123"));
	
	char	*num_str = ft_itoa(42);
	printf("ft_itoa(42) = %s (expected: 42)\n", num_str);
	free(num_str);
	
	char	*dup = ft_strdup("hello");
	printf("ft_strdup(\"hello\") = %s (expected: hello)\n", dup);
	free(dup);
	printf("\n");
}

void	test_list_functions(void)
{
	printf("=== List functions ===\n");
	t_list	*list = NULL;
	
	t_list	*node1 = ft_lstnew((void *)1);
	t_list	*node2 = ft_lstnew((void *)2);
	
	ft_lstadd_front(&list, node1);
	ft_lstadd_back(&list, node2);
	
	printf("ft_lstsize(list) = %d (expected: 2)\n", ft_lstsize(list));
	printf("ft_lstlast(list)->content = %p (expected: %p)\n", ft_lstlast(list)->content, (void *)2);
	
	ft_lstclear(&list, NULL);
	printf("\n");
}

int	main(void)
{
	printf("========== libft Testing ==========\n\n");
	
	test_character_functions();
	test_string_functions();
	test_memory_functions();
	test_conversion_functions();
	test_list_functions();
	
	printf("========== All tests completed ==========\n");
	return (0);
}
