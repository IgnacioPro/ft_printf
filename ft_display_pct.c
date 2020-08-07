/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_pct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 16:17:32 by IgnacioHB         #+#    #+#             */
/*   Updated: 2020/08/07 16:47:01 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void ft_display_pct(printf_s *format, char c)
{
    format->s_pct = format->width - 1;
    while (format->s_pct-- > 0 && format->tab != '-')
        format->strlen += write(1, (format->zero_space != '0' ||
            (format->dot == '.' && format->precision >= 0)) ? " " : "0", 1);
    format->strlen += write(1, &c, 1);
    while (format->s_pct-- >= 0)
        format->strlen += write(1, " ", 1);
}