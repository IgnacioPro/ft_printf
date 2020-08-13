/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_pct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 16:17:32 by IgnacioHB         #+#    #+#             */
/*   Updated: 2020/08/13 13:25:02 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_display_pct(t_printf *format, char c)
{
	format->s_pct = format->width - 1;
	while (format->s_pct-- > 0 && format->tab != '-')
	{
		if ((format->zero_space != '0') ||
			(format->dot == '.' && format->precision >= 0))
			write(1, " ", 1);
		else
			write(1, "0", 1);
		format->strlen++;
	}
	format->strlen++;
	write(1, &c, 1);
	while (format->s_pct-- >= 0)
	{
		write(1, " ", 1);
		format->strlen++;
	}
}
