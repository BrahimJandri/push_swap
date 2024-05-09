/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 12:04:24 by bjandri           #+#    #+#             */
/*   Updated: 2024/05/09 12:21:39 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_five(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*min;
	int		index;
	int		stack_len;

	stack_len = ft_stack_len(*stack_a);
	min = ft_find_min(*stack_a);
	index = current_index(*stack_a, min);
	while (stack_len > 3)
	{
		if (index == 0)
			ft_pb(stack_a, stack_b);
		else if (index <= ft_stack_len(*stack_a) / 2)
			ft_ra(stack_a, 0);
		else if (index > ft_stack_len(*stack_a) / 2)
			ft_rra(stack_a, 0);
		min = ft_find_min(*stack_a);
		index = current_index(*stack_a, min);
		stack_len = ft_stack_len(*stack_a);
	}
	ft_sort_three(stack_a);
	ft_pa(stack_b, stack_a);
	ft_pa(stack_b, stack_a);
}
