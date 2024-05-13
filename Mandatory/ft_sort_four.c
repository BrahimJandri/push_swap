/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_four.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:13:17 by bjandri           #+#    #+#             */
/*   Updated: 2024/05/13 13:28:04 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_four(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*min;
	int		mid;

	mid = ft_stack_len(*stack_a) / 2;
	min = ft_find_min(*stack_a);
	while (ft_stack_len(*stack_a) > 2)
	{
		if((*stack_a)->content == min->content)
			ft_pb(stack_a, stack_b);
		else if (current_index(*stack_a, min) <= mid)
			ft_ra(stack_a, 0);
		else
			ft_rra(stack_a, 0);
		min = ft_find_min(*stack_a);
	}
	if((*stack_a)->content > (*stack_a)->next->content)
		ft_sa(stack_a, 0);
	ft_pa(stack_b, stack_a);
	ft_pa(stack_b, stack_a);
}
