/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:51:54 by bjandri           #+#    #+#             */
/*   Updated: 2024/05/04 12:03:42 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_sort_stacks(t_stack **stack_a, t_stack **stack_b)
{
    int stack_len;
    
    stack_len = ft_stack_len(*stack_a);
    if(stack_len-- > 3 && !ft_is_sorted(*stack_a))
        ft_pb(stack_a, stack_b);
    if(stack_len-- > 3 && !ft_is_sorted(*stack_a))
        ft_pb(stack_a, stack_b);
    while (stack_len-- > 3 && !ft_is_sorted(*stack_a))
    {
        
    }
    
}
