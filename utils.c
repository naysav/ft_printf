#include "ft_printf.h"

int	ft_find_char(const char *s, int c)
{
	while (*(unsigned char *)s)
	{
		if (*(unsigned char *)s == (char)c)
			return (1);
		s++;
	}
	return (0);
}

int	ft_putnstr(char *string, int length)
{
	int	counter;

	counter = 0;
	while (counter < length)
	{
		write(1, &string[counter], 1);
		counter++;
	}
	return (length);
}

int	putnstr_ui_16(char *string, char conversion)
{
	int	counter;

	counter = 0;
	while (string[counter])
	{
		if (string[counter] >= 65 && string[counter] <= 90
			&& conversion == 'x')
		{	
			string[counter] += 32;
			write(1, &string[counter], 1);
		}
		else
			write(1, &string[counter], 1);
		counter++;
	}
	return (counter);
}

int	putnchar(char c, int length)
{
	int	counter;

	counter = length;
	while ((counter)-- > 0)
		write(1, &c, 1);
	return (length);
}
