/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosadchu <kosadchu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 13:55:45 by kosadchu          #+#    #+#             */
/*   Updated: 2019/03/14 17:07:06 by kosadchu         ###   ########.fr       */
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

uintmax_t	cast_hex(va_list ap)
{
	if (g_lst.sz[0] == 'l' && g_lst.sz[1] != 'l')
		return (va_arg(ap, unsigned long int));
	else if (g_lst.sz[0] == 'l' && g_lst.sz[1] == 'l')
		return (va_arg(ap, unsigned long long int));
	else if (g_lst.sz[0] == 'h' && g_lst.sz[1] != 'h')
		return ((unsigned short int)va_arg(ap, unsigned int));
	else if (g_lst.sz[0] == 'h' && g_lst.sz[1] == 'h')
		return ((unsigned char)va_arg(ap, unsigned int));
	else
		return (va_arg(ap, unsigned int));
}

void	two_zero(char *num, int len)
{
	if (g_lst.dot == 1 && num[0] == '0' && len == 1 && g_fl.two_zr == 1)
	{
		g_fl.two_zr = 2;
		g_fl.sh2 = g_lst.width;
	}
	else if (g_lst.dot == 1 && num[0] == '0' && len == 1 && g_fl.two_zr < 1)
	{
		g_fl.save_i = g_bf.i;
		g_fl.two_zr = 1;
		g_fl.sh1 = g_lst.width;
		(g_lst.type == 'o') ? g_lst.bftype = 'o' : 0;
		(g_fl.oc == 1) ? g_fl.oc2 = 1 : 0;
	}
}

void	cpy_str(void)
{
	char	*s;
	char	*tmp;
	int		i;

	i = 0;
	s = ft_strsub(g_bf.buf, g_fl.save_i, g_bf.i - g_fl.save_i);
	while (g_bf.i > g_fl.save_i)
		g_bf.i--;
	while (s[i])
	{
		if (s[i] == '0')
		{
			if (g_lst.width > 0)
				g_bf.buf[g_bf.i++] = ' ';
			i++;
		}
		g_bf.buf[g_bf.i++] = s[i];
		i++;
	}
	tmp = s;
	free(tmp);
}

void	clean_zero(void)
{
	if (g_fl.two_zr == 2)
	{
		if (g_lst.bftype == 'o' && g_lst.type == 'o' && g_fl.oc == 1
			&& g_fl.oc2 == 1)
				cpy_str();
		else
		{
			while (g_bf.i >= g_fl.save_i)
			{
			if (g_bf.buf[g_bf.i] == '0')
				g_bf.buf[g_bf.i] = ' ';
			g_bf.i--;
			}
			g_bf.i += g_fl.sh1 + g_fl.sh2 + 2;
		}
		g_fl.two_zr = 0;
		g_fl.sh1 = 0;
		g_fl.sh2 = 0;
	}
}
