/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 10:59:09 by amorion-          #+#    #+#             */
/*   Updated: 2021/08/18 10:59:45 by amorion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
int		ft_printf(const char *str, ...);
int		ft_print_arg(va_list ap, char c);
int		ft_figures(int n);
int		ft_figuresu(unsigned int n);
int		ft_print_hex(unsigned long long d, char c);
void	ft_putnbru_fd(unsigned int n, int fd);
void	ft_putnbru_fd(unsigned int n, int fd);
int		ft_print_arg(va_list ap, char c);
int		ft_print_address(unsigned long long p);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *str, int fd);
int		ft_strlen(char *str);
#endif
