/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 12:51:01 by IgnacioHB         #+#    #+#             */
/*   Updated: 2020/08/12 14:33:03 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void ft_display_s(printf_s *format, char *str)
{
	int space;
	int len;

	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);

	if (format->precision > 0 && format->precision < len)
		len -= len - format->precision;
	if (format->precision == 0 && format->width > 0 &&
		format->zero_space == ' ' && format->dot == '.')
			len -= len;
	if (format->dot == '.' && format->width == 0 && format->precision == 0)
		len -= len;
	if (format->width > 0)
		space = (format->width - len);
	if (format->width <= 0)
		space = 0;
	if (format->tab == '-')
		++space;
	ft_format_s(format, str, space, len);
}

void ft_format_s(printf_s *format, char *str, int space, int len)
{
	while (space-- > 0 && format->tab != '-')
		format->strlen += write(1, &format->zero_space, 1);
	if (!(format->dot == '.' && format->precision == -1))
		format->strlen += write(1, str, len);
	while (space-- > 0 && format->tab == '-')
		format->strlen += write(1, &format->zero_space, 1);
}
