/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosadchu <kosadchu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 10:31:31 by kosadchu          #+#    #+#             */
/*   Updated: 2019/02/26 16:47:12 by kosadchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct	s_buf
{
	char		buf[4096];
	int			i;
	int			it;
}				t_buf;

typedef struct	s_flags
{
	int			fl_m;
	int			fl_p;
	int			fl_s;
	int			fl_z;
	int			fl_o;
	int			fl_wd;
}				t_flag;

typedef struct	s_type
{
	int			
};


t_buf			g_buf;
t_flag			g_flag;
int				ft_printf(const char *f, ...);
void			save_buf(char c);

#endif