/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosadchu <kosadchu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 16:06:40 by kosadchu          #+#    #+#             */
/*   Updated: 2019/03/05 14:16:05 by kosadchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	save_buff(char c)
{
	g_bf.buf[g_bf.i] = c;
	g_bf.i++;
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
			check_spec(f, ap);
		}
		save_buff(f[g_bf.it]);
		g_bf.it++;
	}
	ft_putstr(g_bf.buf);
}