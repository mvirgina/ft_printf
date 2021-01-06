/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvirgina <mvirgina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 18:49:26 by mvirgina          #+#    #+#             */
/*   Updated: 2021/01/06 18:08:17 by mvirgina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int ft_numlen_u(unsigned int number)
{
    int i;
    
    i = 1;
    while (number >= 10)
    {
        number /= 10;
        i++;
    }
    return (i);
}

int ft_putnbr_u(unsigned int number)
{
    int count;
    
    count = 1;
    if (number >= 10)
		count += ft_putnbr_u(number / 10);
    ft_putchar(number % 10 + 48);
    return (count);
}

int ft_printf_u_a(t_format *format, int length, unsigned int number)
{
    int count;
    
    count = 0;
    if ((format->minus == 0 && format->zero == 0) 
        || (format->minus == 0 && format->point == 1 && format->zero == 1))
        count += ft_putwhile(format->width - length, ' ') + ft_putnbr_u(number);
    else if (format->minus == 0 && format->point == 0 && format->zero == 1)
        count += ft_putwhile(format->width - length, '0') + ft_putnbr_u(number);
    else if (format->minus == 1)
        count += ft_putnbr_u(number) + ft_putwhile(format->width - length, ' ');
    return (count);
}

int ft_printf_u_c(t_format *format, int length, unsigned int number)
{
    int count;
    
    count = 0;
    if ((format->minus == 0 && format->zero == 0) 
        || (format->minus == 0 && format->point == 1 && format->zero == 1))
        count += ft_putwhile(format->width - format->precision, ' ');
    count += ft_putwhile(format->precision - length, '0') + ft_putnbr_u(number);
    if (format->minus == 1)
        count += ft_putwhile(format->width - format->precision, ' ');
    return (count);
}

int ft_printf_u(t_format *format, va_list ap)
{
    unsigned int number;
    int count;
    int length;

    count = 0;
    number = va_arg(ap, unsigned int);
    length = ft_numlen_u(number);
    if (format->precision == 0 && format->point == 1 && number == 0)
        count += ft_putwhile(format->width, ' ');
    else if (length >= format->precision && length >= format->width)
        count += ft_putnbr_u(number);
    else if (length >= format->precision && length < format->width)
        count += ft_printf_u_a(format, length, number);
    else if (length <= format->precision && format->precision >= format->width)
        count += ft_putwhile(format->precision - length, '0') + ft_putnbr_u(number);
    else if (length <= format->precision && format->precision < format->width)
        count += ft_printf_u_c(format, length, number);
    return (count);
}