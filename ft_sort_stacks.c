/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 10:24:39 by bjandri           #+#    #+#             */
/*   Updated: 2024/04/28 13:15:41 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_sort_stacks(t_list **stack_a, t_list **stack_b)
{
    int len_stack_a;

    len_stack_a = ft_lstsize(*stack_a);
    if(len_stack_a > 3 && !ft_is_sorted(*stack_a))
        ft_pb(stack_a, stack_b);
    if(len_stack_a > 3 && !ft_is_sorted(*stack_a))
        ft_pb(stack_a, stack_b);
    // while (len_stack_a > 3 && !ft_is_sorted(*stack_a))
    // {
        
    // }
    
    return(*stack_a);
}