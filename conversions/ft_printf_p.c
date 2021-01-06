/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvirgina <mvirgina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 19:59:37 by mvirgina          #+#    #+#             */
/*   Updated: 2021/01/06 21:00:27 by mvirgina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int ft_printf_p(t_format *format, va_list ap)
{
    unsigned long int dec;
    int count;
    int length;
    char *number;

    count = 0;
    dec = va_arg(ap, unsigned long int);
    number = ft_hexitoa(dec, 'x');
    length = ft_strlen(number);
    //if (format->precision == 0 && format->point == 1 && number == 0);
    //    count += ft_putwhile(format->width - 2, ' ') + ft_putstr("0x");
    if (length + 2 >= format->width)
        count += ft_putstr("0x") + ft_putstr(number);
    else if (length + 2 < format->width)
    {   
        if (format->minus == 0)
            count += ft_putwhile(format->width - 2 - length, ' ');
        count += ft_putstr("0x") + ft_putstr(number);
        if (format->minus == 1)
            count += ft_putwhile(format->width - 2 - length, ' ');
    }
    free(number);
    return(count);
}