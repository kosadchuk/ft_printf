/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosadchu <kosadchu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 16:13:19 by kosadchu          #+#    #+#             */
/*   Updated: 2019/03/05 17:57:30 by kosadchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	make_width(int len, char *s)
{
	int		w;

	if (g_lst.width > len && g_fl.mn == 0)
		{
			if (g_lst.prec > 0 && g_lst.prec < len)
			{
				w = g_lst.width - len + (len - g_lst.prec);
				while (w-- > 0)
					g_bf.buf[g_bf.i++] = ' ';
				while (*s && g_lst.prec-- > 0)
					g_bf.buf[g_bf.i++] = *s++;
			}
			else if (g_lst.prec < len && g_lst.width > g_lst.prec)
			{
				w = g_lst.width - g_lst.prec;
				while (w-- > 0)
					g_bf.buf[g_bf.i++] = ' ';
				while (*s && g_lst.prec-- > 0)
					g_bf.buf[g_bf.i++] = *s++;
			}
		}
	else if (g_lst.width > len && g_fl.mn == 1)
	{
		if (g_lst.prec > 0 && g_lst.prec < len)
		{
			w = g_lst.width - len + (len - g_lst.prec);
			while (*s && g_lst.prec-- > 0)
				g_bf.buf[g_bf.i++] = *s++;
			while (w-- > 0)
				g_bf.buf[g_bf.i++] = ' ';
		}
		else
		{
			w = g_lst.width - len;
			while (*s)
				g_bf.buf[g_bf.i++] = *s++;
			while (w-- > 0)
				g_bf.buf[g_bf.i++] = ' ';
		}
	}
}

void	type_char(const char *f, va_list ap)
{
	char	*s;
	char	ch[2];
	int		len;
	int		w;

	if (f[g_bf.it] == 'c')
	{
		ch[0] = (char) va_arg(ap, int);
		ch[1] = '\0';
		if (g_lst.width > 1)
			make_width(1, ch);
		else
			g_bf.buf[g_bf.i++] = ch[0];
	}
	else if (f[g_bf.it] == 's')
	{
		s = va_arg(ap, char*);
		len = ft_strlen(s);
		if (g_lst.width > len)
			make_width(len, s);
		else
			while (*s)
				g_bf.buf[g_bf.i++] = *s++;
	}
}

