/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 12:04:24 by bjandri           #+#    #+#             */
/*   Updated: 2024/05/07 16:10:49 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	current_index(t_stack *stack, t_stack *num)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack == num)
			return (i);
		else
			stack = stack->next;
		i++;
	}
	return (i);
}

void	ft_sort_five(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*min;
	int		stack_len;

	stack_len = ft_stack_len(*stack_a);
	min = ft_find_min(*stack_a);
	(*stack_a)->index = current_index(*stack_a, min);
	while (stack_len > 3)
	{
		if ((*stack_a)->index == 0)
			ft_pb(stack_b, stack_a);
		else if ((*stack_a)->index <= stack_len / 2)
			ft_ra(stack_a, 0);
		else if ((*stack_a)->index > stack_len / 2)
			ft_rra(stack_a, 0);
		stack_len = ft_stack_len(*stack_a);
		min = ft_find_min(*stack_a);
		(*stack_a)->index = current_index(*stack_a, min);
	}
	ft_sort_three(stack_a);
	ft_pa(stack_b, stack_a);
	ft_pa(stack_b, stack_a);
}
