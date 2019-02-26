/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosadchu <kosadchu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 10:29:49 by kosadchu          #+#    #+#             */
/*   Updated: 2019/02/26 15:57:25 by kosadchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *f, ...)
{
	va_list		ap;

	g_buf.i = 0;
	g_buf.it = 0;
	va_start(ap, f);
	while (f[g_buf.it])
	{
		if (f[g_buf.it] == '%')
		{
			check_spec(f);
		}
		save_buf(f[g_buf.it]);
		g_buf.it++;
	}
	va_end(ap);
	return (0);
}