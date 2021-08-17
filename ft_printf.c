/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 09:01:07 by amorion-          #+#    #+#             */
/*   Updated: 2021/08/17 09:16:57 by amorion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		r;
	va_list	ap;

	r = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			r = r + ft_print_arg(ap, *(str + 1));
			str = str + 2;
		}
		else
		{
			write(1, str, 1);
			str++;
			r++;
		}
	}
	va_end(ap);
	return (r);
}
