#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*result;

	result = (char *)malloc(nmemb * size);
	if (!result)
		return (NULL);
	ft_memset(result, 0, nmemb * size);
	return ((void *)result);
}
