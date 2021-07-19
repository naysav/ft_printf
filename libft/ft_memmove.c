#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	counter;

	if (!dest && !src)
		return (NULL);
	counter = 0;
	if ((unsigned char *)dest > (unsigned char *)src)
		while (n--)
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	else
	{
		while (counter < n)
		{
			((unsigned char *)dest)[counter] = *(unsigned char *)(src++);
			counter++;
		}
	}
	return (dest);
}
