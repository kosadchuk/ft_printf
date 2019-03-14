/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosadchu <kosadchu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 14:47:51 by kosadchu          #+#    #+#             */
/*   Updated: 2019/03/14 14:17:07 by kosadchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	heximal(const char *f, va_list ap)
{
	uintmax_t	u;
	char		*s;
	int			len;

	(f[g_bf.it] == 'o') ? g_lst.type = 'o' : 0;
	(f[g_bf.it] == 'x') ? g_lst.type = 'x' : 0;
	(f[g_bf.it] == 'X') ? g_lst.type = 'X' : 0;
	u = cast_hex(ap);
	(f[g_bf.it] == 'o') ? s = ft_itoa_bs_pf(0, u, 8) : 0;
	(f[g_bf.it] == 'x') ? s = ft_itoa_bs_pf(0, u, 16) : 0;
	(f[g_bf.it] == 'X') ? s = ft_itoa_bs_pf(0, u, 16) : 0;
	len = ft_strlen(s);
	two_zero(s, len);
	(g_lst.prec < len) ? g_lst.prec = 0 : 0;
	(g_lst.width < len) ? g_lst.width = 0 : 0;
	make_prec_width(len);
	if (g_fl.mn == 1)
		if_minus(s, len);
	else
		without_minus(s, len);
}

void	decimal(const char *f, va_list ap)
{
	intmax_t	d;
	char		*s;
	int			len;

	(f[g_bf.it] == 'd') ? g_lst.type = 'd' : 0;
	(f[g_bf.it] == 'i') ? g_lst.type = 'i' : 0;
	d = cast_dec(ap);
	s = ft_itoa_bs_pf(d, 0, 10);
	len = ft_strlen(s);
	two_zero(s, len);
	(d < 0) ? len -= 1 : 0;
	(d < 0  && g_fl.mn == 1) ? g_lst.width -= 1 : 0;
	(g_lst.prec < len) ? g_lst.prec = 0 : 0;
	(g_lst.width < len) ? g_lst.width = 0 : 0;
	make_prec_width(len);
	(d < 0) ? len += 1 : 0;
	if (g_fl.mn == 1)
		if_minus(s, len);
	else
		without_minus(s, len);
}

void	numbers(const char *f, va_list ap)
{
	if (f[g_bf.it] == 'd' || f[g_bf.it] == 'i')
		decimal(f, ap);
	if (f[g_bf.it] == 'o' || f[g_bf.it] == 'x' || f[g_bf.it] == 'X')
		heximal(f, ap);
	clean_zero();
}
