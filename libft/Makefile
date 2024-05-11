# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/22 12:22:53 by bjandri           #+#    #+#              #
#    Updated: 2024/05/10 16:23:41 by bjandri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
FUNC := ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_calloc.c ft_atoi.c ft_strjoin.c ft_split.c \
       ft_printf.c ft_printf_char.c ft_printf_hexlow.c ft_printf_hexupp.c ft_bzero.c ft_memset.c \
	ft_printf_str.c ft_printf_int.c ft_printf_unsigned.c ft_printf_add.c ft_free.c ft_atol.c ft_strncmp.c
       
OBJS := $(FUNC:.c=.o)
CC := cc
CFLAGS := -Wall -Wextra -Werror -fPIE
AR := ar rcs
RM := rm -rf

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS) $(OBJSB)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
