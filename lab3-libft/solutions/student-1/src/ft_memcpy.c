#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	const char		*s;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = (unsigned char)s[i];
		i++;
	}
	return (dest);
}
