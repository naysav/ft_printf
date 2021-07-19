#include "ft_printf.h"

void	print_s(t_sked *s, char *str, int *printed)
{
	if (str == NULL)
		str = "(null)";
	if (s->accuracy != -1 && s->widtf
		&& s->widtf > s->accuracy && s->accuracy < (int)ft_strlen(str))
		s->widtf -= s->accuracy;
	else if (s->widtf > (int)ft_strlen(str))
		s->widtf -= (int)ft_strlen(str);
	else if (s->widtf <= (int)ft_strlen(str) || s->widtf < s->accuracy)
		s->widtf = 0;
	*printed = s->widtf;
	if (s->dash == 0 && s->zero == 0 && s->widtf != 0)
		while ((s->widtf)-- > 0)
			write(1, " ", 1);
	if (s->dash == 0 && s->zero == 1 && s->widtf != 0)
		while ((s->widtf)-- > 0)
			write(1, "0", 1);
	if (s->accuracy == -1 || s->accuracy >= (int)ft_strlen(str))
		*printed += ft_putnstr(str, (int)ft_strlen(str));
	else if (s->accuracy > 0)
		*printed += ft_putnstr(str, s->accuracy);
	if (s->dash == 1 && s->widtf != 0)
		while ((s->widtf)-- > 0)
			write(1, " ", 1);
}
