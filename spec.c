/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosadchu <kosadchu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 16:50:30 by kosadchu          #+#    #+#             */
/*   Updated: 2019/03/05 17:01:48 by kosadchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_width(const char *f)
{
	char	*s;
	int		len;

	len = 0;
	while (ft_strchr("123456789", f[g_bf.it]))
	{
		g_bf.it++;
		len++;
	}
	s = ft_strsub(f, g_bf.it - len, len);
	g_lst.width = ft_atoi(s);
	// printf("width--> %d\n", g_lst.width);
}

void	check_prec(const char *f)
{
	char	*s;
	int		len;

	len = 0;
	if (f[g_bf.it] == '.' && !ft_strchr("0123456789", f[g_bf.it + 1]))
		g_lst.prec = 0;
	else if (f[g_bf.it] == '.')
	{
		g_bf.it++;
		while (ft_strchr("0123456789", f[g_bf.it]))
		{
			g_bf.it++;
			len++;
		}
		s = ft_strsub(f, g_bf.it - len, len);
		g_lst.prec = ft_atoi(s);
		// printf("prec--> %d\n", g_lst.prec);
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

void	check_spec(const char *f, va_list ap)
{
	if (ft_strchr("-+#0 ", f[g_bf.it]))
		save_flags(f);
	if (ft_strchr("123456789", f[g_bf.it]))
		check_width(f);
	if (f[g_bf.it] == '.')
		check_prec(f);
	if (ft_strchr("sc", f[g_bf.it]))
		type_char(f, ap);
	g_bf.it++;
}