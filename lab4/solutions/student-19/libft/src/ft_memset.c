#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	unsigned char	*p;

	p = s;
	i = 0;
	while (i < n)
		p[i++] = (unsigned char)c;
	return (s);
}