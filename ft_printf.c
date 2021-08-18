/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 09:01:07 by amorion-          #+#    #+#             */
/*   Updated: 2021/08/18 11:00:31 by amorion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_return_err(int r, int n)
{
	if (n == -1)
		return (-1);
	else
		return (r);
}

int	ft_printf(const char *str, ...)
{
	int		r;
	va_list	ap;
	int		n;

	r = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%' && *(str + 1))
		{
			n = ft_print_arg(ap, *(str + 1));
			if (n < 0)
				return (ft_return_err(r, n));
			r = r + n;
			str++;
		}
		else if (*str == '%' && ! *(str + 1))
			return (r);
		else
			r = r + write(1, str, 1);
		str++;
	}
	va_end(ap);
	return (r);
}
