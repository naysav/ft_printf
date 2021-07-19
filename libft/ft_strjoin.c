#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	counter;

	if (!s1 || !s2)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (result)
	{
		counter = 0;
		while (*s1)
			result[counter++] = *(s1++);
		while (*s2)
			result[counter++] = *(s2++);
		result[counter] = '\0';
		return (result);
	}
	return (NULL);
}
