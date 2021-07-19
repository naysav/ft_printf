#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*string;
	unsigned char	*result;
	size_t			counter;

	if (!n || dest == src)
		return (dest);
	counter = 0;
	string = (unsigned char *)src;
	result = (unsigned char *)dest;
	while (counter < n)
	{
		result[counter] = string[counter];
		counter++;
	}
	return (dest);
}
