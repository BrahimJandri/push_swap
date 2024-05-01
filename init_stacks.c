/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:04:02 by bjandri           #+#    #+#             */
/*   Updated: 2024/05/01 09:44:12 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void    ft_cur_index(t_stack *stack)
{
    int i;
    int medd;

    i = 0;
    if(!stack)
        return ;
    medd = ft_stack_len(stack) / 2;
    while (stack)
    {
        stack->index = i;
        if(i <= medd)
            stack->fo9_nes = 0;
        else
            stack->fo9_nes = 1;
        stack = stack->next;
        ++i;
    }
}

void    target_stack_a(t_stack *stack_a, t_stack *stack_b)
{
    t_stack *cur_b;
    t_stack *target;

    long    match;
    while (stack_a)
    {
        match = LONG_MIN;
        cur_b = stack_b;
        while (cur_b)
        {
            if (cur_b->content < stack_a->content && cur_b->content > match)
            {
                match = cur_b->content;
                target = cur_b;
            }
            cur_b = cur_b->next;
            if(match == LONG_MIN)
                stack_a->target = ft_find_max(stack_b);
        }
                
    }
    
}

void init_stack_a(t_stack *stack_a, t_stack *stack_b)
{
    ft_cur_index(stack_a);
    ft_cur_index(stack_b);
}