/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 21:05:57 by IgnacioHB         #+#    #+#             */
/*   Updated: 2020/08/12 13:08:40 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void ft_display_p(printf_s *format, char *str)
{
    unsigned long nb;
    int space;
    int len;
    int plus;
    
    len = ft_xlen((unsigned long)str) + 2;
	nb = len;
	format->strlen += nb;
	if (format->precision <= len)
		space = format->width - len;
	if(format->precision > len)
		space = format->width - format->precision;
	if (format->dot == '.' && nb == 0 && format->precision == 0)
		++space;
	if (str == NULL && format->dot == '.')
		++space;
	plus = format->precision - len + 2;
	ft_format_p(format, str, space, len, plus);
}

void ft_format_p(printf_s *format, char *str, int space, int len, int plus)
{
	while (space-- > 0 && format->tab != '-')
	{
		if (format->zero_space != '0' ||
			(format->dot == '.' && format->precision >= 0))
			{
				write(1, " ", 1);
				++format->strlen;
			}
			else
			{
				write(1, "0", 1);
				++format->strlen;
			}
	}
	ft_putstr_fd("0x", 1);
	while (plus-- > 0)
		format->strlen += write(1, "0", 1);
	if(!(format->dot == '.' && str == NULL && format->precision == 0))
		ft_mem(format,str);
	while (space-- >= 0)
		format->strlen += write(1, " ", 1);
	if (format->dot == '.' && str == NULL && format->precision == 0 )
		format->strlen -= 1;
}

void ft_mem(printf_s *format, char *str)
{
    size_t *x;

    x = (size_t *)&str;
	format->hexa = 'x';
    ft_to_hexa(format, *x);
}
