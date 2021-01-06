/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvirgina <mvirgina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 21:08:28 by mvirgina          #+#    #+#             */
/*   Updated: 2021/01/06 16:27:28 by mvirgina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printf_pct(t_format *format)
{
	int		count;

	count = 0;
	if (format->minus == 1)
		count += ft_putchar('%');
	count += ft_putwhile(format->width - 1, (format->zero == 1) ? '0' : ' ');
	if (format->minus == 0)
		count += ft_putchar('%');
	return (count);
}
