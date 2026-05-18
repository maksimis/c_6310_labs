#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*res;
	size_t	len;

	len = ft_strlen(s);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	ft_memcpy(res, s, len);
	res[len] = '\0';
	return (res);
}