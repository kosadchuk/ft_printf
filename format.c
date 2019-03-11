/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosadchu <kosadchu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 16:06:40 by kosadchu          #+#    #+#             */
/*   Updated: 2019/03/11 15:13:36 by kosadchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	save_buff(char c)
{
	g_bf.buf[g_bf.i] = c;
	g_bf.i++;
}

void	free_flags(void)
{
	g_fl.mn = 0;
	g_fl.pl = 0;
	g_fl.oc = 0;
	g_fl.zr = 0;
	g_fl.sp = 0;
	g_lst.type = '0';
}

void	print_space(char *s, int len)
{
	if (g_fl.mn == 1)
	{
		while (*s && len--)
			g_bf.buf[g_bf.i++] = *s++;
		while (g_lst.width--)
			g_bf.buf[g_bf.i++] = ' ';
	}
	else if (g_fl.mn != 1)
	{
		while (g_lst.width--)
			g_bf.buf[g_bf.i++] = ' ';
		while (*s && len--)
			g_bf.buf[g_bf.i++] = *s++;
	}
}

void	check_format(const char *f, va_list ap)
{
	g_bf.i = 0;
	g_bf.it = 0;
	while(f[g_bf.it])
	{
		g_lst.width = 0;
		g_lst.prec = 0;
		if (f[g_bf.it] == '%')
		{
			g_bf.it++;
			free_flags();
			check_spec(f, ap);
		}
		if (f[g_bf.it] != '%')
		{
			save_buff(f[g_bf.it]);
			g_bf.it++;
		}
	}
	ft_putstr(g_bf.buf);
}