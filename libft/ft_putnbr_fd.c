#include "libft.h"

void	ft_putnbr_fd(int c, int fd)
{
	long int	number;

	number = c;
	if (number < 0)
	{
		write(fd, "-", 1);
		number *= -1;
	}
	if (number > 9)
		ft_putnbr_fd((number / 10), fd);
	ft_putchar_fd(('0' + (number % 10)), fd);
}
