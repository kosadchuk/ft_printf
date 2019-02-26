/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosadchu <kosadchu@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 15:33:53 by kosadchu          #+#    #+#             */
/*   Updated: 2019/02/26 16:28:43 by kosadchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	save_buf(char c)
{
	g_buf.buf[g_buf.i] = c;
	ft_putchar(g_buf.buf[g_buf.i]);
	g_buf.i++;
}

void	check_spec(const char *f)
{

}