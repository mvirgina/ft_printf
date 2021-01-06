/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvirgina <mvirgina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 19:46:44 by mvirgina          #+#    #+#             */
/*   Updated: 2021/01/06 20:14:05 by mvirgina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int ft_isnumber(const char s)
{
    if (s >= 48 && s <= 57)
        return (1);
    else
        return (0);
}

int ft_putwhile(int qty, const char symb)
{
    int i;
    i = 0;
    while (qty > 0)
    {
        write(1, &symb, 1);
        qty--;
        i++;
    }
    return(i);
}

int ft_isconversion(t_format *format, va_list ap)
{
    int count;
    
    count = 0;
    if (format->conversion == 'd' || format->conversion == 'i')
        count += ft_printf_d_i(format, ap);
    if (format->conversion == 'x' || format->conversion == 'X')
        count += ft_printf_x_X(format, ap);
    if (format->conversion == 'u')
        count += ft_printf_u(format, ap);
    if (format->conversion == 'c')
        count += ft_printf_c(format, ap);
    if (format->conversion == 's')
        count += ft_printf_s(format, ap);
    if (format->conversion == 'p')
        count += ft_printf_p(format, ap);
    if (format->conversion == '%')
        count += ft_printf_pct(format);
    return (count);
}

int ft_printf(const char *s, ...)
{
    t_format format;
    va_list ap;
    int count;
    
    count = 0;
    va_start(ap, s);
    while (*s)
    {
        if (*s == '%')
        {
            init_format(&format);
            s++;
            check_format(s, &format, ap);
            count += ft_isconversion(&format, ap);
            s = s + format.length;
        }
        else
            count += ft_putchar(*s);
        s++;
    }
    va_end(ap);
    return (count);
}
