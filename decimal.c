/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosadchu <kosadchu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 14:47:51 by kosadchu          #+#    #+#             */
/*   Updated: 2019/03/13 18:28:53 by kosadchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	cast_dec(va_list ap)
{
	if (g_lst.sz[0] == 'l' && g_lst.sz[1] != 'l')
		return (va_arg(ap, long int));
	else if (g_lst.sz[0] == 'l' && g_lst.sz[1] == 'l')
		return (va_arg(ap, long long int));
	else if (g_lst.sz[0] == 'h' && g_lst.sz[1] != 'h')
		return ((short int)va_arg(ap, int));
	else if (g_lst.sz[0] == 'h' && g_lst.sz[1] == 'h')
		return ((signed char)va_arg(ap, int));
	else
		return (va_arg(ap, int));
}

void	print_space_dec(char *str, int len)
{
	if (g_fl.mn == 1)
	{
		(g_fl.pl == 1 && str[0] != '-') ? g_bf.buf[g_bf.i++] = '+' : 0;
		if (g_fl.sp == 1 && str[0] != '-' && g_fl.pl == 0)
			g_bf.buf[g_bf.i++] = ' ';
		(g_fl.pl == 1 && str[0] != '-') ? g_lst.width-- : 0;
		(str[0] == '-' && g_lst.prec > 0) ? g_bf.buf[g_bf.i++] = '-' : 0;
		if (g_lst.prec > 0)
		{
			while (g_lst.prec--)
				g_bf.buf[g_bf.i++] = '0';
			if (str[0] == '-')
			{
				str++;
				while (*str)
					g_bf.buf[g_bf.i++] = *str++;
			}
			else
				while (*str)
					g_bf.buf[g_bf.i++] = *str++;
		}
		else
			while (*str)
				g_bf.buf[g_bf.i++] = *str++;
		if (g_lst.width > 0)
			while (g_lst.width--)
				g_bf.buf[g_bf.i++] = ' ';
	}
	else if (g_fl.mn == 0)
	{
		if (g_fl.pl == 1 && str[0] != '-' && g_lst.width < len)
			g_bf.buf[g_bf.i++] = '+';
		if (g_fl.sp == 1 && str[0] != '-' && g_fl.pl == 0 && g_lst.prec < 1)
			g_bf.buf[g_bf.i++] = ' ';
		(g_fl.pl == 1 || (g_fl.pl == 1 && g_fl.zr == 1)) ? g_lst.width-- : 0;
		(str[0] == '-' && g_fl.zr == 1 && g_fl.pl == 0) ? g_lst.width-- : 0;
		(str[0] == '-' && g_fl.zr == 0 && g_fl.pl == 0) ? g_lst.width-- : 0;
		if (g_lst.width > 0 && g_fl.zr == 0)
			while (g_lst.width--)
				g_bf.buf[g_bf.i++] = ' ';
		if (g_fl.pl == 1 && str[0] != '-' && g_bf.buf[g_bf.i - 1] != '+')
			g_bf.buf[g_bf.i++] = '+';
		if (g_lst.width > 0 && g_fl.zr == 1)
		{
			if (str[0] == '-')
			{
				str++;
				g_bf.buf[g_bf.i++] = '-';
			}
			if (g_lst.prec > 0)
				while (g_lst.width--)
					g_bf.buf[g_bf.i++] = ' ';
			else
				while (g_lst.width--)
					g_bf.buf[g_bf.i++] = '0';
		}
		if (g_lst.prec > 0)
		{
			(str[0] == '-') ? g_bf.buf[g_bf.i++] = '-' : 0;
			while (g_lst.prec--)
				g_bf.buf[g_bf.i++] = '0';
			if (str[0] == '-')
			{
				str++;
				while (*str)
					g_bf.buf[g_bf.i++] = *str++;
			}
			else
				while (*str)
					g_bf.buf[g_bf.i++] = *str++;
		}
		else
			while (*str)
				g_bf.buf[g_bf.i++] = *str++;
	}
}

void	decimal(va_list ap)
{
	intmax_t	d;
	char		*s;
	int			len;

	g_lst.type = 'd';
	d = cast_dec(ap);
	s = ft_itoa_bs_pf(d, 0, 10);
	len = ft_strlen(s);
	(d < 0) ? len -= 1 : 0;
	(d < 0  && g_fl.mn == 1) ? g_lst.width -= 1 : 0;
	(g_lst.prec < len) ? g_lst.prec = 0 : 0;
	(g_lst.width < len) ? g_lst.width = 0 : 0;
	if (g_lst.width > len || g_lst.prec > len)
	{
		(g_lst.prec > len) ? g_lst.prec -= len : 0;
		(g_lst.width > len) ? g_lst.width -= len : 0;
		if (g_lst.prec > g_lst.width)
			g_lst.width = 0;
		if (g_lst.width > g_lst.prec)
			g_lst.width -= g_lst.prec;
	}
	print_space_dec(s, len);
}

void	numbers(const char *f, va_list ap)
{
	if (f[g_bf.it] == 'd')
		decimal(ap);
}