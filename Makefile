NAME = push_swap
B_NAME = checker
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
RM = rm -f
AR = ar rcs
LIBFT = ./libft/libft.a

SRC = Mandatory/push_swap.c Mandatory/ft_check_args.c Mandatory/ft_helper_func.c Mandatory/ft_create_stack.c Mandatory/ft_sort_three.c \
	Mandatory/ft_push.c Mandatory/ft_swap.c Mandatory/ft_rotate.c Mandatory/ft_is_sorted.c Mandatory/ft_reverse_rotate.c Mandatory/ft_sort_stacks.c \
	Mandatory/ft_stack_utils.c Mandatory/ft_sort_five.c Mandatory/ft_sort_four.c Mandatory/ft_helper_func2.c Mandatory/ft_first_step.c

B_SRC = Bonus/ft_check_args_bonus.c Bonus/checker.c Bonus/ft_helper_func_bonus.c Bonus/ft_stack_util_bonus.c Bonus/get_next_line.c \
	Bonus/get_next_line_utils.c Bonus/ft_moves.c Bonus/check_moves.c 

OBJ = $(SRC:.c=.o)
B_OBJ = $(B_SRC:.c=.o)


all: $(NAME)

bonus : $(B_NAME)

$(NAME): $(OBJ) 
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)  $(LIBFT)

$(B_NAME): $(B_OBJ) 
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) -o $(B_NAME) $(B_OBJ)  $(LIBFT)

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJ) $(B_OBJ)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME) $(B_NAME)

re: fclean all

re_bonus : fclean bonus

.PHONY: all clean re fclean