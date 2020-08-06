/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 19:59:04 by IgnacioHB         #+#    #+#             */
/*   Updated: 2020/08/06 19:12:49 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "libftprintf.h"

void ft_formatter(printf_s *format)
{
    format->width = 0;
    format->precision = 0;
    format->tab = ' ';
    format->dot = ' ';
    format->zero_space = ' ';
    format->hexa = ' ';
    while (!ft_isalpha(*format->str))
    {  
        ++format->str;   
        if (*format->str == '.')
            ft_dot(format);
        if (*format->str == '-')
            format->tab = '-';
        if (*format->str == '0' && format->width == 0 && format->tab == ' ')
            format->zero_space = '0';
        if (*format->str == '*')
            ft_args(format);
        if(ft_isdigit(*format->str) && *format->str != '0' && 
            format->width == 0 && format->dot != '.')
                format->width = ft_atoi(format->str);
        if(*format->str == '%')
            break;
    }
}

void ft_dot(printf_s *format)
{
    format->dot = '.';  
    format->str++;
    if (*format->str == '*')
    {
        format->precision = va_arg(format->argptr, int);
        format->str++;
    }
    if (ft_isdigit(*format->str))
        format->precision = ft_atoi(format->str);
}

void ft_args(printf_s *format)
{
    int x;
    x = va_arg(format->argptr, int);
    if (x < 0)
    {
        format->width = (x * -1);
        format->tab = '-';
    }
    else
        format->width = x;
}