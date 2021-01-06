/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x_X.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvirgina <mvirgina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 17:58:50 by mvirgina          #+#    #+#             */
/*   Updated: 2021/01/06 20:23:04 by mvirgina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int ft_counter(unsigned long int dec)
{
    int i;
    
    i = 1;
    while (dec >= 16)
    {
        dec /= 16;
        i++;
    }
    return (i);
}

char *ft_hexitoa(unsigned long int dec, char conversion)
{
    char *base;
    char *hex;
    int length;
    
    base = conversion == 'x' ? "0123456789abcdef" : "0123456789ABCDEF";
    length = ft_counter(dec);
    if (!(hex = malloc((length + 1) * sizeof(*hex))))
        return (NULL);
    hex[length] = '\0';
    while (length != 0)
    {
        length--;
        hex[length] = base[dec % 16];
        dec /= 16;
    }
    return (hex);
}

int ft_printf_x_X_a(t_format *format, int length, char *number)
{
    int count;
    
    count = 0;
    if ((format->minus == 0 && format->zero == 0) 
        || (format->minus == 0 && format->point == 1 && format->zero == 1))
        count += ft_putwhile(format->width - length, ' ') + ft_putstr(number);
    else if (format->minus == 0 && format->point == 0 && format->zero == 1)
        count += ft_putwhile(format->width - length, '0') + ft_putstr(number);
    else if (format->minus == 1)
        count += ft_putstr(number) + ft_putwhile(format->width - length, ' ');
    return (count);
}

int ft_printf_x_X_c(t_format *format, int length, char *number)
{
    int count;
    
    count = 0;
    if ((format->minus == 0 && format->zero == 0) 
        || (format->minus == 0 && format->point == 1 && format->zero == 1))
        count += ft_putwhile(format->width - format->precision, ' ');
    count += ft_putwhile(format->precision - length, '0') + ft_putstr(number);
    if (format->minus == 1)
        count += ft_putwhile(format->width - format->precision, ' ');
    return (count);
}

int ft_printf_x_X(t_format *format, va_list ap)
{
    int dec;
    int count;
    int length;
    char *number;
    
    count = 0;
    dec = va_arg(ap, int);
    number = ft_hexitoa((unsigned int)dec, format->conversion);
    length = ft_strlen(number);
    if (format->precision == 0 && format->point == 1 && dec == 0)
        count += ft_putwhile(format->width, ' ');
    else if (length >= format->precision && length >= format->width)
        count += ft_putstr(number);
    else if (length >= format->precision && length < format->width)
        count += ft_printf_x_X_a(format, length, number);
    else if (length <= format->precision && format->precision >= format->width)
        count += ft_putwhile(format->precision - length, '0') + ft_putstr(number);
    else if (length <= format->precision && format->precision < format->width)
        count += ft_printf_x_X_c(format, length, number);
    free(number);
    return (count);
}
