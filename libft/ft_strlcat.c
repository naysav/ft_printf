#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	result;
	size_t	length_dst;

	length_dst = 0;
	while (dst[length_dst] && length_dst < size)
		length_dst++;
	if (!size)
		return (length_dst + ft_strlen(src));
	result = 0;
	while (src[result] && (result + length_dst) < (size - 1))
	{
		dst[length_dst + result] = src[result];
		result++;
	}
	if (length_dst < size)
		dst[length_dst + result] = '\0';
	while (src[result] != '\0')
		result++;
	return (result + length_dst);
}
