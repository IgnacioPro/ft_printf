/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 20:44:28 by IgnacioHB         #+#    #+#             */
/*   Updated: 2020/08/13 13:49:45 by ihorcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_display_d(t_printf *format, int nb)
{
	int		len;
	int		zero;
	char	*numero;

	numero = ft_itoa(nb);
	len = ft_strlen(numero);
	format->d_s = format->width - ((format->precision <= len)
		? len : format->precision);
	format->d_s += (nb == 0 && format->precision == 0 && format->dot == '.' &&
		format->width > 0) ? 1 : 0;
	format->d_s -= (nb < 0 && format->precision >= len) ? 1 : 0;
	zero = (nb < 0) ? (format->precision - len) + 1 : (format->precision - len);
	if (nb < 0 && (format->d_s > format->precision &&
				format->zero_space == '0'))
		write(1, "-", 1);
	else
		format->n_d = 0;
	ft_zeros_spaces(format, nb, len, zero);
	free(numero);
}

void	ft_zeros_spaces(t_printf *format, int nb, int len, int zero)
{
	while (format->d_s-- > 0 && format->tab != '-')
	{
		if (format->zero_space != '0' || (format->dot == '.'
			&& format->precision >= 0))
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
	ft_space_blank(format, len, nb);
}

void	ft_precision_width(t_printf *format, int nb, int zero)
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

void	ft_space_blank(t_printf *format, int len, int nb)
{
	while (format->d_s-- >= 0)
		format->strlen += write(1, " ", 1);
	format->strlen += len;
	if (nb == 0 && format->precision == 0 && format->dot == '.')
		--format->strlen;
}
