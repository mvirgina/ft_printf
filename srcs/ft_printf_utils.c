/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvirgina <mvirgina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 16:03:08 by mvirgina          #+#    #+#             */
/*   Updated: 2021/01/06 18:06:03 by mvirgina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int ft_putchar(const char s)
{
    write(1, &s, 1);
    return(1);
}

int ft_putnbr(int number)
{
    int i;
    int count;
    
    count = 1;
    if (number < 0)
    {
        ft_putchar('-');
        i = number * -1;
        count++;
    }
    else 
        i = number;
    if (i >= 10)
		count += ft_putnbr(i / 10);
    ft_putchar(i % 10 + 48);
    return (count);
}

int ft_putstr(char *number)
{
    int count;
    
    count = 1;
    while (*number)
    {
        ft_putchar(*number);
        number++;
        count++;
    }
    return (count);
}

int ft_numlen(int number)
{
    int i;
    
    i = 1;
    if (number < 0)
    {
        number *= -1;
        i++;
    }
    while (number >= 10)
    {
        number /= 10;
        i++;
    }
    return (i);
}

int ft_strlen(char *s)
{
    int i;
    
    i = 0;
    while (s[i])
        i++;
    return (i);
}
