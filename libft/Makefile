# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/01 17:57:27 by gim               #+#    #+#              #
#    Updated: 2020/10/08 15:36:22 by gim              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AR = ar
ARFLAGS = rcs
CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRCS_DIR = ./
SRCS = ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strlen.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_memset.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memcmp.c \
		ft_memchr.c \
		ft_memmove.c \
		ft_bzero.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strnstr.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_strdup.c \
		ft_calloc.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c

SRCS_B = ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c

OBJS = $(addprefix $(SRCS_DIR), $(SRCS:c=o))
OBJS_B = $(addprefix $(SRCS_DIR), $(SRCS_B:c=o))

%.o: %.c
		$(CC) $(CFLAGS) -c $<

$(NAME): $(OBJS)
		$(AR) $(ARFLAGS) $@ $^

bonus: $(OBJS_B)
		$(AR) $(ARFLAGS) $(NAME) $^

all: $(NAME)

clean:
		rm -f $(OBJS) $(OBJS_B)

fclean: clean
		rm -f $(NAME)

re: fclean all