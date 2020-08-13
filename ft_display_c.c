/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 20:36:53 by IgnacioHB         #+#    #+#             */
/*   Updated: 2020/08/13 12:54:45 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_display_c(printf_s *format, int nb)
{
	int space;
	int zero;

	zero = 0;
	if (format->zero_space == '0' && format->width > 0)
		zero = format->width - 1;
	if (format->width > 0)
		space = format->width;
	else
		space = 0;
	if (format->width > 0 && format->tab != '-')
		--space;
	while (zero-- > 0 && format->tab != '-')
	{
		format->strlen++;
		ft_putchar_fd('0', 1);
		space = 0;
	}
	while (space-- > 0 && format->tab != '-')
		format->strlen += write(1, " ", 1);
	format->strlen += write(1, &nb, 1);
	while (space-- > 0 && format->tab == '-')
		format->strlen += write(1, " ", 1);
}
