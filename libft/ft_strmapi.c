#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	counter;

	if (!s || !f)
		return (NULL);
	result = (char *)malloc(sizeof(*s) * (ft_strlen(s) + 1));
	if (!result)
		return (NULL);
	counter = 0;
	while (s[counter])
	{
		result[counter] = f(counter, s[counter]);
		counter++;
	}
	result[counter] = '\0';
	return (result);
}
