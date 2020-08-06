/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 12:52:52 by IgnacioHB         #+#    #+#             */
/*   Updated: 2020/08/06 14:14:40 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void    ft_display_u(printf_s *format, int nb)
{
    
	int			len;
	int			space;
	int			zero;
	unsigned	r;

	r = nb;
	nb = r;
	len = ft_strlen(ft_itoa(r));
	space = format->width - ((format->precision <= len) ? len : format->precision);
	zero = format->precision - len;
	space += (nb == 0 && format->precision == 0 &&
		format->dot == '.' && format->width > 0) ? 1 : 0;
	while (space-- > 0 && format->tab != '-')
		format->strlen += write(1, (format->zero_space != '0' ||
			(format->dot == '.' && format->precision >= 0)) ? " " : "0", 1);
	while (--zero >= 0)
		format->strlen += write(1, "0", 1);
	(nb == 0 && format->precision == 0 && format->dot == '.') ? 0 : ft_print_number(nb, 1);
	while (space-- >= 0)
		format->strlen += write(1, " ", 1);
	format->strlen += len;
	if (nb == 0 && format->precision == 0 && format->dot == '.' && format->width >= 0)
		--format->strlen;
}
