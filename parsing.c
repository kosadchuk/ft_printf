/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosadchu <kosadchu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 20:20:10 by kosadchu          #+#    #+#             */
/*   Updated: 2019/03/14 18:34:37 by kosadchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	if_oct(char *s, int l)
{
	if ((g_lst.type == 'x' && g_fl.oc == 1 && !(s[0] == '0' && l == 1))
		|| g_lst.type == 'p')
	{
		g_bf.buf[g_bf.i++] = '0';
		g_bf.buf[g_bf.i++] = 'x';
	}
	else if (g_lst.type == 'X' && g_fl.oc == 1 && !(s[0] == '0' && l == 1))
	{
		g_bf.buf[g_bf.i++] = '0';
		g_bf.buf[g_bf.i++] = 'X';
	}
	else if (g_lst.type == 'o' && g_fl.oc == 1)
		g_bf.buf[g_bf.i++] = '0';
}

void	make_prec_width(int len)
{
	if (g_lst.width > len || g_lst.prec > len)
	{
		(g_lst.prec > len) ? g_lst.prec -= len : 0;
		(g_lst.width > len) ? g_lst.width -= len : 0;
		if (g_lst.prec > g_lst.width)
			g_lst.width = 0;
		if (g_lst.width > g_lst.prec)
			g_lst.width -= g_lst.prec;
	}
}

void	pars_wm(char *str, int len)
{
	if (g_fl.pl == 1 && str[0] != '-' && g_lst.width < len
		&& g_lst.type != 'u')
			g_bf.buf[g_bf.i++] = '+';
	if (g_fl.sp == 1 && str[0] != '-' && g_fl.pl == 0 && g_lst.prec < 1
		&& g_lst.type != 'u')
			g_bf.buf[g_bf.i++] = ' ';
	(g_fl.pl == 1 || (g_fl.pl == 1 && g_fl.zr == 1)) ? g_lst.width-- : 0;
	(str[0] == '-' && g_fl.zr == 1 && g_fl.pl == 0) ? g_lst.width-- : 0;
	(str[0] == '-' && g_fl.zr == 0 && g_fl.pl == 0) ? g_lst.width-- : 0;
	(g_lst.type == 'o' && g_fl.oc == 1) ? g_lst.width-- : 0;
	if ((g_lst.type == 'x' || g_lst.type == 'X' || g_lst.type == 'p')
		&& g_fl.oc == 1)
			g_lst.width -= 2;
}

void	without_minus(char *str, int len)
{
	pars_wm(str, len);
	(g_lst.width > 0 && g_fl.zr == 0) ? space(g_lst.width, ' ') : 0;
	if_oct(str, len);
	if (g_fl.pl == 1 && str[0] != '-' && g_bf.buf[g_bf.i - 1] != '+'
		&& g_lst.type != 'u')
		g_bf.buf[g_bf.i++] = '+';
	if (g_lst.width > 0 && g_fl.zr == 1)
	{
		if (str[0] == '-')
		{
			str++;
			g_bf.buf[g_bf.i++] = '-';
		}
		(g_lst.prec > 0) ? space(g_lst.width, ' ') : 0;
		(g_lst.prec < 1) ? space(g_lst.width, '0') : 0;
	}
	if (g_lst.prec > 0)
	{
		(str[0] == '-') ? g_bf.buf[g_bf.i++] = '-' : 0;
		space(g_lst.prec, '0');
		(str[0] == '-') ? save_buff(str, len, 1) : 0;
		(str[0] != '-') ? save_buff(str, len, 0) : 0;
	}
	else
		save_buff(str, len, 0);
}

void	if_minus(char *str, int len)
{
	(g_fl.pl == 1 && str[0] != '-') ? g_bf.buf[g_bf.i++] = '+' : 0;
	if (g_fl.sp == 1 && str[0] != '-' && g_fl.pl == 0)
		g_bf.buf[g_bf.i++] = ' ';
	(g_fl.pl == 1 && str[0] != '-') ? g_lst.width-- : 0;
	(str[0] == '-' && g_lst.prec > 0) ? g_bf.buf[g_bf.i++] = '-' : 0;
	if (g_lst.prec > 0)
	{
		if_oct(str, len);
		space(g_lst.prec, '0');
		if (str[0] == '-')
			save_buff(str, len, 1);
		else
			save_buff(str, len, 0);
	}
	else
	{
		if_oct(str, len);
		save_buff(str, len, 0);
	}
	if ((g_lst.type == 'x' || g_lst.type == 'X') && g_fl.oc == 1)
		g_lst.width -= 2;
	(g_lst.type == 'o' && g_fl.oc == 1) ? g_lst.width-- : 0;
	(g_lst.width > 0) ? space(g_lst.width, ' ') : 0;
}
