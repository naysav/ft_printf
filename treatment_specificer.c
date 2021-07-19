#include "ft_printf.h"

void	init_sked(t_sked *sked, va_list **argument_pointer, char **str)
{
	sked->dash = 0;
	sked->zero = 0;
	sked->widtf = 0;
	sked->accuracy = -1;
	sked->conversion = '~';
	sked->string = str;
	sked->arg_p = *argument_pointer;
}

int	ft_treatment_conversion(t_sked *s)
{
	int	p;

	p = 0;
	if (s->conversion == 'c')
		p = print_c(s, (char)(va_arg(*(s->arg_p), int)));
	if (s->conversion == '%')
		p = print_c(s, '%');
	if (s->conversion == 's')
		print_s(s, va_arg(*(s->arg_p), char *), &p);
	if (s->conversion == 'p')
		p = print_p(s, ull_to_c(va_arg(*(s->arg_p), unsigned long long), 16));
	if (s->conversion == 'd' || s->conversion == 'i')
		print_i(s, ft_itoa(va_arg(*(s->arg_p), int)), &p);
	if (s->conversion == 'u')
		print_ui(s, ui_to_char(va_arg(*(s->arg_p), unsigned int), 10), &p);
	if (s->conversion == 'x' || s->conversion == 'X')
		print_ui_16(s, ui_to_char(va_arg(*(s->arg_p), unsigned int), 16), &p);
	return (p);
}

int	treatment_specificer(va_list *argument_pointer, char *string)
{
	t_sked	sked;
	int		printed;

	printed = 0;
	init_sked(&sked, &argument_pointer, &string);
	ft_parse_flags(&sked);
	printed = ft_treatment_conversion(&sked);
	return (printed);
}
