#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_sked
{
	int		dash;
	int		zero;
	int		widtf;
	int		accuracy;
	char	conversion;
	char	**string;
	va_list	*arg_p;
}	t_sked;

// utils.c
int			ft_find_char(const char *s, int c);
int			ft_putnstr(char *string, int length);
int			putnstr_ui_16(char *string, char conversion);
int			putnchar(char c, int length);

// print_c.c
int			print_c(t_sked *s, char c);

// print_s.c
void		print_s(t_sked *sked, char *string, int *printed);

// print_i.c
t_sked		*check_sked_i(t_sked *s, char *num);
void		print_i(t_sked *s, char *num, int *printed);

// print_p.c
char		*ull_to_c(unsigned long long p, int base);
int			print_p(t_sked *s, char *p);

// print_u_10.c
char		*ui_to_char(unsigned int p, int base);
void		print_ui(t_sked *s, char *ui, int *printed);

// print_u_16.c
void		print_ui_16(t_sked *s, char *uix, int *printed);

// ft_treatment_specificer.c
void		init_sked(t_sked *sked, va_list **argument_pointer, char **string);
int			ft_treatment_conversion(t_sked *flags);
int			treatment_specificer(va_list *argument_pointer, char *string);

// ft_parsing_flags.c
t_sked		*ft_parse_widtf(t_sked *sked);
t_sked		*ft_parse_minus_or_zero(t_sked *sked);
void		ft_parse_flags(t_sked *flags);

// ft_printf.c
int			ft_treatment_string(va_list *argument_pointer, char *string);
int			ft_printf(const char *str, ...);

#endif
