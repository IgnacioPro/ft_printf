/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 18:22:21 by IgnacioHB         #+#    #+#             */
/*   Updated: 2020/08/13 13:05:16 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef	struct	s_printf
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
	int		n_d;
	va_list argptr;
}				t_printf;

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
void	ft_is_unsigned(unsigned n, int fd);
void	ft_write_unsigned(int n, int fd);
size_t	ft_ulen(long nb);
void	ft_precision_width(printf_s *format, int nb, int zero);
void	ft_space_blank(printf_s *format, int space, int len, int nb);
void	ft_zeros_spaces(printf_s *format, int nb,
			int space, int len, int zero);
void	ft_format_p(printf_s *format, char *str,
			int space, int plus);
void	ft_format_u(printf_s *format, int nb, int len, int space);
void	ft_format_s(printf_s *format, char *str, int space, int len);
void	ft_format_x(printf_s *format, int space,
		int zero, unsigned long nb);

#endif
