/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvirgina <mvirgina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:20:01 by mvirgina          #+#    #+#             */
/*   Updated: 2021/01/06 20:13:59 by mvirgina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printf_s(t_format *format, va_list ap)
{
    int count;
    char *s;
    int precision;
    int width;

    s = va_arg(ap, char *);
    count = 0;
    if (format->precision == 0 && format->point == 1 && format->width == 0)
        return (0);
    if (s == NULL)
        s = "(null)";
    precision = ((format->point == 0 || ft_strlen(s) < format->precision)
                ? ft_strlen(s) : format->precision);
    width = format->width - precision;
    if (format->minus == 0)
        count += ft_putwhile(width, ' ');
    while (*s && precision-- > 0)
    {
        count += ft_putchar(*s);
        s++;
    }
    if (format->minus == 1)
        count += ft_putwhile(width, ' ');
    return (count);
}
