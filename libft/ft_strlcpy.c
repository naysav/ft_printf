#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	result;

	result = 0;
	if (!dst || !src)
		return ((size_t) NULL);
	if (size)
	{
		while (src[result] && (result < (size - 1)))
		{
			dst[result] = src[result];
			result++;
		}
		dst[result] = '\0';
	}
	result = 0;
	while (src[result])
		result++;
	return (result);
}
