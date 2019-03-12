/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosadchu <kosadchu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 14:47:51 by kosadchu          #+#    #+#             */
/*   Updated: 2019/03/12 14:39:12 by kosadchu         ###   ########.fr       */
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

void	decimal(va_list ap)
{
	intmax_t	d;
	char		*s;

	g_lst.type = 'd';
	d = cast_dec(ap);
	s = ft_itoa_bs_pf(d, 0, 10);
	while (*s)
		g_bf.buf[g_bf.i++] = *s++;
}

void	numbers(const char *f, va_list ap)
{
	if (f[g_bf.it] == 'd')
		decimal(ap);
}