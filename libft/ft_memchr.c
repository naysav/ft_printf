#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*string;

	string = (unsigned char *)s;
	while (0 < n--)
	{
		if (*string == (unsigned char)c)
			return ((void *)string);
		string++;
	}
	return (NULL);
}
