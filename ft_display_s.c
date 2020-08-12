/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 12:51:01 by IgnacioHB         #+#    #+#             */
/*   Updated: 2020/08/11 18:25:23 by IgnacioHB        ###   ########.fr       */
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
    len -= (format->precision > 0 &&
        format->precision < len ) ? (len - format->precision) : 0;
    len -= (format->dot == '.' && format->tab == '-' &&
        format->precision == 0 && format->width == 0)? len : 0;
    len -= (format->dot == '.' && format->tab != '-' &&
        format->precision == 0 && format->width == 0) ? len : 0;
    len -= (format->precision == 0 && format->width > 0 &&
        format->zero_space == ' ' && format->dot == '.') ? len : 0;
    space = (format->width > 0) ? (format->width - len) : 0;
    space += (format->tab == '-') ? 1 : 0;

    if (format->tab == '-' && format->zero_space == '0')
        format->zero_space = ' ';
    while (space-- > 0 && format->tab != '-')
        format->strlen += write(1, &format->zero_space, 1);
    if (!(format->dot == '.' && format->precision == -1))
        format->strlen += write(1, str, len);
    while (space-- > 0 && format->tab == '-')
        format->strlen += write(1, &format->zero_space, 1);
}
