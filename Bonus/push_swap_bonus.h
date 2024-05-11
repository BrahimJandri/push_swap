/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 08:39:35 by bjandri           #+#    #+#             */
/*   Updated: 2024/05/11 10:26:47 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	struct s_stack	*head;
	struct s_stack	*next;
	int				content;
	char			**str;
}					t_stack;


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif


void				ft_check_args_bonus(int ac, char **av, t_stack *a);
t_stack				*ft_new_stack_b(int content);
void				ft_clear_stack_b(t_stack **stack, void (*del)(int));
void				ft_add_back_b(t_stack **stack, t_stack *new);
t_stack				*ft_last_stack_b(t_stack *stack);
void				ft_add_front_b(t_stack **stack, t_stack *new);
void				ft_free_str_b(char **str);
void				ft_error_msg_b(char *str);
void				del_b(int data);
void				free_stack_b(t_stack **top);
int					ft_stack_len_b(t_stack *stack);
void				ft_push_bonus(t_stack **stack_a, t_stack **stack_b);
void				ft_rotate_bonus(t_stack **stack);
void				ft_rev_rot_bonus(t_stack **stack);
void				ft_swap_bonus(t_stack **stack);
void 				check_moves(t_stack **satck_a, t_stack **satck_b);
void 				ft_exit(char *str);

char				*get_next_line(int fd);
int					ft_strllen(char *str);
char				*ft_strjjoin(char *s1, char *s2);
char				*ft_strchr(char *str, int c);
char				*ft_free(char *str);

#endif