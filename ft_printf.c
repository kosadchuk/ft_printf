/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosadchu <kosadchu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 13:48:43 by kosadchu          #+#    #+#             */
/*   Updated: 2019/03/31 17:48:52 by kosadchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *f, ...)
{
	va_list		ap;

	g_bf.ret = 0;
	va_start(ap, f);
	check_format(f, ap);
	va_end(ap);
	return (g_bf.ret);
}
