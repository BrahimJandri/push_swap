/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:03:41 by bjandri           #+#    #+#             */
/*   Updated: 2024/05/02 19:19:51 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_cur_index(t_stack *stack)
{
    int i;
    int median;

    i = 0;
    if(!stack)
        return ;
    median = ft_stack_len(stack) / 2;
    while (stack)
    {
        stack->index = i;
        if(i <= median)
            stack->foq_median = true;
        else
            stack->foq_median = false;
        stack = stack->next;
        i++;
    }
}
void ft_target_for_a(t_stack *stack_a, t_stack *satck_b)
{
    
}

void    ft_init_satck_a(t_stack *stack_a, t_stack *stack_b)
{
    ft_cur_index(stack_a);
    ft_cur_index(stack_b);
    ft_target_for_a(stack_a, stack_b);
}