/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bs_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosadchu <kosadchu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:23:50 by kosadchu          #+#    #+#             */
/*   Updated: 2019/03/11 13:49:55 by kosadchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static intmax_t		minus(intmax_t d)
{
	if (d < 0)
		d = -d;
	return (d);
}

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
	}
	res = reverse(i, res);
	return (res);
}

char	*base_ten(char *str, intmax_t d)
{
	int			len;
	intmax_t	tmp;
	char		*res;

	len = (d < 0) ? 2 : 1;
	tmp = d;
	while (tmp /= 10)
		len++;
	res = (char*)ft_memalloc(sizeof(char) * len + 1);
	(d < 0 && g_lst.prec < len) ? res[0] = '-' : res[len];
	res[len--] = '\0';
	while (len > 0)
	{
		res[len--] = str[minus(d % 10)];
		d /= 10;
	}
	return (res);
}

char	*ft_itoa_bs_pf(intmax_t d, uintmax_t u, int base)
{
	char		*str;
	char		*res;

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
	return (res);
}