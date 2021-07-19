#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n--)
	{
		if (*(unsigned char *)s2 != *(unsigned char *)s1)
			return ((int)(*(unsigned char *)s1 - *(unsigned char *)s2));
		if (!(*(unsigned char *)s2) || !(*(unsigned char *)s1))
			return ((int)(*(unsigned char *)s1 - *(unsigned char *)s2));
		s1++;
		s2++;
	}
	return (0);
}
