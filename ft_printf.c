/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosadchu <kosadchu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 13:48:43 by kosadchu          #+#    #+#             */
/*   Updated: 2019/03/12 16:50:21 by kosadchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *f, ...)
{
	va_list		ap;
	g_fl.nl = 0;

	va_start(ap, f);
	check_format(f, ap);
	va_end(ap);
	g_bf.i += g_fl.nl;
	return (g_bf.i);
}