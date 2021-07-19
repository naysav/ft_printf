#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*(unsigned char *)s)
	{
		if (*(unsigned char *)s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*(unsigned char *)s == (char)c)
		return ((char *)s);
	return (NULL);
}
