#include "ft_printf.h"

int ft_print_arg(va_list ap, char c)
{
	int d;
	unsigned int u;
	char *s;
	unsigned long long p;

	if (c == 'c')
	{
		c = (char)va_arg(ap, int);
		write(1, &c, 1);
		return(1);
	}
	if (c == 's')
	{
		s = va_arg(ap, char *);
		ft_putstr_fd(s, 1);
		return(ft_strlen(s));
	}
	if (c == 'p') // Mirar el tamaño
	{
		p = va_arg(ap, unsigned long long);
		ft_print_address(p);
		return (8);
	}
	if (c == 'd' || c == 'i')
	{
		d = va_arg(ap, int);
		ft_putnbr_fd(d, 1);
		return (ft_figures(d));
	}
	if (c == 'u')
    {
		u =va_arg(ap, unsigned int);
		ft_putnbru_fd(u, 1);
		return(ft_figuresu(u));
	}
	if (c == 'x'|| c == 'X')
	{
		u = va_arg(ap, unsigned int);
		return(ft_print_hex(u, c));
	}
	if (c == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	else
	{
		write(1, &c, 1);
		return(2);
	}
}