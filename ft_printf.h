/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosadchu <kosadchu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 13:44:51 by kosadchu          #+#    #+#             */
/*   Updated: 2019/03/05 17:40:29 by kosadchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>

typedef struct	s_bf
{
	char		buf[4096];
	int			i;
	int			it;
}				t_bf;

typedef struct	s_lst
{
	int			width;
	int			prec;
	char		type;
}				t_lst;

typedef struct	s_fl
{
	int			mn;
	int			pl;
	int			oc;
	int			zr;
	int			sp;
}				t_fl;

t_bf			g_bf;
t_lst			g_lst;
t_fl			g_fl;
int				ft_printf(const char *f, ...);
void			check_format(const char *f, va_list ap);
void			save_buff(char c);
void			check_spec(const char *f, va_list ap);
void			save_flags(const char *f);
void			type_char(const char *f, va_list ap);
void			check_width(const char *f);
void			make_width(int	len, char *s);

#endif