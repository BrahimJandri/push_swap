/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:51:54 by bjandri           #+#    #+#             */
/*   Updated: 2024/05/11 09:15:41 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_second_step(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*max;

	max = ft_find_max(*stack_b);
	while (*stack_b)
	{
		if ((*stack_b)->content == max->content)
		{
			ft_pa(stack_b, stack_a);
			max = ft_find_max(*stack_b);
		}
		else if (current_index(*stack_b, max) <= ft_stack_len(*stack_b) / 2)
			ft_rb(stack_b, 0);
		else
			ft_rrb(stack_b, 0);
	}
}

void	ft_sort_stacks(t_stack **stack_a, t_stack **stack_b)
{
	int	*array;

	array = ft_fill_array(*stack_a);
	ft_sort_arry(array, (*stack_a)->size);
	ft_first_step(stack_a, stack_b, array);
	ft_second_step(stack_a, stack_b);
	free(array);
}
