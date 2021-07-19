#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	counter;

	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - (size_t)start)
		len = ft_strlen(s) - start;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result)
	{
		counter = 0;
		while (len-- > 0)
		{
			*result = *(s + start + counter);
			counter++;
			result++;
		}
		*result = '\0';
		result = result - counter;
	}
	return (result);
}
