#include "ft_printf.h"

void	print_ui_16(t_sked *s, char *uix, int *printed)
{
	if (*uix == '0' && s->accuracy == 0)
	{
		free(uix);
		uix = ft_strdup("");
	}
	if (s->accuracy <= (int)ft_strlen(uix))
		s->accuracy = 0;
	if (s->accuracy != 0 && s->accuracy > (int)ft_strlen(uix))
		s->accuracy -= (int)ft_strlen(uix);
	if (s->widtf > 0 && ((int)ft_strlen(uix) + s->accuracy) < s->widtf)
		s->widtf -= (int)ft_strlen(uix) + s->accuracy;
	else if (s->widtf > 0 && ((int)ft_strlen(uix) + s->accuracy) >= s->widtf)
		s->widtf = 0;
	*printed = s->widtf + s->accuracy;
	if ((s->widtf || s->accuracy) && !s->dash && !s->zero)
		s->widtf = putnchar(' ', s->widtf);
	if (s->widtf != 0 && s->zero == 1 && s->accuracy == 0)
		s->widtf = putnchar('0', s->widtf);
	putnchar('0', s->accuracy);
	*printed += putnstr_ui_16(uix, s->conversion);
	if (s->dash == 1 && s->widtf != 0)
		s->widtf = putnchar(' ', s->widtf);
	free(uix);
}
