/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 09:00:43 by amorion-          #+#    #+#             */
/*   Updated: 2021/08/18 10:01:22 by amorion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_chars(va_list ap, char c)
{
	char	*s;

	if (c == 'c')
	{
		c = (char)va_arg(ap, int);
		write(1, &c, 1);
		return (1);
	}
	else
	{
		s = va_arg(ap, char *);
		if (!s)
			return (write(1, "(null)", 6));
		if (ft_strlen(s) > 0)
		{
			ft_putstr_fd(s, 1);
			return (ft_strlen(s));
		}
		return (-1);
	}
}

static int	ft_print_nums(va_list ap, char c)
{
	int				d;
	unsigned int	u;

	if (c == 'd' || c == 'i')
	{
		d = va_arg(ap, int);
		ft_putnbr_fd(d, 1);
		return (ft_figures(d));
	}
	else if (c == 'u')
	{
		u = va_arg(ap, unsigned int);
		ft_putnbru_fd(u, 1);
		return (ft_figuresu(u));
	}
	else
	{
		u = va_arg(ap, unsigned int);
		return (ft_print_hex(u, c));
	}
}

int	ft_print_arg(va_list ap, char c)
{
	unsigned long long	p;

	if (c == 'c' || c == 's')
		return (ft_print_chars(ap, c));
	if (c == 'p')
	{
		p = va_arg(ap, unsigned long long);
		return (ft_print_address(p));
	}
	if (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X')
		return (ft_print_nums(ap, c));
	if (c == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	else
		return (0);
}
