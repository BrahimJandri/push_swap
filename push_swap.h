/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 07:27:21 by bjandri           #+#    #+#             */
/*   Updated: 2024/05/02 17:08:19 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct s_stack
{
    struct s_stack *head;
    struct s_stack *prev;
    struct s_stack *target;
    struct s_stack *next;
    int content;
    int index;
    int push_cost;
    char **str;
    bool cheapest;
    bool foq_median;
} t_stack;


int			ft_is_sorted(t_stack *stack);
int			ft_stack_len(t_stack *stack);
void		ft_check_args(int ac, char **av, t_stack *a);
void		ft_error_msg(char *str);
void		ft_free_str(char **str);
void		del(int data);
void		ft_clear_stack(t_stack **stack, void (*del)(int));
void		ft_add_back(t_stack **stack, t_stack *new);
void		free_stack(t_stack **top);
void	    ft_add_front(t_stack **stack, t_stack *new);
void		ft_sa(t_stack **stack, int c);
void		ft_sb(t_stack **stack, int c);
void		ft_ss(t_stack **stack_a, t_stack **stack_b, int c);
void		ft_pa(t_stack **stack_a, t_stack **stack_b);
void		ft_pb(t_stack **stack_a, t_stack **stack_b);
void		ft_ra(t_stack **stack, int c);
void		ft_rb(t_stack **stack, int c);
void		ft_rr(t_stack **stack_a, t_stack **stack_b, int c);
void		ft_rra(t_stack **stack, int c);
void		ft_rrb(t_stack **stack, int c);
void		ft_rrr(t_stack **stack_a, t_stack **stack_b, int c);
void		ft_swap(t_stack **stack);
void		ft_rev_rot(t_stack **stack);
void		ft_push(t_stack **stack_a, t_stack **stack_b);
void		ft_rotate(t_stack **stack);
void		ft_sort_three(t_stack **stack);
void        ft_sort_stacks(t_stack **stack_a, t_stack **stack_b);
void        ft_init_satck_a(t_stack *stack_a, t_stack *stack_b);
t_stack		*ft_find_min(t_stack *stack);
t_stack	    *ft_last_stack(t_stack *stack);
t_stack		*ft_find_max(t_stack *stack);
t_stack		*ft_new_stack(int content);
t_stack		*ft_creat_stack(int ac, char **av);

#endif