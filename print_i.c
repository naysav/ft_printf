#include "ft_printf.h"

t_sked	*check_sked_i(t_sked *s, char *num)
{
	if (s->accuracy <= (int)ft_strlen(num) - 1 && *num == '-')
		s->accuracy = 0;
	if (s->accuracy <= (int)ft_strlen(num) && *num != '-')
		s->accuracy = 0;
	if (*num == '-' && s->accuracy > (int)ft_strlen(num) - 1)
		s->accuracy -= (int)ft_strlen(num) - 1;
	else if (s->accuracy != 0 && s->accuracy > (int)ft_strlen(num))
		s->accuracy -= (int)ft_strlen(num);
	if (s->widtf > 0 && ((int)ft_strlen(num) + s->accuracy) < s->widtf)
		s->widtf -= (int)ft_strlen(num) + s->accuracy;
	else if (s->widtf > 0 && ((int)ft_strlen(num) + s->accuracy) >= s->widtf)
		s->widtf = 0;
	return (s);
}

void	print_i(t_sked *s, char *num, int *printed)
{
	if (*num == '0' && s->accuracy == 0)
	{
		free(num);
		num = ft_strdup("");
	}
	s = check_sked_i(s, num);
	*printed = s->widtf;
	if ((s->widtf || s->accuracy) && !s->dash && !s->zero)
		s->widtf = putnchar(' ', s->widtf);
	if (*num == '-')
		*printed += (int)(write(1, &(*num), 1));
	if (s->widtf != 0 && s->dash == 0 && s->zero == 1)
		s->widtf = putnchar('0', s->widtf);
	*printed += putnchar('0', s->accuracy);
	if (*num == '-')
		*printed += ft_putnstr((num + 1), (int)ft_strlen(num + 1));
	else
		*printed += ft_putnstr(num, (int)ft_strlen(num));
	if (s->dash == 1 && s->widtf != 0)
		s->widtf = putnchar(' ', s->widtf);
	free(num);
}
