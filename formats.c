#include "ft_printf.h"

int ft_figures(int n)
{
	int i;

	i = 1;
	while(n / 10)
	{
		i++;
		n = n / 10;
	}
	if (n < 0)
		i++;
	return(i);
}

int ft_figuresu(unsigned int n)
{
	int i;

	i = 1;
	while(n / 10)
	{
		i++;
		n = n / 10;
	}
	return(i);
}

int ft_print_hex(unsigned long long d, char c)
{
	int i;
    char *str;

	i = 0;
    if (c == 'x')
	{
    	str = "0123456789abcdef";
	}
	if (c == 'X')
    {
		str = "0123456789ABCDEF";
	}
	if (d < 16)
	{
		write(1, &str[d % 16], 1);
		return (1);
	}
	else
	{
		i = ft_print_hex(d / 16, c);
		write(1, &str[d % 16], 1);
		return(i + 1);
	}
}

void	ft_putnbru_fd(unsigned int n, int fd)
{
	char	c;

	if (n < 10)
	{
		c = n + '0';
		write(fd, &c, 1);
	}
	else
	{
		ft_putnbru_fd(n / 10, fd);
		c = n % 10 + '0';
		write(fd, &c, 1);
	}
}

int ft_print_address(unsigned long long p) // El retorno de los punteros está mal
{
	write(1, "0x", 2);
	return(ft_print_hex(p, 'x') + 2);
}