/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosadchu <kosadchu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 10:03:13 by exam              #+#    #+#             */
/*   Updated: 2019/02/28 13:57:19 by kosadchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*reverse(int i, char *res)
{
	char	*tmp;
	int		j;

	if (!(tmp = (char*)malloc(sizeof(char) * i)))
		return (NULL);
	j = 0;
	i--;
	while (i > -1)
		tmp[j++] = res[i--];
	return (tmp);
}

char	*other_base(const char *b, char *res, int value, int base)
{
	int		i;

	i = 0;
	res[i++] = '\0';
	while (value > 0)
	{
		res[i++] = b[value % base];
		value /= base;
	}
	res = reverse(i, res);
	return (res);
}

char	*base_ten(int len, const char *b, int value, int base)
{
	char	*res;

	if (!(res = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	res[len--] = '\0';
	(value < 0) ? res[0] = '-' : res[len];
	(value < 0) ? value *= -1 : value;
	while (value > 0)
	{
		res[len--] = b[value % base];
		value /= 10;
	}
	return (res);
}

char	*ft_itoa_base(int value, int base)
{
	int			len;
	const char	*b = "0123456789ABCDEF";
	char		*res;
	int			temp;

	if (base < 2 || base > 16)
		return (NULL);
	if (value == 0)
		return ("0");
	if (value == -2147483648)
		return ("-2147483648");
	len = (value < 0) ? 2 : 1;
	temp = value;
	while (temp /= 10)
		len++;
	if (!(res = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (base == 10)
		res = base_ten(len, b, value, base);
	else
		res = other_base(b, res, value, base);
	return (res);
}
