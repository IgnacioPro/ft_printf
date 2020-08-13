/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 18:26:57 by IgnacioHB         #+#    #+#             */
/*   Updated: 2020/08/13 12:55:26 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int		ft_printf(const char *s, ...)
{
	printf_s format;

	format.str = (char *)s;
	va_start(format.argptr, s);
	ft_picker(&format);
	va_end(format.argptr);
	return (format.strlen);
}

void	ft_picker(printf_s *format)
{
	format->strlen = 0;
	while (*format->str)
	{
		if (*format->str == '%')
		{
			ft_formatter(format);
			ft_format_read(format);
			if (*format->str != 'd' && *format->str != 'i' &&
				*format->str != 'c' && *format->str != 's' &&
				*format->str != 'u' && *format->str != 'x' &&
				*format->str != 'X' && *format->str != 'p' &&
				*format->str != '%')
				break ;
		}
		else
			format->strlen = format->strlen + write(1, format->str, 1);
		++format->str;
	}
	va_end(format->argptr);
}

void	ft_format_read(printf_s *format)
{
	if (*format->str == 'i' || *format->str == 'd')
		ft_display_d(format, va_arg(format->argptr, int));
	else if (*format->str == 'c')
		ft_display_c(format, va_arg(format->argptr, int));
	else if (*format->str == 's')
		ft_display_s(format, va_arg(format->argptr, char *));
	else if (*format->str == 'x')
	{
		format->hexa = 'x';
		ft_display_x(format, va_arg(format->argptr, unsigned int));
	}
	else if (*format->str == 'X')
	{
		format->hexa = 'X';
		ft_display_x(format, va_arg(format->argptr, unsigned int));
	}
	else if (*format->str == 'p')
		ft_display_p(format, va_arg(format->argptr, char *));
	else if (*format->str == 'u')
		ft_display_u(format, va_arg(format->argptr, int));
	else if (*format->str == '%')
		ft_display_pct(format, 37);
	else if (ft_isdigit(*format->str))
		format->width = ft_atoi(format->str);
}
