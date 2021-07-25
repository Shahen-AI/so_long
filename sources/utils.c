#include "../so_long.h"

int	ft_strlen(char *str)
{
	int	len;
	int	i;

	i = -1;
	len = 0;
	while (str[++i] != '\0')
		++len;
	return (len);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_error(char *str)
{
	ft_putstr(str);
	exit(0);
}
