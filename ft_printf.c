/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 18:26:57 by IgnacioHB         #+#    #+#             */
/*   Updated: 2020/08/10 16:58:21 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int ft_printf(const char *s, ...)
{
    printf_s format;

    format.str = (char *)s;
    va_start(format.argptr, s);
    ft_picker(&format);
    va_end(format.argptr);
    return (format.strlen);
}

void ft_picker(printf_s *format)
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
                break;
            
        }
        else
            format->strlen = format->strlen + write(1, format->str, 1);
        ++format->str;
    }
    va_end(format->argptr);
}
void ft_format_read(printf_s *format)
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
    else if(*format->str == 'X')
    {
        format->hexa = 'X';
        ft_display_x(format, va_arg(format->argptr, unsigned int));
    }
    else if(*format->str == 'p')
        ft_display_p(format, va_arg(format->argptr, char *));
    else if (*format->str == 'u')
        ft_display_u(format, va_arg(format->argptr, int));
    else if (*format->str == '%')
        ft_display_pct(format, 37);
    else if (ft_isdigit(*format->str))
            format->width = ft_atoi(format->str);
}

// int main()
// {
//     // printf("%d\n",printf("%u\n", -1));
//     // printf("%d\n",ft_printf("%u\n", -1));
//     // printf("%u\n", 4294967295u);
//     ft_printf("%u\n", -12);
//     // printf("%u\n", -12);
    
//     // printf("Il fait au moins %u\n", -8000);
//     // ft_printf("Il fait au moins %u", -8000);
// }
// int main ()
// {
//     // printf("%d",printf("%u\n",-1));
//     // printf("%d",ft_printf("%u\n",-1));
//     // printf("%u\n", 2147483647);
//     // ft_printf("%u\n", 2147483647);
//     // printf("%5%\n");
//     ft_printf("%2%\n");
//     printf("%2%\n");
    
//     return(0);
// }

// int main ()
// {
//     printf("%.*s", 0, "hello");
//     ft_printf("%.*s", 0, "hello");
//     system("leaks a.out");

//     printf("%03.7d\n", -2375);
//     ft_printf("%03.7d\n", -2375);
//     printf("%.3d\n", 0);
//     ft_printf("%.3d", 0);
//     printf("imprimo un %%d y sigo\n");
//     ft_printf("imprimo un %%d y sigo\n");
//     printf("%x%X%x%X%X%x\n", 1, 12, 123, 1234, 12345, 1237172676);
//     ft_printf("%x%X%x%X%X%x\n", 1, 12, 123, 1234, 12345, 1237172676);
//     ft_printf("%.*d\n", 4, 2342324);
//     printf("%.*d\n", 4, 2342324);
//     printf("%X\n", 123456789);
//     ft_printf("%X\n", 123456789);
//     printf("%u\n", -1233);
//     ft_printf("%u", -1233);
//     system("leaks a.out");
//     return(0);
// }
