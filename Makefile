# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/08 14:26:20 by gim               #+#    #+#              #
#    Updated: 2020/10/08 15:57:20 by gim              ###   ########.fr        #
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

SRCS = //

SRCS_B = //

OBJS = $(SRCS:c=o)
OBJS_B = $(SRCS_B:c=o)

$(LIBFT):
		make all -C libft/

%.o: %.c
		$(CC) $(CFLAGS) -c -L./libft -lft $<

$(NAME): $(LIBFT) $(OBJS)
		$(AR) $(ARFLAGS) $@ $^

bonus: $(OBJS_B)
		$(AR) $(ARFLAGS) $(NAME) $^

all: $(NAME)

clean:
		make clean -C libft/
		$(RM) $(OBJS) $(OBJS_B)

fclean:
		make fclean -C libft/
		$(RM) $(NAME)

re: fclean all


