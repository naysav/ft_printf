#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		len_trimstr;

	if (!s1 || !set)
		return (NULL);
	if (*s1 == '\0')
		return (ft_strdup(""));
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	len_trimstr = 0;
	while (s1[len_trimstr])
		len_trimstr++;
	while (ft_strchr(set, s1[len_trimstr]) && len_trimstr)
		len_trimstr--;
	len_trimstr++;
	result = ft_substr(s1, 0, len_trimstr);
	return (result);
}
