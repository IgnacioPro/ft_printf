/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 20:44:28 by IgnacioHB         #+#    #+#             */
/*   Updated: 2020/08/11 17:16:14 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void ft_display_d(printf_s *format, int nb)
{
	int len;
	int space;
	int zero;
	char *numero;

	numero = ft_itoa(nb);
	len = ft_strlen(numero);
	space = format->width - ((format->precision <= len) 
		? len : format->precision);
	space += (nb == 0 && format->precision == 0 && format->dot == '.' &&
		format->width > 0) ? 1 : 0;
	space -= (nb < 0 && format->precision >= len) ? 1 : 0;
	zero = (nb < 0) ? (format->precision - len) + 1 : (format->precision - len);
	if (nb < 0 && (space > format->precision && format->zero_space == '0'))
		write(1, "-", 1);
		else
			format->n_d = 0;
	ft_zeros_spaces(format, nb, space, len, zero);
	free(numero);
}

void ft_zeros_spaces(printf_s *format, int nb, int space, int len, int zero)
{
	while (space-- > 0 && format->tab != '-')
	{
		if (format->zero_space != '0' || (format->dot == '.' &&
			format->precision >= 0))
			{
				write(1, " ", 1);
				format->strlen++;
			}
		else
			{
				write(1, "0", 1);
				format->strlen++;
			}
	}
	ft_precision_width(format, nb, zero);
	ft_space_blank(format, space, len, nb);
}

void ft_precision_width(printf_s *format, int nb, int zero)
{
	if (nb < 0 && format->n_d == 0)
		write(1, "-", 1);
	while (--zero >= 0)
	{
		write(1, "0", 1);
		format->strlen++;
	}
	if (!(nb == 0 && format->precision == 0 && format->dot == '.'))
		ft_print_number(nb, 1);
}

void ft_space_blank(printf_s *format, int space, int len, int nb)
{
	while (space-- >= 0)
		format->strlen += write(1, " ", 1);
	format->strlen += len;
	if (nb == 0 && format->precision == 0 && format->dot == '.')
		--format->strlen;
}
