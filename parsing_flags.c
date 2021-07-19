#include "ft_printf.h"

t_sked	*ft_parse_minus_or_zero(t_sked *sked)
{
	while (**(sked->string) == '-' || **(sked->string) == '0')
	{
		if (sked->dash == 1)
		{
			(*(sked->string))++;
			continue ;
		}
		if (**(sked->string) == '-')
		{
			sked->dash = 1;
			sked->zero = 0;
		}
		else if (**(sked->string) == '0' && sked->dash != 1)
			sked->zero = 1;
		(*(sked->string))++;
	}
	return (sked);
}

t_sked	*ft_parse_widtf(t_sked *sked)
{
	if (**(sked->string) == '*')
	{
		sked->widtf = va_arg(*(sked->arg_p), int);
		if (sked->widtf < 0)
		{
			sked->widtf *= -1;
			sked->dash = 1;
			sked->zero = 0;
		}
	}
	else if ((**(sked->string) >= '1' && **(sked->string) <= '9'))
		sked->widtf = ft_atoi(*(sked->string));
	while ((**(sked->string) >= '0' && **(sked->string) <= '9')
		|| **(sked->string) == '*')
	{
		(*(sked->string))++;
	}
	return (sked);
}

t_sked	*ft_parse_accuracy(t_sked *sked)
{
	(*(sked->string))++;
	if (**(sked->string) == '*')
	{
		sked->accuracy = va_arg(*(sked->arg_p), int);
		if (sked->accuracy < 0)
			sked->accuracy = -1;
	}
	else if (ft_find_char("cspdiuxX", **(sked->string)))
		sked->accuracy = 0;
	else if (**(sked->string) >= '0' && **(sked->string) <= '9')
		sked->accuracy = ft_atoi(*(sked->string));
	while ((**(sked->string) >= '0' && **(sked->string) <= '9')
		|| **(sked->string) == '*' || **(sked->string) == '*')
		(*(sked->string))++;
	if (sked->accuracy > -1 && **(sked->string) != '%')
		sked->zero = 0;
	return (sked);
}

void	ft_parse_flags(t_sked *sked)
{
	if (**(sked->string) == '-' || **(sked->string) == '0')
		sked = ft_parse_minus_or_zero(sked);
	if ((**(sked->string) >= '1' && **(sked->string) <= '9')
		|| **(sked->string) >= '*')
		sked = ft_parse_widtf(sked);
	if (**(sked->string) == '.')
		sked = ft_parse_accuracy(sked);
	sked->conversion = **(sked->string);
	(*(sked->string))++;
}
