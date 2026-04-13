#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*copy;
	size_t	i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	copy = (char *)malloc(len + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
