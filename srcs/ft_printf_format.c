/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvirgina <mvirgina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 16:05:28 by mvirgina          #+#    #+#             */
/*   Updated: 2021/01/06 20:14:08 by mvirgina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void init_format(t_format *format)
{
    format->minus = 0;
    format->zero = 0;
    format->width = 0;
    format->point = 0;
    format->precision = 0;
    format->conversion = '\0';
    format->length = 0;
}

void check_format(const char *s, t_format *format, va_list ap)
{
    int i;
    
    i = 0;
    while (s[i] == '-' || s[i] == '.' || s[i] == '*' || ft_isnumber(s[i]))
        {
            if (s[i] == '-')
                format->minus = 1;
            if (s[i] == '*')
                check_star(format, ap);
            if (s[i] == '.')
                format->point = 1;
            if (ft_isnumber(s[i]))
            {
                if (s[i] == '0' && format->width == 0 && format->precision == 0 && format->minus == 0)
                    format->zero = 1;
                if (format->point == 0)
                    format->width = format->width * 10 + (s[i] - 48);
                if (format->point == 1)
                    format->precision = format->precision * 10 + (s[i] - 48);
            }
            i++;
        }
    format->conversion = s[i];
    format->length = i;
}

void check_star(t_format *format, va_list ap)
{
    if (format->point == 0)
    {
        format->width = va_arg(ap, int);
        if (format->width < 0)
        {
            format->minus = 1;
            format->zero = 0;
            format->width *= -1;
        }
    }
    if (format->point == 1)
    {
        format->precision = va_arg(ap, int);
        if (format->precision < 0)
        {
            format->point = 0;
            format->precision = 0;
        }
    }
}
