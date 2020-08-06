/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 19:50:55 by IgnacioHB         #+#    #+#             */
/*   Updated: 2020/08/04 20:04:54 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void ft_display_x(printf_s *format, unsigned long nb)
{
    int len;
    int space;
    int zero;

    len = ft_xlen(nb);
    format->strlen = format->strlen + len;
    if (format->precision < len)
        space = format->width - len;
    else
        space = format->width - format->precision;
    if (format->dot == '.' && nb == 0 && format->precision == 0)
        space += 1;
    zero = format->precision - len;
    while (space-- > 0 && format->tab != '-')
    {
        format->strlen += write(1, (format->zero_space != '0' || (format->dot == '.' && format->precision >= 0)) ? " " : "0", 1);
    }
    while (zero-- > 0)
        format->strlen = format->strlen + write(1, "0", 1);
    if (!(format->dot == '.' && nb == 0 && format->precision == 0))
        ft_to_hexa(format,nb);
    while (space-- >= 0)
        format->strlen += write(1, " ", 1);
    if (format->dot == '.' && nb == 0 && format->precision == 0)
        format->strlen = format->strlen - 1;
}
