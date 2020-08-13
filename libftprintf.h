/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 18:22:21 by IgnacioHB         #+#    #+#             */
/*   Updated: 2020/08/13 13:31:04 by ihorcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
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

int				ft_printf(const char *s, ...);
void			ft_picker(t_printf *format);
void			ft_format_read(t_printf *format);
void			ft_dot(t_printf *format);
size_t			ft_intlen(long nb);
void			ft_formatter(t_printf *format);
void			ft_args(t_printf *format);
void			ft_display_c(t_printf *format, int nb);
void			ft_display_s(t_printf *format, char *str);
void			ft_display_d(t_printf *format, int nb);
void			ft_display_x(t_printf *format, unsigned long nb);
void			ft_display_p(t_printf *format, char *str);
size_t			ft_xlen(size_t nb);
void			ft_to_hexa(t_printf *format, unsigned long number);
void			ft_mem(t_printf *format, char *str);
void			ft_display_u(t_printf *format, int nb);
void			ft_putunbr(int n, int fd);
void			ft_print_number(int n, int fd);
void			ft_display_pct(t_printf *format, char c);
void			ft_is_unsigned(unsigned n, int fd);
void			ft_write_unsigned(int n, int fd);
size_t			ft_ulen(long nb);
void			ft_precision_width(t_printf *format, int nb, int zero);
void			ft_space_blank(t_printf *format, int space, int len, int nb);
void			ft_zeros_spaces(t_printf *format, int nb,
					int space, int len, int zero);
void			ft_format_p(t_printf *format, char *str,
					int space, int plus);
void			ft_format_u(t_printf *format, int nb, int len, int space);
void			ft_format_s(t_printf *format, char *str, int space, int len);
void			ft_format_x(t_printf *format, int space,
					int zero, unsigned long nb);

#endif
