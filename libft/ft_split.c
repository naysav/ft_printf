#include "libft.h"

static size_t	length_part_string(char const *s, char c)
{
	size_t	result;

	result = 0;
	while (*(unsigned char *)s && *(unsigned char *)s != c)
	{
		result++;
		s++;
	}
	return (result);
}

static size_t	counter_part_string(char const *s, char c)
{
	size_t	result;

	result = 0;
	while (*s)
	{
		if (*s != c)
		{
			result++;
			while (*s != c && *s)
				s++;
			s--;
		}
		s++;
	}
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	counter_strok;

	result = NULL;
	if (!s)
		return (NULL);
	counter_strok = 0;
	result = (char **)malloc((counter_part_string(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			result[counter_strok] = ft_substr(s, 0, length_part_string(s, c));
			s += length_part_string(s, c);
			counter_strok++;
		}
		else
			s++;
	}
	result[counter_strok] = NULL;
	return (result);
}
