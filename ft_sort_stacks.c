/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 10:24:39 by bjandri           #+#    #+#             */
/*   Updated: 2024/05/01 09:12:40 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_sort_stacks(t_stack **stack_a, t_stack **stack_b)
{
	int len_stack_a;

	len_stack_a = ft_stack_len(*stack_a);
	if (len_stack_a > 3 && !ft_is_sorted(*stack_a))
		ft_pb(stack_a, stack_b);
	len_stack_a = ft_stack_len(*stack_a);
	if (len_stack_a > 3 && !ft_is_sorted(*stack_a))
		ft_pb(stack_a, stack_b);
	while (len_stack_a > 3 && !ft_is_sorted(*stack_a))
	{
        init_stack_a(*stack_a, *stack_b);
	}
	return (*stack_a);
}