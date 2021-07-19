#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	counter;

	counter = 0;
	while (((unsigned char *)s)[counter])
		counter++;
	if (((unsigned char *)s)[counter] == (char)c)
		return ((char *)(s + counter));
	while (counter >= 0)
	{
		if (((unsigned char *)s)[counter] == (char)c)
			return ((char *)(s + counter));
		counter--;
	}
	return (NULL);
}
