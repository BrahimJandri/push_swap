NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
RM = rm -f
AR = ar rcs
LIBFT = ./libft/libft.a

SRC = main.c ft_check_args.c ft_helper_func.c ft_create_stack.c ft_sort_three.c \
	ft_push.c ft_swap.c ft_rotate.c 
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean re fclean