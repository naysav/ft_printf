#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		counter;
	char	*result;

	counter = 0;
	while (s[counter])
		counter++;
	result = (char *)malloc(sizeof(*s) * (counter + 1));
	if (result)
	{
		counter = 0;
		while (s[counter])
		{
			result[counter] = s[counter];
			counter++;
		}
		result[counter] = s[counter];
	}
	return (result);
}
