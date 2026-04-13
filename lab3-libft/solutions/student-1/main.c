#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* -------- is* / to* / strlen ---------- */

static void	test_is_to_strlen(void)
{
	int	c;
	int	ok_alpha = 1;
	int	ok_digit = 1;
	int	ok_alnum = 1;
	int	ok_ascii = 1;
	int	ok_print = 1;

	printf("=== 1–9: is* / to* / strlen ===\n");

	/* Проверяем все символы один раз, но выводим итогами */
	for (c = 0; c <= 127; c++)
	{
		if (ft_isalpha(c) != (!!isalpha(c)))
			ok_alpha = 0;
		if (ft_isdigit(c) != (!!isdigit(c)))
			ok_digit = 0;
		if (ft_isalnum(c) != (!!isalnum(c)))
			ok_alnum = 0;
		if (ft_isascii(c) != (!!isascii(c)))
			ok_ascii = 0;
		if (ft_isprint(c) != (!!isprint(c)))
			ok_print = 0;
	}

	printf("1. ft_isalpha: %s\n", ok_alpha ? "OK" : "FAIL");
	printf("2. ft_isdigit: %s\n", ok_digit ? "OK" : "FAIL");
	printf("3. ft_isalnum: %s\n", ok_alnum ? "OK" : "FAIL");
	printf("4. ft_isascii: %s\n", ok_ascii ? "OK" : "FAIL");
	printf("5. ft_isprint: %s\n", ok_print ? "OK" : "FAIL");

	printf("6. ft_toupper('a') = %c (orig %c)\n",
		ft_toupper('a'), toupper('a'));
	printf("7. ft_tolower('Z') = %c (orig %c)\n",
		ft_tolower('Z'), tolower('Z'));

	printf("8. ft_strlen(\"Hello\") = %zu (orig %zu)\n",
		ft_strlen("Hello"), strlen("Hello"));
	printf("9. ft_strlen(\"\") = %zu (orig %zu)\n\n",
		ft_strlen(""), strlen(""));
}


/* -------- strchr / strrchr / strncmp / strnstr / strlcpy / strlcat -------- */

static void	test_str_functions(void)
{
	char	buf[20];

	printf("=== 10–15: string search / compare ===\n");
	printf("10. ft_strchr(\"abcabc\", 'b') = %s (orig %s)\n",
		ft_strchr("abcabc", 'b'), strchr("abcabc", 'b'));
	printf("11. ft_strrchr(\"abcabc\", 'b') = %s (orig %s)\n",
		ft_strrchr("abcabc", 'b'), strrchr("abcabc", 'b'));

	printf("12. ft_strncmp(\"abc\",\"abd\",3)=%d (orig %d)\n",
		ft_strncmp("abc", "abd", 3), strncmp("abc", "abd", 3));
	printf("13. ft_strncmp(\"abc\",\"abc\",2)=%d (orig %d)\n",
		ft_strncmp("abc", "abc", 2), strncmp("abc", "abc", 2));

	printf("14. ft_strnstr(\"Foo Bar Baz\",\"Bar\",11)=%s\n",
		ft_strnstr("Foo Bar Baz", "Bar", 11));
	printf("15. ft_strnstr(\"Foo Bar\",\"Baz\",7)=%s\n",
		ft_strnstr("Foo Bar", "Baz", 7));

	printf("\n=== 16–17: strlcpy / strlcat ===\n");
	memset(buf, 'X', sizeof(buf));
	buf[0] = '\0';
	printf("16. ft_strlcpy ret=%zu, dst=\"%s\"\n",
		ft_strlcpy(buf, "Hello", sizeof(buf)), buf);
	printf("17. ft_strlcat ret=%zu, dst=\"%s\"\n\n",
		ft_strlcat(buf, " World", sizeof(buf)), buf);
}

/* -------- atoi / itoa / isspace ---------- */

static void	test_atoi_itoa(void)
{
	const char	*tests[] = {"0", "42", "-42", "   +10",
		"  -2147483648", "2147483647", "\t\n  -0012abc", NULL};
	int			i;
	char		*str;

	printf("=== 18–24: atoi / itoa / isspace ===\n");
	i = 0;
	while (tests[i])
	{
		printf("18.%d ft_atoi(\"%s\") = %d\n",
			i, tests[i], ft_atoi(tests[i]));
		i++;
	}
	printf("19. ft_isspace(' ') = %d\n", ft_isspace(' '));
	printf("20. ft_isspace('a') = %d\n", ft_isspace('a'));

	str = ft_itoa(-2147483648);
	printf("21. ft_itoa(-2147483648) = %s\n", str);
	free(str);
	str = ft_itoa(0);
	printf("22. ft_itoa(0) = %s\n\n", str);
	free(str);
}

/* -------- память: memset/bzero/memcpy/memmove/calloc ---------- */

