/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bs_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosadchu <kosadchu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:23:50 by kosadchu          #+#    #+#             */
/*   Updated: 2019/03/14 14:55:59 by kosadchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*reverse(int i, char *res)
{
	char	*tmp;
	int		j;

	tmp = (char*)ft_memalloc(sizeof(char) * i);
	j = 0;
	i--;
	while (i > -1)
		tmp[j++] = res[i--];
	return (tmp);
}

char	*uns_base(char *str, uintmax_t u, int base)
{
	char		*res;
	char		*t;
	int			len;
	uintmax_t	tmp;
	int			i;

	tmp = u;
	len = 1;
	i = 0;
	while (tmp /= 10)
		len++;
	res = (char*)ft_memalloc(sizeof(char) * len + 1);
	res[i++] = '\0';
	while (u > 0)
	{
		res[i++] = str[u % base];
		u /= base;
	}
	t = reverse(i, res);
	free(res);
	return (t);
}

char	*base_ten(char *str, intmax_t d)
{
	int			len;
	intmax_t	tmp;
	char		*res;
	int			min;

	len = (d < 0) ? 2 : 1;
	min = (d < 0) ? 1 : 0;
	tmp = d;
	while (tmp /= 10)
		len++;
	(d < 0) ? d *= -1 : d;
	res = (char*)ft_memalloc(sizeof(char) * len + 1);
	res[len--] = '\0';
	res[len--] = str[d % 10];
	d /= 10;
	while (len > -1)
	{
		res[len--] = str[d % 10];
		d /= 10;
	}
	(min == 1) ? res[0] = '-' : 0;
	return (res);
}

char	*ft_itoa_bs_pf(intmax_t d, uintmax_t u, int base)
{
	char		*str;
	char		*res;
	char		*tmp;

	str = "0123456789";
	(g_lst.type == 'o') ? str = "01234567" : 0;
	(g_lst.type == 'x') ? str = "0123456789abcdef" : 0;
	(g_lst.type == 'X') ? str = "0123456789ABCDEF" : 0;
	if (base < 2 || base > 16)
		return (NULL);
	if (d == 0 && u == 0)
		return ("0");
	if (base == 10 && (g_lst.type == 'd' || g_lst.type == 'i'))
		res = base_ten(str, d);
	if (g_lst.type == 'o')
		res = uns_base(str, u, 8);
	else if (g_lst.type == 'x' || g_lst.type == 'X')
		res = uns_base(str, u, 16);
	else if (g_lst.type == 'u')
		res = uns_base(str, u, 10);
	tmp = res;
	free(tmp);
	return (res);
}