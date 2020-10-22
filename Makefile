# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/08 14:26:20 by gim               #+#    #+#              #
#    Updated: 2020/10/22 19:43:04 by gim              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AR = ar
ARFLAGS = rcs
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

NAME = libftprintf.a

LIBFT = libft.a
LIBFT_H = ./libft/libft.h

SRCS = ft_printf.c \
		print_format.c \
		print.c \
		check_specifier.c \
		itoa_ui.c \
		convert_base.c \

OBJS = $(SRCS:c=o)

%.o: %.c
		$(CC) $(CFLAGS) -c $<

$(NAME): $(LIBFT) $(OBJS)
		mkdir libft_o && cd libft_o && ar -x ../libft/libft.a && cd ..
		$(AR) $(ARFLAGS) $@ libft_o/*.o $(OBJS)
		rm -rf libft_o

test:
		gcc test.c -L. -lftprintf

bonus: $(OBJS_B)
		$(AR) $(ARFLAGS) $(NAME) $^

all: $(NAME)

$(LIBFT):
		make -C libft/

clean:
		make clean -C libft/
		$(RM) $(OBJS) $(OBJS_B)

fclean:
		make fclean -C libft/
		$(RM) $(OBJS) $(OBJS_B)
		$(RM) $(NAME) $(LIBFT)

re: fclean all