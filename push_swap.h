/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 07:27:21 by bjandri           #+#    #+#             */
/*   Updated: 2024/04/22 16:03:13 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdlib.h>

typedef struct s_stack
{
	t_list	*top;
	t_list	*bottom;
	t_list	*next;
	int		max;
	char	**str;
	int		value;
	int		size;
}			t_stack;

void		ft_check_args(int ac, char **av, t_stack *a);
void		ft_error_msg(char *str);
void		ft_free_str(char **str);
void		del(int data);
void		free_stack(t_list **top);
void		ft_sa(t_list **stack);
int			ft_find_max(t_list *stack);
int			ft_find_min(t_list *stack);
int			ft_stack_len(t_list *stack);
void		ft_sb(t_list **stack);
void		ft_pa(t_list **stack_a, t_list **stack_b);
void		ft_pb(t_list **stack_a, t_list **stack_b);
void		ft_ra(t_list **stack);
void		ft_rb(t_list **stack);
void		ft_rra(t_list **stack);
void		ft_rrb(t_list **stack);
void		ft_rrr(t_list **stack_a, t_list **stack_b);
void		ft_push(t_list **stack_a, t_list **stack_b);
void		ft_ss(t_list **stack_a, t_list **stack_b);
int			ft_is_sorted(t_list *stack);
t_list		*ft_sort_three(t_list **stack);
t_list		*ft_creat_stack(int ac, char **av);
t_list		*ft_sort_five(t_list **stack_a, t_list **stack_b);

#endif