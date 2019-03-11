/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosadchu <kosadchu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 16:50:30 by kosadchu          #+#    #+#             */
/*   Updated: 2019/03/11 15:17:17 by kosadchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_width(const char *f)
{
	char	*s;
	int		len;

	len = 0;
	while (ft_strchr("0123456789", f[g_bf.it]))
	{
		g_bf.it++;
		len++;
	}
	s = ft_strsub(f, g_bf.it - len, len);
	g_lst.width = ft_atoi(s);
}

void	check_prec(const char *f)
{
	char	*s;
	int		len;

	len = 0;
	if (f[g_bf.it] == '.' && !ft_strchr("0123456789", f[g_bf.it + 1]))
	{
		g_lst.dot = 1;
		g_bf.it++;
	}
	else
	{
		g_bf.it++;
		while (ft_strchr("0123456789", f[g_bf.it]))
		{
			g_bf.it++;
			len++;
		}
		s = ft_strsub(f, g_bf.it - len, len);
		g_lst.prec = ft_atoi(s);
	}
}

void	save_flags(const char *f)
{
	while (ft_strchr("-+#0 ", f[g_bf.it]))
	{
		if (f[g_bf.it] == '-' || g_fl.mn == 1)
			g_fl.mn = 1;
		if (f[g_bf.it] == '+' || g_fl.pl == 1)
			g_fl.pl = 1;
		if (f[g_bf.it] == '#' || g_fl.oc == 1)
			g_fl.oc = 1;
		if (f[g_bf.it] == '0' || g_fl.zr == 1)
			g_fl.zr = 1;
		if (f[g_bf.it] == ' ' || g_fl.sp == 1)
			g_fl.sp = 1;
		g_bf.it++;
	}
}

void	save_size(const char *f)
{
	if (f[g_bf.it] == 'l' && ft_strchr("diouxXf", f[g_bf.it + 1]))
		g_lst.sz[0] = 'l';
	else if (f[g_bf.it] == 'l' && f[g_bf.it + 1] == 'l'
			&& ft_strchr("diouxXf", f[g_bf.it + 2]))
	{
		g_lst.sz[0] = 'l';
		g_lst.sz[1] = 'l';
		g_bf.it++;
	}
	else if (f[g_bf.it] == 'h' && ft_strchr("diouxXf", f[g_bf.it + 1]))
		g_lst.sz[0] = 'h';
	else if (f[g_bf.it] == 'h' && f[g_bf.it + 1] == 'h'
			&& ft_strchr("diouxXf", f[g_bf.it + 2]))
	{
		g_lst.sz[0] = 'h';
		g_lst.sz[1] = 'h';
		g_bf.it++;
	}
	g_bf.it++;
}

void	check_spec(const char *f, va_list ap)
{
	if (ft_strchr("-+#0 ", f[g_bf.it]))
		save_flags(f);
	if (ft_strchr("123456789", f[g_bf.it]))
		check_width(f);
	if (f[g_bf.it] == '.')
		check_prec(f);
	if (ft_strchr("lhL", f[g_bf.it]))
		save_size(f);
	if (ft_strchr("sc", f[g_bf.it]))
		str_char(f, ap);
	if (ft_strchr("diouxX", f[g_bf.it]))
		decimal(f, ap);
	if (f[g_bf.it] == '%')
		g_bf.buf[g_bf.i++] = '%';
	else
		g_bf.buf[g_bf.i++] = f[g_bf.it];
	g_bf.it++;
	(f[g_bf.it] == '.') ? g_bf.it++ : g_bf.it;
}