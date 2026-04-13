#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	int		i;

	if (!s)
		return (NULL);
	ch = (char)c;
	i = (int)ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == ch)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}
