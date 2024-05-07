/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_four.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:13:17 by bjandri           #+#    #+#             */
/*   Updated: 2024/05/07 16:22:38 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_sort_four(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *min;
    int medin = ft_stack_len(*stack_a) / 2;
    min = ft_find_min(*stack_a);
    (*stack_a)->index = current_index(*stack_a, min);
    while ((*stack_a)->content != min->content)
    {
        if((*stack_a)->index <= medin)
            ft_ra(stack_a, 0);
        else
            ft_rra(stack_a, 0);   
    }
    ft_pb(stack_a, stack_b);
    ft_sort_three(stack_a);
    ft_pa(stack_b, stack_a);   
}