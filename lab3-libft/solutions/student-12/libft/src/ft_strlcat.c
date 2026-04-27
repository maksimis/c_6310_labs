#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	if (!dst || !src)
		return (0); // безопасная проверка на NULL

	dst_len = 0;
	while (dst[dst_len] && dst_len < size)
		dst_len++;

	src_len = 0;
	while (src[src_len])
		src_len++;

	i = 0;
	if (dst_len < size)
	{
		while (src[i] && dst_len + i + 1 < size)
		{
			dst[dst_len + i] = src[i];
			i++;
		}
		dst[dst_len + i] = '\0';
	}
	return (dst_len + src_len);
}