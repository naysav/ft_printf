#include "ft_printf.h"

char	*ull_to_c(unsigned long long p, int base)
{
	char				*pointer;
	unsigned long long	p_copy;
	int					counter;

	if (p == 0)
		return (ft_strdup("0"));
	counter = 0;
	p_copy = p;
	while (p != 0 && ++counter)
		p /= base;
	pointer = malloc(sizeof(char) * (counter + 1));
	if (!pointer)
		return (0);
	pointer[counter] = '\0';
	while (p_copy != 0)
	{
		if ((p_copy % base) < 10)
			pointer[counter - 1] = (p_copy % base) + 48;
		else
			pointer[counter - 1] = (p_copy % base) + 87;
		p_copy /= base;
		counter--;
	}
	return (pointer);
}

int	print_p(t_sked *s, char *p)
{
	int	printed;

	if (*p == '0' && s->accuracy > -1)
		p = ft_strdup("");
	printed = 2;
	if (s->widtf != 0 && s->widtf != 0 && s->widtf > (int)ft_strlen(p) + 2)
		s->widtf -= (int)ft_strlen(p) + 2;
	else
		s->widtf = 0;
	if (s->dash != 1 && s->widtf != 0)
	{
		printed += s->widtf;
		while ((s->widtf)-- > 0)
			write(1, " ", 1);
	}
	write(1, "0x", 2);
	if (s->accuracy > -1 && s->accuracy > (int)ft_strlen(p))
		printed += putnchar('0', s->accuracy - (int)ft_strlen(p));
	printed += ft_putnstr(p, (int)ft_strlen(p));
	if (s->dash == 1 && s->widtf != 0)
		printed += putnchar(' ', s->widtf);
	free(p);
	return (printed);
}
