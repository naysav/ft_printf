#include "ft_printf.h"

int	ft_treatment_string(va_list *argument_pointer, char *string)
{
	int	printed;

	printed = 0;
	while (*string)
	{
		if (*string != '%')
		{
			write(1, &(*string), 1);
			string++;
			printed++;
		}
		else
		{
			printed += treatment_specificer(argument_pointer, ++string);
			while (!ft_find_char("cspdiuxX%", *string))
				string++;
			string++;
		}
	}
	return (printed);
}

int	ft_printf(const char *str, ...)
{
	int			printed;
	va_list		argument_pointer;
	char		*string;

	string = ft_strdup(str);
	va_start(argument_pointer, str);
	printed = ft_treatment_string(&argument_pointer, string);
	va_end(argument_pointer);
	free(string);
	return (printed);
}
