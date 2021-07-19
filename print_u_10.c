#include "ft_printf.h"

char	*ui_to_char(unsigned int p, int base)
{
	char			*pointer;
	unsigned int	p_copy;
	int				counter;

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
			pointer[counter - 1] = (p_copy % base) + 55;
		p_copy /= base;
		counter--;
	}
	return (pointer);
}

void	print_ui(t_sked *s, char *ui, int *printed)
{
	if (*ui == '0' && s->accuracy == 0)
	{
		free(ui);
		ui = ft_strdup("");
	}
	if (s->accuracy <= (int)ft_strlen(ui))
		s->accuracy = 0;
	if (s->accuracy != 0 && s->accuracy > (int)ft_strlen(ui))
		s->accuracy -= (int)ft_strlen(ui);
	if (s->widtf > 0 && ((int)ft_strlen(ui) + s->accuracy) < s->widtf)
		s->widtf -= (int)ft_strlen(ui) + s->accuracy;
	else if (s->widtf > 0 && ((int)ft_strlen(ui) + s->accuracy) >= s->widtf)
		s->widtf = 0;
	*printed = s->widtf + s->accuracy;
	if ((s->widtf || s->accuracy) && !s->dash && !s->zero)
		s->widtf = putnchar(' ', s->widtf);
	if (s->widtf != 0 && s->zero == 1 && s->accuracy == 0)
		s->widtf = putnchar('0', s->widtf);
	putnchar('0', s->accuracy);
	*printed += ft_putnstr(ui, (int)ft_strlen(ui));
	if (s->dash == 1 && s->widtf != 0)
		s->widtf = putnchar(' ', s->widtf);
	free(ui);
}
