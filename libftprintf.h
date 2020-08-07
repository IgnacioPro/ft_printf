/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 18:22:21 by IgnacioHB         #+#    #+#             */
/*   Updated: 2020/08/07 16:41:17 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
#define LIBFTPRINTF_H

#include "libft/libft.h"
#include <stdarg.h>

typedef struct printf_st
{
	char	*str;
	char	tab;
	char	dot;
	int		width;
	int		precision;
	int		format_len;
	char	zero_space;
	int		strlen;
	char	hexa;
	int		s_pct;
	int		len_pct;

	va_list argptr;
} printf_s;

int		ft_printf(const char *s, ...);
void	ft_picker(printf_s *format);
void	ft_format_read(printf_s *format);
void	ft_dot(printf_s *format);
size_t	ft_intlen(long nb);
void	ft_formatter(printf_s *format);
void	ft_args(printf_s *format);
void	ft_display_c(printf_s *format, int nb);
void	ft_display_s(printf_s *format, char *str);
void	ft_display_d(printf_s *format, int nb);
void	ft_display_x(printf_s *format, unsigned long nb);
void	ft_display_p(printf_s *format, char *str);
size_t	ft_xlen(size_t nb);
void	ft_to_hexa(printf_s *format, unsigned long number);
void	ft_mem(printf_s *format, char *str);
void	ft_display_u(printf_s *format, int nb);
void	ft_putunbr(int n, int fd);
void	ft_print_number(int n, int fd);
void	ft_display_pct(printf_s *format, char c);

#endif
