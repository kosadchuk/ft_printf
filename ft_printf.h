/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosadchu <kosadchu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 13:44:51 by kosadchu          #+#    #+#             */
/*   Updated: 2019/03/14 16:24:56 by kosadchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <limits.h>

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
	int			dot;
	char		type;
	char		bftype;
	char		sz[2];
}				t_lst;

typedef struct	s_fl
{
	int			mn;
	int			pl;
	int			oc;
	int			oc2;
	int			zr;
	int			sp;
	int			two_zr;
	int			save_i;
	int			sh1;
	int			sh2;
}				t_fl;

t_bf			g_bf;
t_lst			g_lst;
t_fl			g_fl;
int				ft_printf(const char *f, ...);
void			check_format(const char *f, va_list ap);
void			save_buff(char *s, int len, int minus);
void			check_spec(const char *f, va_list ap);
void			save_flags(const char *f);
void			str_char(const char *f, va_list ap);
void			check_width(const char *f);
void			print_space(char *s, int len);
void			decimal(const char *f, va_list ap);
void			numbers(const char *f, va_list ap);
void			free_flags(void);
char			*ft_itoa_bs_pf(intmax_t d, uintmax_t u, int base);
void			*ft_memalloc(size_t size);
void			ft_putstr(char const *s);
char			*ft_strchr(const char *s, int c);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
int				ft_atoi(const char *str);
size_t			ft_strlen(const char *s);
void			ft_bzero(void *s, size_t n);
void			pars_char(char c, int len);
void			space(int len, char c);
void			make_prec_width(int len);
void			without_minus(char *str, int len);
void			if_minus(char *str, int len);
void			pars_wm(char *str, int len);
void			two_zero(char *num, int len);
void			clean_zero(void);
intmax_t		cast_dec(va_list ap);
uintmax_t		cast_hex(va_list ap);

#endif