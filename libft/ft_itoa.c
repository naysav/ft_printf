#include "libft.h"

static int	length_of_number(int n)
{
	int		result;

	result = 0;
	if (n < 0 || n == 0)
	{
		n *= -1;
		result++;
	}
	while (n > 0)
	{
		n /= 10;
		result++;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	char		*result;
	int			length;
	int			counter;

	counter = 0;
	length = length_of_number(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	result = (char *)malloc(sizeof(char) * (length + 1));
	if (!result)
		return (NULL);
	result[length] = '\0';
	if (n < 0)
	{
		result[counter] = '-';
		n *= -1;
		counter++;
	}
	while (counter < length--)
	{
		result[length] = n % 10 + '0';
		n /= 10;
	}
	return (result);
}
