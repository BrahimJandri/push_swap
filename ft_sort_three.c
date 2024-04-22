/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <bjandri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:25:19 by bjandri           #+#    #+#             */
/*   Updated: 2024/04/22 16:15:25 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_sort_three(t_list **stack)
{
	t_list	*last;
	int		max;

	last = ft_lstlast(*stack);
	max = ft_find_max(*stack);
	while (last->content != max)
	{
		ft_ra(stack);
		last = ft_lstlast(*stack);
	}
	if ((*stack)->content > (*stack)->next->content)
		ft_sa(stack);
	return (*stack);
}

t_list		*ft_sort_five(t_list **stack_a, t_list **stack_b)
{
	int min;
	int i;

	i = 0;
	min = ft_find_min(*stack_a);
	while ((*stack_a)->content == min && i < 2)
	{
		ft_pb(stack_a, stack_b);
		min = ft_find_min(*stack_a);
		i++;	
	}
	ft_sort_three(stack_a);
	i = 0;
	while(i < 2)
	{
		ft_pa(stack_a, stack_b);
		i++;
	}
	return(*stack_a);
}
