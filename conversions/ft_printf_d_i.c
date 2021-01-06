/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d_i.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvirgina <mvirgina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 17:58:12 by mvirgina          #+#    #+#             */
/*   Updated: 2021/01/06 20:47:31 by mvirgina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int ft_printf_d_i_a(t_format *format, int length, int number)
{
    int count;
    
    count = 0;
    if ((format->minus == 0 && format->zero == 0) 
        || (format->minus == 0 && format->point == 1 && format->zero == 1))
        count += ft_putwhile(format->width - length, ' ') + ft_putnbr(number);
    else if (format->minus == 0 && format->point == 0 && format->zero == 1)
    {
        if (number < 0)
        {
            count += ft_putchar('-');
            number *= -1;
            format->precision += 1;
        }
        count += ft_putwhile(format->width - length, '0') + ft_putnbr(number);
    }
    else if (format->minus == 1)
        count += ft_putnbr(number) + ft_putwhile(format->width - length, ' ');
    return (count);
}

int ft_printf_d_i_b(t_format *format, int length, int number)
{
    int count;
    
    count = 0;
    if (number < 0)
    {
        count += ft_putchar('-');
        number *= -1;
        format->precision += 1;
    }
    count += ft_putwhile(format->precision - length, '0') + ft_putnbr(number);
    return (count);
}

int ft_printf_d_i_c(t_format *format, int length, int number)
{
    int count;
    
    count = 0;
    if (number < 0)
		format->precision += 1;
    if ((format->minus == 0 && format->zero == 0) 
        || (format->minus == 0 && format->point == 1 && format->zero == 1))
        count += ft_putwhile(format->width - format->precision, ' ');
    if (number < 0)
        {
            count += ft_putchar('-');
            number *= -1;
        }
    count += ft_putwhile(format->precision - length, '0') + ft_putnbr(number);
    if (format->minus == 1)
        count += ft_putwhile(format->width - format->precision, ' ');
    return (count);
}

int ft_printf_d_i(t_format *format, va_list ap)
{
    int number;
    int count;
    int length;

    count = 0;
    number = va_arg(ap, int);
    length = ft_numlen(number);
    if (format->precision == 0 && format->point == 1 && number == 0)
        count += ft_putwhile(format->width, ' ');
    else if (length >= format->precision && length >= format->width)
        count += ft_putnbr(number);
    else if (length >= format->precision && length < format->width)
        count += ft_printf_d_i_a(format, length, number);
    else if (length <= format->precision && format->precision >= format->width)
        count += ft_printf_d_i_b(format, length, number);
    else if (length <= format->precision && format->precision < format->width)
        count += ft_printf_d_i_c(format, length, number);
    return (count);
}