static void	test_memory(void)
{
	char	buf1[20];
	char	buf2[20];
	char	src[20] = "1234567890";
	char	*cal;

	printf("=== 25–29: memory ===\n");
	ft_memset(buf1, 'A', 10);
	buf1[10] = '\0';
	printf("25. ft_memset -> \"%s\"\n", buf1);

	ft_bzero(buf1, 5);
	printf("26. ft_bzero first 5 -> \"%s\"\n", buf1);

	ft_memcpy(buf1, src, 10);
	buf1[10] = '\0';
	printf("27. ft_memcpy -> \"%s\"\n", buf1);

	strcpy(buf2, "abcdefghij");
	ft_memmove(buf2 + 2, buf2, 8);
	buf2[10] = '\0';
	printf("28. ft_memmove overlap -> \"%s\"\n", buf2);

	cal = (char *)ft_calloc(5, sizeof(char));
	if (cal)
	{
		int	i;

		printf("29. ft_calloc(5,char):");
		i = 0;
		while (i < 5)
		{
			printf(" %d", (unsigned char)cal[i]);
			i++;
		}
		printf("\n\n");
		free(cal);
	}
}

/* -------- строки с malloc: strdup/substr/strjoin/strtrim/split/strmapi/striteri ---------- */

static char	to_upper_idx(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

static void	iter_to_x(unsigned int i, char *c)
{
	(void)i;
	if (*c != ' ')
		*c = 'X';
}

static void	test_string_alloc(void)
{
	char	*dup;
	char	*sub;
	char	*join;
	char	*trim;
	char	**split;
	char	*mapi;
	char	str_iter[] = "iter test";
	int		i;

	printf("=== 30–36: strdup/substr/strjoin/strtrim/split/strmapi/striteri ===\n");
	dup = ft_strdup("Hello");
	sub = ft_substr("HelloWorld", 5, 10);
	join = ft_strjoin("foo", "bar");
	trim = ft_strtrim("  xxx42xxx  ", " x");
	printf("30. ft_strdup: \"%s\"\n", dup);
	printf("31. ft_substr(\"HelloWorld\",5,10): \"%s\"\n", sub);
	printf("32. ft_strjoin(\"foo\",\"bar\"): \"%s\"\n", join);
	printf("33. ft_strtrim(\"  xxx42xxx  \",\" x\"): \"%s\"\n", trim);

	split = ft_split("  hello  world  42  ", ' ');
	printf("34. ft_split:\n");
	i = 0;
	while (split && split[i])
	{
		printf("   [%d] \"%s\"\n", i, split[i]);
		free(split[i]);
		i++;
	}
	free(split);

	mapi = ft_strmapi("abcDe", to_upper_idx);
	printf("35. ft_strmapi(\"abcDe\", to_upper_idx): \"%s\"\n", mapi);
	free(mapi);

	ft_striteri(str_iter, iter_to_x);
	printf("36. ft_striteri(\"iter test\"): \"%s\"\n\n", str_iter);

	free(dup);
	free(sub);
	free(join);
	free(trim);
}

/* -------- put*fd -------- */

static void	test_put_fd(void)
{
	printf("=== 37–40: put*fd (stdout) ===\n");
	printf("37. ft_putchar_fd('A'):\n");
	ft_putchar_fd('A', 1);
	ft_putchar_fd('\n', 1);
	printf("38. ft_putstr_fd(\"Hello\"):\n");
	ft_putstr_fd("Hello", 1);
	ft_putchar_fd('\n', 1);
	printf("39. ft_putendl_fd(\"World\"):\n");
	ft_putendl_fd("World", 1);
	printf("40. ft_putnbr_fd(-12345):\n");
	ft_putnbr_fd(-12345, 1);
	ft_putchar_fd('\n', 1);
	printf("\n");
}

/* -------- списки -------- */

static void	del_dummy(void *p)
{
	(void)p;
}

static void	*dup_content(void *p)
{
	return (ft_strdup((char *)p));
}

static void	print_node(void *p)
{
	printf("   iter: %s\n", (char *)p);
}

static void	test_list(void)
{
	t_list	*head;
	t_list	*tmp;
	t_list	*map;

	printf("=== 41–49: list functions ===\n");
	head = NULL;
	ft_lstadd_back(&head, ft_lstnew("one"));
	ft_lstadd_front(&head, ft_lstnew("zero"));
	ft_lstadd_back(&head, ft_lstnew("two"));
	printf("41. ft_lstsize = %d\n", ft_lstsize(head));
	printf("42. ft_lstlast content = %s\n",
		(char *)ft_lstlast(head)->content);

	printf("43. manual iteration:\n");
	tmp = head;
	while (tmp)
	{
		printf("   node: %s\n", (char *)tmp->content);
		tmp = tmp->next;
	}

	printf("44. ft_lstiter:\n");
	ft_lstiter(head, print_node);

	printf("45–48. ft_lstmap (duplicate strings):\n");
	map = ft_lstmap(head, dup_content, free);
	tmp = map;
	while (tmp)
	{
		printf("   mapped: %s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
	ft_lstclear(&head, del_dummy);
	ft_lstclear(&map, free);
	printf("49. lists cleared\n\n");
}

/* -------- main -------- */

int	main(void)
{
	printf("===== Testing libft (numbered) =====\n\n");
	test_is_to_strlen();
	test_str_functions();
	test_atoi_itoa();
	test_memory();
	test_string_alloc();
	test_put_fd();
	test_list();
	printf("===== End of tests =====\n");
	return (0);
}
