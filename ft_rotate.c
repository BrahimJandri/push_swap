/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:57:07 by bjandri           #+#    #+#             */
/*   Updated: 2024/04/17 15:57:37 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_ra(t_list *stack)
{
    t_list *tmp;

    tmp = stack;
    stack = stack->next;
    tmp->next = NULL;
    ft_lstadd_back(&stack, tmp);
}

void    ft_rb(t_list *stack)
{
    t_list *tmp;

    tmp = stack;
    stack = stack->next;
    tmp->next = NULL;
    ft_lstadd_back(&stack, tmp);
}

void    ft_rr(t_list *stack_a, t_list *stack_b)
{
    ft_ra(stack_a);
    ft_rb(stack_b);
}
