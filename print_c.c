#include "ft_printf.h"

int	print_c(t_sked *s, char c)
{
	int	printed;

	printed = 0;
	if (s->dash == 1 && s->widtf != 0)
	{
		write(1, &c, 1);
		printed = s->widtf;
		while (--(s->widtf) > 0)
			write(1, " ", 1);
	}
	else if (s->widtf != 0)
	{
		printed = s->widtf;
		if (s->zero == 1 && s->conversion == '%' && !s->dash)
			putnchar('0', --(s->widtf));
		else
			putnchar(' ', --(s->widtf));
		write(1, &c, 1);
	}
	else
		write(1, &c, ++printed);
	return (printed);
}
