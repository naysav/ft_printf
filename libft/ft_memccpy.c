#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	counter;

	counter = 0;
	while (counter < n)
	{
		((unsigned char *)dest)[counter] = ((unsigned char *)src)[counter];
		if (((unsigned char *)dest)[counter] == (unsigned char)c)
			return ((unsigned char *)dest + counter + 1);
		counter++;
	}
	return (NULL);
}
