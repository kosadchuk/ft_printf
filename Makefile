# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kosadchu <kosadchu@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/11 15:24:32 by kosadchu          #+#    #+#              #
#    Updated: 2019/04/06 13:05:54 by kosadchu         ###   ########.fr        #
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
		parsing.c \
		cast.c \
		float.c \
		float2.c \
		lib_func1.c \
		lib_func2.c \
		other_func.c

OBJ := ft_printf.o \
		format.o \
		chars.o \
		spec.o \
		decimal.o \
		ft_itoa_bs_pf.o \
		parsing.o \
		cast.o \
		float.o \
		float2.o \
		lib_func1.o \
		lib_func2.o \
		other_func.o

INCLD := ft_printf.h

all: $(NAME)
$(NAME): $(OBJ) $(INCLD)
	gcc $(CFLAGS) $(SRCS) -I $(INCLD)
	ar rc $(NAME) $(OBJ)
clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re
