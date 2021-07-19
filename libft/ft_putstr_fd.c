#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	counter;

	counter = 0;
	if (s)
	{
		while (s[counter])
		{
			write(fd, &(s[counter]), 1);
			counter++;
		}
	}
}
