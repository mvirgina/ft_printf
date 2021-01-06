/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvirgina <mvirgina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 19:52:20 by mvirgina          #+#    #+#             */
/*   Updated: 2021/01/06 20:14:04 by mvirgina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct	s_format
{
	int		minus;
	int		zero;
	int		width;
	int		point;
	int		precision;
	char	conversion;
	int		length;
}				t_format;

int ft_printf(const char *s, ...);
int ft_putchar(const char s);
int ft_putnbr(int number);
int ft_putstr(char *number);
int ft_numlen(int number);
int ft_strlen(char *s);
void init_format(t_format *format);
void check_format(const char *s, t_format *format, va_list ap);
void check_star(t_format *format, va_list ap);
int ft_isnumber(const char s);
int ft_putwhile(int qty, const char symb);
int ft_isconversion(t_format *format, va_list ap);
int	ft_printf_c(t_format *format, va_list ap);
int ft_printf_d_i_a(t_format *format, int length, int number);
int ft_printf_d_i_b(t_format *format, int length, int number);
int ft_printf_d_i_c(t_format *format, int length, int number);
int ft_printf_d_i(t_format *format, va_list ap);
int ft_printf_p(t_format *format, va_list ap);
int	ft_printf_pd(t_format *format, int len, char *end_hex);
int	ft_printf_pc(t_format *format, int len, char *end_hex);
int	ft_printf_pb(t_format *format, int len, char *end_hex);
int	ft_printf_pa(t_format *format);
int	ft_printf_pct(t_format *format);
int	ft_printf_s(t_format *format, va_list ap);
int ft_numlen_u(unsigned int number);
int ft_putnbr_u(unsigned int number);
int ft_printf_u_a(t_format *format, int length, unsigned int number);
int ft_printf_u_c(t_format *format, int length, unsigned int number);
int ft_printf_u(t_format *format, va_list ap);
int ft_counter(unsigned long int dec);
char *ft_hexitoa(unsigned long int dec, char conversion);
int ft_printf_x_X_a(t_format *format, int length, char *number);
int ft_printf_x_X_c(t_format *format, int length, char *number);
int ft_printf_x_X(t_format *format, va_list ap);

#endif
