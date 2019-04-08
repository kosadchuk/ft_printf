/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_func1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosadchu <kosadchu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 17:29:15 by kosadchu          #+#    #+#             */
/*   Updated: 2019/04/05 15:41:54 by kosadchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_strchr(const char *s, int c)
{
	char		ch;
	char		*s1;
	size_t		i;

	ch = (char)c;
	s1 = (char *)s;
	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == ch)
			return (s1 + i);
		i++;
	}
	if (ch == '\0')
		return (s1 + i);
	return (NULL);
}

void			*ft_memalloc(size_t size)
{
	char		*m;

	m = malloc(sizeof(*m) * size);
	if (!m)
		return (NULL);
	ft_bzero(m, size);
	return (m);
}

char			*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*sub;
	size_t		i;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (NULL);
	sub = (char*)malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
		return (NULL);
	while (i < len && s[start] != '\0')
	{
		sub[i] = s[start];
		start++;
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

size_t			ft_strlen(const char *s)
{
	int			i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

__int128_t		ft_atoi(const char *str)
{
	size_t		i;
	__int128_t	j;
	int			x;

	i = 0;
	j = 0;
	x = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		x = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		j = (j * 10) + (str[i] - '0');
		i++;
	}
	return (j * x);
}
