/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:57:53 by bjandri           #+#    #+#             */
/*   Updated: 2024/04/17 15:58:10 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_rra(t_list *stack)
{
    t_list *tmp;
    t_list *last;

    tmp = stack;
    while (tmp->next->next)
        tmp = tmp->next;
    last = tmp->next;
    tmp->next = NULL;
    ft_lstadd_front(&stack, last);
}

void    ft_rrb(t_list *stack)
{
    t_list *tmp;
    t_list *last;

    tmp = stack;
    while (tmp->next->next)
        tmp = tmp->next;
    last = tmp->next;
    tmp->next = NULL;
    ft_lstadd_front(&stack, last);
}

void    ft_rrr(t_list *stack_a, t_list *stack_b)
{
    ft_rra(stack_a);
    ft_rrb(stack_b);
}

