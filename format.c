/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosadchu <kosadchu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 16:06:40 by kosadchu          #+#    #+#             */
/*   Updated: 2019/03/13 20:18:39 by kosadchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	free_flags(void)
{
	g_fl.mn = 0;
	g_fl.pl = 0;
	g_fl.oc = 0;
	g_fl.zr = 0;
	g_fl.sp = 0;
	g_lst.type = '0';
}

void	space(int len, char c)
{
	while (len--)
		g_bf.buf[g_bf.i++] = c;
}

void	save_buff(char *s, int len, int minus)
{
	if (minus == 0)
		while (*s && len--)
			g_bf.buf[g_bf.i++] = *s++;
	else if (minus == 1)
	{
		s++;
		while (*s)
			g_bf.buf[g_bf.i++] = *s++;
	}
}

void	print_buf(void)
{
	int		l;

	l = 0;
	while (l < g_bf.i)
	{
		write(1, &g_bf.buf[l], 1);
		l++;
	}
}

void	check_format(const char *f, va_list ap)
{
	g_bf.i = 0;
	g_bf.it = 0;
	int		j;
	j = 0;
	while(f[g_bf.it] != '\0')
	{
		g_lst.width = 0;
		g_lst.prec = 0;
		if (f[g_bf.it] == '%')
		{
			g_bf.it++;
			free_flags();
			check_spec(f, ap);
		}
		if (f[g_bf.it] != '%' && f[g_bf.it] != '\0')
		{
			g_bf.buf[g_bf.i++] = f[g_bf.it];
			g_bf.it++;
		}
	}
	print_buf();
}