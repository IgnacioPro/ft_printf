/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 12:52:52 by IgnacioHB         #+#    #+#             */
/*   Updated: 2020/08/11 10:51:16 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void    ft_display_u(printf_s *format, int nb)
{
    
	int			len;
	int			space;
	int			zero;
	unsigned 	unsigned_nb;

	unsigned_nb = nb;
	len = ft_ulen(unsigned_nb);
	space = format->width - ((format->precision <= len) ? len : format->precision);
	zero = format->precision - len;
	space += (nb == 0 && format->precision == 0 &&
		format->dot == '.' && format->width > 0) ? 1 : 0;
	while (space-- > 0 && format->tab == ' ')
		format->strlen += write(1, (format->zero_space != '0' ||
			(format->dot == '.' && format->precision >= 0)) ? " " : "0", 1);
	while (--zero >= 0)
		format->strlen += write(1, "0", 1);
	if (!(nb == 0 && format->precision == 0 && format->dot == '.'))
		ft_write_unsigned(nb, 1);
	while (space-- >= 0)
		format->strlen += write(1, " ", 1);
	if (nb == 0 && format->precision == 0 && format->dot == '.')
		format->strlen--;
	format->strlen += len;
}

size_t ft_ulen(long nb)
{
	size_t len;

	len = 0;
	if (nb == 0)
	{
		len++;
		return(len);
	}
	if(nb < 0)
	{
		nb *= -1;
		len++;
	}
	while(nb > 0)
	{
		nb /= 10; 
		len++;
	}
	return(len);
}