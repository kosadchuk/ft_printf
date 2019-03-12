# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kosadchu <kosadchu@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/11 15:24:32 by kosadchu          #+#    #+#              #
#    Updated: 2019/03/11 17:00:05 by kosadchu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

CFLAGS := -c -Wall -Wextra -Werror

SRCS :=	ft_printf.c \
		format.c \
		chars.c \
		spec.c \
		decimal.c \
		ft_itoa_bs_pf.c \
		ft_strchr.c \
		ft_putstr.c \
		ft_memalloc.c \
		ft_strsub.c \
		ft_atoi.c \
		ft_strlen.c \
		ft_bzero.c

OBJ := ft_printf.o \
		format.o \
		chars.o \
		spec.o \
		decimal.o \
		ft_itoa_bs_pf.o \
		ft_strchr.o \
		ft_putstr.o \
		ft_memalloc.o \
		ft_strsub.o \
		ft_atoi.o \
		ft_strlen.o \
		ft_bzero.o

INCLD := ft_printf.h

all: $(NAME)
$(NAME): $(OBJ)
	gcc $(CFLAGS) $(SRCS) -I $(INCLD)
	ar rc $(NAME) $(OBJ)
clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re
