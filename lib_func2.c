/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_func2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosadchu <kosadchu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 17:36:03 by kosadchu          #+#    #+#             */
/*   Updated: 2019/03/31 17:39:00 by kosadchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_bzero(void *s, size_t n)
{
	__int128_t		*t_bzero_s;
	unsigned char	*uchar_s;
	size_t			i;

	t_bzero_s = (__int128_t *)s;
	uchar_s = (unsigned char *)s;
	i = n - (n % sizeof(__int128_t));
	while (i < n)
		uchar_s[i++] = 0;
	n /= sizeof(__int128_t);
	while (n)
		t_bzero_s[--n] = 0;
}

int		ft_lenint(__int128_t n)
{
	int		len;

	len = 0;
	if (n < 0)
	{
		len = 1;
		n = n * -1;
	}
	if ((n / 10) == 0)
		return (len + 1);
	else
	{
		while (n > 0)
		{
			n /= 10;
			len++;
		}
		return (len);
	}
}

char	*ft_strdup(const char *s1)
{
	char	*m;
	int		i;

	i = ft_strlen(s1);
	m = (char *)malloc(sizeof(char) * (i + 1));
	if (m == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		m[i] = s1[i];
		i++;
	}
	m[i] = '\0';
	return (m);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l;
	int		i;
	char	*jo;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	l = (ft_strlen(s1) + ft_strlen(s2));
	jo = (char*)malloc(sizeof(char) * (l + 1));
	if (jo == NULL)
		return (NULL);
	i = 0;
	while (*s1 != '\0')
	{
		jo[i++] = *s1++;
	}
	while (*s2 != '\0')
	{
		jo[i++] = *s2++;
	}
	jo[i] = '\0';
	return (jo);
}
