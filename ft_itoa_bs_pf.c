/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bs_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosadchu <kosadchu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:23:50 by kosadchu          #+#    #+#             */
/*   Updated: 2019/03/02 13:29:50 by kosadchu         ###   ########.fr       */
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
	(d < 0) ? res[0] = '-' : res[len];
	(d < 0) ? d *= -1 : d;
	res[len--] = '\0';
	while (d > 0)
	{
		res[len--] = str[d % 10];
		d /= 10;
	}
	return (res);
}

char	*ft_itoa_bs_pf(intmax_t d, uintmax_t u, int base)
{
	char		*str;
	char		*res;

	str = "0123456789";
	(g_sp->type == 'o') ? str = "01234567" : 0;
	(g_sp->type == 'x') ? str = "0123456789abcdef" : 0;
	(g_sp->type == 'X') ? str = "0123456789ABCDEF" : 0;
	if (base < 2 || base > 16)
		return (NULL);
	if (base == 10 && (g_sp->type == 'd' || g_sp->type == 'i'))
		res = base_ten(str, d);
	if (g_sp->type == 'o')
		res = uns_base(str, u, 8);
	else if (g_sp->type == 'x' || g_sp->type == 'X')
		res = uns_base(str, u, 16);
	else if (g_sp->type == 'u')
		res = uns_base(str, u, 10);	
	return (res);
}