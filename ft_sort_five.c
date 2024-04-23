/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:08:09 by bjandri           #+#    #+#             */
/*   Updated: 2024/04/23 11:08:48 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_min(t_list *stack)
{
	t_list	*min;
	t_list	*cur;

	if (!stack)
	{
		return (-1);
	}
	min = stack;
	cur = stack->next;
	while (cur)
	{
		if (cur->content < min->content)
			min = cur;
		cur = cur->next;
	}
	return (min->content);
}

int	ft_find_index(t_list *stack, int num)
{
	int		i;
	t_list	*cur;

	i = 0;
	if (!stack)
	{
		return (-1);
	}
	cur = stack->next;
	while (cur)
	{
		if (cur->content == num)
			return (i);
		cur = cur->next;
		i++;
	}
	return (-1);
}

t_list	*ft_sort_five(t_list **stack_a, t_list **stack_b)
{
	int	min;
	int	i;
	int	min_index;

	i = 0;
	min = ft_find_min(*stack_a);
	min_index = ft_find_index(*stack_a, min);
	while (i < 2)
	{
		if ((*stack_a)->content == min)
		{
			ft_pb(stack_a, stack_b);
			min = ft_find_min(*stack_a);
			i++;
		}
		if (min_index >= ft_lstsize(*stack_a) / 2)
			ft_rra(stack_a);
		else
			ft_ra(stack_a);
	}
	ft_sort_three(stack_a);
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
	return (*stack_a);
}
