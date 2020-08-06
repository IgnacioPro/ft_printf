/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 20:50:41 by IgnacioHB         #+#    #+#             */
/*   Updated: 2020/08/06 14:22:16 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t ft_xlen(size_t nb)
{
    size_t len;

    len = 0;
    if (nb == 0)
    {
        len++;
        return(len);
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
    return(len);
}

void ft_to_hexa(printf_s *format, unsigned long number)
{
    unsigned long n;

    n = number;
    if (n >= 16)
        ft_to_hexa(format, n / 16);
    n = n % 16;
    n = n < 10 ? n + '0' : n + (format->hexa == 'x' ? 87 : 55);
    ft_putchar_fd(n, 1);
}



void ft_print_number(int n, int fd)
{
    long r;

    r = n;
    if (r < 0)
        r *= -1;
    if (r >= 10)
    {
        ft_putnbr_fd(r / 10, fd);
        ft_putnbr_fd(r % 10, fd);
    }
    else
    {
        ft_putchar_fd(r + '0', fd);
    }
    
}