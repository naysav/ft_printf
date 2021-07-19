#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (0 < n--)
		str[n] = (unsigned char)c;
	return (s);
}
