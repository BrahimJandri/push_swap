/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:25:19 by bjandri           #+#    #+#             */
/*   Updated: 2024/05/02 15:55:48 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_find_min(t_stack *stack)
{
	t_stack	*min;
	t_stack	*cur;

	if (!stack)
	{
		return NULL;
	}
	min = stack;
	cur = stack->next;
	while (cur)
	{
		if (cur->content < min->content)
			min = cur;
		cur = cur->next;
	}
	return (min);
}

t_stack	*ft_find_max(t_stack *stack)
{
	t_stack	*max;
	t_stack	*cur;

	if (!stack)
	{
		return (NULL);
	}
	max = stack;
	cur = stack->next;
	while (cur != NULL)
	{
		if (cur->content > max->content)
			max = cur;
		cur = cur->next;
	}
	return (max);
}

void	ft_sort_three(t_stack **stack)
{
	t_stack	*last;
	t_stack	*max;
	last = ft_last_stack(*stack);
	max = ft_find_max(*stack);
	while (last->content != max->content)
	{
		ft_ra(stack, 0);
		last = ft_last_stack(*stack);
	}
	if ((*stack)->content > (*stack)->next->content)
		ft_sa(stack, 0);
}
