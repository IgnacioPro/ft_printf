/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ints.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 20:50:41 by IgnacioHB         #+#    #+#             */
/*   Updated: 2020/08/13 13:25:35 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_xlen(size_t nb)
{
	size_t len;

	len = 0;
	if (nb == 0)
	{
		len++;
		return (len);
	}
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb > 0)
	{
		nb /= 16;
		len++;
	}
	return (len);
}

void	ft_to_hexa(t_printf *format, unsigned long number)
{
	unsigned long n;

	n = number;
	if (n >= 16)
		ft_to_hexa(format, n / 16);
	n = n % 16;
	if (n < 10)
		n = n + '0';
	else
	{
		if (format->hexa == 'x')
			n = n + 87;
		if (format->hexa == 'X')
			n = n + 55;
	}
	ft_putchar_fd(n, 1);
}

void	ft_print_number(int n, int fd)
{
	long x;

	x = n;
	if (x < 0)
		x *= -1;
	if (x > 9)
	{
		ft_print_number(x / 10, fd);
		ft_print_number(x % 10, fd);
	}
	else
	{
		ft_putchar_fd(x + '0', fd);
	}
}

void	ft_write_unsigned(int n, int fd)
{
	unsigned x;

	x = n;
	if (x > 9)
	{
		ft_write_unsigned(x / 10, fd);
		ft_write_unsigned(x % 10, fd);
	}
	else
		ft_putchar_fd(x + '0', fd);
}
