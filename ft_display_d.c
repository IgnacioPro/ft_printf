/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 20:44:28 by IgnacioHB         #+#    #+#             */
/*   Updated: 2020/08/06 19:24:25 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void ft_display_d(printf_s *format, int nb)
{
    int len;
    int space;
    int zero;
    int flag;
    char *numero;
    
    numero = ft_itoa(nb);

    len = ft_strlen(numero);
    format->strlen = format->strlen + len;
    space = format->width - ((format->precision < len) ?
        len : format->precision);
    space -= (nb < 0 && format->precision >= len) ? 1 : 0;
    space += (format->dot == '.' && nb == 0 && format->precision == 0) ? 1 : 0;
    zero = (nb > 0) ? (format->precision - len) + 1 : (format->precision - len);
    flag = (nb < 0 && (space > format->precision && format->zero_space == '0'))
		? write(1, "-", 1) : 0;
	while (space > 0 && format->tab != '-')
	{
		format->strlen += write(1, (format->zero_space != '0' ||
			(format->dot == '.' && format->precision >= 0)) ? " " : "0", 1);
        space --;
	}
	while (--zero > 0)
		format->strlen += write(1, "0", 1);
	if(!(format->dot == '.' && nb == 0 && format->precision == 0))
        ft_putnbr_fd(nb, 1);
	while (space-- > 0)
		format->strlen += write(1, " ", 1);
    if (format->dot == '.' && nb == 0 && format->precision == 0)
        format->strlen -= 1;
    free(numero);
}

