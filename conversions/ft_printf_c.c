/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvirgina <mvirgina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 15:59:01 by mvirgina          #+#    #+#             */
/*   Updated: 2021/01/06 16:14:57 by mvirgina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printf_c(t_format *format, va_list ap)
{
    int count;
    unsigned char c;

    c = va_arg(ap, int);
    count = 0;
    if (format->minus == 1)
        count += ft_putchar(c) + ft_putwhile(format->width - 1, ' ');
    else
        count += ft_putwhile(format->width - 1, ' ') + ft_putchar(c);
    return (count);
}
