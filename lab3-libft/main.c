#include "inc/libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	del(void *content)
{
	free(content);
}

void	print_content(void *content)
{
	printf("%s\n", (char *)content);
}

void	*dup_content(void *content)
{
	return (ft_strdup((char *)content));
}

char	map_char(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

void	iter_char(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
}

int	main(void)
{
	char	buffer[50];
	char	**split;
	char	*tmp;
	t_list	*lst;
	t_list	*mapped;
	int		i;

	printf("=== CHAR ===\n");
	printf("ft_isalpha('A') = %d\n", ft_isalpha('A'));
	printf("ft_isdigit('5') = %d\n", ft_isdigit('5'));
	printf("ft_isalnum('z') = %d\n", ft_isalnum('z'));
	printf("ft_isascii(128) = %d\n", ft_isascii(128));
	printf("ft_isprint(' ') = %d\n", ft_isprint(' '));
	printf("ft_toupper('a') = %c\n", ft_toupper('a'));
	printf("ft_tolower('Z') = %c\n", ft_tolower('Z'));
	printf("ft_isspace('\\n') = %d\n", ft_isspace('\n'));

	printf("\n=== STRING ===\n");
	printf("ft_strlen(\"hello\") = %zu\n", ft_strlen("hello"));
	printf("ft_strchr(\"hello\", 'l') = %s\n", ft_strchr("hello", 'l'));
	printf("ft_strrchr(\"hello\", 'l') = %s\n", ft_strrchr("hello", 'l'));
	printf("ft_strncmp(\"abc\", \"abd\", 2) = %d\n", ft_strncmp("abc", "abd", 2));
	printf("ft_strnstr(\"hello world\", \"world\", 11) = %s\n",
		ft_strnstr("hello world", "world", 11));

	ft_strlcpy(buffer, "hello", sizeof(buffer));
	printf("ft_strlcpy buffer = %s\n", buffer);
	ft_strlcat(buffer, " world", sizeof(buffer));
	printf("ft_strlcat buffer = %s\n", buffer);

	tmp = ft_strdup("duplicate");
	printf("ft_strdup = %s\n", tmp);
	free(tmp);

	tmp = ft_substr("hello world", 6, 5);
	printf("ft_substr = %s\n", tmp);
	free(tmp);

	tmp = ft_strjoin("hello ", "world");
	printf("ft_strjoin = %s\n", tmp);
	free(tmp);

	tmp = ft_strtrim("xxhelloxx", "x");
	printf("ft_strtrim = %s\n", tmp);
	free(tmp);

	split = ft_split("one,two,three", ',');
	i = 0;
	while (split[i])
	{
		printf("ft_split[%d] = %s\n", i, split[i]);
		free(split[i]);
		i++;
	}
	free(split);

	tmp = ft_itoa(-2147483648);
	printf("ft_itoa(INT_MIN) = %s\n", tmp);
	free(tmp);

	tmp = ft_strmapi("abc", map_char);
	printf("ft_strmapi = %s\n", tmp);
	free(tmp);

	tmp = ft_strdup("abc");
	ft_striteri(tmp, iter_char);
	printf("ft_striteri = %s\n", tmp);
	free(tmp);

	printf("\n=== MEMORY ===\n");
	ft_memset(buffer, 'A', 5);
	buffer[5] = '\0';
	printf("ft_memset = %s\n", buffer);

	ft_bzero(buffer, 5);
	printf("ft_bzero first byte = %d\n", buffer[0]);

	ft_memcpy(buffer, "hello", 6);
	printf("ft_memcpy = %s\n", buffer);

	ft_memmove(buffer + 2, buffer, 4);
	buffer[6] = '\0';
	printf("ft_memmove overlap = %s\n", buffer);

	printf("ft_memchr(\"abc\", 'b', 3) = %s\n",
		(char *)ft_memchr("abc", 'b', 3));
	printf("ft_memcmp(\"abc\", \"abd\", 3) = %d\n",
		ft_memcmp("abc", "abd", 3));

	tmp = ft_calloc(5, sizeof(char));
	printf("ft_calloc first byte = %d\n", tmp[0]);
	free(tmp);

	printf("\n=== ATOI ===\n");
	printf("ft_atoi(\"   -42\") = %d\n", ft_atoi("   -42"));

	printf("\n=== FD OUTPUT ===\n");
	ft_putchar_fd('X', 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("hello fd\n", 1);
	ft_putendl_fd("hello endl", 1);
	ft_putnbr_fd(-12345, 1);
	ft_putchar_fd('\n', 1);

	printf("\n=== LIST ===\n");
	lst = NULL;
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("one")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("two")));
	ft_lstadd_front(&lst, ft_lstnew(ft_strdup("zero")));

	printf("ft_lstsize = %d\n", ft_lstsize(lst));
	printf("ft_lstlast = %s\n", (char *)ft_lstlast(lst)->content);

	printf("ft_lstiter:\n");
	ft_lstiter(lst, print_content);

	mapped = ft_lstmap(lst, dup_content, del);
	printf("ft_lstmap:\n");
	ft_lstiter(mapped, print_content);

	ft_lstclear(&lst, del);
	ft_lstclear(&mapped, del);

	printf("\n=== DONE ===\n");
	return (0);
}