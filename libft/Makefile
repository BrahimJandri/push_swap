# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/22 12:22:53 by bjandri           #+#    #+#              #
#    Updated: 2024/02/15 12:09:06 by bjandri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
FUNC := ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
       ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
       ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
       ft_calloc.c ft_strdup.c ft_toupper.c ft_tolower.c \
       ft_strchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
       ft_strnstr.c ft_atoi.c ft_strrchr.c ft_substr.c \
       ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
       ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
       ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
       ft_printf.c ft_printf_char.c ft_printf_hexlow.c ft_printf_hexupp.c \
	ft_printf_str.c ft_printf_int.c ft_printf_unsigned.c ft_printf_add.c ft_free.c
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
